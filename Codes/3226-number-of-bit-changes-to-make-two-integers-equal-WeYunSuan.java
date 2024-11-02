/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 10:59:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 10:59:53
 */
class Solution {
    public int minChanges(int n, int k) {
        return (n | k) == n ? Integer.bitCount(n ^ k) : -1;
    }
}