/*
 * @Author: LetMeFly
 * @Date: 2026-09-19 08:23:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-19 08:38:52
 */
package main

func getClosest(center, x1, x2 int) int {
	if x1 > center {
		return x1
	} else if x2 < center {
		return x2
	} else {
		return center
	}
}

func getPow(x int) int {
	return x * x
}

func checkOverlap(radius int, xCenter int, yCenter int, x1 int, y1 int, x2 int, y2 int) bool {
	x := getClosest(xCenter, x1, x2)
	y := getClosest(yCenter, y1, y2)
	return getPow(x - xCenter) + getPow(y - yCenter) <= getPow(radius)
}
