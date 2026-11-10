/*
 * @Author: LetMeFly
 * @Date: 2026-11-10 21:50:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-10 22:32:23
 */
use std::ops::Index;

struct ABC {
    a: [i32; 3],
    diff: usize,
}

impl ABC {
    pub fn new() -> Self {
        Self {
            a: [0; 3],
            diff: 0,
        }
    }

    pub fn push(&mut self, v: i32) {
        self.a[self.diff] = v;
        self.diff = self.diff + 1;
    }
}

impl Index<usize> for ABC {
    type Output = i32;

    fn index(&self, i: usize) -> &Self::Output {
        &self.a[(self.diff + i) % 3]
    }
}

impl Solution {
    pub fn climb_stairs(n: i32, costs: Vec<i32>) -> i32 {
        let mut abc = ABC::new();
        for &cost in costs.iter() {
            abc.push(cost + (abc[0] + 9).min(abc[1] + 4).min(abc[2] + 1));
        }
        abc[2]
    }
}
