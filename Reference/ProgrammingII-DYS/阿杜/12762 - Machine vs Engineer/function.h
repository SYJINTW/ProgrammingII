#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

class Machine{
public:
    Machine(int L = 1, int R = 10);
    ~Machine();
    void init(int L, int R);
    bool MakeAnswer(char query_str[]) const;
    int TheNumber() const;
private:
    int Password;
};


class Engineer{
public:
    Engineer();
    ~Engineer();
    void init(); // Initialize the history, count
    void MakeQuery(char* query_str); // Make a Query depends on the history
    void GetAnswer(bool ans); // Get the answer From Machine, Update
private:
    int count;
    int value_history[201];
    int action_history[201];
    bool answer_history[201];
};

#endif
