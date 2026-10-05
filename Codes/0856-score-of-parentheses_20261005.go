/*
 * @Author: LetMeFly
 * @Date: 2026-10-05 16:38:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-05 16:42:41
 */
package main

func scoreOfParentheses(s string) (ans int) {
	layer := 0
	for i, c := range s {
		if c == '(' {
			layer++
		} else {
			layer--
			if s[i - 1] == '(' {
				ans += 1 << layer
			}
		}
	}
	return
}
