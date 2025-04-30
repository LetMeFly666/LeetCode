/*
 * @Author: LetMeFly
 * @Date: 2025-04-30 17:24:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 17:28:26
 */
func findNumbers(nums []int) (ans int) {
    for _, t := range nums {
		cnt := 0
		for t > 0 {
			cnt++
			t /= 10
		}
		if cnt % 2 == 0 {
			ans++
		}
	}
	return
}