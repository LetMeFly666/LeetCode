---
title: 服务器内存治理 - 从内存与日俱增到稳定运行 - 到底是哪里泄漏的内存
title_en: "From Memory Creep to Stability: A Deep Dive into Server Memory Leaks"
date: 2025-12-25 12:53:16
tags: [其他, 服务器, Linux, Django, Python]
categories: [技术思考]
---

# 服务器内存治理 - 从内存与日俱增到稳定运行 - 到底是哪里泄漏的内存

> From Memory Creep to Stability: A Deep Dive into Server Memory Leaks

## 背景

吾有一小服务器，大二时写的服务一直在上面运行。后续增增改改，转眼间五年过去。

之前服务器可能平均大约能运行个一百五十天，然后内存就会疯狂报警，再过2天左右会因内存占满而死机。

最近这种现象开始变得频繁，十来天甚至五天都可能遇到一次。是时候治理一下了。

## 内存监控

所有服务刚启动时，服务器资源总占用不到1G，光服务运行缓存之类的正常不至于增到内存占满，大概是存在着一些内存泄漏或者死进程。

于是思路是写个脚本监控下悄悄增加的内存有哪些。

```bash
TS=$(date +"%Y-%m-%d %H:%M:%S")
OUT="/var/log/let_proc_snapshot.log"

echo "===== $TS =====" >> "$OUT"
ps -eo pid,ppid,user,lstart,etimes,rss,comm,args --sort=-rss,ppid,pid >> "$OUT"
echo >> "$OUT"
```

保存为`WatchMem.sh`，然后

```bash
chmod +x WatchMem.sh
```

设置为定时任务，1分钟采样一次（其实不用这么频繁就行）

```bash
crontab -e
```

添加一行：

```
* * * * * /bin/bash -c '/xx/TFpath/WatchMem.sh'
```

会得到类似这样的日志：

```log
    PID    PPID USER                      STARTED ELAPSED   RSS COMMAND         COMMAND
   2020       1 mysql    Fri Dec 19 13:37:47 2025  250527 495552 mysqld         /usr/libexec/mysqld --basedir=/usr
```

不得不说服务器这次挺给力的，刚运行不到48h内存就增加了200M，是时候分析下了。

## 日志采样

决定直接丢给ChatGPT让帮忙分析一波，结果30多MB的纯文本数据过大，无法上传。

于是写了个日志采样脚本，只保留分钟数是5的倍数的日志：

```python
import re
from typing import Optional
from datetime import datetime

INPUT_FILE = "xx/let_proc_snapshot.log"
OUTPUT_FILE = "xx/proc_snapshot_5min.log"

# 匹配头部时间行
HEADER_RE = re.compile(r"^===== (.+) =====$")

def parse_time(line: str) -> Optional[datetime]:
    m = HEADER_RE.match(line.strip())
    if not m:
        return None
    return datetime.strptime(m.group(1), "%Y-%m-%d %H:%M:%S")

def should_keep(ts: datetime) -> bool:
    return ts.minute % 5 == 0

def main():
    with open(INPUT_FILE, "r", encoding="utf-8") as fin, \
         open(OUTPUT_FILE, "w", encoding="utf-8") as fout:

        block_lines = []
        block_time = None

        for line in fin:
            ts = parse_time(line)
            if ts:
                # 新 block 开始，先处理上一个
                if block_time and should_keep(block_time):
                    fout.writelines(block_lines)

                block_lines = [line]
                block_time = ts
            else:
                block_lines.append(line)

        # 文件结束，别忘了最后一个 block
        if block_time and should_keep(block_time):
            fout.writelines(block_lines)

    print(f"Resample done: {OUTPUT_FILE}")

if __name__ == "__main__":
    main()
```

文件体积变成了6M。

## 找到“元凶”

可能是AI的节能策略，GPT默认并没有分析日志文件，而是直接开始“猜测”可能原因。经过一轮对话的周折，AI一下就分析出来了。

进程中多了好几个`python manage.py crontab run xxxxx`，诶，说明很多定时任务没有退出。

一个python定时任务大约占用小50M内存，几个就占200M了。回到django目录运行`python manage.py crontab show`得知这个定时任务是我本科时候担任学校ACM集训队队长时，写的企业微信比赛提醒机器人。

脚本定时爬取比赛数据并在比赛即将开始时推送，比赛范围包括Codeforces、AtCoder等。

本科毕业已经几年过去，不知当时的机器人是否还有人在使用。但一看就能知道大概是外国这些网站HTTP请求阻塞了。

## 解决“元凶”

先杀掉所有被卡死的进程：

```bash
pkill -f "manage.py crontab run"
```

然后设置crontab最大执行时间：

```bash
crontab -e
```

在`*/5 * * * * timeout 60 python crontab run xxx`命令前面加个`timeout 60`变成`*/5 * * * * timeout 60 python crontab run xxx`，这样超时也会自动退出了。

## 不看不知道，一看吓一跳

看了看才知道，服务器中依然使用的几年前的命令，不适合用在开发环境的：

```bash
python manage.py runserver
```

赶紧改成了：

```bash
# pip install gunicorn
gunicorn ProjectName.wsgi:application --workers 2 --bind 127.0.0.1:8000 --max-requests 1000 --max-requests-jitter 100
```

## End

至此，本次治理暂时完结。

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156268688)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/25/Other-Server-MemoryGovernance/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)