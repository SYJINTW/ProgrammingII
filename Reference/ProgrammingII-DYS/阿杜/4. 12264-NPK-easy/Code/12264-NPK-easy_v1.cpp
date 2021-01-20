#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <algorithm>

using namespace std;
list<int> line;
queue<int> country[3];

int main()
{
    string s;
    int n, id;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s=="ENQUEUE"){
            cin >> id;
            // Find out the person's country
            int num = id%3;
            // Push the person into his country's queue
            country[num].push(id);
            // If the country is not waiting in line, push the country into line
            if(find(line.begin(),line.end(),num)==line.end()) line.push_back(num);
        }
        else if(s=="DEQUEUE"){
            // Check which country is in the front of the line
            int num = line.front();
            // Output the person's ID from the front of the country's queue
            cout << country[num].front() << endl;
            // Pop that person from queue
            country[num].pop();
            // If there are no people in that country, pop the country from line
            if(country[num].empty()) line.pop_front();
        }
    }
    return 0;
}
