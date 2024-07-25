/*
 * @Author: LetMeFly
 * @Date: 2024-07-25 16:44:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-25 17:04:26
 */
class Solution {
    private int thisEnd(String num, int n) {
        char finding = (char)(n % 10 + '0');
        int i = num.lastIndexOf(finding);
        finding = (char)(n / 10 % 10 + '0');
        i = num.lastIndexOf(finding, i - 1);
        return i == -1 ? num.length() : num.length() - i - 2;
    }

    public int minimumOperations(String num) {
        int ans = num.indexOf('0') == -1 ? num.length() : num.length() - 1;
        ans = Math.min(ans, Math.min(
            thisEnd(num, 0), Math.min(
                thisEnd(num, 25), Math.min(
                    thisEnd(num, 50), thisEnd(num, 75)
                )
            )
        ));
        return ans;
    }
}