/*
 * @Author: LetMeFly
 * @Date: 2026-10-09 08:25:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-09 11:19:46
 */
package main

func minInsertions(s string) (ans int) {
	diff := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			diff++
		} else {
			if diff > 0 {
				diff--
			} else {
				ans++
			}
			if i + 1 < len(s) && s[i + 1] == ')' {
				i++
			} else {
				ans++
			}
		}
	}
	return ans + diff * 2
}
