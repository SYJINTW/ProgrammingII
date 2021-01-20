#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    // create a map (a dictionary) that maps a string to an integer
    // map: key->value where
    // key: string, value: int
    map<string, int> WordFreq;

    string str;
    while (cin >> str) {
    /*
        // use the idiom of finding an element in a container
        auto found = WordFreq.find(str);
        if (found == WordFreq.cend()) {
            // a new word, initialize its count as 1
            WordFreq[str] = 1;
        } else {
            // an existing word; increase its frequency by 1
            WordFreq[str]++;
        }
   */
        if (WordFreq.count(str)==0) {
            // a new word, initialize its count as 1
            WordFreq[str] = 1;
        } else {
            // an existing word; increase its frequency by 1
            WordFreq[str]++;
        }

    }

    // iterate through the data in the map
    // the data are sorted by the keys
    // .first is the key and .second is the value
    /*
    for (auto it=WordFreq.cbegin(); it!=WordFreq.cend(); ++it) {
        cout << (*it).first << ": " << (*it).second << '\n';
    }
    */

    for (auto w : WordFreq) {
        cout << w.first << ": " << w.second << '\n';
    }

}
