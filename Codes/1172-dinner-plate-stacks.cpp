/*
 * @Author: LetMeFly
 * @Date: 2023-04-28 09:43:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-28 10:31:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
class DinnerPlates {
private:
    int capacity;
    vector<int> v;
    set<int> popedPosition;
    vector<int> top;
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }
    
    void push(int val) {
        if (popedPosition.empty()) {
            v.push_back(val);
            if (v.size() % capacity == 1) {
                top.push_back(0);
            }
            else {
                top.back()++;
            }
        }
        else {
            set<int>::iterator toAdd = popedPosition.begin();
            v[*toAdd] = val;
            top[*toAdd / capacity]++;
            popedPosition.erase(toAdd);
        }
    }
    
    int pop() {
        while (v.size() && popedPosition.count(v.size() - 1)) {
            popedPosition.erase(v.size());
            if (v.size() % capacity == 0) {
                top.pop_back();
            }
            v.pop_back();
        }
        if (v.empty()) {
            return -1;
        }
        int pos = v.size() - 1;
        int val = v.back();
        v.pop_back();
        if (pos % capacity == 0) {
            top.pop_back();
        }
        else {
            top.back() = top.size() - 2;
        }
        return val;
    }
    
    int popAtStack(int index) {
        if (index >= top.size() || !top[index]) {
            return -1;
        }
        int pos = index * capacity + top[index];
        top[index]--;
        popedPosition.insert(pos);
        return v[pos];
    }
};