/*
 * @Author: LetMeFly
 * @Date: 2024-03-03 12:01:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-03 12:01:35
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {

    }
    
    void push(int x) {
        queue<int> tempQ;
        tempQ.push(x);
        while (q.size()) {
            tempQ.push(q.front());
            q.pop();
        }
        swap(q, tempQ);
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */