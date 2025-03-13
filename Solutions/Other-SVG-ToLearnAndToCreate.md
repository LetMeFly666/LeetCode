---
title: SVG(可缩放矢量图形) - toLearn 和 创建
date: 2023-07-06 10:15:01
tags: [其他, SVG, 可缩放矢量图形]
categories: [技术思考]
---

# SVG(可缩放矢量图形) - toLearn 和 创建

SVG矢量图有着不失真、体积小等优势。

## 学习地址

学习地址：

+ [菜鸟教程](https://www.runoob.com/svg/svg-tutorial.html)
+ [MDN web docs](https://developer.mozilla.org/zh-CN/docs/Web/SVG/Tutorial)
+ [W3School](https://www.w3school.com.cn/svg/index.asp)

## 在线编辑

手动编码创建SVG比较复杂，较为复杂的SVG推荐使用SVG编辑器进行创建。

在线SVG编辑器：

+ [Pixso](https://pixso.cn/designskills/svg-online-editor/)
+ [菜鸟工具](https://c.runoob.com/more/svgeditor/)
+ [zuohaotu.com](http://www.zuohaotu.com/svg/)

## 实战 - Windows登录界面轻松访问图标的制作

Win10登录界面右下角有个轻松访问图标：

<center><img src='data:image/jpeg;base64,/9j/4AAQSkZJRgABAQAAAQABAAD/2wBDAAMCAgMCAgMDAwMEAwMEBQgFBQQEBQoHBwYIDAoMDAsKCwsNDhIQDQ4RDgsLEBYQERMUFRUVDA8XGBYUGBIUFRT/2wBDAQMEBAUEBQkFBQkUDQsNFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBT/wgARCAAsAC4DAREAAhEBAxEB/8QAHQAAAQMFAQAAAAAAAAAAAAAACAEECQACAwYHBf/EABQBAQAAAAAAAAAAAAAAAAAAAAD/2gAMAwEAAhADEAAAAIwwjQgSO0ciBOGoBBgBDofBYAdkp4KASY2GRHSYR0H8R9mwB2nHDpoDx44piLxC8o//xAAwEAABAwMEAQMCAwkAAAAAAAABAgMEBQYHAAgREiEJEzEQURRBoRUjJENjcXKBwv/aAAgBAQABPwAq7eEgk/Yawh6fuW89U1FUpNNYo9HWnlFRqi+jStbUdldGtjNmRrPvtymXSum24uY0uC6VIQ5pCUiQ+E+Eh1QA+w511+mz3arEzPbl4XpcNR/Y9t25FW4ZX9YeU6v7eblKt2sxZUS65MO26aDFZTBWWvebSSAVcHXpHT35+R8svzJK5L6rVXyt3/PSFj8RIAP8wn9dQG3KjPYhMHu++4lpCR+aieANXZbtUsityKVWoLsSayeFNvJI/wBjUTOq7S9OVFlU22p8d6s1N1EytlHDLqfcJCQrTCEBhJ6duvnj769NrNmDaPa1dE+DCtS6kwQxOffX4mMavu9tu8nP6JUS1JMOwoDnLjMBXZUohWrWv/aZGk2xckLCtejRJFRbZh1R9rhn3e+vVTvzDlbrduRYDLE+7GFFU1+B1CQyUeEq1tZh0zctsAu/Ew9kXPbjjtRg/fysr1OgSKDUJFPmJ9uRHcU0pJ8eQeNIX0UpaSU8ggkHjnVt0STctfp1Jhthcia+hhCe3ypSgB+p1vznxcFbbMSYTp0tBrcDirznWflBUVqTqZJkVaY9MmvLkyXTytxxXJJ1YGSrixdVHZtAqsmmiQj2pAjq47tn5HH9tWdi/a/uwx5S4cC4V2FkJhn+Kcnr4RJd/NSiSRqkbAlS80z7HcyZazUGIwZSqmZf7paB/wBazDZW2bbVjOdRaPVX7yyWtAXGqUBZ6RXh8K+QOArV33nW8g112sXBUpFUnrSlBekK5ISkAAD7DgfRKQvkHRYS2sqSSkp+ODoAqcW4Vr78fPY6SOT2JJP1/8QAFBEBAAAAAAAAAAAAAAAAAAAAUP/aAAgBAgEBPwAT/8QAFBEBAAAAAAAAAAAAAAAAAAAAUP/aAAgBAwEBPwAT/9k='></center>

我在<a href='https://pixso.cn/app/editor/4SEAIWPs_c3GjqF9A7NArQ?showGuide=true&page-id=111%3A12' title='我的在线编辑项目你可能访问不了'>Pixso</a>上编辑了一个，效果如下：

<center id='ToShowSVG'><svg width='102.000000' height='93.000000' viewBox='0 0 102 93' fill='none' xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink'>
    <desc>
        Author: LetMeFly(https://www.letmefly.xyz). Created with Pixso(https://pixso.cn/).
    </desc>
    <defs/>
    <rect width='102.000000' height='93.000000' fill='#FFFFFF'/>
    <circle id='椭圆 1' r='41.500000' transform='matrix(1 0 0 1 46 47)' stroke='#000000' stroke-width='7.000000'/>
    <rect id='矩形 1' x='40.000000' width='53.000000' height='51.000000' fill='#FFFFFF'/>
    <line id='直线 1' x1='46.000000' y1='45.000000' x2='46.000000' y2='0.000000' stroke='#000000' stroke-width='7.000000'/>
    <line id='直线 1' x1='55.000000' y1='45.000000' x2='95.000000' y2='45.000000' stroke='#000000' stroke-width='7.000000'/>
    <path id='多边形 1' d='M102 44.5L92.25 35.4067L92.25 53.5933L102 44.5Z' fill-rule='evenodd' fill='#000000'/>
    <line id='直线 3' x1='53.000000' y1='47.000000' x2='55.000000' y2='47.000000' stroke='#000000' stroke-width='3.000000'/>
    <line id='直线 2' x1='51.000000' y1='49.000000' x2='58.000000' y2='39.000000' stroke='#FFFFFF' stroke-width='3.000000'/>
    <line id='直线 4' x1='9.000000' y1='45.000000' x2='0.000000' y2='45.000000' stroke='#FFFFFF' stroke-width='3.000000'/>
    <line id='直线 4' x1='11.000000' y1='16.000000' x2='17.363953' y2='22.363953' stroke='#FFFFFF' stroke-width='3.000000'/>
    <line id='直线 4' x1='11.000000' y1='77.363968' x2='17.363953' y2='71.000000' stroke='#FFFFFF' stroke-width='3.000000'/>
    <line id='直线 4' x1='73.000000' y1='73.000000' x2='79.363968' y2='79.363968' stroke='#FFFFFF' stroke-width='3.000000'/>
    <line id='直线 4' x1='46.000000' y1='93.000000' x2='46.000000' y2='84.000000' stroke='#FFFFFF' stroke-width='3.000000'/>
    <path id='多边形 1' d='M46.5 52L55.5933 42.25L37.4067 42.25L46.5 52Z' fill-rule='evenodd' fill='#000000'/>
</svg></center>

<a class='btn' id='ToDownloadSVG' title='LetMeFly4 Easy Access'>点我下载SVG</a>

<script>
    function setSVGDownload() {
        const fileName = '轻松访问.svg';
        const fileStream = document.querySelector('#ToShowSVG').innerHTML;
        const blob = new Blob([fileStream], {type: 'application/text'});
        const href = window.URL.createObjectURL(blob);
        const a = document.querySelector('#ToDownloadSVG');
        a.href = href;
        a.download = decodeURI(fileName);
        // window.URL.revokeObjectURL(href);
    }
    setSVGDownload();
</script>

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/06/Other-SVG-ToLearnAndToCreate/)哦~
> [https://blog.letmefly.xyz/2023/07/06/Other-SVG-ToLearnAndToCreate/](https://blog.letmefly.xyz/2023/07/06/Other-SVG-ToLearnAndToCreate/)
