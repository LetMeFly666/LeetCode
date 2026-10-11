/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:11:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:23:09
 */
package main

func sumOfSquares(nums []int) (ans int) {
	n := len(nums)
	for i := 1; i * i <= n; i++ {
		if n % i == 0 {
			ans += nums[i - 1] * nums[i - 1];
			if i * i != n {
				ans += nums[n / i - 1] * nums[n / i - 1];
			}
		}
	}
	return
}
