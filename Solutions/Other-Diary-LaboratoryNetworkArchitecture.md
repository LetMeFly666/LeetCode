---
title: 日记 - 记录一次实验室(后几排)网络架构探究
date: 2024-09-03 09:54:30
tags: [日记, 网络]
categories: [技术思考]
---

# 日记 - 记录一次实验室(后几排)网络架构探究

## 前言

昨晚趁着夜深人静，大约从12点摸排到1点。~~才不是因为[Github@LetMeFly666/BYRBT_RyukawaChihiro@#14 (comment)](https://github.com/LetMeFly666/BYRBT_RyukawaChihiro/issues/14#issuecomment-2325041334)~~，方式是~~悄悄地临时小拔插~~

## 经过

实验室(科研楼426)有5大排，每排有两小排面对面，大约每一大排靠墙位置有一个交换机。

(门口视为第一排)第4排的交换机是由一根网线从第5排的交换机上引出的，第5排的交换机的网络来源是一根远古的埋在桌子里和墙边管子里的古老网线，且这跟网线并非来自第3排的交换机，暂未能获取齐来源。

大约半个月前我们后两排网在断开半小时左右后由千兆网变成百兆网了(并且非完全全双工，单测上传和下载都是百兆，但上传下载总计从未达到过150Mbps)，之后一直没有恢复。

入网水晶头有些老化但未看出异样，第3排是正常的千兆网。解决方案有二：

1. 更换入网水晶头。但正好昨天白天有同学整理实验室隔间，水晶头压制工具不知道放哪里了，怎么也找不到
2. 从第3排交换机引入一根千兆网线到第五排交换机，替换掉原有入网网线。找不到合适长度的现成网线（约6m），准备购置一根

## End

<center><font size="6px" face="Ink Free">The End, thanks!</font></center>

> 原文链接[https://blog.letmefly.xyz/2024/09/03/Other-Diary-LaboratoryNetworkArchitecture](https://blog.letmefly.xyz/2024/09/03/Other-Diary-LaboratoryNetworkArchitecture/)
