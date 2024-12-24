/*
 * @Author: LetMeFly
 * @Date: 2024-12-24 18:58:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-24 19:07:07
 */
import java.util.PriorityQueue;

class Solution {
    public int eatenApples(int[] apples, int[] days) {
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);
        int ans = 0, day = 0;
        for (; day < apples.length; day++) {
            if (apples[day] > 0) {
                pq.add(new int[]{day + days[day], apples[day]});
            }
            while (pq.size() > 0) {
                int[] temp = pq.poll();
                int rotDay = temp[0], appleNum = temp[1];
                if (rotDay <= day) {
                    continue;
                }
                ans++;
                appleNum--;
                if (appleNum > 0) {
                    pq.add(new int[]{rotDay, appleNum});
                }
                break;
            }
        }
        while (!pq.isEmpty()) {
            int[] temp = pq.poll();
            int rotDay = temp[0], appleNum = temp[1];
            int eat = Math.max(0, Math.min(rotDay - day, appleNum));
            ans += eat;
            day += eat;
        }
        return ans;
    }
}