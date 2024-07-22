/*
 * @Author: LetMeFly
 * @Date: 2024-07-21 19:16:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-21 19:17:58
 */
class Solution {
    public int maximumSum(int[] arr) {
        int del0 = arr[0], del1 = 0, ans = arr[0];
        for (int i = 1; i < arr.length; i++) {
            del1 = Math.max(del1 + arr[i], del0);
            del0 = Math.max(del0 + arr[i], arr[i]);
            ans = Math.max(ans, Math.max(del0, del1));
        }
        return ans;
    }
}