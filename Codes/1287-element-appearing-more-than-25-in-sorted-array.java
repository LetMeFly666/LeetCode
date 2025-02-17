/*
 * @Author: LetMeFly
 * @Date: 2025-02-17 14:39:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-17 14:44:38
 */
class Solution {
    public int findSpecialInteger(int[] arr) {
        int locDiff = arr.length / 4;
        for (int i = 0; true; i++) {
            if (arr[i] == arr[i + locDiff]) {
                return arr[i];
            }
        }
    }
}