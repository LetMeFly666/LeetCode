/*
 * @Author: LetMeFly
 * @Date: 2024-10-22 22:24:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-22 22:26:32
 */
package main

import "fmt"

func main() {
	var a *int
	var s []int
	fmt.Println(a, s)
	fmt.Println(a == nil, s == nil)
	// a = s  // 报错
}