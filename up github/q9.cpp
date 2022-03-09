#include<iostream>
#include<stack>
using namespace std;


class CQueue {
private:
    stack<int> stkin;
    stack<int> stkout;

public:
    CQueue() {
        
    }

    void appendTail(int value) {
        stkin.push(value);
    }

    int deleteHead() {
        if (stkout.empty()) {
            if (stkin.empty())return -1;
            while (!stkin.empty()) {                
                stkout.push(stkin.top());
                stkin.pop();
            }
        }
        
        int ret = stkout.top();
        stkout.pop();
        return ret;
    }
};