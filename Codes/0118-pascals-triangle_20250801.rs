/*
 * @Author: LetMeFly
 * @Date: 2025-08-01 23:51:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-02 13:25:16
 */
impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let size = num_rows as usize;
        let mut ans = vec![vec![]; size];
        for i in 0..size {
            ans[i].resize(i + 1, 1);
            for j in 1..i {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        ans
    }
}