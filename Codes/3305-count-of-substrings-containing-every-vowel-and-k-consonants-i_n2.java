/*
 * @Author: LetMeFly
 * @Date: 2025-03-12 09:44:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-12 09:53:33
 */
class Solution {
    private final char[] aeiou = {'a', 'e', 'i', 'o', 'u'};

    private int isaeiou(char c) {
        for (int i = 0; i < 5; i++) {
            if (aeiou[i] == c) {
                return i;
            }
        }
        return -1;
    }

    private boolean all(int[] cnt) {
        for (int i = 0; i < 5; i++) {
            if (cnt[i] == 0) {
                return false;
            }
        }
        return true;
    }

    public int countOfSubstrings(String word, int k) {
        int ans = 0;
        for (int i = 0; i < word.length(); i++) {
            int[] cnt5 = new int[5];
            int cntk = 0;
            for (int j = i; j < word.length(); j++) {
                int index = isaeiou(word.charAt(j));
                if (index == -1) {
                    cntk++;
                } else {
                    cnt5[index]++;
                }
                if (all(cnt5) && cntk == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
}