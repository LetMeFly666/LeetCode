/*
 * @Author: LetMeFly
 * @Date: 2025-01-19 14:16:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-19 14:19:48
 */
class Solution {
    private static final int mod = 1000000007;
    private static final int[] dp3 = new int[100001];
    private static final int[] dp4 = new int[100001];

    static {
        dp3[0] = dp4[0] = 1;
        dp3[1] = dp4[1] = 1;
        dp3[2] = dp4[2] = 2;
        dp3[3] = dp4[3] = 4;
        for (int i = 4; i <= 100000; i++) {
            dp3[i] = ((dp3[i- 1] + dp3[i - 2]) % mod + dp3[i - 3]) % mod;
            dp4[i] = (((dp4[i - 1] + dp4[i - 2]) % mod + dp4[i - 3]) % mod + dp4[i - 4]) % mod;
        }
    }

    public int countTexts(String pressedKeys) {
        long ans = 1;
        int cnt = 0;
        for (int i = 0; i < pressedKeys.length(); i++) {
            cnt++;
            if (i == pressedKeys.length() - 1 || pressedKeys.charAt(i) != pressedKeys.charAt(i + 1)) {
                ans = ans * (pressedKeys.charAt(i) == '7' || pressedKeys.charAt(i) == '9' ? dp4[cnt] : dp3[cnt]) % mod;
                cnt = 0;
            }
        }
        return (int)ans;
    }
}