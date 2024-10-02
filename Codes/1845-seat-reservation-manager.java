/*
 * @Author: LetMeFly
 * @Date: 2024-10-02 22:34:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-02 23:06:12
 */
// import java.util.Queue;
import java.util.PriorityQueue;

class SeatManager {
    private PriorityQueue<Integer> q = new PriorityQueue<>();

    public SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            q.add(i);
        }
    }
    
    public int reserve() {
        return q.poll();
    }
    
    public void unreserve(int seatNumber) {
        q.add(seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */