/*
 * @Author: LetMeFly
 * @Date: 2025-03-13 12:52:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-13 12:59:04
 */
class Solution {
    private final char[] aeiou = {'a', 'e', 'i', 'o', 'u'};

    private int aeiouIndex(char c) {
        for (int i = 0; i < 5; i++) {
            if (aeiou[i] == c) {
                return i;
            }
        }
        return -1;
    }

    public long countOfSubstrings(String word, int k) {
        int[] bin1 = new int[5];
        int cntc1 = 0, cntk1 = 0, left1 = 0;
        int[] bin2 = new int[5];
        int cntc2 = 0, cntk2 = 0, left2 = 0;
        long ans = 0;
        for (char c : word.toCharArray()) {
            int index = aeiouIndex(c);
            if (index == -1) {
                cntk1++;
                cntk2++;
            } else {
                bin1[index]++;
                if (bin1[index] == 1) {
                    cntc1++;
                }
                bin2[index]++;
                if (bin2[index] == 1) {
                    cntc2++;
                }
            }

            while (cntc1 == 5 && cntk1 >= k) {
                index = aeiouIndex(word.charAt(left1++));
                if (index == -1) {
                    cntk1--;
                } else {
                    bin1[index]--;
                    if (bin1[index] == 0) {
                        cntc1--;
                    }
                }
            }
            while (cntc2 == 5 && cntk2 > k) {
                index = aeiouIndex(word.charAt(left2++));
                if (index == -1) {
                    cntk2--;
                } else {
                    bin2[index]--;
                    if (bin2[index] == 0) {
                        cntc2--;
                    }
                }
            }
            ans += left1 - left2;
        }
        return ans;
    }
}