/*
 * @Author: LetMeFly
 * @Date: 2026-01-05 13:31:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-05 13:43:32
 */
impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut ans: i64 = 0;
        let mut mini: i32 = 1000000;
        let mut cnt_neg: i32 = 0;
        for row in matrix.iter() {
            for t in row.iter() {
                ans += t.abs() as i64;
                if *t < 0 {
                    cnt_neg += 1;
                }
                mini = mini.min(t.abs());
            }
        }
        if cnt_neg % 2 == 1 {
            ans -= 2 * mini as i64;
        }
        ans
    }
}