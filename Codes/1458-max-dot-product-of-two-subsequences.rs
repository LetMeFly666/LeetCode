/*
 * @Author: LetMeFly
 * @Date: 2026-01-08 09:21:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-08 09:51:58
 */
impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let n: usize = nums1.len();
        let m: usize = nums2.len();
        let mut dp: Vec<Vec<i32>> = vec![vec![-1000000; m+1]; n+1];
        for i in 1..=n {
            for j in 1..=m {
                dp[i][j] = dp[i-1][j].max(dp[i][j-1].max((nums1[i-1] * nums2[j-1]).max(dp[i-1][j-1] + nums1[i-1] * nums2[j-1])));
            }
        }
        dp[n][m]
    }
}