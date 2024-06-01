/*
 * @Author: LetMeFly
 * @Date: 2024-06-01 11:46:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-01 11:47:27
 */
class Solution {
    public int distributeCandies(int n, int limit) {
        int ans = 0;
        for (int x = 0; x <= n && x <= limit; x++) {
            for (int y = 0; y <= n - x && y <= limit; y++) {
                if (n - x - y <= limit) {
                    ans++;
                }
            }
        }
        return ans;
    }
}