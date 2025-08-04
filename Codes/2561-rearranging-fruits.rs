/*
 * @Author: LetMeFly
 * @Date: 2025-08-03 22:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-04 23:06:33
 */
use std::collections::HashMap;

impl Solution {
    pub fn min_cost(basket1: Vec<i32>, basket2: Vec<i32>) -> i64 {
        let mut m: i32 = i32::MAX;
        let mut timeDiffs = HashMap::new();
        for &t in &basket1 {
            *timeDiffs.entry(t).or_insert(0) += 1;
            m = m.min(t);
        }
        for &t in &basket2 {
            *timeDiffs.entry(t).or_insert(0) -= 1;
            m = m.min(t);
        }
        
        let mut change: Vec<i32> = vec![];
        for (&val, &times) in timeDiffs.iter() {
            if times % 2 != 0 {
                return -1;
            }
            for _ in 0..((times as i32).abs() / 2) {
                change.push(val);
            }
        }

        change.sort_unstable();
        let mut ans: i64 = 0;
        for i in 0..(change.len() / 2) {
            ans += i64::from(change[i].min(2 * m));
        }
        ans
    }
}