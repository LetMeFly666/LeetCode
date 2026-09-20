/*
 * @Author: LetMeFly
 * @Date: 2026-09-20 10:25:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-20 10:30:28
 */
package main

func reverseDegree(s string) (ans int) {
	for i, c := range s {
		ans += (i + 1) * (26 - (byte)s[i] + 'a')
	}
	return
}
