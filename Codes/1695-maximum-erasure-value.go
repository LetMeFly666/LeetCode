/*
 * @Author: LetMeFly
 * @Date: 2025-07-23 10:31:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-24 13:08:34
 */
package main

import "fmt"

// 昨天晚上干别的去了，今天中午补上，间隔时间更久效果更好(bushi)
func maximumUniqueSubarray(nums []int) (ans int) {
    had := map[int]struct{}{}
    l, cnt := 0, 0
    for _, t := range nums {
        for _, ok := had[t]; ok; {
            delete(had, nums[l])
            cnt -= nums[l]
            l++
        }
        cnt += t
        had[t] = struct{}{}
    }
    return
}

func main() {
    nums := []int{4, 2, 4, 5, 6}
    ans := maximumUniqueSubarray(nums)
    fmt.Println(ans)
}