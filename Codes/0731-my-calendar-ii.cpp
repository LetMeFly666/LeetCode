/*
 * @Author: LetMeFly
 * @Date: 2022-07-19 10:41:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-19 10:51:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error + 改了一半
typedef pair<int, int> pii;

class MyCalendarTwo {
private:
    vector<pii> booked;

    inline bool overlap(int l1, int r1, int l2, int r2) {

    }
public:    
    bool book(int start, int end) {
        int cnt = 0;
        for (auto[l, r] : booked) {
            if (overlap(l, r, start, end)) {
                cnt++;
            }
        }
        if (cnt < 2) {
            booked.push_back({start, end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
#else  // FirstTry
class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        for (auto &[l, r] : overlaps) {
            if (l < end && start < r) {
                return false;
            }
        }
        for (auto &[l, r] : booked) {
            if (l < end && start < r) {
                overlaps.emplace_back(max(l, start), min(r, end));
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;
};
#endif  // FirstTry