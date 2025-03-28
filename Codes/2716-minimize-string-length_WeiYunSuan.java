/*
 * @Author: LetMeFly
 * @Date: 2025-03-28 13:31:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-28 13:31:42
 */
class Solution {
    public int minimizedStringLength(String s) {
        int mask = 0;
        for (char c : s.toCharArray()) {
            mask |= 1 << (c - 'a');
        }
        return Integer.bitCount(mask);
    }
}