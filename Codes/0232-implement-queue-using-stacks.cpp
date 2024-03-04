/*
 * @Author: LetMeFly
 * @Date: 2024-03-04 08:59:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-04 09:05:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class MyQueue {
private:
    stack<int> st;

public:
    MyQueue() {

    }
    
    void push(int x) {
        stack<int> tempSt;
        tempSt.push(x);
        while (st.size()) {
            tempSt.push(st.top());
            st.pop();
        }
        swap(st, tempSt);
    }
    
    int pop() {
        int ans = st.top();
        st.pop();
        return ans;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */