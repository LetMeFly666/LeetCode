---
title: 教资（教师资格证）学习笔记
date: 2023-06-24 11:39:09
tags: [其他, 知识, 教资, 教师资格证]
categories: [技术思考]
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

{% raw %}
<pre>
<code class="mermaid">
graph LR

a["职业理念"] --> b["教育观"]
a --> c["学生观"]
a --> d["教师观"]

click b href "#教育观" "教育观"
click c href "#学生观" "学生观"
click d href "#教师观" "教师观"
</code>
</pre>
{% endraw %}

### 教育观

{% raw %}
<pre>
<code class="mermaid">
graph LR

classDef white fill:white

jiaoyuguan["教育观"] --> a["素质教育的基本内涵（<b><span style='color: red'>必背</span></b>）"]
    a --> a1["<small>素质教育是</small><b>以<span style='color: red'>提</span>高国民<span style='color: red'>素</span>质为根本宗旨</b><small>的教育</small>"]
    a --> a2["<small>素质教育是</small><b>面向<span style='color: red'>全体</span>学生</b><small>的教育</small>"]
    a --> a3["<small>素质教育是</small><b>促进学生<span style='color: red'>全面</span>发展</b><small>的教育</small>"]
    a --> a4["<small>素质教育是</small><b>促进学生<span style='color: red'>个性</span>发展</b><small>的教育</small>"]
    a --> a5["<small>素质教育是</small><b>以培养学生的<span style='color: red'>创</span>新精神和实践能力为重点</b><small>的教育</small>"]
    a1 --> aa["提素个性创两全"]:::white
    a2 --> aa
    a3 --> aa
    a4 --> aa
    a5 --> aa
jiaoyuguan --> b["新课<span style='color: red'>改</span>下的教学观"]
    b --> b1["<small>教学从“</small><b>以教育者为中心</b><small>”向“</small><b><span style='color: red'>学</span>习者为中心</b><small>”<span style='color: #4079a0'>转变</span></small>"]
    b --> b2["<small>教学从“</small><b>教会学生知识</b><small>”向“</small><b>教会学生学<span style='color: red'>习</span></b><small>”<span style='color: #4079a0'>转变</span></small>"]
    b --> b3["<small>教学从“</small><b>重结论轻过程</b><small>”向“</small><b>重结论更重<span style='color: red'>过</span>程</b><small>”<span style='color: #4079a0'>转变</span></small>"]
    b --> b4["<small>教学从“</small><b>关注学科</b><small>”向“</small><b>关注<span style='color: red'>人</span></b><small>”<span style='color: #4079a0'>转变</span></small>"]
    b1 --> ba["学习过人/四个<span style='color: #4079a0'>转变</span>"]:::white
    b2 --> ba
    b3 --> ba
    b4 --> ba
</code>
</pre>
{% endraw %}

**答题模板**（学生观和教师观同样适用，记得审题，别答错了）

> 材料中老师的教育行为是正确的（错误的），遵循了（违背了）素质教育观的相关要求，值得我们学习（希望老师们引以为戒）。
>
> **首先**，素质教育观认为素质教育是面向全体学生的教育【观点】，人人都有受教育的权利，强调在教育中使每个人都得到发展。【一句话解释】材料中...。【引用材料】
>
> **其次**，素质教育观认为素质教育是促进学生全面发展的教育【观点】，实现学生德、智、体、美、劳等方面的全面发展。【一句话解释】材料中...。【引用材料】
>
> **最后**，素质教育观认为教学应从“以教育者为中心”转向“以学习者为中心”【观点】，鼓励学生参与教学，交给学生思维的方法。【一句话解释】材料中...。【引用材料】
>
> 综上所述，作为老师，我们应该做到面向全体学生、促进学生的全面发展。

### 学生观

{% raw %}
<pre>
<code class="mermaid">
graph LR

classDef white fill:white
classDef small fill:white, font-size:small, stroke:#f66, stroke-width:2px, stroke-dasharray: 5

xueshengguan["学生观"] --> a["学生是<span style='color: red'>独</span>立意义的人"]
    a --> a1["⭐学生具有个体独立性，不以教师的意志为转移"] --> bigEnd
        a1 -.- a12["尊重学生"]:::small
    a --> a2["⭐学生具有独立意义的主体，不以教师的意志为转移"] --> bigEnd
        a2 -.- a22["学生是学习的主人，教师起主导地位"]:::small
    a --> a3["学生是责权的主体"] --> bigEnd
        a3 -.- a32["责权与利益相统一"]:::small
xueshengguan --> b["学生是<span style='color: red'>独</span>特的人<small>(学生与学生不同，学生与成人不同)</small>"]
    b --> b1["⭐学生是完整的人"] --> bigEnd
    b --> b2["⭐每个学生都具有自身的独特性"] --> bigEnd
        b2 -.- b22["因材施教"]:::small
    b --> b3["⭐学生与成人之间存在着巨大的差异"] --> bigEnd
        b3 -.- b32["老师要换位思考"]:::small
xueshengguan --> c["学生是<span style='color: red'>发</span>展的人"]
    c --> c1["学生的身心发展是有规律的"] --> bigEnd
    c --> c2["⭐学生具有巨大的发展潜能"] --> bigEnd
        c2 -.- c22["可塑性"]:::small
    c --> c3["⭐学生是处于发展过程中的人"] --> bigEnd
        c3 -.- c32["容错性、包容性"]:::small
xueshengguan --> d["<span style='color: red'>全</span>面发展"]
    d --> d1["德智体美劳全面发展"] --> bigEnd
