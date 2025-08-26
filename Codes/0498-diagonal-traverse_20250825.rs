/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 10:33:40
 */
impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let n: usize = mat.len();
        let m: usize = mat[0].len();
        let mut ans: Vec<i32> = vec![0; m * n];
        let mut cnt: usize = 0;
        for k in 0..(m + n - 1) {
            if k % 2 == 0 {
                let mut i: usize = k.min(n - 1);
                let mut j: usize = k - i;
                while i >= 0 && j < m {
                    ans[cnt] = mat[i][j];
                    cnt += 1;
                    i -= 1;
                    j += 1;
                }
            } else {
                let mut j: usize = k.min(m - 1);
                let mut i: usize = k - j;
                while i < n && j >= 0 {
                    ans[cnt] = mat[i][j];
                    cnt += 1;
                    i += 1;
                    j -= 1;
                }
            }
        }
        ans
    }
}