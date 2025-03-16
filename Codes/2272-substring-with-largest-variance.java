/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 11:09:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 11:13:27
 */
class Solution {
    public int largestVariance(String s) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            char a = (char)(i + 'a');
            for (int j = 0; j < 26; j++) {
                char b = (char)(j + 'a');
                int mayNoB = 0, hasB = -10000000;
                for (char c : s.toCharArray()) {
                    if (c == a) {
                        mayNoB = Math.max(mayNoB + 1, 1);
                        hasB++;
                    } else if (c == b) {
                        mayNoB = Math.max(mayNoB - 1, -1);
                        hasB = mayNoB;
                    }
                    ans = Math.max(ans, hasB);
                }
            }
        }
        return ans;
    }
}