---
title: Windows - UWP - 通过链接启动Windows设置中的应用：ms-settings
date: 2023-03-16 20:46:27
tags: [其他, Windows, UWP]
---

## 前言

前段时间（大概是2023年2月23日）发现了浏览器可以打开Windows的“设置”中的“疑难解答”

通过“复制链接”的方式很容易得到其实是在浏览器中访问了

```
ms-settings:troubleshoot
```

## 使用方法

在Windows10中，使用组合键```Win + R```，在“运行”中输入```ms-settings:troubleshoot```并```回车```即可打开Windows设置中的“疑难解答”

同样地，在浏览器（例如Google）的地址栏中输入```ms-settings:troubleshoot```并```回车```，浏览器会询问“是否打开”，点击打开即可

同样地，也可以使用Python打开：

```python
import os
os.system("start ms-settings:troubleshoot")
```

当然，C语言也可以

```c
#include <windows.h>

int main() {
    system("start ms-settings:troubleshoot");
    return 0;
}
```

在HTML网页中：

```html
<button onclick="location.href='ms-settings:troubleshoot'">疑难解答</button>
```

## More

其中```ms```肯定是```Microsoft```的缩写，```settings```就是设置，```troubleshoot```就是疑难解答。

这样，就可以在自己的网页或程序中，打开对应的Windows设置了。

有没有更多的相关设置呢？当然有！

在找到了MS官方文档后，得到了很多类似的操作。

