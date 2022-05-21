/*
 * @Author: LetMeFly
 * @Date: 2022-05-06 08:37:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-06 08:39:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class RecentCounter {
private:
    list<int> li;
    int cnt;
public:
    RecentCounter() {
        cnt = 0;
    }
    
    int ping(int t) {
        li.push_back(t);
        cnt++;
        while (t - *li.begin() > 3000) {
            li.pop_front();
            cnt--;
        }
        return cnt;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */