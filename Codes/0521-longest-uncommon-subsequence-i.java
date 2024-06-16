/*
 * @Author: LetMeFly
 * @Date: 2024-06-16 18:17:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-16 18:18:58
 */
class Solution {
    public int findLUSlength(String a, String b) {
        return a.equals(b) ? -1 : Math.max(a.length(), b.length());
    }
}