package main

func maximumRobots(chargeTimes []int, runningCosts []int, budget int64) int {
    ans := 0
    sumCosts := int64(0)
    q := []int{}

    for l, r := 0, 0; r < len(chargeTimes); r++ {
        for len(q) > 0 && chargeTimes[r] >= chargeTimes[q[len(q) - 1]] {
            q = q[:len(q) - 1]
        }
        q = append(q, r)
        sumCosts += int64(runningCosts[r])
        
        for len(q) > 0 && int64(chargeTimes[q[0]]) + int64(r - l + 1) * sumCosts > budget {
            if l == q[0] {
                q = q[1:]
            }
            sumCosts -= int64(runningCosts[l])
            l++
        }

        if r - l + 1 > ans {
            ans = r - l + 1
        }
    }
    return ans
}