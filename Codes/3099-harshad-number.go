/*
 * @Author: LetMeFly
 * @Date: 2024-07-03 19:28:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-03 19:30:06
 */
package main

func getSum(n int) int {
	ans := 0
	for n > 0 {
		ans += n % 10
		n /= 10
	}
	return ans
}

func sumOfTheDigitsOfHarshadNumber(x int) int {
	sum := getSum(x)
	if x%sum == 0 {
		return sum
	}
	return -1
}