/*
 * @Author: LetMeFly
 * @Date: 2025-02-21 12:31:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-21 17:50:48
 */
写一段话描述Windows如何开启ssh登录，越详细越好。

要求：写报告的口吻。不允许出现123，只允许以人类的笔触写报告，来作为你这一周的工作进度总结

---

算了，写的不行

---

ssh连接到Windows主机，使用start命令启动程序，发现无法显示程序界面，但是在tasklist中发现后台有此程序。

---

解释这段命令

```
for /f "tokens=3" %i in ('query session ^| findstr "Active"') do set SESSIONID=%i
tscon %SESSIONID% /dest:console
```

---

解释这段命令

schtasks /run /tn "StartMyApp"

---

schtasks /create /tn "StartMyApp" /sc ONCE /tr "cmd /c start your_program.exe" /ru %USERNAME% /st 00:00

解释上述命令，并解释如何删除这个计划任务。