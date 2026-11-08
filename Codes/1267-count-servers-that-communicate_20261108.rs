/*
 * @Author: LetMeFly
 * @Date: 2026-11-08 10:46:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-08 10:58:49
 */
impl Solution {
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        let mut a = vec![0; n];
        let mut b = vec![0; m];
        for i in 0..n {
            for j in 0..m {
                if grid[i][j] == 1 {
                    a[i] += 1;
                    b[j] += 1;
                }
            }
        }

        let mut ans = 0;
        for i in 0..n {
            for j in 0..m {
                if grid[i][j] == 1 && (a[i] > 1 || b[j] > 1) {
                    ans += 1;
                }
            }
        }
        ans
    }
}
