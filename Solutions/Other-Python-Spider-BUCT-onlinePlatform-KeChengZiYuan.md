---
title: Python爬虫无需鉴权下载北化在线平台的“课程资源”
date: 2022-12-04 15:56:46
tags: [其他, Python, 中等, 爬虫, 北化, 北京化工大学, BUCT, 深度优先搜索, DFS]
---

最近百❀给19计科同学又安排了一门YiYanNanJin的课，考研冲刺20天时需要自学这门课的那种。

老师让其研究生把自学资源放到了北化在线平台，老师也将录制好的视频放在了BiliBili上。

这门课将“自学”写入了教学大纲，但北化在线平台的PDF预览效果，，，，，。。。超级糊。

在线平台把PDF渲染成图片并展示到页面上，但渲染效果真的不咋滴。

研究生将PDF“加密上传”了，同学只有在线浏览权限而没有下载权限。

这点老师是为了防止自己的课件被“广泛传播”，非常理解。

但是在线效果又很差，之前修改```url```直接越权下载的方法被修复了。

> 之前，对于任何在线文件，例如文件的在线浏览页面是```https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929762&resid=391905&lid=28271```，那么此文件的下载地址即为```https://course.buct.edu.cn/meol/common/script/download.jsp?fileid=3929762&resid=391905&lid=28271```（把两个```preview```和其中第二个```preview```前面的```_```去掉即可）
> 现在下载地址也是，但是平台在下载前增加了鉴权机制，老师设置禁止下载的话平台会返回“禁止下载页面”，而不是之前的无脑返回原文件

但是我发现```PDF```渲染前的地址无鉴权处理，并且“课程资源”页面也无鉴权处理。

也就是说，无论是谁（未在非校园网环境下测试，但推测无需校园网环境），无需登录，就能访问“课程资源”，获取资源目录结构（类似Windows文件系统），获取PDF原始地址，并进行下载。

因此，一个深度优先搜索就搞定了。


```python
'''
Author: LetMeFly
Date: 2022-12-04 14:27:36
LastEditors: LetMeFly
LastEditTime: 2022-12-04 15:51:53
'''
# 递归遍历下载 北化在线平台 的 计算机系统综合设计 的 课程资源 的 PDF文件
import os
import requests
from bs4 import BeautifulSoup

BASEURL = "https://course.buct.edu.cn/meol/common/script/"
didnotDownload = []


def download(filePath, url):
    totalURL = BASEURL + url
    print("访问页面：", totalURL)
    response = requests.get(totalURL)
    soup = BeautifulSoup(response.content, "lxml")
    h2 = soup.find("h2")
    p = h2.next_sibling
    span = p.find("span")
    fileName = span.get_text().strip()
    if fileName.endswith(".pdf"):
        downloadURL = "https://course.buct.edu.cn/meol/analytics/resPdfShow.do?" + (totalURL.split("?")[1].replace("resid", "resId"))
        totalName = os.path.join(filePath, fileName)
        print(f"正在下载：{totalName}({downloadURL})")
        fileResponse = requests.get(downloadURL)
        with open(totalName, "wb") as f:
            f.write(fileResponse.content)
    else:
        didnotDownload.append(totalURL)



def dfs(nowPath, nowURL):
    if not os.path.exists(nowPath):
        print("创建文件夹：", nowPath)
        os.mkdir(nowPath)
    totalURL = BASEURL + nowURL
    print("访问页面：", totalURL)
    response = requests.get(totalURL)
    soup = BeautifulSoup(response.content, "lxml")
    table = soup.find("table")
    trs = table.find_all("tr")
    for tr in trs:
        a = tr.find("a")
        if not a:
            continue
        newURL = a.get("href")
        newName = a.get_text().strip()
        if "listview" in newURL:
            dfs(
                nowPath=os.path.join(nowPath, newName),
                nowURL=newURL
            )
        else:
            download(nowPath, newURL)
    

dfs(
    nowPath="计算机系统结构",
    nowURL="listview.jsp?acttype=enter&folderid=391903&lid=28271"
)

print("PDF下载完毕，其它未下载：", didnotDownload)
```

执行结果：

