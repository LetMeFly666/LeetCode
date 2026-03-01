/*
 * @Author: LetMeFly
 * @Date: 2026-03-01 19:50:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-01 20:20:09
 */
// THIS CANNOT BE ACCPETED
class Solution {
    public int minPartitions(String n) {
        char m = '0';
        n.chars().forEach(c -> m = Math.max(m, (char) c));
        return m - '0';
    }
}