/*
 * @Author: LetMeFly
 * @Date: 2026-06-29 15:07:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-29 15:22:08
 */
impl Solution {
    pub fn num_of_strings(patterns: Vec<String>, word: String) -> i32 {
        let mut ans = 0;
        for p in patterns.iter() {
            if word.contains(p) {
                ans += 1;
            }
        }
        ans
    }
}
