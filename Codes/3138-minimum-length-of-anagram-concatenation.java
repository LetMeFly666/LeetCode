/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 20:58:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 21:05:54
 */
import java.util.Arrays;

class Solution {
    private int[] count(char[] s, int l, int r) {
        int[] ans = new int[26];
        for (int i = l; i < r; i++) {
            ans[s[i] - 'a']++;
        }
        return ans;
    }
    public int minAnagramLength(String S) {
        char[] s = S.toCharArray();
        loop:
        for (int ans = 1; ans < s.length; ans++) {
            if (s.length % ans != 0) {
                continue;
            }
            int[] should = count(s, 0, ans);
            for (int i = ans; i < s.length; i += ans) {
                int[] now = count(s, i, i + ans);
                if (!Arrays.equals(should, now)) {
                    continue loop;
                }
            }
            return ans;
        }
        return s.length;
    }
}