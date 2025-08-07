/*
 * @Author: LetMeFly
 * @Date: 2025-08-05 10:28:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-07 10:38:25
 */
use std::collections::HashMap;

impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut l = 0;
        let mut window = HashMap::new();
        for (r, &x) in fruits.iter().enumerate() {
            *window.entry(x).or_insert(0) += 1;
            while window.len() > 2 {
                *window.entry(fruits[l]) -= 1;
                if (window[fruits[l]] == 0) {
                    window.remove(fruits[l]);
                }
                l += 1;
            }
            ans = ans.max(r - l + 1);
        }
        ans
    }
}