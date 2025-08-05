/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 13:38:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 20:31:11
 */
package main

// import "fmt"

var ans2044, maxium2044 int = 0, 0
var nums2044 []int

func dfs2044(th, now int) {
    if now == maxium2044 {
        ans2044 += 1 << (len(nums2044) - th)
        return
    }
    if th == len(nums2044) {
        return
    }
    dfs2044(th + 1, now)
    dfs2044(th + 1, now | nums2044[th])
}

func countMaxOrSubsets(nums []int) int {
    nums2044 = nums
    ans2044 = 0
    maxium2044 = 0
    for _, t := range nums {
        maxium2044 |= t
    }
    dfs2044(0, 0)
    return ans2044
}

// func main() {
//     fmt.Println(countMaxOrSubsets([]int{2, 2, 2}))
// }