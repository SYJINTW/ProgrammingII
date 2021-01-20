#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> vec;
    int i;

    // We can grow a vector incrementally using push_back().
    // To stop cin, type Ctrl-Z+Enter at the beginning of a line.
    cout << "Enter some integers ";
    cout << "and type Ctrl-Z + Return at the beginning of a newline.\n";
    while (cin >> i) {
        vec.push_back(i);
    }

    // There are several way to iterate through a vector.
    // They can be treated as idioms.
    // 1. Access the elements by indexes and []
    for (unsigned int i=0; i<vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    cout << '\n';

    // 2. Use C++11 range-based for loops.
    for (auto v : vec) {
        cout << v << ' ';
    }
    cout << '\n';

    // 3. Use for_each (need to include <algorithm>) and C++11 lambda functions
    for_each(vec.cbegin(), vec.cend(),
             [](const int v){cout << v << " "; }
             );
    cout << '\n';

    // 4. Use an iterator
    for (auto it=vec.cbegin(); it!=vec.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';

    // Other types of vectors
    vector<string> heroes{"Ironman", "Batman", "Superman", "Spiderman", "Thor"};
    for (auto s : heroes)
        cout << s << ' ';
    cout << '\n';

    cout << "Sorted: \n";
    sort(heroes.begin(), heroes.end());
    for (auto s : heroes)
        cout << s << ' ';
    cout << '\n';

    cout << "Shuffle: \n";
    random_shuffle(heroes.begin(), heroes.end());
    for (auto s : heroes)
        cout << s << ' ';
    cout << '\n';

    // functions in <algorithm>
    // all_of, none_of, any_of
    if ( all_of(heroes.cbegin(), heroes.cend(), [](string s){ return s.length()>3; }) )
        cout << "All names have more than three letters.\n";
    else
        cout << "false\n";

}
