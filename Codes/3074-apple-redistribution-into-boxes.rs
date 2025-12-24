/*
 * @Author: LetMeFly
 * @Date: 2025-12-24 13:30:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-24 18:47:13
 */
impl Solution {
    pub fn minimum_boxes(apple: Vec<i32>, mut capacity: Vec<i32>) -> i32 {
        let mut cnt: i32 = 0;
        for t in apple.iter() {
            cnt += t;
        }
        capacity.sort_by(|a, b| b.cmp(a));

        let mut ans: i32 = 0;
        for t in capacity.iter() {
            cnt -= t;
            ans += 1;
            if cnt <= 0 {
                return ans
            }
        }
        ans
    }
}