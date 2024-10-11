/*
 * @Author: LetMeFly
 * @Date: 2024-10-11 23:03:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-11 23:07:47
 */
package main
import "math"

func numberOfPairs(nums1 []int, nums2 []int, k int) int64 {
    ma := map[int]int{}
    for _, t := range nums1 {
        if t % k != 0 {
            continue
        }
        t /= k
        sqrt_ := int(math.Sqrt(float64(t)));
        for i := 1; i <= sqrt_; i++ {
            if t % i == 0 {
                ma[i]++
                ma[t / i]++
            }
        }
        if sqrt_ * sqrt_ == t {
            ma[sqrt_]--
        }
    }
    ans := int64(0)
    for _, t := range nums2 {
        ans += int64(ma[t])
    }
    return ans
}