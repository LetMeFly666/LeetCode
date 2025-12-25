/*
 * @Author: LetMeFly
 * @Date: 2025-12-25 12:56:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-25 13:12:12
 */
impl Solution {
    pub fn maximum_happiness_sum(mut happiness: Vec<i32>, k: i32) -> i64 {
        let mut ans: i64 = 0;
        happiness.sort_by(|a: &i32, b: &i32| b.cmp(a));
        for i in 0..k {
            if happiness[i as usize] <= i {
                return ans;
            }
            ans += (happiness[i as usize] - i) as i64;
        }
        ans
    }
}