/*
 * @Author: LetMeFly
 * @Date: 2026-02-15 18:09:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-15 18:20:24
 */
// THIS CANNOT BE ACCEPTED
impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![0; n];
        for i in 0..n {
            ans[i] = nums[((nums[i] as usize + i) % n + n) % n];
        }
        ans
    }
}