/*
 * @Author: LetMeFly
 * @Date: 2026-11-12 19:11:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-12 19:24:55
 */
class ABC {
    private int[] a = new int[3];
    private int diff = 0;

    public void push(int v) {
        a[diff] = v;
        diff = (diff + 1) % 3;
    }

    public int get(int i) {
        return a[(diff + i) % 3];
    }
}

class Solution {
    public int climbStairs(int n, int[] costs) {
        ABC abc = new ABC();
        for (int cost : costs) {
            abc.push(cost + Math.min(
                abc.get(0) + 9, Math.min(
                    abc.get(1) + 4,
                    abc.get(2) + 1
                )
            ));
        }
        return abc.get(2);
    }
}
