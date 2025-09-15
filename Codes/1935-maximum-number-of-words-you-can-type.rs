/*
 * @Author: LetMeFly
 * @Date: 2025-09-15 21:48:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-15 22:11:40
 */
use std::collections::HashSet;

impl Solution {
    pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {
        let cannot: HashSet<char> = broken_letters.chars().collect();
        let mut ans: i32 = 0;
        let mut can: bool = true;
        for c in text.chars() {
            if c == ' ' {
                ans += if can { 1 } else { 0 }
                can = true;
            } else if cannot.contains(&c) {
                can = false;
            }
        }
        ans + if can { 1 } else { 0 }
    }
}