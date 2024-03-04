/*
 * @Author: LetMeFly
 * @Date: 2024-03-04 08:59:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-04 09:12:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class MyQueue {
private:
    stack<int> input, output;

    void preTreatment() {
        if (output.size()) {
            return;
        }
        while (input.size()) {
            output.push(input.top());
            input.pop();
        }
    }

public:
    MyQueue() {

    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        preTreatment();
        int ans = output.top();
        output.pop();
        return ans;
    }
    
    int peek() {
        preTreatment();
        return output.top();
    }
    
    bool empty() {
        preTreatment();
        return output.empty();
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