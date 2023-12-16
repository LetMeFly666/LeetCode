/*
 * @Author: LetMeFly
 * @Date: 2023-12-16 19:06:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-16 19:21:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class CountIntervals {
private:
    map<int, int> ma;
    int cnt;
public:
    CountIntervals() {
        cnt = 0;
    }
    
    void add(int left, int right) {
        map<int, int>::iterator it = ma.upper_bound(right);
        if (it != ma.begin())  {
            it--;
        }
        while (it != ma.end() && it->first <= right && it->second >= left) {
            int leftInmap = it->first, rightInmap = it->second;
            cnt -= rightInmap - leftInmap + 1;
            left = min(left, leftInmap), right = max(right, rightInmap);
            ma.erase(it);
            it = ma.upper_bound(right);
            if (it != ma.begin()) {
                it--;
            }
        }
        ma[left] = right;
        cnt += right - left + 1;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */