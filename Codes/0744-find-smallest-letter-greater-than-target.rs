/*
 * @Author: LetMeFly
 * @Date: 2026-01-31 13:49:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-31 14:03:50
 */
impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        for i in 0..letters.len() {
            if letters[i] > target {
                return letters[i];
            }
        }
        letters[0]
    }
}