/*
 * @Author: LetMeFly
 * @Date: 2025-01-13 23:45:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 23:48:54
 */
class Solution {
    private int get(int num1, int num2, int num3, int dev) {
        return Math.min(num1 / dev % 10, Math.min(num2 / dev % 10, num3 / dev % 10));
    }

    public int generateKey(int num1, int num2, int num3) {
        return get(num1, num2, num3, 1000) * 1000 +
               get(num1, num2, num3, 100) * 100 + 
               get(num1, num2, num3, 10) * 10 + 
               get(num1, num2, num3, 1); 
    }
}