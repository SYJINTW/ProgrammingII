#include <iostream>
#include "12764.h"

using namespace oj;

int main()
{
    int n, i;
    std::string s;

    BST tree;

    std::cin >> n;
    getline(std::cin, s);
    for (i=0; i<n; i++){
        getline(std::cin, s);
        tree.insertNode(s);
    }

    tree.print();
    return 0;
}
