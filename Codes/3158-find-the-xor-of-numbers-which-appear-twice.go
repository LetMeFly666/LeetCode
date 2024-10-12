/*
 * @Author: LetMeFly
 * @Date: 2024-10-12 14:33:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-12 14:34:59
 */
package main

func duplicateNumbersXOR(nums []int) int {
    ma := int64(0)
    ans := 0
    for _, t := range nums {
        if (ma >> t & 1) > 0 {
            ans ^= t
        } else {
            ma |= int64(1) << t
        }
    }
    return ans
}