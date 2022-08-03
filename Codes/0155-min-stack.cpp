/*
 * @Author: LetMeFly
 * @Date: 2022-08-03 16:34:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-03 17:02:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // map
class MinStack {
private:
    map<int, int> ma;
    stack<int> st;
public:
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        ma[val]++;
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        ma[val]--;
        if (!ma[val]) {
            ma.erase(val);
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ma.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
#else  // FirstTry
// SecondTry  // 辅助栈
class MinStack {
private:
    stack<int> realStack;
    stack<int> minStack;
public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        realStack.push(val);
        minStack.push(min(val, minStack.top()));
    }
    
    void pop() {
        realStack.pop();
        minStack.pop();
    }
    
    int top() {
        return realStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
#endif  // FirstTry