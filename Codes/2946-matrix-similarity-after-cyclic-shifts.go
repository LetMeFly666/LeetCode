/*
 * @Author: LetMeFly
 * @Date: 2026-03-27 08:48:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-29 19:44:59
 */
package main

func areSimilar(mat [][]int, k int) bool {
	m := len(mat[0])
	for _, row := range mat {
		for j := range row {
			if row[j] != row[(j + k) % m] {
				return false
			}
		}
	}
	return true
}