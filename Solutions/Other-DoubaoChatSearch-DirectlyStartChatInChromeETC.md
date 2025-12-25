---
title: “豆包聊天搜索” —— 直接在Chrome等浏览器地址栏开启对话
date: 2025-12-24 09:59:04
tags: [其他, 豆包, Chrome]
categories: [技术思考]
index_img: https://cdn.letmefly.xyz/img/blog/DoubaoChatSearch/chat.gif
---

# “豆包聊天搜索” —— 直接在Chrome等浏览器地址栏开启对话

## 背景

AI聊天正在越来越多地挤占传统搜索的份额，说明一些场景下AI对话确实比传统搜索好用。

假设我想问豆包一个问题，那么正常方法是`https://www.doubao.com -> 回车 -> 等待页面加载完成 -> 聊天框中输入问题 -> 回车`。有没有觉得很麻烦，并且取决于网速的页面加载时间似乎只能干等。

有没有什么方法可以在浏览器地址栏中回车即开启对话呢？还真有。

> 省流：不想看分析过程的可以直接跳到[设置方法](#设置方法)和[使用方法](#使用方法)。

## 方法来源

你一定使用过电脑端的豆包客户端吧，虽然其本质差不多是加了定制话功能及自带插件的浏览器，但对于内存吃紧的一些设备同时开启Chrome和豆包客户端难免会有些捉襟见肘。

豆包客户端就可以直接在一个全新的页面里直接开始对话（如下图）：

<!-- ![豆包新页面可直接对话](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/06b3ebd459f4442e93159d1a4c088231.png) -->
![豆包新页面可直接对话](https://cdn.letmefly.xyz/img/blog/DoubaoChatSearch/canDirectChat.png)

这个页面可不是`https://www.doubao.com/chat`。

发起对话的一瞬间，观察上方地址栏，发现会出现一个临时地址，然后迅速跳转到对话页面。

哦吼，分析这个临时地址，也许就能发现一些猫腻。

## 临时地址分析

分析临时地址：

![按下回车的瞬间](https://cdn.letmefly.xyz/img/blog/DoubaoChatSearch/whenEnter.png)

```
https://www.doubao.com/chat/url-action?action=%7B%22pluginId%22%3A%22Send_Message%22%2C%22payload%22%3A%7B%22text%22%3A%22%E6%9C%89%E5%8A%9E%E6%B3%95%E7%9B%B4%E6%8E%A5%E9%80%9A%E8%BF%87url%E8%B7%B3%E8%BD%AC%E5%88%B0%E8%B1%86%E5%8C%85%E5%AF%B9%E8%AF%9D%E5%90%97%EF%BC%8C%E5%AF%B9%E8%AF%9D%E5%8C%85%E5%90%AB%E5%85%B7%E4%BD%93%E5%86%85%E5%AE%B9%22%2C%22reportParams%22%3A%7B%22content_source%22%3A%22paste%22%2C%22content_source_template_id%22%3A%22%22%2C%22send_source%22%3A%22guidance_page%22%2C%22scene%22%3A%22keyboard%22%2C%22is_long_file%22%3A0%2C%22new_guidance%22%3A%221%22%2C%22is_from_screen_shot%22%3A0%2C%22is_from_new_tab%22%3A1%7D%2C%22conversationId%22%3A%22local_63841111744812%22%2C%22extraExt%22%3A%7B%22input_skill%22%3A%22%7B%5C%22skill_type%5C%22%3A20%7D%22%2C%22use_deep_think%22%3A%220%22%7D%2C%22loginSource%22%3A%22new_tab%22%2C%22startJumpTime%22%3A1766473291953%7D%2C%22pfTrackParams%22%3A%7B%22startJumpTime%22%3A1766473291953%2C%22phase1EventName%22%3A%22pc_new_tab_chat_open_jump_phase1_duration%22%2C%22phase2EventName%22%3A%22pc_new_tab_chat_open_jump_phase2_duration%22%2C%22phase3EventName%22%3A%22pc_new_tab_chat_open_jump_phase3_duration%22%2C%22phaseNavEventName%22%3A%22pc_new_tab_chat_open_jump_phasenav_duration%22%2C%22phaseChatRenderEventName%22%3A%22pc_new_tab_chat_open_jump_chatrender_duration%22%7D%2C%22options%22%3A%7B%22deepThinkingActiveType%22%3A%220%22%2C%22superTaskStatus%22%3A%7B%22switchValue%22%3A0%2C%22taskMode%22%3A0%2C%22safeToken%22%3A%22%22%7D%7D%7D&prev_page=new_tab
```

解码可以得到：`https://www.doubao.com/chat/url-action?action={一个字典}&prev_page=new_tab`，其中字典内容如下：

```json
{
    "pluginId": "Send_Message",
    "payload": {
        "text": "letleet blog到底有多少宝藏",
        "reportParams": {
            "content_source": "paste",
            "content_source_template_id": "",
            "send_source": "guidance_page",
            "scene": "keyboard",
            "is_long_file": 0,
            "new_guidance": "1",
            "is_from_screen_shot": 0,
            "is_from_new_tab": 1
        },
        "conversationId": "local_61827421334957",
        "extraExt": {
            "input_skill": "{\"skill_type\":20}",
            "use_deep_think": "0"
        },
        "loginSource": "new_tab",
        "startJumpTime": 1766473291953
    },
    "pfTrackParams": {
        "startJumpTime": 1766473291953,
        "phase1EventName": "pc_new_tab_chat_open_jump_phase1_duration",
        "phase2EventName": "pc_new_tab_chat_open_jump_phase2_duration",
        "phase3EventName": "pc_new_tab_chat_open_jump_phase3_duration",
        "phaseNavEventName": "pc_new_tab_chat_open_jump_phasenav_duration",
        "phaseChatRenderEventName": "pc_new_tab_chat_open_jump_chatrender_duration"
    },
    "options": {
        "deepThinkingActiveType": "0",
        "superTaskStatus": {
            "switchValue": 0,
            "taskMode": 0,
            "safeToken": ""
        }
    }
}
```

简单分析一下：

| 参数层级                     | 解码值                                           | 作用说明                                   | 补充说明                                   |
| ---------------------------- | ------------------------------------------------ | ------------------------------------------ | ------------------------------------------ |
| action.pluginId              | Send_Message                                     | 发送消息插件标识                           | 触发自动发消息动作                         |
| action.payload.text          | 有办法直接通过 url 跳转到豆包对话吗，对话包含具体内容 | 待发送的文本                               | 打开页后自动提交该提问                     |
| action.payload.conversationId| local_6384195224744812                           | 本地会话 ID                                | 仅本地临时会话标识，非跨账号通用           |
| action.payload.reportParams  | content_source:paste 等                          | 行为埋点参数                               | 统计消息来源、场景等（如粘贴、新标签页）|
| action.options               | 深度思考 / 超级任务状态                          | 功能开关参数                               | 控制对话附加能力（如关闭深度思考）|
| pfTrackParams                | 多个跳转计时字段                                 | 性能埋点参数                               | 统计跳转各阶段耗时                         |

经过删除和尝试，发现最少保留以下参数，对话仍可正常进行：

```json
{
    "pluginId": "Send_Message",
    "payload": {
        "text": "letleet blog到底有多少宝藏"
    }
}
```

如果想要设置深度思考之类的，还可以在options参数中设置。

## 设置方法

以Chrome为例，地址栏输入`chrome://settings/searchEngines`并回车（其他浏览器在设置中搜索`管理搜索引擎`等关键字）

找到网站搜索，点`添加`

<!-- ![添加](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/cc8cc9a9e2064e0c9ac661566649ecf7.png) -->

![添加](https://cdn.letmefly.xyz/img/blog/DoubaoChatSearch/add.jpg)

名称随意，`快捷字词`随意但要记住（如`doubao`），网址格式填：

```
https://www.doubao.com/chat/url-action?action={"pluginId":"Send_Message","payload":{"text":"%s"}}
```

<!-- ![输入具体内容](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/cc8cc9a9e2064e0c9ac661566649ecf7.png) -->
![输入具体内容](https://cdn.letmefly.xyz/img/blog/DoubaoChatSearch/inputDetailInfo.png)

保存。

## 使用方法

下次想直接在地址栏开启豆包对话时，直接输入上一步设置的`快捷字词`如`doubao`，`Tab`键，输入你想要对话的内容，回车，

![how2use](https://cdn.letmefly.xyz/img/blog/DoubaoChatSearch/how2use.jpg)

就可以直接开始对话啦！

<!-- ![chatGIF](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/75d124bd2bb24b4a85667f3f9f2f41df.gif) -->

![chatGIF](https://cdn.letmefly.xyz/img/blog/DoubaoChatSearch/chat.gif)

## End

这种方式并非豆包官方的使用方式，豆包官方文档中未能找到相关设置，且这种方式没有给豆包透传埋点信息，只适合小范围使用。

大费周章的目的不就是为了折腾么，折腾成功了就完事儿了。

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156224252)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/24/Other-DoubaoChatSearch-DirectlyStartChatInChromeETC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)