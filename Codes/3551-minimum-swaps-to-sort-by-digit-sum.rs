/*
 * @Author: LetMeFly
 * @Date: 2026-10-17 16:31:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-17 20:57:05
 */
struct Union {
    parent: Vec<usize>,
    sz: Vec<usize>,
    count: usize,
}

impl Union {
    fn new(n: usize) -> Self {
        Union {
            parent: (0..n).collect(),
            sz: vec![1; n],
            count: n
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] == x {
            x
        } else {
            self.parent[x] = self.find(self.parent[x]);
            self.parent[x]
        }
    }

    fn merge(&mut self, x: usize, y: usize) {
        let mut px = self.find(x);
        let mut py = self.find(y);
        if px == py {
            return;
        }
        if self.sz[px] > self.sz[py] {
            std::mem::swap(&mut px, &mut py);
        }
        self.sz[py] += self.sz[px];
        self.parent[px] = py;
        self.count -= 1;
    }
}

impl Solution {
    fn get_sum(mut n: i32) -> i32 {
        let mut ans = 0;
        while n > 0 {
            ans += n % 10;
            n /= 10;
        }
        ans
    }

    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut idxs: Vec<usize> = (0..n).collect();
        idxs.sort_by_key(|&i| (Solution::get_sum(nums[i]), nums[i]));  // i是&usize类型，&i是usize类型
        
        let mut union = Union::new(n);
        for i in 0..n {
            union.merge(i, idxs[i]);
        }
        (n - union.count) as i32
    }
}
