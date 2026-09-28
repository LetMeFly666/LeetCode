/*
 * @Author: LetMeFly
 * @Date: 2026-09-28 08:10:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-28 10:00:29
 */
package main

func maxDepth(s string) (ans int) {
	layer := 0
	for _, c := range s {
		if c == '(' {
			layer++
			ans = max(ans, layer)
		} else if c == ')' {
			layer--
		}
	}
	return
}
