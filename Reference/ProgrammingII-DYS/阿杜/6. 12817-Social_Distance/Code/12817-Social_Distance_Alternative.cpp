#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <iterator>
using namespace std;

struct Interval {
    int leftPos, rightPos, leftNode, rightNode;
    Interval() : leftPos(0), rightPos(0), leftNode(0), rightNode(0) {}
    Interval(const int &leftPos, const int &rightPos, const int &leftNode, const int &rightNode);
    bool operator<(const Interval &rhs) const;
    bool operator==(const Interval &rhs) const;
};

class Container {
private:
    set<Interval> intervals;
    vector<pair<set<Interval>::iterator, set<Interval>::iterator>> nodes;
    int leftBoundPos, rightBoundPos, minDist, limitDist;
public:
    Container();
    void init(int length, int nodeNum, int limitDist);
    void printAns();
    void insert(int node);
    void remove(int node);
};

int main() {
    Container classroom;
    int seats, students, limitDist, num;
    string inst;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> seats >> students >> limitDist;
    classroom.init(seats, students, limitDist);
    while (cin >> inst >> num) {
        if (inst == "i")
            classroom.insert(num);
        else if (inst == "o")
            classroom.remove(num);
    }
    classroom.printAns();
    return 0;
}

Interval::Interval(const int &leftPos, const int &rightPos, const int &leftNode, const int &rightNode) {
    this->leftPos = leftPos;
    this->rightPos = rightPos;
    this->leftNode = leftNode;
    this->rightNode = rightNode;
}

bool Interval::operator<(const Interval &rhs) const {
    int lhsDist, rhsDist;

    lhsDist = (rightPos - leftPos) / 2;
    rhsDist = (rhs.rightPos - rhs.leftPos) / 2;
    return lhsDist != rhsDist ? lhsDist > rhsDist : leftPos < rhs.leftPos;
}

bool Interval::operator==(const Interval &rhs) const {
    return leftPos == rhs.leftPos && rightPos == rhs.rightPos && leftNode == rhs.leftNode && rightNode == rhs.rightNode;
}

Container::Container() {
    leftBoundPos = rightBoundPos = 0;
    minDist = (int)2e9;
    limitDist = 0;
}

void Container::init(int length, int nodeNum, int limitDist) {
    leftBoundPos = 0;
    rightBoundPos = length + 1;
    minDist = rightBoundPos - leftBoundPos;
    this->limitDist = limitDist;
    nodes.resize(nodeNum + 2);
    auto it = intervals.insert(Interval(leftBoundPos, rightBoundPos, 0, nodeNum + 1));
    nodes.at(0) = make_pair(set<Interval>::iterator(), it.first);
    nodes.at(nodeNum + 1) = make_pair(it.first, set<Interval>::iterator());
}

void Container::printAns() {
    cout << (minDist >= limitDist ? "YES" : "NO") << "\n";
    if (minDist == (rightBoundPos - leftBoundPos))
        cout << "INF\n";
    else
        cout << minDist << "\n";
}

void Container::insert(int node) {
    auto it = intervals.begin();
    int leftPos = it->leftPos, rightPos = it->rightPos;
    int leftNode = it->leftNode, rightNode = it->rightNode;
    int mid = (leftPos + rightPos) / 2;
    auto leftIt = intervals.insert(Interval(leftPos, mid, leftNode, node));
    auto rightIt = intervals.insert(Interval(mid, rightPos, node, rightNode));
    nodes.at(leftNode).second = leftIt.first;
    nodes.at(rightNode).first = rightIt.first;
    nodes.at(node) = make_pair(leftIt.first, rightIt.first);
    intervals.erase(it);
    if (leftPos != leftBoundPos && mid - leftPos < minDist)
        minDist = mid - leftPos;
    if (rightPos != rightBoundPos && rightPos - mid < minDist)
        minDist = rightPos - mid;
}

void Container::remove(int node) {
    auto itPair = nodes.at(node);
    int leftPos = itPair.first->leftPos, rightPos = itPair.second->rightPos;
    int leftNode = itPair.first->leftNode, rightNode = itPair.second->rightNode;
    intervals.erase(itPair.first);
    intervals.erase(itPair.second);
    auto it = intervals.insert(Interval(leftPos, rightPos, leftNode, rightNode));
    nodes.at(leftNode).second = it.first;
    nodes.at(rightNode).first = it.first;
}
