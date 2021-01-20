#include <list>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <ctime>
#include <iostream>

#include "header/I2P2_List.h"
#include "header/I2P2_Vector.h"

template <typename S, typename I>
void test(std::function<void(S &, I &)> rng)
{
    std::vector<S> ans;  // answer
    I2P2::Vector<I> def; // yours

    for (int opcnt = 0; opcnt < 1 << 20; ++opcnt)
    {
        // std::cout << "opcnt = " << opcnt << "\n";
        int rnd = rand() % 16;
        if (rnd == 0 || rnd > 7)
        { // insert random value
            // std::cout << "Test 0\n";
            S s;
            I i;
            rng(s, i);
            ans.push_back(s);
            def.push_back(i);
        }
        else if (rnd == 1)
        { // insert val to begin
            // std::cout << "Test 1\n";
            S s;
            I i;
            if (ans.size())
            {
                ans.insert(ans.begin(), s);
                def.insert(def.begin(), i);
            }
        }
        else if (rnd == 2)
        { // pop last
            // std::cout << "Test 2\n";
            if (ans.size())
            {
                ans.pop_back();
                def.pop_back();
            }
        }
        else if (rnd == 3)
        { // copy last to back
            // std::cout << "Test 3\n";
            if (ans.size())
            {
                ans.push_back(ans.back());
                def.push_back(def.back());
            }
        }
        else if (rnd == 4)
        { // erase last
            // std::cout << "Test 4\n";
            if (!ans.empty())
            {
                ans.erase(--ans.end());
                def.erase(--def.end());
            }
        }
        else if (rnd == 5)
        { // clear
            // std::cout << "Test 5\n";
            ans.clear();
            def.clear();
        }
        else if (rnd == 6)
        { //shrink
            // std::cout << "Test 6\n";
            ans.shrink_to_fit();
            assert(ans.size() == ans.capacity());
            def.shrink_to_fit();
            assert(def.size() == def.capacity());
        }
        else if (rnd == 7)
        { // reserve
            // std::cout << "Test 7\n";
            ans.reserve(ans.size() + rnd);
            def.reserve(def.size() + rnd);
        }
    }

    assert(ans.size() == def.size());
    for (int i = 0; i < (int)ans.size(); ++i)
    {
        assert(ans[i].size() == def[i].size());
        typename S::iterator sit = ans[i].begin();
        typename I::iterator iit = def[i].begin();
        for (; sit != ans[i].end(); ++sit, ++iit)
        {
            assert(*sit == *iit);
        }
        assert(iit == def[i].end());
    }
}

int main()
{
    srand(time(0));

    std::cout << "Checking Vector...\n";
    test<std::vector<int>, I2P2::Vector<int>>([](std::vector<int> &a, I2P2::Vector<int> &b) {
        for (int i = 0; i < 10; ++i)
            a.push_back(std::rand());
        for (int i = 0; i < 10; ++i)
            b.push_back(a[i]);
    });
    std::cout << "Checking List...\n";
    test<std::list<double>, I2P2::List<double>>([](std::list<double> &a, I2P2::List<double> &b) {
        for (int i = 0; i < 10; ++i)
            a.insert(a.begin(), std::rand());
        std::list<double>::iterator it = a.begin();
        for (int i = 0; i < 10; ++i, ++it)
            b.insert(b.end(), *it);
    });
    std::cout << "Finished\n";
    std::cout << (double)clock() / CLOCKS_PER_SEC << "S";

    return 0;
}
