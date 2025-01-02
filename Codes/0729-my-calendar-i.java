/*
 * @Author: LetMeFly
 * @Date: 2025-01-02 16:22:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-02 16:27:07
 */
import java.util.ArrayList;

class MyCalendar {
    private ArrayList<Integer> start, end;

    public MyCalendar() {
        start = new ArrayList<Integer>();
        end = new ArrayList<Integer>();
    }
    
    public boolean book(int startTime, int endTime) {
        for (int i = 0; i < start.size(); i++) {
            if (end.get(i) > startTime && endTime > start.get(i)) {
                return false;
            }
        }
        start.add(startTime);
        end.add(endTime);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(startTime,endTime);
 */