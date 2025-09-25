/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:12:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:31:13
 */
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle.get(i).set(j, triangle.get(i).get(j) + Math.min(triangle.get(i + 1).get(j), triangle.get(i + 1).get(j + 1)));
            }
        }
        return triangle.get(0).get(0);
    }
}