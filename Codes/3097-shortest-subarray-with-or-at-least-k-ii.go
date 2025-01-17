/*
 * @Author: LetMeFly
 * @Date: 2025-01-17 12:42:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-17 13:47:03
 */
package main

func calc(cnt []int) (ans int) {
    for i, v := range cnt {
        if v > 0 {
            ans |= 1 << i
        }
    }
    return
}

func add(cnt []int, a int) {
    for i := range cnt {
        cnt[i] += a >> i & 1
    }
}

func del(cnt []int, a int) {
    for i := range cnt {
        cnt[i] -= a >> i & 1
    }
}

func minimumSubarrayLength(nums []int, k int) int {
    if k == 0 {
        return 1
    }
    ans := 1000000
    cnt := make([]int, 30)
    for l, r := 0, 0; l < len(nums); l++ {
        if l > 0 {
            del(cnt, nums[l - 1])
        }
        for r < len(nums) && calc(cnt) < k {
            add(cnt, nums[r])
            r++
        }
        if calc(cnt) >= k {
            ans = min(ans, r - l)
        }
    }
    if ans == 1000000 {
        return -1
    }
    return ans
}