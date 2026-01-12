/*
 * @Author: LetMeFly
 * @Date: 2026-01-12 23:24:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-12 23:37:10
 */
impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let mut ans: i32 = 0;
        for i in 1..points.len() {
            ans += (points[i][0] - points[i - 1][0]).abs().max((points[i][1] - points[i - 1][1]).abs());
        }
        ans
    }
}