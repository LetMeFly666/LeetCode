/*
 * @Author: LetMeFly
 * @Date: 2025-07-23 10:31:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-24 13:16:17
 */
package main

// import "fmt"

func maximumUniqueSubarray(nums []int) (ans int) {
    had := map[int]struct{}{}
    l, cnt := 0, 0
    for _, t := range nums {
        for _, ok := had[t]; ok; _, ok = had[t] {
            delete(had, nums[l])
            cnt -= nums[l]
            l++
        }
        cnt += t
        had[t] = struct{}{}
        ans = max(ans, cnt)
    }
    return
}

// func main() {
//     nums := []int{4, 2, 4, 5, 6}
//     ans := maximumUniqueSubarray(nums)
//     fmt.Println(ans)
// }