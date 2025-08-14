/*
 * @Author: LetMeFly
 * @Date: 2025-08-14 10:28:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-14 18:43:30
 */
package main

func checkPowersOfThree(n int) bool {
    for ; n > 0; n /= 3 {
        if n % 3 == 2 {
            return false
        }
    }
    return true
}