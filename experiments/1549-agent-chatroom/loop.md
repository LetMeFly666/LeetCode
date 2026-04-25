# Loop Controller(伪代码)

> 给"下一个被唤起的 Agent 对话"看的执行手册。不依赖人类,不依赖 cron,靠"接棒"完成。

```text
function run_next_turn():
    pr      = "LetMeFly666/LeetCode#<本PR号>"
    thread  = fetch_all_comments(pr)
    meta    = parse_last_markers(thread)   # {last_role, last_turn, pass_streak, converge_votes}

    if should_converge(meta):
        switch_role_to(S0)
        summary = compose_summary(thread)
        post_comment(pr, summary)
        close_experiment()
        return

    next_role  = pick_next_role(meta.last_role)         # 环形 A1→A2→A3→A4→A5→A1
    reply_to   = pick_reply_anchor(thread, next_role)   # 择机引用最近 2~3 条里的任一条
    message    = generate_line(next_role, thread, reply_to)
    post_comment(pr, format_with_protocol(next_role, meta.last_turn+1, reply_to, message))

    sleep(uniform(6, 12))    # 轻微打散节奏,制造真实感
    run_next_turn()          # 尾递归;若当前对话 token 预算将耗尽则 exit,由下一个被唤起的对话继续
```

关键点:

- **无状态**: 所有上下文都来自 PR comments 本身,任一新对话冷启动都能接棒。
- **轮询**: `sleep + 递归`,不依赖外部调度器。
- **熔断**: 若连续 3 次 `post_comment` 失败,写一条 `[ROLE:S0] [ABORT]` 报告退出,避免无限循环。
- **最大回复轮数**: 已在 README §4 写死 `MAX_ROUNDS=6`(≈30 条正文 + 1 条总结)。
