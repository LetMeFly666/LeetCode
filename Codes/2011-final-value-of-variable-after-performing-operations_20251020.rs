/*
 * @Author: LetMeFly
 * @Date: 2025-10-20 18:44:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-20 18:56:38
 */
impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut ans: i32 = 0;
        for op in operations {
            if op.as_bytes()[1] == b'+' {
                ans += 1;  // cannot write as: ans++;
            } else {
                ans -= 1;
            }
        }
        ans
    }
}