/*
 * @Author: LetMeFly
 * @Date: 2026-03-07 13:14:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-07 13:16:55
 */
package main

func checkOnesSegment(s string) bool {
    for i := 1; i < len(s); i++ {
		if s[i - 1] == '0' && s[i] == '1' {
			return false
		}
	}
	return true
}