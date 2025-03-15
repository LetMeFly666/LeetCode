/*
 * @Author: LetMeFly
 * @Date: 2025-03-15 10:33:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-15 10:35:05
 */
package main

import "fmt"

func main() {
	a := byte(1)
	b := byte(2)
	c := a - b
	fmt.Println(c)  // 255
	d := int(c)
	fmt.Println(d)  // 255
}