/*
 * @Author: LetMeFly
 * @Date: 2025-12-20 22:44:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-20 23:02:29
 */
// THIS CANNOT ACCESS
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let n = strs.len();
        let m = strs[0].len();
        let mut ans: i32 = 0;
        for j in 0..m {
            for i in 0..n {
                if strs[i][j] < strs[i-1][j] {
                    ans += 1;
                    break;
                }
            } 
        }
        ans
    }
}