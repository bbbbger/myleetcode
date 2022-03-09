#include<iostream>
#include<stack>
#include<set>
using namespace std;

class MinStack {
private:
    stack<int> stk;
    multiset<int> mtset;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk.push(x);
        mtset.insert(x);
    }

    void pop() {
        int top = stk.top();
        stk.pop();
        auto fd = mtset.find(top);
        mtset.erase(fd);
        
    }

    int top() {
        return stk.top();
    }

    int min() {
        return *mtset.begin();
    }
};

//法二 辅助栈 只存最小数据