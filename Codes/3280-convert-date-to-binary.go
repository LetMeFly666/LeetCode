/*
 * @Author: LetMeFly
 * @Date: 2025-01-01 18:54:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-01 18:57:15
 */
package main

import (
	"strconv"
	"strings"
)

func convertDateToBinary(date string) string {
    a := strings.Split(date, "-")
    for i := range a {
        x, _ := strconv.Atoi(a[i])
        a[i] = strconv.FormatUint(uint64(x), 2)
    }
    return strings.Join(a, "-")
}