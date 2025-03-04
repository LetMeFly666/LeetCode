/*
 * @Author: LetMeFly
 * @Date: 2025-03-04 10:47:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-04 10:49:14
 */
class Solution {
    public boolean checkPartitioning(String s) {
        int n = s.length();
        boolean[][] isok = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                isok[i][j] = true;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                isok[i][j] = s.charAt(i) == s.charAt(j) && isok[i + 1][j - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (isok[0][i] && isok[i + 1][j] && isok[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
}