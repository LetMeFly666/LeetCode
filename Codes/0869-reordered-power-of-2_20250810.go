/*
 * @Author: LetMeFly
 * @Date: 2025-08-10 17:20:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-10 20:44:18
 */
package main

import (
	"slices"
	"strconv"
)

var can0869 = map[string]bool{}

func init0869() {
    if len(can0869) > 0 {
        return
    }
    for i := 0; i < 31; i++ {
        can0869[itoa869(i)] = true
    }
}

func itoa869(i int) string {
    s := []byte(strconv.Itoa(i))
    slices.Sort(s)
    return string(s)
}

func reorderedPowerOf2(n int) bool {
    init0869()
    return can0869[itoa869(n)]
}