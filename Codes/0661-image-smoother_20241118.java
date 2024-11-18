/*
 * @Author: LetMeFly
 * @Date: 2024-11-18 21:13:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-18 21:36:01
 */
class Solution {
    public int[][] imageSmoother(int[][] img) {
        int[][] ans = new int[img.length][img[0].length];
        for (int i = 0; i < img.length; i++) {
            for (int j = 0; j < img[0].length; j++) {
                int cnt = 0, s = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int x = i + dx, y = j + dy;
                        if (0 <= x && x < img.length && 0 <= y && y < img[0].length) {
                            cnt++;
                            s += img[x][y];
                        }
                    }
                }
                ans[i][j] = s / cnt;
            }
        }
        return ans;
    }
}