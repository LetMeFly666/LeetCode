/*
 * @Author: LetMeFly
 * @Date: 2026-10-06 11:26:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-06 11:28:37
 */
package main

func minAddToMakeValid(s string) (ans int) {
	diff := 0
	for _, c := range s {
		if c == '(' {
			diff++
		} else {
			if diff > 0 {
				diff--
			} else {
				ans++
			}
		}
	}
	return ans + diff
}
