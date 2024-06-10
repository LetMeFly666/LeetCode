/*
 * @Author: LetMeFly
 * @Date: 2024-06-10 15:25:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-10 15:27:28
 */
package main

import "sort"

func numRescueBoats(people []int, limit int) int {
    sort.Ints(people);
    ans := 0
    for l, r := 0, len(people) - 1; l <= r; ans, r = ans + 1, r - 1 {
        if people[l] + people[r] <= limit {
            l++;
        }
    }
    return ans
}