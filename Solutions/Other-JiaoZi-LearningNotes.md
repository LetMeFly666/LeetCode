---
title: 教资（教师资格证）学习笔记
date: 2023-06-24 11:39:09
tags: [其他, 知识, 教资, 教师资格证]
mermaid: true
---

# 教资

## 考试流程

笔试通过后有两年有效期，期间内通过面试就能拿证了。

中小学教资笔试分为三大部分（科目一、科目二、科目三），科目一（综合素质）和科目二（教育知识与能力）都一样且都要考，科目三（学科知识与教学能力）是报啥考啥（例如报的信息学就考计算机）。在有效期内，可以通过一次科目一科目二 和 数个不同科目的科目三，从而获取多个教师资格证。

## 题型介绍

**图例：**

```mermaid
graph TB
classDef green fill:#008b4c
a["绿色为必会题，复习性价比高"]:::green
b["橙色为随缘题，复习性价比低"]
style b fill:#ffba00
```

**科目一：综合素质**

```mermaid
graph LR

classDef green fill:#008b4c
classDef orange fill:#ffba00
classDef white fill:white

KeMu1[综合素质] --> KeGuanXuanZeTi["客观选择题（单选）29x2’=58’"]
    KeGuanXuanZeTi --> ZhiYeLiNian["职业理念"]:::green --> number01["4题"]:::white
    KeGuanXuanZeTi --> JiaoYuFaLvFaGui["教育法律法规"]:::green --> number02["8题"]:::white
    KeGuanXuanZeTi --> ZhiYeDaoDe["职业道德"]:::green --> number03["4题"]:::white
    KeGuanXuanZeTi --> WenHuaSuYang["文化素养"]:::orange --> number04["9题"]:::white
    KeGuanXuanZeTi --> JiBenNengLi["基本能力"]:::orange --> number05["4题"]:::white
KeMu1 --> CaiLiaoFenXiTi["材料分析题 3x14’=42’"]:::green
    CaiLiaoFenXiTi --> ZhiYeLiNian2["职业理念"]:::orange --> number06["1题"]:::white
    CaiLiaoFenXiTi --> ZhiYeDaoDe2["职业道德"]:::orange --> number07["1题"]:::white
    CaiLiaoFenXiTi --> YueDuLiJie["阅读理解"]:::orange --> number08["1题"]:::white
KeMu1 --> ZuoWen["作文 1x50’=50’"]:::orange
    ZuoWen --> number09["1题"]:::white --> ZuoWenMoreInfo["最简单稳妥的写作方式：和教育挂钩"]
```

**科目二：教育知识与能力**

```mermaid
graph LR

classDef green fill:#008b4c
classDef orange fill:#ffba00
classDef white fill:white
classDef blue1 fill:#00a0f4
classDef pink fill:pink
classDef green1 fill:#008498

KeMu2["教育知识与能力"] --> KeGuanXuanZeTi["客观选择题（单选）21x2’=42’"]
    KeGuanXuanZeTi --> a0["教育基础知识和基本原理"] --> a1["5题"]:::white
    KeGuanXuanZeTi --> a2["中学课程"] --> a3["2题"]:::white
    KeGuanXuanZeTi --> a4["中学教学"] --> a5["3题"]:::white
    KeGuanXuanZeTi --> a6["中学生学习心理"] --> asf["2题"]:::white
    KeGuanXuanZeTi --> a434["中学生发展心理"] --> a66567["2题"]:::white
    KeGuanXuanZeTi --> a245["中学生心理辅导"] --> asfa1["1题"]:::white
    KeGuanXuanZeTi --> a56["中学德育"] --> a23f["2题"]:::white
    KeGuanXuanZeTi --> afds["中学班级管理与教师心理"] --> as3f["4题"]:::white
KeMu2 --> BianXiTi["辨析题 4x8’=32’"]
    BianXiTi --> ljw["教育基础知识和基本原理"]:::blue1 --> ba1["1题"]:::white
    BianXiTi --> l32jw["中学教育"]:::pink --> asf11["1题"]:::white
    BianXiTi --> jlf["中学生学习心理"]:::green1 --> a41a1["2题"]:::white
KeMu2 --> JianDaTi["简答题 4x1’=42’"]
    JianDaTi --> jwi13["教育基础知识和基本原理"]:::blue1 --> oa1["1题"]:::white
    JianDaTi --> jw2i13["中学教育"]:::pink --> ha1["1题"]:::white
    JianDaTi --> jw2i1["中学生发展心理"] --> gha1["1题"]:::white
    JianDaTi --> ji13["中学生辅导心理"] --> ma1["1题"]:::white
KeMu2 --> CaiLiaoFenXiTi["材料分析题 2x18’=36’"]
    CaiLiaoFenXiTi --> j038h["中学生学习心理"]:::green1 --> pbga1["1题"]:::white
    CaiLiaoFenXiTi --> j38h["中学生德育"] --> a1hd["1题"]:::white
```

```mermaid
graph LR

classDef white fill:white
classDef blue1 fill:#00a0f4
classDef pink fill:pink
classDef green1 fill:#008498

a["（科二）各模块分支权重"]
   a --> b["中学生学习心理"]:::green1 --> c["25%"]:::white
   a --> d["教育基础知识与基本原理"]:::blue1 --> p["19%"]:::white
   a --> m["中学教育"]:::pink --> o["16%"]:::white
   a --> f["中学德育"] --> i["15%"]:::white
   a --> g["中学生发展心理"] --> u["9%"]:::white
   a --> q["中学生心理辅导"] --> y["8%"]:::white
   a --> w["中学班级管理与教师心理"] --> t["5%"]:::white
   a --> e["中学课程"] --> r["3%"]:::white
```

**科目三：学科知识与教学能力**

```mermaid
graph LR

classDef white fill:white

a["学科知识与教学能力"] --> b["客观选择题（单选）30x2’=60’"]
a --> c["简答题 1x20’=20’"]
a --> d["教学情境分析题 1x30’=30’"]
a --> e["教学设计题 1x40’=40’"]
```

## 科目一

<style>
    red {
        color: red;
    }
</style>

```mermaid
graph LR

a["职业理念"] --> b["教育观"]
a --> c["学生观"]
a --> d["教师观"]
```

```mermaid
graph LR

jiaoyuguan["教育观"] --> a["素质教育的基本内涵（<b><red>必备</red></b>）"]
    a --> a1["<small>素质教育是</small><b>以<red>提</red>高国民<red>素</red>质为根本宗旨</b><small>的教育</small>"]
    a --> a2["<small>素质教育是</small><b>面向<red>全体</red>学生</b><small>的教育</small>"]
    a --> a3["<small>素质教育是</small><b>促进学生<red>全面</red>发展</b><small>的教育</small>"]
    a --> a4["<small>素质教育是</small><b>促进学生<red>个性</red>发展</b><small>的教育</small>"]
    a --> a5["<small>素质教育是</small><b>以培养学生的<red>创</red>新精神和实践能力为重点</b><small>的教育</small>"]
jiaoyuguan --> b["新课改下的教学观"]
```

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/06/24/Other-JiaoZi-LearningNotes)哦~
> [https://blog.tisfy.eu.org/2023/06/24/Other-JiaoZi-LearningNotes](https://blog.tisfy.eu.org/2023/06/24/Other-JiaoZi-LearningNotes)