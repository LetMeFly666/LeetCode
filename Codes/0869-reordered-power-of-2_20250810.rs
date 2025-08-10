/*
 * @Author: LetMeFly
 * @Date: 2025-08-10 17:20:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-10 21:17:39
 */
use std::collections::HashSet;

lazy_static::lazy_static! {
    static ref CAN: HashSet<String> = {
        let mut can = HashSet::new();
        for i in 0..31 {
            can.insert(Solution::itoa(1 << i));
        }
        can
    };
}

impl Solution {
    fn itoa(i: i32) -> String {
        let mut v: Vec<char> = i.to_string().chars().collect();
        v.sort();
        v.into_iter().collect()
    }
    
    pub fn reordered_power_of2(n: i32) -> bool {
        CAN.contains(&Self::itoa(n))
    }
}