/*
 * @Author: LetMeFly
 * @Date: 2025-01-05 21:26:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-05 21:33:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class MyCalendarThree {
private:
    unordered_map<int, int> tree, lazy;

    void update(int start, int end, int index, int l, int r) {
        if (start > r || l > end) {
            return;
        }
        if (l >= start && r <= end) {
            tree[index]++;
            lazy[index]++;
        } else {
            int mid = (l + r) >> 1;
            update(start, end, index * 2 + 1, l, mid);
            update(start, end, index * 2 + 2, mid + 1, r);
            tree[index] = lazy[index] + max(tree[index * 2 + 1], tree[index * 2 + 2]);
        }
    }
public:
    MyCalendarThree() {}
    
    int book(int startTime, int endTime) {
        update(startTime, endTime - 1, 0, 0, 1000000000);
        return tree[0];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */