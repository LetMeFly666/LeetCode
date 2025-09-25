/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:12:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:34:54
 */
impl Solution {
    pub fn minimum_total(mut triangle: Vec<Vec<i32>>) -> i32 {
        for i in (0..triangle.len()-1).rev() {
            for j in 0..=i {
                triangle[i][j] += triangle[i+1][j].min(triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
}