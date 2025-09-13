/*
 * @Author: LetMeFly
 * @Date: 2025-09-13 16:07:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-13 16:32:24
 */
impl Solution {
    const MASK: usize = 1<<0 | 1<<4 | 1<<8 | 1<<14 | 1<<20;

    pub fn max_freq_sum(s: String) -> i32 {
        let mut times: Vec<i32> = vec![0; 26];
        for c in s.bytes() {
            times[(c - b'a') as usize] += 1;
        }
        let mut cnt: Vec<i32> = vec![0; 2];
        for i in 0..26 {
            let idx: usize = Self::MASK >> i & 1;
            cnt[idx] = cnt[idx].max(times[i]);
        }
        cnt[0] + cnt[1]
    }
}