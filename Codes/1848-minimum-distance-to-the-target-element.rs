/*
 * @Author: LetMeFly
 * @Date: 2026-04-13 21:39:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-13 21:46:02
 */
impl Solution {
    pub fn get_min_distance(nums: Vec<i32>, target: i32, start: i32) -> i32 {
        let mut ans = nums.len() as i32;
        for i in 0..nums.len() {
            if nums[i] == target {
                ans = ans.min((i as i32 - start).abs());
            }
        }
        ans
    }
}
