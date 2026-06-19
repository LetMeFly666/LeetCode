/*
 * @Author: LetMeFly
 * @Date: 2026-06-19 10:15:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-19 10:19:43
 */
impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut now = 0;
        for t in gain.iter() {
            now += t;
            ans = ans.max(now);
        }
        ans
    }
}
