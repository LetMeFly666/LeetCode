---
title: Linux - 内存相关 - 减小Mysql的内存占用 or 查看内存使用情况
date: 2023-02-20 08:56:33
tags: [其他, Linux, MySQL, 内存]
---

# 减小Mysql在Linux的内存占用

## 前言

之前在阿里云租的服务器上跑有一些东西，之前在上面通过FFmpeg进行OpenCV合成的视频的推流时，可能会由于内存占满而照成服务器无响应。

分析了内存占用后，决定减小Mysql的内存占用（因为我服务器上的Mysql使用量不大，小站没有那么多的数据）

## Linux查看系统占用前10

PS：下面指令可以查看Linux的内存占用前10：

```bash
ps aux|head -1;ps aux|sort -rn -k4|head -10
```

下面指令可以查看Linux的CPU占用前10

```bash
ps aux|head -1;ps aux|sort -rn -k3|head -10
```

**解释：**

```ps aux|head -1;ps aux|sort -rn -k3|head -10```相当于```ps aux|head -1```和```ps aux|sort -rn -k3|head -10```分别执行

**ps**

其中```ps```的参数```a```代表“所有进程(all with tty, including other users)”，```u```代表“user(user-oriented format)”，```x```代表“显示所有进程(processes without controlling ttys)”

那么```ps aux```就显示了所有进程的资源占用信息：

```bash
[Tisfy@LetMeFly ~]# ps aux
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.0  0.3 250788  6128 ?        Ss    2022  10:08 /usr/lib/systemd/systemd --switched-root --system --d
root           2  0.0  0.0      0     0 ?        S     2022   0:02 [kthreadd]
root           3  0.0  0.0      0     0 ?        I<    2022   0:00 [rcu_gp]
root           4  0.0  0.0      0     0 ?        I<    2022   0:00 [rcu_par_gp]
root           6  0.0  0.0      0     0 ?        I<    2022   0:00 [kworker/0:0H-kblockd]
(以下省略)
```

**head**

```head```命令用于显示前几行。```head -1```就是显示第一行的内容，也就是

```
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
```

同理，```head -10```就是显示前10行

**sort**

```sort```命令用于排序，```-r```是“从大到小排序(reverse the result of comparisons)”默认从小到大，```-n```是“根据数值排序(compare according to string numerical value)”，```-k```是“以第几列为依据进行排序(sort via a key; KEYDEF gives location and type)”（下标从1开始，没有-k0）

## How to do

我修改了Mysql的配置文件（文件路径：```/etc/my.conf```）

可以修改或在下方添加这些参数。参数的具体意义可以在网上搜索

```yml
#
# This group is read both both by the client and the server
# use it for options that affect everything
#
[client-server]

#
# include all files from the config directory
#
!includedir /etc/my.cnf.d

[mysqld]
key_buffer_size = 8M
table_open_cache = 4
sort_buffer_size = 64K
read_buffer_size = 256K
read_rnd_buffer_size = 256K
net_buffer_length = 2K
thread_stack = 240K
table_definition_cache = 400
```

PS，今日添加了table_definition_cache，内存占用大概降低了5%（2G × 5% ≈ 100M）

> 若Mysql增删改查频率较高则不建议随意修改。

2023.4.3更：有时重启一下MySQL服务也是个不错的选择

## Linux查看内存占用

```bash
free
```

其中```free -m```是以M形式显示（显示多少M），```free -g```是以G的形式显示（1.7G会显示为1G哈哈）

**对于我的服务器**，MySQL大约会使用300M，远程VSCode在有连接时大约会使用160M，无连接时大约会使用70M，django项目每个约70M，nginx大约会使用5M

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/02/20/Other-Linux-MysqlMemReduce/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129120029](https://letmefly.blog.csdn.net/article/details/129120029)