/*
 * @Author: LetMeFly
 * @Date: 2024-06-20 09:29:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-20 09:59:40
 */
package main

func getFirst(n int) int {
    for ; n >= 10; {
        n /= 10;
    }
    return n
}

func gcd(a int, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}

func countBeautifulPairs(nums []int) int {
    ans := 0
    for i := 0; i < len(nums); i++ {
        for j := i + 1; j < len(nums); j++ {
            if gcd(getFirst((nums[i])), nums[j] % 10) == 1 {
                ans++
            }
        }
    }
    return ans
}