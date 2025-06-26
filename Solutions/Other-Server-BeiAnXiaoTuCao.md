---
title: 域名转到国外注册商-备案失效风险折腾日记
date: 2025-06-23 12:55:26
tags: [其他, 域名, 备案]
categories: [技术思考]
---

# 域名转到国外注册商-备案失效风险折腾日记

使用Cloudflare的DNS和代理很久了，一直免费版心里有一丢丢过意不去，就想着买下cloudflare的产品。正好域名比正在用的阿里云还便宜（似乎cloudflare域名注册上并没有赚差价和服务费，而是域名服务商原价给了用户），就把阿里云的域名转移到了cloudflare上并续费了几年。

然后就收到了阿里云的“不支持域名注册商无法完成备案”提醒。

## 评价

这个提醒不能责怪阿里云，阿里云买服务器送的5个域名备案服务确实很方便！阿里云只是奉命执行下工信部的政策。

但是工信部为什么要规定国外域名注册商购买的域名不能备案呢？我能想到的就是必须让公民域名的WHOIS信息**实名**并且掌握在国内。

## 过程

### 转出到Cloudflare

把域名转到Cloudflare前我也做了很多攻略，搜寻了是否影响备案等资料，但得到的答案是不影响。所以我想记录下这次过程，希望能给想要把域名转到国外注册商(如Cloudflare)的站长检索到。

转出过程很顺利，只要能付钱(付钱还能延长一年域名有效期)按操作流程走一遍就好了。

### 想忍痛把域名再次转回阿里云

[ICANN规定域名在注册或转移后的60天内禁止再次转出以防止恶意转出](https://www.icann.org/resources/pages/about-transfer-policy-2017-10-19-zh)、[Transfer domain out from Cloudflare](https://developers.cloudflare.com/registrar/account-options/transfer-out-from-cloudflare/)

阿里云给了15个工作日的时间来处理，我申请了一次延期，得到如下提示：

> 您的延期处理申请已通过。以上问题请您于2025年07月15日0点之前完成处理， 如果逾期未处理可能会导致您的问题网站被限制访问、被取消接入、或者被注销。
>
> 如您已完成处理，请耐心等待，我们将会在指定时间到达后进行再次核查。再次核查前，您的网站不会受到影响。

但是我的域名在7.26日才达转移60天才能转出，不妙。

### 濒死挣扎

挣扎方案有2:

1. 联系Cloudflare尝试申请提前转出（联系客服无果提交工单为AI回复）
2. 联系阿里云申请延期检查

## 未完待续

最坏结果就是域名备案被取消，然后就得重新走一遍较为繁琐的备案流程。

TODO:Let 到时候我再把结果更新[过来](https://blog.letmefly.xyz/2025/06/23/Other-Server-BeiAnXiaoTuCao/)吧！

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148844350)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/06/23/Other-Server-BeiAnXiaoTuCao/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
