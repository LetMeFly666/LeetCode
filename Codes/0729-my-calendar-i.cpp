/*
 * @Author: LetMeFly
 * @Date: 2025-01-02 23:18:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-03 13:06:29
 */
/*
 * @Author: LetMeFly
 * @Date: 2025-01-02 16:13:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-02 16:15:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class MyCalendar {
private:
    vector<int> start, end;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (int i = 0; i < start.size(); i++) {
            if (!(end[i] <= startTime || endTime <= start[i])) {
                return false;
            }
        }
        start.push_back(startTime);
        end.push_back(endTime);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */