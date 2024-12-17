/*
 * @Author: LetMeFly
 * @Date: 2024-12-16 23:16:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-17 08:56:47
 */
package main

import "fmt"
import "reflect"

func main() {
    // 创建
    var array [5]int
    array[0] = 1
    fmt.Println(array)  // [1 0 0 0 0]
    slice := []int{1, 2, 3}
    slice2 := make([]int, 5)
    subSlice := slice[1:2]
    fmt.Println(slice)  // [1 2 3]
    fmt.Println(slice2)  // [0 0 0 0 0]
    fmt.Println(subSlice)  // [2]
    // 赋值
    array2 := array
    array2[2] = 100
    fmt.Println(array)  // [1 0 0 0 0]
    slice3 := slice
    slice3[1] = 100
    fmt.Println(slice3)  // [1 100 3]
    // 转换
    sFromA := array[:]
    fmt.Printf("%s(%s): %v\n", reflect.TypeOf(sFromA), reflect.TypeOf(sFromA).Kind(), sFromA);  // []int(slice): [1 0 0 0 0]
    var aFromS [3]int
    copy(aFromS[:], slice)
    fmt.Printf("%T(%s): %v\n", aFromS, reflect.TypeOf(aFromS).Kind(), aFromS);  // [3]int(array): [1 100 3]
}