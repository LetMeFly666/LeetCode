/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 13:38:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-13 14:00:33
 */
package main

import (
	"strconv"
	"strings"
)

func dfs2999(i int, limitLow, limitHigh bool, start, finish string, nonFixed int, cache []int64, limit int, suffix string) (ans int64) {
    if i == len(start) {
        return 1
    }
    if !limitLow && !limitHigh && cache[i] == -1 {
        return cache[i]
    }

    var low, high int
    if limitLow {
        low = int(start[i]) - int('0')
    } else {
        low = 0
    }
    if limitHigh {
        high = int(finish[i]) - int('0')
    } else {
        high = 9
    }
    if i < nonFixed {
        for d := low; d <= min(high, limit); d++ {
            ans += dfs2999(i + 1, limitLow && d == low, limitHigh && d == high, start, finish, nonFixed, cache, limit, suffix)
        }
    } else {
        d := int(suffix[i - nonFixed]) - int('0')
        if low <= d && d <= high {
            ans = dfs2999(i + 1, limitLow && d == low, limitHigh && d == high, start, finish, nonFixed, cache, limit, suffix)
        }
    }
    if !limitLow && !limitHigh {
        cache[i] = ans
    }
    return ans
}

func numberOfPowerfulInt(start int64, finish int64, limit int, s string) int64 {
    finish_str := strconv.FormatInt(finish, 10)
    cache := make([]int64, len(finish_str) + 1)
    for i := range cache {
        cache[i] = -1
    }
    start_str := strconv.FormatInt(start, 10)
    start_str = strings.Repeat("0", len(finish_str) - len(start_str)) + start_str
    nonFixed := len(finish_str) - len(s)
    return dfs2999(0, true, true, start_str, finish_str, nonFixed, cache, limit, s)
}