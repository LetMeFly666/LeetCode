/*
 * @Author: LetMeFly
 * @Date: 2025-08-14 10:28:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-14 18:44:38
 */
class Solution {
    public boolean checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
}