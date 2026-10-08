/*
 * @Author: LetMeFly
 * @Date: 2026-10-08 08:52:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-08 09:15:54
 */
package main

import "strings"

func removeOuterParentheses(s string) string {
	var ans strings.Builder
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
			ans.WriteRune(c)
		}
	}
	return ans.String()
}
