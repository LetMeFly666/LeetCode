/*
 * @Author: LetMeFly
 * @Date: 2025-03-07 11:08:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-07 11:17:05
 */
github actions的actions/checkout
能否checkout所有分支，但是每个分支都只检出最近的一次提交


git fetch --all虽然没有拉取所有历史记录，但是不是已经需要把所有需要的信息拉取到本地了
如果历史记录特别多，可能会很慢。这就失去了每个分支只检出最近一次提交的意义


---

请详细解释github actions的actions/checkout
以及我能不能做到这样：
第一个step:先checkout一个分支的一次commit
step2: 判断这次commit有无指定文件
step3: 根据判断结果来决定是否checkout其他分支


不对，step1的意义何在？
step1我只想checkout默认分支的最近一次提交，这是为了防止历史记录过多导致checkout过慢