/*
 * @Author: LetMeFly
 * @Date: 2024-07-03 19:26:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-03 19:27:35
 */
class Solution {
    private int getSum(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    public int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = getSum(x);
        return x % sum == 0 ? sum : -1;
    }
}