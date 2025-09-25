/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:12:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:33:34
 */
impl Solution {
    pub fn minimum_total(triangle: mut Vec<Vec<i32>>) -> i32 {
        for i := (triangle.len()-2)..-1 {
            for j := 0..(i+1) {
                triangle[i][j] += triangle[i+1][j].min(triangle[i+1][j+1]);
            }
        }
        return tirangle[0][0];
    }
}