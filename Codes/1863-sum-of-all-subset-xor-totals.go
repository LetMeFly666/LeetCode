/*
 * @Author: LetMeFly
 * @Date: 2025-04-06 16:34:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-06 16:37:55
 */
package main

func subsetXORSum(nums []int) (ans int) {
    for i := 0; i < 1 << len(nums); i++ {
        thisCnt := 0
        for j := 0; j < len(nums); j++ {
            if i >> j & 1 == 1 {
                thisCnt ^= nums[j]
            }
        }
        ans += thisCnt
    }
    return ans
}