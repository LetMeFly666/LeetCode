/*
 * @Author: LetMeFly
 * @Date: 2026-03-01 19:50:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-01 20:20:21
 */

class Solution {
    public int minPartitions(String n) {
        return n.chars().max().getAsInt() - '0';
    }
}