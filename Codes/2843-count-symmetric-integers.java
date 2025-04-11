/*
 * @Author: LetMeFly
 * @Date: 2025-04-11 21:13:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-11 21:17:40
 */
class Solution {
    private int isOk(int n) {
        String s = String.valueOf(n);
        if (s.length() % 2 == 1) {
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            cnt += s.charAt(i) - s.charAt(s.length() - i - 1);
        }
        return cnt != 0 ? 0 : 1;
    }

    public int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            ans += isOk(i);
        }
        return ans;
    }
}