/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:12:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:29:00
 */
class Solution {  // 这个交上去肯定RE
    public int minimumTotal(List<List<Integer>> triangle) {
        for (int i = triangle.length() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle.at(i).set(j, triangle.at(i).at(j) + Math.min(triangle.at(i + 1).at(j), triangle.at(i + 1).at(j + 1)));
            }
        }
        return triangle.at(i).at(j);
    }
}