/*
 * @Author: LetMeFly
 * @Date: 2025-01-05 21:39:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-05 21:44:12
 */
import java.util.HashMap;

class MyCalendarThree {
    private HashMap<Integer, Integer> tree, lazy;

    private void update(int start, int end, int index, int l, int r) {
        if (l > end || start > r) {
            return;
        }
        if (l >= start && r <= end) {
            tree.put(index, tree.getOrDefault(index, 0) + 1);
            lazy.put(index, lazy.getOrDefault(index, 0) + 1);
        } else {
            int mid = (l + r) >> 1;
            update(start, end, index * 2 + 1, l, mid);
            update(start, end, index * 2 + 2, mid + 1, r);
            tree.put(index, lazy.getOrDefault(index, 0) + Math.max(tree.getOrDefault(index * 2 + 1, 0), tree.getOrDefault(index * 2 + 2, 0)));
        }
    }

    public MyCalendarThree() {
        tree = new HashMap<Integer, Integer>();
        lazy = new HashMap<Integer, Integer>();
    }
    
    public int book(int startTime, int endTime) {
        update(startTime, endTime - 1, 0, 0, 1000000000);
        return tree.get(0);
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(startTime,endTime);
 */