文档：[启动 Windows 设置应用](https://learn.microsoft.com/zh-cn/windows/uwp/launch-resume/launch-settings-app)

其被归类到了[UWP](https://learn.microsoft.com/zh-cn/windows/uwp/)中，把链接中的```zh-cn```修改为```en-us```即为原版纯英的[UWP教程](https://learn.microsoft.com/en-us/windows/uwp/)

以下数个表格来自上文提到的[微软官方文档](https://learn.microsoft.com/zh-cn/windows/uwp/launch-resume/launch-settings-app)，并将HTML格式转为了Markdown格式

**帐户**

| “设置”页面       | URI                                        |
| ---------------- | ------------------------------------------ |
| 访问工作单位或学校 | ms-settings:workplace                      |
| 电子邮件和应用帐户 | ms-settings:emailandaccounts                |
| 家人和其他人       | ms-settings:otherusers                      |
| 设置展台           | ms-settings:assignedaccess                  |
| 登录选项           | ms-settings:signinoptions<br>ms-settings:signinoptions-dynamiclock |
| 同步设置           | ms-settings:sync<br>ms-settings：backup (Windows 11) 中弃用的“备份”页 |
| Windows Hello 设置 | ms-settings:signinoptions-launchfaceenrollment<br>ms-settings:signinoptions-launchfingerprintenrollment |
| 你的信息           | ms-settings:yourinfo                        |

**应用**

|    “设置”页面    |                           URI                           |
|:-----------------:|:------------------------------------------------------:|
|  应用和功能       |                  ms-settings:appsfeatures                |
|  应用功能         | ms-settings:appsfeatures-app<br><br> 若要使用 URI 访问此页面，请使用 URI `ms-settings:appsfeatures-app` 并传递应用的 *包系列名称* 的可选参数。 |
|  网站应用         |                 ms-settings:appsforwebsites               |
|  默认应用         |                    ms-settings:defaultapps                 |
|  管理可选功能     |                  ms-settings:optionalfeatures              |
|  离线地图         |         ms-settings:maps<br>ms-settings:maps-downloadmaps (下载地图)         |
|  启动应用         |                    ms-settings:startupapps                  |
|  视频播放         |                   ms-settings:videoplayback                |


**控制中心**

| “设置”页面       | URI                                        |
| ---------------- | ------------------------------------------ |
| 控制中心 | ms-settings:controlcenter                      |

**Cortana**

|    “设置”页面          |                     URI                      |
|:-----------------------:|:--------------------------------------------:|
|  “跨设备的 Cortana”      |            ms-settings:cortana-notifications           |
|  更多详细信息            |            ms-settings:cortana-moredetails              |
|  权限和历史记录          |           ms-settings:cortana-permissions                |
|  搜索 Windows            |           ms-settings:cortana-windowssearch              |
|  与 Cortana 交谈         | ms-settings:cortana-language<br>ms-settings:cortana<br>ms-settings:cortana-talktocortana |

**设备**

| "设置"页面          | URI                                                                                          |
|-----------------------|--------------------------------------------------------------------------------------------------|
| 自动播放              | ms-settings:autoplay                                                                           |
| Bluetooth             | ms-settings:bluetooth                                                                          |
| 连接的设备            | ms-settings:connecteddevices                                                                   |
| 默认相机              | ms-settings：camera (**行为在 Windows 10 版本 1809 及更高版本中弃用**)                            |
| 相机设置              | ms-settings：camera (**行为在 Windows 11、版本 22000 及更高版本中引入**)                           |
| 鼠标和触摸板        | ms-settings:mousetouchpad（仅具有触摸板的设备可使用触摸板设置）                                 |
| 触控笔和 Windows Ink | ms-settings:pen                                                                               |
| 打印机和扫描仪      | ms-settings:printers                                                                           |
| 触摸                  | ms-settings:devices-touch                                                                      |
| 触摸板                | ms-settings:devices-touchpad（仅在存在触摸板硬件时可用）                                        |
| 文本建议              | ms-settings:devicestyping-hwkbtextsuggestions                                                  |
| Typing                | ms-settings:typing                                                                             |
| USB                   | ms-settings:usb                                                                                |
| 滚轮                  | ms-settings:wheel（仅在“拨号”配对成功后可用）                                                  |
| 你的手机              | ms-settings:mobile-devices                                                                     |

**附加信息**

| "设置"页面          | URI                                                                                          |
|-----------------------|--------------------------------------------------------------------------------------------------|
|附加信息|ms-settings:extras（仅在通过某种方式（例如第三方）安装了“设置应用”后可用）|


**家庭组**

| "设置"页面          | URI                                                                                          |
|-----------------------|--------------------------------------------------------------------------------------------------|
|家庭组|ms-settings:family-group|

**游戏**

| “设置”页面  | URI                                       |
| ------------ | ----------------------------------------- |
| 游戏栏       | ms-settings:gaming-gamebar                |
| 游戏 DVR     | ms-settings:gaming-gamedvr                |
| 游戏模式     | ms-settings:gaming-gamemode               |
| 全屏玩游戏   | ms-settings:quietmomentsgame              |
| TruePlay     | ms-settings:gaming-trueplay（从 Windows 10 版本 1809（10.0，内部版本 17763）起，Windows 中会删除此功能）|

**主页**

| "设置"页面          | URI                                                                                          |
|-----------------------|--------------------------------------------------------------------------------------------------|
|默认浏览器设置|ms-settings:defaultbrowsersettings|


**混合现实**

| “设置”页面       | URI                                         |
|:-----------------|:--------------------------------------------|
| 音频和语音       | ms-settings:holographic-audio               |
| 环境             | ms-settings:privacy-holographic-environment |
| 头戴显示设备显示 | ms-settings:holographic-headset             |
| 卸载             | ms-settings:holographic-management          |
| 启动和桌面       | ms-settings:holographic-startupandesktop    |

**网络和 Internet**

| “设置”页面        | URI                                                              |
|:------------------|:-----------------------------------------------------------------|
| 网络 & Internet   | ms-settings:network-status                                       |
| 高级设置          | ms-settings:network-advancedsettings                             |
| 飞行模式          | ms-settings:network-airplanemodems-settings:proximity            |
| 手机网络和 SIM 卡 | ms-settings:network-cellular                                     |
| 拨号              | ms-settings:network-dialup                                       |
| DirectAccess      | ms-settings:network-directaccess（仅在启用 DirectAccess 后可用） |
| 以太网            | ms-settings:network-ethernet                                     |
| 管理已知网络      | ms-settings:network-wifisettings                                 |
| 移动热点          | ms-settings:network-mobilehotspot                                |
| 代理              | ms-settings:network-proxy                                        |
| VPN               | ms-settings:network-vpn                                          |
| WLAN              | ms-settings:network-wifi（仅当设备具有 WLAN 适配器时可用）       |
| Wi-Fi 预配        | ms-settings:wifi-provisioning                                    |

**个性化**

| “设置”页面                       | URI                                                                              |
|:---------------------------------|:---------------------------------------------------------------------------------|
| 背景                             | ms-settings:personalization-background                                           |
| 选择哪些文件夹显示在“开始”菜单上 | ms-settings:personalization-start-places                                         |
| 颜色                             | ms-settings:personalization-colorsms-settings:colors                             |
| 概览                             | ms-settings:personalization-glance（已在 Windows 10 版本 1809 及更高版本中弃用） |
| 锁屏界面                         | ms-settings:lockscreen                                                           |
| 导航栏                           | ms-settings:personalization-navbar（已在 Windows 10 版本 1809 及更高版本中弃用） |
| 个性化（类别）                   | ms-settings:personalization                                                      |
| 开始                             | ms-settings:personalization-start                                                |
| 任务栏                           | ms-settings:taskbar                                                              |
| 触摸键盘                         | ms-settings:personalization-touchkeyboard                                        |
| 主题                             | ms-settings:themes                                                               |

**电话**

| “设置”页面   | URI                                                                                                                           |
|:-------------|:------------------------------------------------------------------------------------------------------------------------------|
| 你的手机     | ms-settings:mobile-devices<br>ms-settings:mobile-devices-addphone<br>ms-settings:mobile-devices-addphone-direct（打开“你的手机”应用） |
| 设备使用情况 | ms-settings:deviceusage                                                                                                       |

**隐私**

| “设置”页面   | URI                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|:-------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 外部设备应用 | ms-settings:privacy-accessoryapps（已在 Windows 10 版本 1809 及更高版本中弃用）                                                                                                                                                                                                                                                                                                                                                                            |
| 帐户信息     | ms-settings:privacy-accountinfo                                                                                                                                                                                                                                                                                                                                                                                                                            |
| 活动历史记录 | ms-settings:privacy-activityhistory                                                                                                                                                                                                                                                                                                                                                                                                                        |
| 广告 ID      | ms-settings:privacy-advertisingid（已在 Windows 10 版本 1809 及更高版本中弃用）                                                                                                                                                                                                                                                                                                                                                                            |
| 应用诊断     | ms-settings:privacy-appdiagnostics                                                                                                                                                                                                                                                                                                                                                                                                                         |
| 自动文件下载 | ms-settings:privacy-automaticfiledownloads                                                                                                                                                                                                                                                                                                                                                                                                                 |
| 后台应用     | ms-settings：privacy-backgroundapps (在 Windows 11、21H2 及更高版本中弃用) <br>注意：在 Windows 11 中，后台应用权限是单独访问的。 若要查看权限，请转到 “应用->已安装的应用 ”，然后在新式应用中选择 “...” ，然后选择“ 高级选项”。 新式应用会显示高级页面，除非设置了组策略或用户的全局切换值 (Windows 10) 中已弃用的设置，否则将显示“后台应用权限”部分。 若要使用 URI 访问此页面，请使用 URI ms-settings:appsfeatures-app 并传递应用的 包系列名称 的可选参数。 |
| 后台空间感知 | ms-settings:privacy-backgroundspatialperception                                                                                                                                                                                                                                                                                                                                                                                                            |
| 日历         | ms-settings:privacy-calendar                                                                                                                                                                                                                                                                                                                                                                                                                               |
| 呼叫历史记录 | ms-settings:privacy-callhistory                                                                                                                                                                                                                                                                                                                                                                                                                            |
| 照相机       | ms-settings:privacy-webcam                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| 联系人       | ms-settings:privacy-contacts                                                                                                                                                                                                                                                                                                                                                                                                                               |
| Documents    | ms-settings:privacy-documents                                                                                                                                                                                                                                                                                                                                                                                                                              |
| “下载”文件夹 | ms-settings:privacy-downloadsfolder                                                                                                                                                                                                                                                                                                                                                                                                                        |
| 电子邮件     | ms-settings:privacy-email                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| 眼球跟踪器   | ms-settings:privacy-eyetracker（需要眼球跟踪器硬件）                                                                                                                                                                                                                                                                                                                                                                                                       |
| 反馈和诊断   | ms-settings:privacy-feedback                                                                                                                                                                                                                                                                                                                                                                                                                               |
| 文件系统     | ms-settings:privacy-broadfilesystemaccess                                                                                                                                                                                                                                                                                                                                                                                                                  |
| 常规         | ms-settings:privacy 或 ms-settings:privacy-general                                                                                                                                                                                                                                                                                                                                                                                                         |
| 显卡         | ms-settings:privacy-graphicscaptureprogrammatic<br>ms-settings:privacy-graphicscapturewithoutborder                                                                                                                                                                                                                                                                                                                                                          |
| &            | ms-settings:privacy-speechtyping                                                                                                                                                                                                                                                                                                                                                                                                                           |
| 位置         | ms-settings:privacy-location                                                                                                                                                                                                                                                                                                                                                                                                                               |
| Messaging    | ms-settings:privacy-messaging                                                                                                                                                                                                                                                                                                                                                                                                                              |
| 麦克风       | ms-settings:privacy-microphone                                                                                                                                                                                                                                                                                                                                                                                                                             |
| 移动         | ms-settings:privacy-motion                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| 音乐库       | ms-settings:privacy-musiclibrary                                                                                                                                                                                                                                                                                                                                                                                                                           |
| 通知         | ms-settings:privacy-notifications                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 其他设备     | ms-settings:privacy-customdevices                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 电话呼叫     | ms-settings:privacy-phonecalls                                                                                                                                                                                                                                                                                                                                                                                                                             |
| 图片         | ms-settings:privacy-pictures                                                                                                                                                                                                                                                                                                                                                                                                                               |
| 无线电收发器 | ms-settings:privacy-radios                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| 语音         | ms-settings:privacy-speech                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| 任务         | ms-settings:privacy-tasks                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| 视频         | ms-settings:privacy-videos                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| 语音激活     | ms-settings:privacy-voiceactivation                                                                                                                                                                                                                                                                                                                                                                                                                        |

**搜索**

| “设置”页面       | URI                            |
|:-----------------|:-------------------------------|
| 搜索             | ms-settings:search             |
| 搜索更多详细信息 | ms-settings:search-moredetails |
| 搜索权限         | ms-settings:search-permissions |

**Surface Hub**

| “设置”页面   | URI                                     |
|:-------------|:----------------------------------------|
| 帐户         | ms-settings:surfacehub-accounts         |
| 会话清理     | ms-settings:surfacehub-sessioncleanup   |
| 团队会议     | ms-settings:surfacehub-calling          |
| 团队设备管理 | ms-settings:surfacehub-devicemanagenent |
| 欢迎屏幕     | ms-settings:surfacehub-welcome          |

**系统**

| “设置”页面           | URI                                                                           |
|:---------------------|:------------------------------------------------------------------------------|
| 关于                 | ms-settings:about                                                             |
| 高级显示设置         | ms-settings:display-advanced（仅适用于支持高级显示选项的设备）                |
| 应用音量和设备首选项 | ms-settings:apps-volume（已在 Windows 10 版本 1903 中添加）                   |
| 节电模式             | ms-settings:batterysaver（仅在具有电池的设备[如平板电脑]上可用）              |
| “节电模式”设置       | ms-settings:batterysaver-settings（仅在具有电池的设备[如平板电脑]上可用）     |
| 电池使用             | ms-settings:batterysaver-usagedetails（仅在具有电池的设备[如平板电脑]上可用） |
| 剪贴板               | ms-settings:clipboard                                                         |
| 显示                 | ms-settings:display                                                           |
| 默认保存位置         | ms-settings:savelocations                                                     |
| 显示                 | ms-settings:screenrotation                                                    |
| 复制我的屏幕         | ms-settings:quietmomentspresentation                                          |
| 在这些时间内         | ms-settings:quietmomentsscheduled                                             |
| 加密                 | ms-settings:deviceencryption                                                  |
| 专注助手             | ms-settings:quiethours                                                        |
| 图形设置             | ms-settings:display-advancedgraphics（仅适用于支持高级图形选项的设备）        |
| 图形默认设置         | ms-settings:display-advancedgraphics-default                                  |
| 多任务               | ms-settings:multitasking ms-settings:multitasking-sgupdate                    |
| 夜灯设置             | ms-settings:nightlight                                                        |
| 投影到这台电脑       | ms-settings:project                                                           |
| 共享体验             | ms-settings:crossdevice                                                       |
| 平板模式             | ms-settings:tabletmode（已在 Windows 11 中删除）                              |
| 任务栏               | ms-settings:taskbar                                                           |
| 通知和操作           | ms-settings:notifications                                                     |
| 远程桌面             | ms-settings:remotedesktop                                                     |
| 电话                 | ms-settings:phone（已在 Windows 10 版本 1809 及更高版本中弃用）               |
| 电源和睡眠           | ms-settings:powersleep                                                        |
| 声音                 | ms-settings:sound                                                             |
| 声音设备             | ms-settings:sound-devices                                                     |
| 存储                 | ms-settings:storagesense                                                      |
| 存储感知             | ms-settings:storagepolicies                                                   |
| 有关存储的建议       | ms-settings:storagerecommendations                                            |
| 磁盘 & 卷            | ms-settings：disksandvolumes                                                  |

**时间和语言**

| “设置”页面     | URI                                                                                                                                                                                                                                                                |
|:---------------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 日期和时间     | ms-settings:dateandtime                                                                                                                                                                                                                                            |
| 日本输入法设置 | ms-settings:regionlanguage-jpnime（在安装了 Microsoft 日本输入法编辑器的情况下可用）                                                                                                                                                                               |
| 区域           | ms-settings:regionformatting                                                                                                                                                                                                                                       |
| 语言           | ms-settings:keyboard<br>ms-settings:keyboard-advanced<br>ms-settings:regionlanguage<br>ms-settings:regionlanguage-bpmfime<br>ms-settings:regionlanguage-cangjieime<br>ms-settings:regionlanguage-chsime-wubi-udp<br>ms-settings:regionlanguage-quickime  <br>ms-settings:regionlanguage-korime |
| 拼音输入法设置 | ms-settings：regionlanguage-chsime-pinyin (如果 microsoft Pinyin 输入法编辑器安装) <br>ms-settings：regionlanguage-chsime-pinyin-domainlexicon<br>ms-settings:regionlanguage-chsime-pinyin-keyconfig<br>ms-settings:regionlanguage-chsime-pinyin-udp                           |
| 语音           | ms-settings:speech                                                                                                                                                                                                                                                 |
| 五笔输入法设置 | ms-settings:regionlanguage-chsime-wubi（在安装了 Microsoft 五笔输入法编辑器的情况下可用）                                                                                                                                                                          |
| 添加显示语言   | ms-settings:regionlanguage-adddisplaylanguage                                                                                                                                                                                                                      |
| 语言选项       | ms-settings:regionlanguage-languageoptions                                                                                                                                                                                                                         |
| 设置显示语言   | ms-settings:regionlanguage-setdisplaylanguage                                                                                                                                                                                                                      |

**更新和安全**

| “设置”页面                      | URI                                                                                                                       |
|:--------------------------------|:--------------------------------------------------------------------------------------------------------------------------|
| 激活                            | ms-settings:activation                                                                                                    |
| 备份                            | ms-settings：在 Windows 11 中删除了 backup (页;打开“同步)                                                                 |
| 传递优化                        | ms-settings:delivery-optimization  <br>ms-settings:delivery-optimization-activity  <br>ms-settings:delivery-optimization-advanced |
| 查找我的设备                    | ms-settings:findmydevice                                                                                                  |
| 面向开发人员                    | ms-settings:developers                                                                                                    |
| 恢复                            | ms-settings:recovery                                                                                                      |
| 启动安全密钥注册                | ms-settings:signinoptions-launchsecuritykeyenrollment                                                                     |
| 疑难解答                        | ms-settings:troubleshoot                                                                                                  |
| Windows 安全性                  | ms-settings:windowsdefender                                                                                               |
| Windows 预览体验计划            | ms-settings:windowsinsider（仅当用户在 WIP 中注册时显示）<br>ms-settings:windowsinsider-optin                                 |
| Windows 更新                    | ms-settings:windowsupdate<br>ms-settings:windowsupdate-action                                                                 |
| Windows 更新-活动小时数         | ms-settings:windowsupdate-activehours                                                                                     |
| Windows 更新 - 高级选项         | ms-settings:windowsupdate-options                                                                                         |
| Windows 更新-可选更新           | ms-settings:windowsupdate-optionalupdates                                                                                 |
| Windows 更新 - 重启选项         | ms-settings:windowsupdate-restartoptions                                                                                  |
| Windows 更新-按需查找器         | ms-settings:windowsupdate-seekerondemand                                                                                  |
| Windows 更新 - 查看更新历史记录 | ms-settings:windowsupdate-history                                                                                         |

**用户帐户**

| “设置”页面       | URI                                                                        |
|:-----------------|:---------------------------------------------------------------------------|
| 设置             | ms-settings:workplace-provisioning（仅在企业部署了预配包后可用）           |
| 修复令牌         | ms-settings:workplace-repairtoken                                          |
| 设置             | ms-settings:workplace-provisioning（仅在移动设备和企业部署了预配包后可用） |
| Windows Anywhere | ms-settings:windowsanywhere（设备必须支持 Windows Anywhere）               |

其中将HTML表格转为Markdown表格的Python脚本代码为：

```python
from bs4 import BeautifulSoup
import pandas as pd
import pyperclip

html_table = """
<table class="table table-sm">
<thead>
<tr>
<th>“设置”页面</th>
<th>URI</th>
</tr>
</thead>
<tbody>
<tr>
<td>修复令牌</td>
<td>ms-settings:workplace-repairtoken</td>
</tr>
</tbody>
</table>
"""

soup = BeautifulSoup(html_table, 'html.parser')

table = soup.find('table')
table_headers = [header.text for header in table.find_all('th')]

rows = []
for row in table.find_all('tr')[1:]:
    rows.append([val.text.replace('\n', '').replace('\xa0', '') for val in row.find_all('td')])

df = pd.DataFrame(rows, columns=table_headers)
markdown_table = df.to_markdown(index=False)

print(markdown_table)
pyperclip.copy(markdown_table)
```

上述的代码无法正确处理标签```<br>```，转换完成后还需要手动添加```<br>```标签以达到换行的效果

**注意：Windows11与之大不相同**

例如：

+ ```ms-settings:bluetooth```改为```ms-settings:bluetoothdevices```
+ ```ms-settings:camera```改为```ms-settings:privacy-webcam```
+ ```ms-settings:cellular```改为```ms-settings:network-cellular```
+ ```ms-settings:dateandtime```改为```ms-settings:dateandtime-language```
+ ```ms-settings:emailandaccounts```改为```ms-settings:emailandaccounts-accountssettings```
+ ```ms-settings:network-ethernet```改为```ms-settings:network-ethernetandproxy```
+ ```ms-settings:network-mobilehotspot```改为```ms-settings:network-mobilehotspotandtethering```
+ ```ms-settings:network-proxy```改为```ms-settings:network-proxyandvpn```
+ ```ms-settings:network-vpn```改为```ms-settings:network-vpn```
+ ```ms-settings:network-wifi```改为```ms-settings:network-wifi-legacy```
+ ```ms-settings:notifications```改为```ms-settings:notifications-and-actions```
+ ```ms-settings:powersleep```改为```ms-settings:powersleep-and-battery```
+ ```ms-settings:privacy```改为```ms-settings:privacy-general```
+ ```ms-settings:regionlanguage```改为```ms-settings:region```
+ ```ms-settings:storagesense```改为```ms-settings:system-storage```
+ ```ms-settings:tabletmode```改为```ms-settings:tabletmode```
+ ```ms-settings:windowsupdate```改为```ms-settings:windowsupdate-options```
+ ```ms-settings:personalization-background```改为```ms-settings:personalization-background```
+ ```ms-settings:personalization-colors```改为```ms-settings:personalization-colors```
+ ```ms-settings:personalization-lockscreen```改为```ms-settings:lockscreen```
+ ```ms-settings:personalization-start```改为```ms-settings:personalization-start```

上面列表中的21条“修改”来自ChatGPT。

> By the way, 今天有Google账号和ChatGPT等账号啦，2美元买的虚拟号，一条短信近7￥😭😂

## Other

其他的一些可以使用命令行直接打开的有：

|页面|命令|
|:--:|:--:|
|环境变量|rundll32 sysdm.cpl,EditEnvironmentVariables|

> 原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/03/16/Other-WIndows-UWP-launchSttingsApp/)哦~
> [https://letmefly.blog.csdn.net/article/details/129601344](https://letmefly.blog.csdn.net/article/details/129601344)

