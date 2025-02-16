/*
 * @Author: LetMeFly
 * @Date: 2025-02-16 10:21:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-16 10:24:13
 */
class Solution {
    public int[] replaceElements(int[] arr) {
        int M = -1;
        for (int i = arr.length - 1; i >= 0; i--) {
            int nM = Math.max(M, arr[i]);
            arr[i] = M;
            M = nM;
        }
        return arr;
    }
}