/*
 * @Author: LetMeFly
 * @Date: 2026-09-19 08:23:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-19 08:39:53
 */
class Solution {
    private int getClosest(int c, int a, int b) {
        if (a > c) {
            return a;
        } else if (b < c) {
            return b;
        } else {
            return c;
        }
    }

    private int p(int a) {
        return a * a;
    }

    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = getClosest(xCenter, x1, x2);
        int y = getClosest(yCenter, y1, y2);
        return p(x - xCenter) + p(y - yCenter) <= p(radius);
    }
}
