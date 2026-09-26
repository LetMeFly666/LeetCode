/*
 * @Author: LetMeFly
 * @Date: 2026-06-29 15:07:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-29 15:20:20
 */
package main

import "strings"

func numOfStrings(patterns []string, word string) (ans int) {
	for _, p := range patterns {
		if strings.Contains(word, p) {
			ans++
		}
	}
	return
}
