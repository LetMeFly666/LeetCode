/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 10:39:12
 */
impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let n: isize = mat.len() as isize;  // 注意，usize永远大于0
        let m: isize = mat[0].len() as isize;
        let mut ans: Vec<i32> = vec![0; (m * n) as usize];
        let mut cnt: usize = 0;
        for k in 0..(m + n - 1) {
            if k % 2 == 0 {
                let mut i: isize = k.min(n - 1);
                let mut j: isize = k - i;
                while i >= 0 && j < m {
                    ans[cnt] = mat[i as usize][j as usize];
                    cnt += 1;
                    i -= 1;
                    j += 1;
                }
            } else {
                let mut j: isize = k.min(m - 1);
                let mut i: isize = k - j;
                while i < n && j >= 0 {
                    ans[cnt] = mat[i as usize][j as usize];
                    cnt += 1;
                    i += 1;
                    j -= 1;
                }
            }
        }
        ans
    }
}