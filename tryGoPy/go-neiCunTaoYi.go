/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 14:56:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-26 16:40:21
 */
package main

import "fmt"

func main() {
	// type t struct{a int}
	type t struct{}
	a := &t{}
	b := &t{}
	fmt.Printf("%p\n", a)
	fmt.Printf("%p\n", b)
	fmt.Println(a == b)  // true
	// a.a = 1
	// fmt.Println(a)
	// fmt.Println(b)
	// fmt.Println(a == b)  // false
	

	c := &t{}
	d := &t{}
	fmt.Println(c == d)  // false
}