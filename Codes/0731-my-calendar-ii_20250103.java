/*
 * @Author: LetMeFly
 * @Date: 2025-01-03 13:17:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-03 13:21:03
 */
import java.util.ArrayList;

class MyCalendarTwo {
    private ArrayList<Integer> booked_start, booked_end, overlap_start, overlap_end;

    public MyCalendarTwo() {
        booked_start = new ArrayList<>();
        booked_end = new ArrayList<>();
        overlap_start = new ArrayList<>();
        overlap_end = new ArrayList<>();
    }
    
    public boolean book(int startTime, int endTime) {
        for (int i = 0; i < overlap_start.size(); i++) {
            if (endTime > overlap_start.get(i) && overlap_end.get(i) > startTime) {
                return false;
            }
        }
        for (int i = 0; i < booked_start.size(); i++) {
            if (endTime > booked_start.get(i) && booked_end.get(i) > startTime) {
                overlap_start.add(Math.max(startTime, booked_start.get(i)));
                overlap_end.add(Math.min(endTime, booked_end.get(i)));
            }
        }
        booked_start.add(startTime);
        booked_end.add(endTime);
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(startTime,endTime);
 */