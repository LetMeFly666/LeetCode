/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 21:42:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 21:55:39
 */
class Solution {
    public int differenceOfSums(int n, int m) {
        return (1 + n) * n / 2 + (m + n / m * m) * (n / m);
    }
}