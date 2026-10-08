/*
 * @Author: LetMeFly
 * @Date: 2026-10-08 08:52:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-08 09:11:09
 */
package main

func removeOuterParentheses(s string) (ans string) {
	layer := 0
	for _, c := range s {
		skip := false
		if c == '(' {
			if layer == 0 {
				skip = true
			}
			layer++
		} else {
			layer--
			if layer == 0 {
				skip = true
			}
		}
		if !skip {
			ans = append(ans, c)
		}
	}
	return ans
}
