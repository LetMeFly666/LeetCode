/*
 * @Author: LetMeFly
 * @Date: 2025-10-23 23:05:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-23 23:46:40
 */
impl Solution {
    pub fn has_same_digits(s: String) -> bool {
        let mut a: Vec<u8> = s.chars()
            .map(|c| c.to_digit(10).unwrap() as u8)
            .collect();
        while a.len() > 2 {
            let mut b = Vec::with_capacity(a.len() - 1);
            for i in 0..a.len() - 1 {
                b.push((a[i] + a[i + 1]) % 10);
            }
            a = b;
        }
        a[0] == a[1]
    }
}