/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 14:56:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-29 14:23:18
 */
package main

import "fmt"

func main() {
	a := make([]int, 5)
	for i := range a {
		i++
		fmt.Println(i)  // 1 2 3 4 5
	}

	for i := 0; i < 5; i++ {
		i++
		fmt.Println(i)  // 1 3 5
	}
}

// golang range赋值类似pyton
// 传统for循环类似C