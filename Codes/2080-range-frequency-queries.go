/*
 * @Author: LetMeFly
 * @Date: 2025-02-18 10:17:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-18 10:50:44
 */
package main

import "sort"


type RangeFreqQuery map[int][]int


func Constructor(arr []int) RangeFreqQuery {
    ma := map[int][]int{}
	for i, v := range arr {
		ma[v] = append(ma[v], i)
	}
	return ma
}


func (this *RangeFreqQuery) Query(left int, right int, value int) int {
    v := (*this)[value]
	return sort.SearchInts(v, right + 1) - sort.SearchInts(v, left)
}


/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * obj := Constructor(arr);
 * param_1 := obj.Query(left,right,value);
 */