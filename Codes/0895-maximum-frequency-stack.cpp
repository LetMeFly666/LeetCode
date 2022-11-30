/*
 * @Author: LetMeFly
 * @Date: 2022-11-30 22:49:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-30 22:56:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class FreqStack {
private:
    unordered_map<int, int> value2times;
    unordered_map<int, stack<int>> times2values;
    int maxTimes;
public:
    FreqStack() {
        maxTimes = 0;
    }
    
    void push(int val) {
        value2times[val]++;
        int thisTimes = value2times[val];
        times2values[thisTimes].push(val);
        maxTimes = max(maxTimes, thisTimes);
    }
    
    int pop() {
        int value = times2values[maxTimes].top();
        times2values[maxTimes].pop();
        value2times[value]--;
        if (times2values[maxTimes].empty()) {
            maxTimes--;
        }
        return value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */