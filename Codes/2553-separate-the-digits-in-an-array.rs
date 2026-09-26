/*
 * @Author: LetMeFly
 * @Date: 2026-05-11 21:16:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-11 21:35:16
 */
impl Solution {
    pub fn separate_digits(mut nums: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::new();
        for i in (0..nums.len()).rev() {
            while nums[i] != 0 {
                ans.push(nums[i] % 10);
                nums[i] /= 10;
            }
        }
        ans.reverse();
        ans
    }
}
