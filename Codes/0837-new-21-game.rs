/*
 * @Author: LetMeFly
 * @Date: 2025-08-17 19:33:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-17 22:55:04
 */
impl Solution {
    pub fn new21_game(n: i32, k: i32, max_pts: i32) -> f64 {
        let k: usize = k as usize;
        let max_pts: usize = max_pts as usize;
        let n: usize = n as usize;

        let mut dp: Vec<f64> = vec![0.; k + max_pts];
        let mut s: f64 = 0.;
        for i in k..(k+max_pts) {
            if i <= n {
                dp[i] = 1.;
            } else {
                dp[i] = 0.;
            }
            s += dp[i];
        }
        for i in (0..k).rev() {
            dp[i] = s / max_pts as f64;
            s = s + dp[i] - dp[i + max_pts];
        }
        dp[0]
    }
}