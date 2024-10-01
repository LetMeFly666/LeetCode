/*
 * @Author: LetMeFly
 * @Date: 2024-09-30 23:43:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-30 23:47:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> q;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
    }
    
    int reserve() {
        int ans = q.top();
        q.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */