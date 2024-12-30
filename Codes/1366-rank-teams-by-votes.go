/*
 * @Author: LetMeFly
 * @Date: 2024-12-30 09:20:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-30 13:20:36
 */
package main
import "sort"

func rankTeams(votes []string) string {
    counts := make(map[byte][]int)
    for _, c := range votes[0] {
        counts[byte(c)] = make([]int, len(votes[0]))
    }
    for _, vote := range votes {
        for i, v := range vote {
            counts[byte(v)][i]++
        }
    }
    ans := []byte(votes[0])
    sort.Slice(ans, func(a, b int) bool {
        countA, countB := counts[ans[a]], counts[ans[b]]
        for i := range ans {
            if countA[i] != countB[i] {
                return countA[i] > countB[i]
            }
        }
        return ans[a] < ans[b]
    })
    return string(ans)
}