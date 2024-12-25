/*
 * @Author: LetMeFly
 * @Date: 2024-12-23 17:47:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-23 18:16:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FristTry  // WA - 没看题根本
class ExamRoom {
private:
    set<int> seats;
public:
    ExamRoom(int n) {
        for (int i = 0; i < n; i++) {
            seats.insert(i);
        }
    }
    
    int seat() {
        int ans = *seats.begin();
        seats.erase(seats.begin());
        return ans;
    }
    
    void leave(int p) {
        seats.insert(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
#else  // FristTry
// SecondTry - Copy了还是
class ExamRoom {
public:
    ExamRoom(int n) {
        
    }
    
    int seat() {
        
    }
    
    void leave(int p) {
        
    }
};
#endif  // FristTry