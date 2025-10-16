/*
 * @Author: LetMeFly
 * @Date: 2025-10-16 19:40:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-16 20:01:33
 */
package main

func findSmallestInteger(nums []int, value int) (ans int) {
    cnt := map[int]int{}
    for _, t := range nums {
        cnt[(t % value + value) % value]++
    }
    for cnt[ans % value] > 0 {
        cnt[ans % value]--
        ans++
    }
    return
}