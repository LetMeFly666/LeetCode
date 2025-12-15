/*
 * @Author: LetMeFly
 * @Date: 2025-12-15 21:33:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-15 21:41:17
 */
impl Solution {
    pub fn get_descent_periods(prices: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        let mut cnt: i64 = 0;
        let mut last: i32 = 0;
        for p in prices {  // 一借不还
            if p != last - 1 {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
            cnt += 1;
            last = p;
        }
        ans + cnt * (cnt + 1) / 2
    }
}