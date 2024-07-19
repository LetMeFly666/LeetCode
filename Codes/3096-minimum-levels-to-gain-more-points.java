/*
 * @Author: LetMeFly
 * @Date: 2024-07-19 16:11:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-19 16:11:18
 */
class Solution {
    public int minimumLevels(int[] possible) {
        int cnt = 0;
        for (int t : possible) {
            cnt += t == 0 ? -1 : 1;
        }
        int now = 0;
        for (int i = 0; i < possible.length - 1; i++) {
            now += possible[i] == 0 ? -1 : 1;
            if (now > cnt - now) {
                return i + 1;
            }
        }
        return -1;
    }
}