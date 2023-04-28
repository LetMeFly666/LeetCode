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
#ifdef FirstTry  // Error
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
#else  // FirstTry
// SecondTry  // Copy
class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        if (poppedPos.empty()) {
            int pos = stk.size();
            stk.emplace_back(val);
            if (pos % capacity == 0) {
                top.emplace_back(0);
            } else {
                top.back()++;
            }
        } else {
            int pos = *poppedPos.begin();
            poppedPos.erase(pos);
            stk[pos] = val;
            int index = pos / capacity;
            top[index]++;
        }
    }
    
    int pop() {
        while (!stk.empty() && poppedPos.count(stk.size() - 1)) {
            stk.pop_back();
            int pos = *poppedPos.rbegin();
            poppedPos.erase(pos);
            if (pos % capacity == 0) {
                top.pop_back();
            }
        }
        if (stk.empty()) {
            return -1;
        } else {
            int pos = stk.size() - 1;
            int val = stk.back();
            stk.pop_back();
            if (pos % capacity == 0) {
                top.pop_back();
            } else {
                top.back() = top.size() - 2;
            }
            return val;
        }
    }
    
    int popAtStack(int index) {
        if (index >= top.size()) {
            return -1;
        }
        int stackTop = top[index];
        if (stackTop < 0) {
            return -1;
        }
        top[index]--;
        int pos = index * capacity + stackTop;
        poppedPos.emplace(pos);
        return stk[pos];
    }
private:
    int capacity;
    vector<int> stk;
    vector<int> top;
    set<int> poppedPos;
};
// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/dinner-plate-stacks/solutions/2247703/can-pan-zhan-by-leetcode-solution-afsw/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
#endif  // FirstTry