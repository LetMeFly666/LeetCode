/*
 * @Author: LetMeFly
 * @Date: 2025-10-16 19:40:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-16 20:18:30
 */
use std::collections::HashMap;

// 这语言设计的真精妙
impl Solution {
    pub fn find_smallest_integer(nums: Vec<i32>, value: i32) -> i32 {
        let mut cnt: HashMap<i32, i32> = HashMap::new();
        for x in nums {
            *cnt.entry((x % value + value) % value).or_insert(0) += 1;
        }

        for ans in 0.. {
            // if matches!(cnt.get_mut(&(ans % value)), Some(v) if *v > 0) {
            //     *v -= 1;  // 无法使用v报错
            //     continue;
            // }
            if let Some(v) = cnt.get_mut(&(ans % value)) {
                if *v > 0 {  // 记得是大于
                    *v -= 1;
                    continue;
                }
            }
            return ans;
        }
        unreachable!()
    }
}