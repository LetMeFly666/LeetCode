/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 16:05:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-05 16:07:53
 */
package main

func breakPalindrome(palindrome string) string {
    if len(palindrome) == 1 {
        return ""
    }
    for i := 0; i < len(palindrome) / 2; i++ {
        if palindrome[i] != 'a' {
            return palindrome[:i] + "a" + palindrome[i + 1:]
        }
    }
    return palindrome[:len(palindrome) - 1] + "b"
}