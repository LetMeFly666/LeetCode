---
title: 安卓 - ADB - ADB的简单使用、简化华为鸿蒙系统
date: 2023-07-27 15:52:08
tags: [其他, 安卓, Android, ADB, 华为, 鸿蒙, HarmonyOS]
---

# 前言

ADB（Android Debug Bridge）可以做到很多手机上做不到的事情（例如卸载部分系统内置应用）

+ ADB文档[developer.android.com](https://developer.android.com/studio/command-line/adb?hl=zh-cn)

# 基本功能

|||
|:--:|:--|
|查看已连接设备（USB连接状态下授权后可能会自动连接）|```adb devices```|
|断开连接|```adb kill-server```|
|进入shell（进入后无需再输```adb shell```命令）|```adb shell```|
|adb卸载应用|```pm uninstall --user 0 包名```|
|获取应用列表|```pm list packages```|
|获取包含huawei的列表|```pm list packages \| grep huawei```|
|查看某应用信息|```dumpsys package```|
|启动应用|```am start -n 包名/activity名```|
|清除应用数据|```pm clear 包名```|

# 拿到华为手机后可卸载

“笔者推荐” + “笔者未卸载”的包名来自[BiliBili](https://www.bilibili.com/read/cv21078097/)，其中由笔者筛选后得出。

其他华为包名（可选）来自Youtube。

## 笔者推荐

以下是[笔者](https://letmefly.xyz)推荐的可以卸载的应用/服务。

使用方法： 

+ 使用```adb shell pm uninstall --user 0 包名```
+ 或在```adb shell```下使用```pm uninstall --user 0 包名```

例如：

```bash
adb shell pm uninstall --user 0 com.huawei.hifolder   # 精品推荐
```

可卸载表：

|内容|包名|
|:--|:--|
|精品推荐|com.huawei.hifolder|
|教育中心|com.huawei.educenter|
|天际通APP|com.huawei.hiskytone|
|"天际通"服务|com.huawei.skytone|
|"游戏中心"App|com.huawei.gamebox|
|"GameKit"服务|com.huawei.game.kitserver|
|"应用助手"服务,其实就是"游戏助手,不玩游戏可删!|com.huawei.gameassistant|
|"智慧助手·今天"服务，负一屏的垃圾广告|com.huawei.intelligent|
|"华为钱包"App，我手机也没有NFC，平时用微信不用这个|com.huawei.wallet|
|"WalletSDK"服务,钱包 SDK 而已|com.huawei.wallet.sdk.walletsdk|
||com.huawei.wallet.facard|
|"会员中心"App|com.huawei.mycenter|
|"华为商城"App|com.vmall.client|
|"阅读"App|com.huawei.hwireader|
|"华为视频"App|com.huawei.himovie|
||com.huawei.himovie.partner1|
||com.huawei.himovie.partner2|
|"华为视频"App - 腾讯视频模块|com.tencent.qqlivehuawei|
|"华为视频"App - 搜狐视频模块|com.sohu.sohuvideo.emplayer|
|"花瓣剪辑"|com.huawei.videoeditor|
|华为"地理围栏服务",其实就是精准推送广告|com.huawei.spaceservice|
|华为"EasyGo SDK",给折叠屏用的;|com.huawei.easygo|
|"华为地图服务"|com.huawei.featurelayer.sharedfeature.map|
|华为"息屏支付"|com.huawei.hwpanpayservice|
|"银联可信服务安全组件",给华为钱包调用的安全组件|com.unionpay.tsmservice|
|华为"视频开发引擎"|com.huawei.multimedia.hivideoplayengine|
|"华为区块链"????,这... ...删了吧!|com.huawei.hwblockchain|
|"K 歌特效"|com.huawei.android.karaoke|
|"畅连"App，卸载了某地图服务的话，畅连会一直弹“缺少必要组件”|com.huawei.meetime|
|"畅连服务"|com.huawei.hwvoipservice|

## 笔者未卸载

|内容|包名|
|:--|:--|
|"智能提醒"App|com.huawei.tips|
|"玩机技巧"App|com.huawei.android.tips|
|"运动健康"App|com.huawei.health|
|[HarmongOS]"运动健康"App|com.huawei.ohos.health|
|"手写笔应用专区"App|com.huawei.stylus.mpenzone|
|"手写笔悬浮窗"服务|com.huawei.stylus.floatmenu|
|"手机克隆"App|com.hicloud.android.clone|
|"镜子"App|com.huawei.mirror|
|"智能遥控"App|com.huawei.android.remotecontroller|
|"AR 测量"|com.huawei.ar.measure|
|"录音机"App|com.android.soundrecorder|
|"计算器"App|com.huawei.calculator|
|"天气"App|com.huawei.android.totemweather|
|"电子邮件"App|com.huawei.email|
|"生活服务"App|com.huawei.lives|
|"智慧生活"App|com.huawei.smarthome|
|[HarmongOS]"智慧生活"App|com.huawei.ohos.smarthome|
|"智慧生活基础服务"|com.huawei.hilink.framework|
|"备忘录"App|com.huawei.notepad|
|"Link Now"App|com.huawei.welinknow|
|"指南针"App|com.huawei.compass|
|"杂志锁屏"|com.huawei.magazine|
|"智能检测"|com.huawei.hwdetectrepair|
|"我的华为"App|com.huawei.phoneservice|
|"智慧搜索"|com.huawei.search|
|"融合搜索服务"|com.huawei.searchservice|
|[HarmongOS]"全局搜索数据服务"|com.huawei.ohos.search|
|"查找设备"App|com.huawei.android.findmyphone|
|"华为音乐"App|com.android.mediacenter|
|"旅行助手"|com.huawei.scenepack|
|"HiCard"卡片服务|com.huawei.hicard|
|"HiCar"汽车服务|com.huawei.hicar|
|"XRKit"|com.huawei.featurelayer.sharedfeature.xrkit|
|"AREngineServer"华为 AR 引擎服务|com.huawei.arengine.service|
|"音频产品管家"|com.huawei.audioaccessorymanager|
|"WAudios",不知是啥!|com.huawei.waudio|
|"HwAudioKit",不知是啥!|com.huawei.multimedia.audioengine|
|  "SIM App Dialog"|com.android.simappdialog|
|"SIM 卡应用"App|com.android.stk|
|"主题"App,更换完主题就删除,用的时候在"华为应用商店"安装就行了;|com.huawei.android.thememanager|
|华为"浏览器"App,推荐 Edge 浏览器,别用"夸克"了,太"和谐"了!|com.huawei.browser|
|"华为云空间"|com.huawei.hidisk|
|"华为云空间服务"|com.huawei.hicloud|
|"隐私空间"|com.huawei.privatespace|
|"隐私空间"|com.huawei.securitymgr|
|华为"日历"App|com.huawei.calendar|
|"日历存储"|com.android.providers.calendar|
|华为"时钟"App|com.android.deskclock|
|"百度输入法"|com.baidu.input_huawei|
|"小艺建议"|com.huawei.ohos.suggestion|
|"华为智能建议"|com.huawei.pengine|
|华为"快应用中心"|com.huawei.fastapp|
|华为"备份"|com.huawei.localBackup|
|华为"支付保护中心"|com.huawei.trustspace|
|"Feature Framework"|com.huawei.featurelayer.featureframework|
|"华为智慧引擎"|com.huawei.hiai|
|华为"HUAWEI HiAI Base" 基础服务|com.huawei.hiaction|
|"华为智慧引擎"|com.huawei.recsys|
|华为"智慧语音"|com.huawei.vassistant|
|"扫名片"|com.huawei.contactscamcard|
|华为"智慧识屏"|com.huawei.hitouch|
|"华为 VR 服务"|com.huawei.vrservice|
|华为"手势服务"|com.huawei.motionservice|
|华为"智慧协同"|com.huawei.devicemanager|
|华为"无线投屏"|com.huawei.android.airsharing|
|华为"情景智能"|com.huawei.suggestion|
|华为"智慧视觉"|com.huawei.scanner|
|"华为分享"|com.huawei.pcassistant|
|"华为分享"|com.huawei.android.instantshare|
|"WLAN 直连"|com.huawei.android.wfdft|
|华为"悬浮导航"|com.huawei.android.FloatTasks|
|"华为打印"|com.huawei.printservice|
|华为"HwNearby"附近服务|com.huawei.nearby|
|华为"屏幕朗读"服务|com.bjbyhd.screenreader_huawei|
|"华为安全公共服务"|com.huawei.securityserver|
|华为"文件管理",推荐 "MT管理器"|com.huawei.filemanager|
|华为"我的文件"|com.huawei.desktop.explorer|
|"下载管理"|com.android.providers.downloads|
|"下载管理" UI|com.android.providers.downloads.ui|
|华为"关键资产同步"|com.huawei.assetsync|
|华为"关键资产同步"服务|com.huawei.assetsyncservice|
|华为"联系人同步"|com.huawei.contacts.sync|
|华为"Air Link"|com.huawei.airlink|
|"华为 RCS 服务",同华为手机的免费短信|com.huawei.rcsserviceapplication|
|华为"通过蓝牙导入"|com.huawei.bluetooth|
|华为"智能解锁"|com.huawei.trustagent|
|华为"蓝牙触控笔管理"|com.huawei.hwbluetoothpencilmanager|
|讯飞语音引擎|com.iflytek.speechsuite|
|[HarmongOS]华为"服务中心"|com.huawei.ohos.famanager|
|"共享存储备份"|com.android.sharedstoragebackup|
|华为"检测/诊断"|com.huawei.hwdiagnosis|
|华为"超级终端"|com.huawei.controlcenter|
|华为"注册服务"|com.huawei.regservice|
|华为"可信认证跳过"|com.huawei.trustedthingsauth|
|华为"协同"|com.huawei.synergy|
|华为"联合认证"|com.huawei.coauthservice|

## 其他华为包名（可选）

|内容|包名|
|:--|:--|
|华为视频|com.huawei.himovie|
|华为音乐|com.android.mediacenter|
|华为游戏中心|com.huawei.gamebox|
|华为阅读|com.huawei.hwireader|
|华为移动服务|com.huawei.hwid|
|华为健康|com.huawei.health|
|华为健康|com.huawei.ohos.health|
|浏览器|com.android.browser|
|华为商城|com.vmall.client|
|华为桌面|com.huawei.android.launcher|
|华为应用市场|com.huawei.appmarket|
|华为杂志锁屏|com.huawei.magazine|
|华为钱包|com.huawei.wallet|
|百度输入法华为版|com.baidu.input_huawei|
|天际通|com.huawei.hiskytone|
|天际通数据服务|com.huawei.skytone|
|查找我的手机|com.huawei.android.findmyphone|
|系统更新|com.huawei.android.hwouc|
|推送服务|com.huawei.android.pushagent|
|语音助手|com.huawei.vassistant|
|安装向导|com.huawei.hwstartupguide|
|会员服务|com.huawei.phoneservice|
|文件|com.android.documentsui|
|文件管理|com.huawei.hidisk|
|主题|com.huawei.android.thememanager|
|华为框架服务|com.huawei.android.hsf|
|下载管理器|com.android.providers.downloads|
|备份|com.huawei.localBackup|
|下载内容|com.android.providers.downloads.ui|
|手机管家|com.huawei.systemmanager|
|打包安装程序|com.android.packageinstaller|
|电子邮件|com.android.email|
|智能助手|com.huawei.intelligent|
|搜索|com.huawei.search|
|智慧识屏|com.huawei.hitouch|
|智慧视觉|com.huawei.scanner|
|服务中心|com.huawei.ohos.famanager|
|负一屏|com.huawei.intelligent|
|SIM卡应用|com.android.stk|


> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/27/Other-Android-ADB-SampleUseAndSamplifyHuaweiHarmonyOS/)哦~
> 地址：[https://blog.letmefly.xyz/2023/07/27/Other-Android-ADB-SampleUseAndSamplifyHuaweiHarmonyOS/](https://blog.letmefly.xyz/2023/07/27/Other-Android-ADB-SampleUseAndSamplifyHuaweiHarmonyOS/)
