/*
 * @Author: LetMeFly
 * @Date: 2026-06-01 22:06:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-01 22:16:25
 */
// THIS CANNOT BE ACCEPTED
impl Solution {
    pub fn minimum_cost(mut cost: Vec<i32>) -> i32 {
        let mut ans = 0;
        cost.sort_unstable();
        let mut cnt = 0;
        for i in (cost.len() - 1)..=0 {
            if cnt == 2 {
                cnt = 0;
            } else {
                ans += cost[i];
                cnt += 1;
            }
        }
        ans
    }
}
