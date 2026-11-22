/*
 * @Author: LetMeFly
 * @Date: 2026-11-22 09:57:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-22 09:59:59
 */
package main

func checkString(s string) bool {
	n := len(s)
	for i := 1; i < n; i++ {
		if s[i - 1] == 'b' && s[i] == 'a' {
			return false
		}
	}
	return true
}
