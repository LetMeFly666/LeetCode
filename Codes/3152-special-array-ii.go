/*
 * @Author: LetMeFly
 * @Date: 2024-08-14 23:39:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-14 23:44:28
 */
package main

func isArraySpecial(nums []int, queries [][]int) []bool {
    cnt := 0
    for i := 0; i < len(nums) - 1; i++ {
        same := nums[i] % 2 == nums[i + 1] % 2
        nums[i] = cnt
        if same {
            cnt++
        }
    }
    nums[len(nums) - 1] = cnt
    ans := make([]bool, len(queries))
    for i, q := range queries {
        ans[i] = nums[q[0]] == nums[q[1]]
    }
    return ans
}