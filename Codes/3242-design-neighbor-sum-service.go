/*
 * @Author: LetMeFly
 * @Date: 2024-11-09 10:20:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-09 10:42:32
 */
package main

var direction = []struct{x, y int}{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}
type Value [][2]int

type NeighborSum struct {
    cache Value
}


func Constructor(grid [][]int) NeighborSum {
    n := len(grid)
    var neighborSum NeighborSum
    neighborSum.cache = make(Value, n * n)
    for i, row := range grid {
        for j, v := range row {
            for k, d := range direction {
                x, y := i + d.x, j + d.y
                if x >= 0 && x < n && y >= 0 && y < n {
                    neighborSum.cache[v][k / 4] += grid[x][y]
                }
            }
        }
    }
    return neighborSum
}


func (this *NeighborSum) AdjacentSum(value int) int {
    return this.cache[value][0]
}


func (this *NeighborSum) DiagonalSum(value int) int {
    return this.cache[value][1]
}


/**
 * Your NeighborSum object will be instantiated and called as such:
 * obj := Constructor(grid);
 * param_1 := obj.AdjacentSum(value);
 * param_2 := obj.DiagonalSum(value);
 */