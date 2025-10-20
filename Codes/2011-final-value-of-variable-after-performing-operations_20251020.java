/*
 * @Author: LetMeFly
 * @Date: 2025-10-20 18:44:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-20 18:48:23
 */
class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0;
        for (String op : operations) {
            if (op.charAt(1) == '+') {
                ans++;
            } else {
                ans--;
            }
        }
        return ans;
    }
}