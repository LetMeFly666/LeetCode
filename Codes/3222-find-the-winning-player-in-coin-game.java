/*
 * @Author: LetMeFly
 * @Date: 2024-11-05 09:53:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-05 09:54:06
 */
class Solution {
    public String losingPlayer(int x, int y) {
        return Math.min(x, y / 4) % 2 == 1 ? "Alice" : "Bob";
    }
}