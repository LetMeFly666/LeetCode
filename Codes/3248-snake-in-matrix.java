/*
 * @Author: LetMeFly
 * @Date: 2024-11-21 23:05:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-21 23:06:44
 */
class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int ans = 0;
        for (String c : commands) {
            switch (c.charAt(0)) {
                case 'U':
                    ans -= n;
                    break;
                case 'D':
                    ans += n;
                    break;
                case 'L':
                    ans--;
                    break;
                default:
                    ans++;
                    break;
            }
        }
        return ans;
    }
}