/*
 * @Author: LetMeFly
 * @Date: 2024-12-21 18:01:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-21 18:04:28
 */
import java.util.Arrays;

class Solution {
    public int[][] sortTheStudents(int[][] score, int k) {
        Arrays.sort(score, (a, b) -> b[k] - a[k]);
        return score;
    }
}