/*
 * @Author: LetMeFly
 * @Date: 2025-08-12 09:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-12 22:00:07
 */
impl Solution {
    pub fn number_of_ways(n: i32, x: i32) -> i32 {
        let n: usize = n as usize;
        let mut dp: Vec<i32> = vec![0; n + 1];
        dp[0] = 1;
        for th in 1usize.. {
            let p: usize = th.pow(x as u32);
            if p > n {
                break;
            }
            for i in (p..=n).rev() {
                dp[i] = ((dp[i] as i64 + dp[i - p] as i64) % (1000000007 as i64)) as i32
            }
        }
        dp[n]
    }
}