```
PS F:\OtherApps\Program\VsCode\Code\系统结构> ls


    目录: F:\OtherApps\Program\VsCode\Code\系统结构


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----         2022/12/4     15:52           2070 main.py


PS F:\OtherApps\Program\VsCode\Code\系统结构> python main.py
创建文件夹： 计算机系统结构
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391903&lid=28271
创建文件夹： 计算机系统结构\第1章 微型计算机系统导论
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391904&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929762&resid=391905&lid=28271
正在下载：计算机系统结构\第1章 微型计算机系统导论\第1章 微型计算机系统导论——1微型计算机的概念.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929762&resId=391905&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929765&resid=391906&lid=28271
正在下载：计算机系统结构\第1章 微型计算机系统导论\第1章 微型计算机系统导论——2计算机发展历史.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929765&resId=391906&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929767&resid=391907&lid=28271
正在下载：计算机系统结构\第1章 微型计算机系统导论\第1章 微型计算机系统导论——3主流的计算机架构.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929767&resId=391907&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929769&resid=391908&lid=28271
正在下载：计算机系统结构\第1章 微型计算机系统导论\第1章 微型计算机系统导论——4龙芯处理器基础知识.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929769&resId=391908&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929770&resid=391909&lid=28271
正在下载：计算机系统结构\第1章 微型计算机系统导论\第1章 微型计算机系统导论——5龙芯1B处理器的构成要素.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929770&resId=391909&lid=28271)
创建文件夹： 计算机系统结构\第2章 数值的表示和运算
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391910&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929788&resid=391911&lid=28271
正在下载：计算机系统结构\第2章 数值的表示和运算\第2章 数值的表示和运算——1数的十进制表示方法.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929788&resId=391911&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929789&resid=391912&lid=28271
正在下载：计算机系统结构\第2章 数值的表示和运算\第2章 数值的表示和运算——2整数的二进制表示及运算.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929789&resId=391912&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929790&resid=391913&lid=28271
正在下载：计算机系统结构\第2章 数值的表示和运算\第2章 数值的表示和运算——3小数的二进制表示及运算.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929790&resId=391913&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929792&resid=391914&lid=28271
正在下载：计算机系统结构\第2章 数值的表示和运算\第2章 数值的表示和运算——4十六进制和八进制数的表示方法.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929792&resId=391914&lid=28271)
创建文件夹： 计算机系统结构\第3章 存储器的分类和原理
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391915&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929793&resid=391916&lid=28271
正在下载：计算机系统结构\第3章 存储器的分类和原理\第2章 数值的表示和运算——1数的十进制表示方法.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929793&resId=391916&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929795&resid=391917&lid=28271
正在下载：计算机系统结构\第3章 存储器的分类和原理\第2章 数值的表示和运算——2整数的二进制表示及运算.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929795&resId=391917&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929797&resid=391918&lid=28271
正在下载：计算机系统结构\第3章 存储器的分类和原理\第2章 数值的表示和运算——3小数的二进制表示及运算.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929797&resId=391918&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929803&resid=391919&lid=28271
正在下载：计算机系统结构\第3章 存储器的分类和原理\第2章 数值的表示和运算——4十六进制和八进制数的表示方法.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929803&resId=391919&lid=28271)
创建文件夹： 计算机系统结构\第4章 软件开发工具的下载、安装和使用
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391920&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929805&resid=391921&lid=28271
正在下载：计算机系统结构\第4章 软件开发工具的下载、安装和使用\第4章 软件开发工具的下载、安装和使用——1软件开发工具的介绍.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929805&resId=391921&lid=28271)
创建文件夹： 计算机系统结构\第5章 MIPS32指令集架构
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391922&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929810&resid=391923&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——1字节顺序和端.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929810&resId=391923&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929813&resid=391924&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——2指令的基本概念.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929813&resId=391924&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929815&resid=391925&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——3MIPS指令架构的发展和特征.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929815&resId=391925&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929816&resid=391926&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——4MIPS寄存器集.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929816&resId=391926&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929817&resid=391927&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——5指令类型和寻址模式.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929817&resId=391927&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929819&resid=391928&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——6.1算术类指令.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929819&resId=391928&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929822&resid=391929&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——6.2位移类指令.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929822&resId=391929&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929823&resid=391930&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——6.3逻辑指令.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929823&resId=391930&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929824&resid=391931&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——6.4移动指令.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929824&resId=391931&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929825&resid=391932&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——6.5加载和保存指令.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929825&resId=391932&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929826&resid=391933&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——6.6指令控制指令.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929826&resId=391933&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929832&resid=391935&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——6.7分支和跳转指令.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929832&resId=391935&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929833&resid=391936&lid=28271
正在下载：计算机系统结构\第5章 MIPS32指令集架构\第5章 MIPS32指令集架构——6.8陷阱指令.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929833&resId=391936&lid=28271)
创建文件夹： 计算机系统结构\第6章 中央处理单元的架构
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391937&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929841&resid=391944&lid=28271
正在下载：计算机系统结构\第6章 中央处理单元的架构\第6章 中央处理单元的架构——1冯诺依曼结构和哈佛结构.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929841&resId=391944&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929842&resid=391945&lid=28271
正在下载：计算机系统结构\第6章 中央处理单元的架构\第6章 中央处理单元的架构——2存储器系统的分层结构和访问类型.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929842&resId=391945&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929855&resid=391946&lid=28271
正在下载：计算机系统结构\第6章 中央处理单元的架构\第6章 中央处理单元的架构——3龙芯处理器高速缓存的映射及管理.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929855&resId=391946&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929857&resid=391947&lid=28271
正在下载：计算机系统结构\第6章 中央处理单元的架构\第6章 中央处理单元的架构——4存储器管理单元的结构和管理.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929857&resId=391947&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929861&resid=391948&lid=28271
正在下载：计算机系统结构\第6章 中央处理单元的架构\第6章 中央处理单元的架构——5GS232处理器内核原理和关键技术.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929861&resId=391948&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929862&resid=391949&lid=28271
正在下载：计算机系统结构\第6章 中央处理单元的架构\第6章 中央处理单元的架构——6处理器系统的地址分配和映射.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929862&resId=391949&lid=28271)
创建文件夹： 计算机系统结构\第7章 协处理器架构
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391938&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929878&resid=391956&lid=28271
正在下载：计算机系统结构\第7章 协处理器架构\第7章 协处理器架构——1协处理器CP0的功能.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929878&resId=391956&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929879&resid=391957&lid=28271
正在下载：计算机系统结构\第7章 协处理器架构\第7章 协处理器架构——2协处理器中的控制寄存器.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929879&resId=391957&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929880&resid=391958&lid=28271
正在下载：计算机系统结构\第7章 协处理器架构\第7章 协处理器架构——3协处理器指令格式和功能.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929880&resId=391958&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929882&resid=391959&lid=28271
正在下载：计算机系统结构\第7章 协处理器架构\第7章 协处理器架构——4协处理器0操作实例.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929882&resId=391959&lid=28271)
创建文件夹： 计算机系统结构\第8章 汇编语言程序设计和实现
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391939&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929883&resid=391960&lid=28271
正在下载：计算机系统结构\第8章 汇编语言程序设计和实现\第8章 汇编语言程序设计和实现——1汇编语言程序框架.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929883&resId=391960&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929885&resid=391961&lid=28271
正在下载：计算机系统结构\第8章 汇编语言程序设计和实现\第8章 汇编语言程序设计和实现——2汇编语言语法格式.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929885&resId=391961&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929886&resid=391962&lid=28271
正在下载：计算机系统结构\第8章 汇编语言程序设计和实现\第8章 汇编语言程序设计和实现——3伪指令的格式和功能.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929886&resId=391962&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929887&resid=391963&lid=28271
正在下载：计算机系统结构\第8章 汇编语言程序设计和实现\第8章 汇编语言程序设计和实现——4MIPS相关特性.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929887&resId=391963&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929888&resid=391964&lid=28271
正在下载：计算机系统结构\第8章 汇编语言程序设计和实现\第8章 汇编语言程序设计和实现——5链接脚本文件.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929888&resId=391964&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929889&resid=391965&lid=28271
正在下载：计算机系统结构\第8章 汇编语言程序设计和实现\第8章 汇编语言程序设计和实现——6汇编语言实例一_冒泡排序的实现和分析.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929889&resId=391965&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929891&resid=391966&lid=28271
正在下载：计算机系统结构\第8章 汇编语言程序设计和实现\第8章 汇编语言程序设计和实现——7汇编语言实例二_通用输入和输出端口的驱动.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929891&resId=391966&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929892&resid=391967&lid=28271
正在下载：计算机系统结构\第8章 汇编语言程序设计和实现\第8章 汇编语言程序设计和实现——8汇编语言实例三_看门狗定时器的应用.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929892&resId=391967&lid=28271)
创建文件夹： 计算机系统结构\第9章 中断和异常原理及实现
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391940&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929893&resid=391968&lid=28271
正在下载：计算机系统结构\第9章 中断和异常原理及实现\第9章 中断和异常原理及实现——1基本概念.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929893&resId=391968&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929894&resid=391969&lid=28271
正在下载：计算机系统结构\第9章 中断和异常原理及实现\第9章 中断和异常原理及实现——2中断原理.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929894&resId=391969&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929896&resid=391970&lid=28271
正在下载：计算机系统结构\第9章 中断和异常原理及实现\第9章 中断和异常原理及实现——3异常原理.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929896&resId=391970&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929897&resid=391971&lid=28271
正在下载：计算机系统结构\第9章 中断和异常原理及实现\第9章 中断和异常原理及实现——4中断触发和处理的实现.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929897&resId=391971&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929899&resid=391972&lid=28271
正在下载：计算机系统结构\第9章 中断和异常原理及实现\第9章 中断和异常原理及实现——5定时器原理及中断的实现.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929899&resId=391972&lid=28271)
创建文件夹： 计算机系统结构\第10章  C语言的程序设计和分析
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391941&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929900&resid=391973&lid=28271
正在下载：计算机系统结构\第10章  C语言的程序设计和分析\第10章  C语言的程序设计和分析——1基本数据类型的表示.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929900&resId=391973&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929902&resid=391974&lid=28271
正在下载：计算机系统结构\第10章  C语言的程序设计和分析\第10章  C语言的程序设计和分析——2基本数据类型的扩展.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929902&resId=391974&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929907&resid=391975&lid=28271
正在下载：计算机系统结构\第10章  C语言的程序设计和分析\第10章  C语言的程序设计和分析——3复杂数据类型的表示.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929907&resId=391975&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929908&resid=391976&lid=28271
正在下载：计算机系统结构\第10章  C语言的程序设计和分析\第10章  C语言的程序设计和分析——4描述语句.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929908&resId=391976&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929912&resid=391977&lid=28271
正在下载：计算机系统结构\第10章  C语言的程序设计和分析\第10章  C语言的程序设计和分析——5函数的调用与返回.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929912&resId=391977&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929913&resid=391978&lid=28271
正在下载：计算机系统结构\第10章  C语言的程序设计和分析\第10章  C语言的程序设计和分析——6内嵌汇编.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929913&resId=391978&lid=28271)
创建文件夹： 计算机系统结构\第11章 异步串口原理和通信的实现
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391942&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929914&resid=391979&lid=28271
正在下载：计算机系统结构\第11章 异步串口原理和通信的实现\第11章 异步串口原理和通信的实现——1RS-232协议规范.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929914&resId=391979&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929915&resid=391980&lid=28271
正在下载：计算机系统结构\第11章 异步串口原理和通信的实现\第11章 异步串口原理和通信的实现——2龙芯1B处理器中UART模块原理.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929915&resId=391980&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929916&resid=391981&lid=28271
正在下载：计算机系统结构\第11章 异步串口原理和通信的实现\第11章 异步串口原理和通信的实现——3PuTTY工具的下载和安装.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929916&resId=391981&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929917&resid=391982&lid=28271
正在下载：计算机系统结构\第11章 异步串口原理和通信的实现\第11章 异步串口原理和通信的实现——4串口重定位的设计与实现.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929917&resId=391982&lid=28271)
创建文件夹： 计算机系统结构\研电赛设计（仅供参考）
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=391943&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929919&resid=391983&lid=28271
正在下载：计算机系统结构\研电赛设计（仅供参考）\北京化工大学_406yyds_基于龙芯1B处理器构建面向智能物联网应用的计算机系统平台.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=3929919&resId=391983&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=3929921&resid=391984&lid=28271
3929921&resId=391984&lid=28271)
创建文件夹： 计算机系统结构\2022.12.04补充资料
访问页面： https://course.buct.edu.cn/meol/common/script/listview.jsp?acttype=enter&folderid=392981&lid=28271
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=4016463&resid=392983&lid=28271
正在下载：计算机系统结构\2022.12.04补充资料\David M. Harris, Sarah L. Harris - Digital Design and Computer Architecture, (2012, Morgan Kaufmann).pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=4016463&resId=392983&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=4016474&resid=392984&lid=28271
正在下载：计算机系统结构\2022.12.04补充资料\第1章 Codescape下载安装和使用指南.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=4016474&resId=392984&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=4016479&resid=392985&lid=28271
正在下载：计算机系统结构\2022.12.04补充资料\第6章 单周期MIPS系统的设计和验证.pdf(https://course.buct.edu.cn/meol/analytics/resPdfShow.do?fileid=4016479&resId=392985&lid=28271)
访问页面： https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=4016488&resid=392986&lid=28271
PDF下载完毕，其它未下载： ['https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=4016488&resid=392986&lid=28271']
PS F:\OtherApps\Program\VsCode\Code\系统结构> tree /F
卷 新加卷 的文件夹 PATH 列表
卷序列号为 E4B6-492F
F:.
│  main.py
│
└─计算机系统结构
    ├─2022.12.04补充资料
    │      David M. Harris, Sarah L. Harris - Digital Design and Computer Architecture, (2012, Morgan Kaufmann).pdf
    │      第1章 Codescape下载安装和使用指南.pdf
    │      第6章 单周期MIPS系统的设计和验证.pdf
    │
    ├─研电赛设计（仅供参考）
    │      北京化工大学_406yyds_基于龙芯1B处理器构建面向智能物联网应用的计算机系统平台.pdf
    │      第十七届中国研究生电子设计竞赛技术论文.pdf
    │
    ├─第10章  C语言的程序设计和分析
    │      第10章  C语言的程序设计和分析——1基本数据类型的表示.pdf
    │      第10章  C语言的程序设计和分析——2基本数据类型的扩展.pdf
    │      第10章  C语言的程序设计和分析——3复杂数据类型的表示.pdf
    │      第10章  C语言的程序设计和分析——4描述语句.pdf
    │      第10章  C语言的程序设计和分析——5函数的调用与返回.pdf
    │      第10章  C语言的程序设计和分析——6内嵌汇编.pdf
    │
    ├─第11章 异步串口原理和通信的实现
    │      第11章 异步串口原理和通信的实现——1RS-232协议规范.pdf
    │      第11章 异步串口原理和通信的实现——2龙芯1B处理器中UART模块原理.pdf
    │      第11章 异步串口原理和通信的实现——3PuTTY工具的下载和安装.pdf
    │      第11章 异步串口原理和通信的实现——4串口重定位的设计与实现.pdf
    │
    ├─第1章 微型计算机系统导论
    │      第1章 微型计算机系统导论——1微型计算机的概念.pdf
    │      第1章 微型计算机系统导论——2计算机发展历史.pdf
    │      第1章 微型计算机系统导论——3主流的计算机架构.pdf
    │      第1章 微型计算机系统导论——4龙芯处理器基础知识.pdf
    │      第1章 微型计算机系统导论——5龙芯1B处理器的构成要素.pdf
    │
    ├─第2章 数值的表示和运算
    │      第2章 数值的表示和运算——1数的十进制表示方法.pdf
    │      第2章 数值的表示和运算——2整数的二进制表示及运算.pdf
    │      第2章 数值的表示和运算——3小数的二进制表示及运算.pdf
    │      第2章 数值的表示和运算——4十六进制和八进制数的表示方法.pdf
    │
    ├─第3章 存储器的分类和原理
    │      第2章 数值的表示和运算——1数的十进制表示方法.pdf
    │      第2章 数值的表示和运算——2整数的二进制表示及运算.pdf
    │      第2章 数值的表示和运算——3小数的二进制表示及运算.pdf
    │      第2章 数值的表示和运算——4十六进制和八进制数的表示方法.pdf
    │
    ├─第4章 软件开发工具的下载、安装和使用
    │      第4章 软件开发工具的下载、安装和使用——1软件开发工具的介绍.pdf
    │
    ├─第5章 MIPS32指令集架构
    │      第5章 MIPS32指令集架构——1字节顺序和端.pdf
    │      第5章 MIPS32指令集架构——2指令的基本概念.pdf
    │      第5章 MIPS32指令集架构——3MIPS指令架构的发展和特征.pdf
    │      第5章 MIPS32指令集架构——4MIPS寄存器集.pdf
    │      第5章 MIPS32指令集架构——5指令类型和寻址模式.pdf
    │      第5章 MIPS32指令集架构——6.1算术类指令.pdf
    │      第5章 MIPS32指令集架构——6.2位移类指令.pdf
    │      第5章 MIPS32指令集架构——6.3逻辑指令.pdf
    │      第5章 MIPS32指令集架构——6.4移动指令.pdf
    │      第5章 MIPS32指令集架构——6.5加载和保存指令.pdf
    │      第5章 MIPS32指令集架构——6.6指令控制指令.pdf
    │      第5章 MIPS32指令集架构——6.7分支和跳转指令.pdf
    │      第5章 MIPS32指令集架构——6.8陷阱指令.pdf
    │
    ├─第6章 中央处理单元的架构
    │      第6章 中央处理单元的架构——1冯诺依曼结构和哈佛结构.pdf
    │      第6章 中央处理单元的架构——2存储器系统的分层结构和访问类型.pdf
    │      第6章 中央处理单元的架构——3龙芯处理器高速缓存的映射及管理.pdf
    │      第6章 中央处理单元的架构——4存储器管理单元的结构和管理.pdf
    │      第6章 中央处理单元的架构——5GS232处理器内核原理和关键技术.pdf
    │      第6章 中央处理单元的架构——6处理器系统的地址分配和映射.pdf
    │
    ├─第7章 协处理器架构
    │      第7章 协处理器架构——1协处理器CP0的功能.pdf
    │      第7章 协处理器架构——2协处理器中的控制寄存器.pdf
    │      第7章 协处理器架构——3协处理器指令格式和功能.pdf
    │      第7章 协处理器架构——4协处理器0操作实例.pdf
    │      
    ├─第8章 汇编语言程序设计和实现
    │      第8章 汇编语言程序设计和实现——1汇编语言程序框架.pdf
    │      第8章 汇编语言程序设计和实现——2汇编语言语法格式.pdf
    │      第8章 汇编语言程序设计和实现——3伪指令的格式和功能.pdf
    │      第8章 汇编语言程序设计和实现——4MIPS相关特性.pdf
    │      第8章 汇编语言程序设计和实现——5链接脚本文件.pdf
    │      第8章 汇编语言程序设计和实现——6汇编语言实例一_冒泡排序的实现和分析.pdf
    │      第8章 汇编语言程序设计和实现——7汇编语言实例二_通用输入和输出端口的驱动.pdf
    │      第8章 汇编语言程序设计和实现——8汇编语言实例三_看门狗定时器的应用.pdf
    │
    └─第9章 中断和异常原理及实现
            第9章 中断和异常原理及实现——1基本概念.pdf
            第9章 中断和异常原理及实现——2中断原理.pdf
            第9章 中断和异常原理及实现——3异常原理.pdf
            第9章 中断和异常原理及实现——4中断触发和处理的实现.pdf
            第9章 中断和异常原理及实现——5定时器原理及中断的实现.pdf
```

这种方法的原理是：

> 既然在线平台是将从后端获取到的完整的PDF渲染后显示到前端，那么我们直接访问PDF的原始地址即可。

因此，只支持PDF格式的文件的下载。

正如运行结果的最后一行：

```
PDF下载完毕，其它未下载： ['https://course.buct.edu.cn/meol/common/script/preview/download_preview.jsp?fileid=4016488&resid=392986&lid=28271']
```

这是一个压缩包，因此未下载

这么做仅仅是为了方便**自己**看到更好效果的PDF，无违老师“防止课件被乱传”的初衷

分享出来供大家学习的是技术，请勿用于其他用途，更不要通过这种方式将老师辛辛苦苦制作的课件下载下来随意传播！请仅限于自己查看（例如飞机上无网时可借此方法提前缓存并于下飞机后删除所下载文件）。

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/04/Other-Python-Spider-BUCT-onlinePlatform-KeChengZiYuan/)哦~