xueshengguan --> e["面向<span style='color: red'>全</span>体学生"]
    e --> e1["公平公正对待每个学生，不能偏爱某个学生"] --> bigEnd

bigEnd["两独一发 + 两全"]:::white
</code>
</pre>
{% endraw %}

### 教师观

{% raw %}
<pre>
<code class="mermaid">
graph LR

classDef white fill:white
classDef small fill:white, font-size:small, stroke:#f66, stroke-width:2px, stroke-dasharray: 5

jiaoshiguan["教师观"] --> a["教师<span style='color: red'>角色</span>的转变"]
    aend["建促放研(见醋放盐)"]:::white
    a --> a1["⭐ 教师是学生的引导者和发展的<span style='color: red'>促</span>进者"] --> aend
        a1 -.- a12("发现、探索、动手、做人"):::small
    a --> a2["⭐ 教师是课程的<span style='color: red'>建</span>设者和开发者"] --> aend
        a2 -.- a22["课本课程、开发课程"]:::small
    a --> a3["⭐ 教师是教育教学的<span style='color: red'>研</span>究者"] --> aend
        a3 -.- a32["研究问题、论文、课题等"]:::small
    a --> a4["教师是社区型的开<span style='color: red'>放</span>教师"] --> aend
        a4 -.- a42["从学校到社区（没考过）"]:::small
jiaoshiguan --> b["教师<span style='color: red'>行为</span>的转变"]
    bend["你它我她/赞助合反(赞助盒饭)"]:::white
    b --> b1["在对待<span style='color: blue'>师生</span>关系上，新课程强调尊重、<span style='color: red'>赞</span>赏"] --> bend
    b --> b2["在对待<span style='color: blue'>教学</span>上，新课程强调帮<span style='color: red'>助</span>、引导"] --> bend
        b2 -.- b22["学习方法、价值观"]:::small
    b --> b3["在对待自<span style='color: blue'>我</span>上，新课程强调<span style='color: red'>反</span>思"] --> bend
        b3 -.- b32["教学前、中、后都要反思"]:::small
    b --> b4["在对待与其<span style='color: blue'>他</span>教育者的关系上，新课程强调<span style='color: red'>合</span>作"] --> bend

</code>
</pre>
{% endraw %}

### 职业道德

{% raw %}
<pre>
<code class="mermaid">
graph LR

classDef white fill:white
classDef whiteWithNoBoard fill:white, stroke-width: 0px
classDef small fill:white, font-size:small, stroke:#f66, stroke-width:2px, stroke-dasharray: 5

zhiyedaode["教师职业道德规范"] --> a["<span style='color: red'>爱</span>国守法"]
    a-->a1["热爱祖国、热爱人民，拥护共产党和社会主义制度"]:::whiteWithNoBoard-->bigEnd
    a-->a2["遵守法律法规，依法履行教师的职责和权利"]:::whiteWithNoBoard-->bigEnd
    asmall["基本要求"]:::small-.-a
zhiyedaode-->b["⭐ <span style='color: red'>爱</span>岗敬业"]
    b-->b1["认真备课、上课、批改作业、辅导学生"]:::whiteWithNoBoard-->bigEnd
    b-->b2["勤恳敬业、乐于奉献"]:::whiteWithNoBoard-->bigEnd
    bsmall["本质要求"]:::small-.-b
zhiyedaode-->c["⭐ 关<span style='color: red'>爱</span>学生"]
    c-->c1["关爱全体学生、尊重学生人格、平等公正"]:::whiteWithNoBoard-->bigEnd
    c-->c2["严慈相济、良师益友"]:::whiteWithNoBoard-->bigEnd
    c-->c3["不体罚、不变相体罚、不讽刺、不挖苦、不歧视"]:::whiteWithNoBoard-->bigEnd
    csmall["道德灵魂"]:::small-.-c
zhiyedaode-->d["⭐ 教书育<span style='color: red'>人</span>"]
    d-->d1["素质教育"]:::whiteWithNoBoard-->bigEnd
    d-->d2["循循善诱、诲人不倦、因材施教"]:::whiteWithNoBoard-->bigEnd
    d-->d3["培养学生的良好品行、激发创造力、全面发展"]:::whiteWithNoBoard-->bigEnd
    d-->d4["不以分数作为评价学生的唯一标准"]:::whiteWithNoBoard-->bigEnd
    dsmall["天职、核心"]:::small-.-d
zhiyedaode-->e["⭐ 为<span style='color: red'>人</span>师表"]
    e-->e1["以身作则——服装、言谈举止"]:::whiteWithNoBoard-->bigEnd
    e-->e2["尊重理解加载"]:::whiteWithNoBoard-->bigEnd
    e-->e3["与同事合作"]:::whiteWithNoBoard-->bigEnd
    e-->e4["与金钱相关的<b>全部</b>Say No"]:::whiteWithNoBoard-->bigEnd
    esmall["内在要求"]:::small-.-e
zhiyedaode-->f["⭐ <span style='color: red'>终身</span>学习"]
    f-->f1["不断学习、钻研业务、勇于创新"]:::whiteWithNoBoard-->bigEnd
    f-->f2["提升自身能力（专业素养+教学水平）"]:::whiteWithNoBoard-->bigEnd
    fsmall["不竭动力"]:::small-.-f

bigEnd["三爱两人一终身"]:::white
</code>
</pre>
{% endraw %}

## 科目二

+ 打篮球属于教育

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/06/24/Other-JiaoZi-LearningNotes)哦~
> [https://blog.letmefly.xyz/2023/06/24/Other-JiaoZi-LearningNotes](https://blog.letmefly.xyz/2023/06/24/Other-JiaoZi-LearningNotes)