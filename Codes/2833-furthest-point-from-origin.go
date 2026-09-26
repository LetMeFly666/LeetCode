/*
 * @Author: LetMeFly
 * @Date: 2026-04-24 20:58:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-24 21:25:20
 */
package main

func furthestDistanceFromOrigin(moves string) int {
	flex, diff := 0, 0
	for _, c := range moves {
		switch byte(c) {
		case 'L':
			diff--
		case 'R':
			diff++
		default:
			flex++
		}
	}
	if diff > 0 {
		return diff + flex
	}
	return flex - diff
}
