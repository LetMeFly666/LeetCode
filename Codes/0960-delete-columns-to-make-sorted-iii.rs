/*
 * @Author: LetMeFly
 * @Date: 2025-12-22 22:28:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-22 23:05:28
 */
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let m = strs[0].len();
        let mut dp = vec![0; m];
        for cur in 0..m {
            for prev in 0..cur {
                if dp[prev] > dp[cur] && strs.iter().all(|s| s.as_bytes()[prev] <= s.as_bytes()[cur]) {
                    dp[cur] = dp[prev];
                }
            }
            dp[cur] += 1;
        }
        m as i32 - *dp.iter().max().unwrap()
    }
}