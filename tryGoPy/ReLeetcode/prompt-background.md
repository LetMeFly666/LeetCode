<!--
 * @Author: LetMeFly
 * @Date: 2025-12-20 11:56:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-20 11:56:30
-->
# GitHub Projects v2 自动化系统背景 Prompt

你正在协助维护 GitHub 仓库 [LeetCode](https://github.com/LetMeFly666/LeetCode) 的自动化系统，核心是 **每日一题 Issue → Project v2**。

## 核心约定

- 项目：`1Problem1Day`，User Project：https://github.com/users/LetMeFly666/projects/5  
- 所有时间使用 **事件时间 +8小时 (UTC+8)**，格式 `YYYY-MM-DD`  
- 每日一题 Issue 标题正则：^\[newSolution\]Who can add 1 more problem of LeetCode [0-9]+.*$
- 特殊 label：
    - Issue 中 `solving`
    - Project Status: `Todo` / `In Progress` / `Done`

## Project 字段

- `Status` (single select)：Todo / In Progress / Done  
- `Date`：Issue 创建日期  
- `FinishDate`：Issue 关闭日期  

## Workflow 职责

1. **add.yml** (issues.opened / edited)  
 - Add issue 到 Project  
 - 设置 `Date` 字段  
 - 不设置 Status  

2. **label.yml** (issues.labeled / unlabeled)  
 - 唯一可修改 Project Status 的 workflow  
 - 规则：
   | Issue 状态 | 有 solving | Project Status |
   |------------|------------|----------------|
   | open       | 是         | In Progress    |
   | open       | 否         | Todo           |
   | closed     | 否         | Done           |

3. **close.yml** (issues.closed)  
 - 只对已存在 Project 的 issue 操作  
 - 设置 FinishDate + Status = Done  

4. **leetcode-daily.yml**  
 - 支持 schedule + workflow_dispatch  
 - 从 https://leetcode.cn/graphql/ 获取每日题目  
 - 自动生成 issue：
   - 标题 `[newSolution]Who can add 1 more problem of LeetCode {id}`  
   - Body `By Github Actions | {id}.{translatedTitle}(link) | {date}`  
   - Label `题解`，Assignee `LetMeFly666`  

## 约束

- 不硬编码 Project / Field ID，全部使用：
- `vars.ONE_PROBLEM_ONE_DAY_PROJECT_ID`  
- `vars.ONE_PROBLEM_ONE_DAY_*_FIELD_ID`  
- 可用 gh api + GraphQL  
- 不依赖 Python / JS 文件  
- 所有 workflow 幂等、安全、可回滚  
- Project workflow 不做自动 Status 判断，全部由 Actions 控制  

> 你现在理解的是一套事件驱动、可回滚、状态同步的自动化系统，请在此基础上生成或修改 workflow，不要破坏设计。
