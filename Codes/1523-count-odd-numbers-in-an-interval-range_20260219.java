/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 17:59:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 18:04:04
 */
class Solution {
    public int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
}