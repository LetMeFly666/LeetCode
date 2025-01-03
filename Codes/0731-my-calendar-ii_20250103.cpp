/*
 * @Author: LetMeFly
 * @Date: 2025-01-03 13:06:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-03 13:11:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class MyCalendarTwo {
private:
    vector<int> booked_start, booked_end, overlap_start, overlap_end;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (int i = 0; i < overlap_start.size(); i++) {
            if (endTime > overlap_start[i] && overlap_end[i] > startTime) {
                return false;
            }
        }
        for (int i = 0; i < booked_start.size(); i++) {
            if (endTime > booked_start[i] && booked_end[i] > startTime) {
                overlap_start.push_back(max(startTime, booked_start[i]));
                overlap_end.push_back(min(endTime, booked_end[i]));
            }
        }
        booked_start.push_back(startTime);
        booked_end.push_back(endTime);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */