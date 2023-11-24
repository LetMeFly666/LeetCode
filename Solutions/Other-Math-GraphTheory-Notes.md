---
title: 图论笔记 - 极简极入门级
date: 2023-10-27 14:14:21
tags: [数学, 简单, 图论, Notes]
---

# 图论笔记 - 极简极入门级

## 图的概念

+ **环(loop, selfloop)** ：两个端点相同的边
+ **棱(link)** ：两个端点不同的边
+ **孤立点(isolated vertex)** ：不与任何顶点相邻的顶点
+ **简单图(simple graph)** ：无环，无重边的图
+ **平凡图(trival graph)** ：仅有一个顶点的图（可有多条环）
+ **空图(empty graph)/零图** ：没有边的图（注意：任何一图都有$V\neq \emptyset$）
+ **奇点(odd vertex)/偶点(even vertex)** ：度为奇/偶的点
+ **悬挂点(end vertex)/叶点(leaf)** ：度为1的顶点
+ **悬挂边(end edge)** ：悬挂点的关联边
+ **邻域(neighborhood)** ：点$u$相邻的点的集合称为点$u$的邻域，记作$N(u)$
+ **独立集(independent set)** ：若图$G$的顶点子集$V'(V'\subseteq V(G))$中任意两个顶点在图$G$中都互不相邻，则称$V'$为图$G$的独立集
+ 有向图的**基础图** ：将有向图每条边改为无向边得到的图
+ 无向图的**定向图** ：将无向图每条边改为有向边得到的图
+ 

记号：

+ $\mathcal{v}=|V(G)|$，$\varepsilon =|E(G)|$（点的个数、边的个数）
+ $\Delta(G)$：最大度；$\delta(G)$：最小度
+ $d^-(v)$：点$v$的入度；$d^+(v)$：点$v$的出度
+ $uv$一般指无向边，$<u, v>$一般指有向边        

## End

<center><font size="6px" face="Ink Free">The End, thanks!</font></center>

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/10/27/Other-Math-GraphTheory-Notes/)哦~
