/*
 * @Author: LetMeFly
 * @Date: 2024-12-09 17:07:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-09 17:08:09
 */
class Solution {
    public boolean squareIsWhite(String coordinates) {
        return coordinates.charAt(0) % 2 != coordinates.charAt(1) % 2;
    }
}