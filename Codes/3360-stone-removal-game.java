/*
 * @Author: LetMeFly
 * @Date: 2026-11-26 07:52:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-26 08:03:30
 */
class Solution {
    public boolean canAliceWin(int n) {
        boolean state = false;
        int need = 10;
        while (n >= need) {
            n -= need--;
            state = !state;
        }
        return state;
    }
}
