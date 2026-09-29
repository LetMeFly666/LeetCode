---
title: Windows - 杀死冷冻再利用流氓软件服务——某深信服软件斗智过程
date: 2026-09-29 10:38:11
tags: [其他, Windows, 流氓软件]
categories: [技术思考]
---

# Windows - 杀死冷冻再利用流氓软件服务——某深信服软件斗智过程

## 前言

> WARNGING: 本文的唯一目的就是学习Windows系统知识，了解Windows服务、进程保活相关技能。
> 
> 文中所分析的样本均为带有签名的正常样本，本文对任何第三方开发的软件没有恶意。

1. 某特定网站需要安装深信服的“认证助手”Ingress服务才能访问。但Ingress开机自启、关闭自动重启、多服务相互拉起、自动修改服务启动类型和重试策略、安全模式下都要启动。能否只在需要访问该特定网站的时候启动认证助手服务，不需要的时候就关掉呢？
2. 某主机插入非认证的U盘无法使用，能否在不具备认证U盘的情况下使用普通U盘向该主机拷贝一些开发环境呢？

## 深信服Ingress相关服务探索

### 排查过程

#### Ingress、IngressMgr

任务管理器可看到`准入服务（32位）`，右键`转到详细信息（G）`可以看到`Ingress.exe`。

在powershell中查看谁启动的它：

```powershell
Get-CimInstance Win32_Process | Select-Object ProcessID, ParentProcessID, Name | findstr Ingress.exe
```

可看到它的父进程是`IngressMgr.exe`，如果刚刚详细信息页面是以名称排序的话，`IngressMgr.exe`就在`Ingress.exe`旁边。

在`IngressMgr.exe`上右键，`转到服务（S）`，可知该进程是通过在系统中注册了`IngressMgr`服务来启动的。

点击`打开服务`并再次找到这个服务，在这个服务上右键`属性（S）`，可以看到这个服务默认是自动启动，且不可操作（`停止`、`暂停`等按钮是灰色的），恢复状态是`重新启动服务`。

好，那咱就先给服务设置成“禁用”，恢复类型设置为不恢复，同时赶快杀掉`Ingress.exe`和`IngressMgr.exe`，防止二者相互拉起唤醒。在`cmd`中执行以下命令：

```bash
sc.exe config IngressMgr start= disabled
sc.exe failure IngressMgr reset=0 actions= ""
taskkill /f /im IngressMgr.exe
taskkill /f /im Ingress.exe
```

（注意`start=`后面和`actions=`后面必须有空格。）

可以看到Ingress.exe、IngressMgr.exe都消失了。但是过了约十几秒，鼠标一转圈，这两个东西又起来了！并且服务也被修改回了原本的自启动和失败重试。

#### nac_monitor

Sangfor一定还注册了别的程序/服务来保活。

在服务列表里寻找，发现了一个描述为`Sangfor NAC Monitor Service`的服务`nac_monitor`。把这个服务也给设置成`禁用`，再次执行刚刚的四句命令，可以发现`Ingress`没有再自启动了。

如果想访问该特定网站的时候，重新启动IngressMgr服务就好了。并且发现，这个`nac_monitor`服务即使一直禁用掉不启用，也不影响该特定网站的访问和使用。

### 总结：怎么优雅使用

不想访问这个特定网站的时候（可能是大多时候），给nac_monitor服务和Ingress服务禁用掉；想访问这个特定网站的时候，再给Ingress服务重新开启就好了。

`nac_monitor`服务会每隔几十秒重置`IngressMgr`服务为自启动和失败重试，`IngressMgr`服务会启动`Ingress.exe`且二者会相互拉起。

关（CMD中以管理员权限执行）：

```bash
sc.exe config nac_monitor start= disabled
sc.exe failure nac_monitor reset=0 actions= ""
taskkill /f /im nac_agent.exe
taskkill /f /fi "SERVICES eq nac_monitor" /im *

sc.exe config IngressMgr start= disabled
sc.exe failure IngressMgr reset=0 actions= ""
taskkill /f /im IngressMgr.exe
taskkill /f /im Ingress.exe
taskkill /f /fi "SERVICES eq IngressMgr" /im *
```

也可以把下面这段代码另存为`closeNet.bat`，记得编码方式为`GBK`：

```bat
@echo off

:: 检查是否已经是管理员权限
fltmc >nul 2>&1
if errorlevel 1 (
    echo 请求管理员权限...
    powershell -NoProfile -Command "Start-Process -FilePath '%~f0' -Verb RunAs"
    exit /b
)

echo.
echo ===== 关闭 nac_monitor =====
sc.exe config nac_monitor start= disabled
sc.exe failure nac_monitor reset=0 actions= ""
taskkill /f /im nac_agent.exe
taskkill /f /fi "SERVICES eq nac_monitor" /im *

echo.
echo ===== 关闭 IngressMgr =====
sc.exe config IngressMgr start= disabled
sc.exe failure IngressMgr reset=0 actions= ""
taskkill /f /im IngressMgr.exe
taskkill /f /im Ingress.exe
taskkill /f /fi "SERVICES eq IngressMgr" /im *

echo.
echo ===== 执行完毕 =====
pause
```

开（CMD中以管理员权限执行）：

```bash
sc.exe config IngressMgr start= demand
sc.exe start IngressMgr
```

也可以把下面这段代码另存为`openNet.bat`，记得编码方式为`GBK`：

```bat
@echo off

:: 检查是否已经是管理员权限
fltmc >nul 2>&1
if errorlevel 1 (
    echo 请求管理员权限...
    powershell -NoProfile -Command "Start-Process -FilePath '%~f0' -Verb RunAs"
    exit /b
)

sc.exe config IngressMgr start= demand
sc.exe start IngressMgr

echo.
echo ===== 执行完毕 =====
pause
```

样本：Ingress3.0.0。

## U盘识别策略探索

### 启动U盘识别

> U盘插入后禁止安装，这个策略的设定来源未知，可能与深信服无关。

本想往某主机通过U盘拷贝一些开发环境，结果插入U盘后资源管理器中并未出现U盘。在资源管理器`此电脑`右键，`管理（G）`，`计算机管理（本地） -> 系统工具 -> 设备管理器`中的`其他设备`下可以看到一个`SanDisk Ultra USB3.0`，右键`属性（R）`点击`事件`可看到`阻止的设备 disk.inf 策略已阻止设备USBSTOR xx 的配置`。

解决方案是：`Win+R -> gpedit.msc`，`计算机配置 -> 管理模板 -> 系统 -> 设备安装 -> 设备安装限制`，找到`禁止安装未由其他策略设置描述的设备`，右键`编辑（E）`，把`已启用(E)`改为`未配置(C)`。

### 清理U盘相关日志

若不想工作留痕，可(宁可错杀100不留一个活口地)执行下面powershell命令（不保证清理干净）：

```powershell
# USB 设备历史
Remove-Item 'HKLM:\SYSTEM\CurrentControlSet\Enum\USBSTOR' -Recurse -Force
# 普通 USB 设备历史
Remove-Item 'HKLM:\SYSTEM\CurrentControlSet\Enum\USB' -Recurse -Force
# 当前用户的盘符/卷挂载痕迹
Remove-Item 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\MountPoints2' -Recurse -Force
# SetupAPI 设备安装日志
Remove-Item "$env:WINDIR\INF\SetupAPI.dev.log" -Force -ErrorAction SilentlyContinue
Remove-Item "$env:WINDIR\INF\SetupAPI.app.log" -Force -ErrorAction SilentlyContinue
# 设备相关事件日志
wevtutil cl Microsoft-Windows-DriverFrameworks-UserMode/Operational
wevtutil cl Microsoft-Windows-DeviceSetupManager/Admin
wevtutil cl Microsoft-Windows-DeviceSetupManager/Operational
```

可以另存为一个GBK格式编码的`cleanUSBHistory.ps1`，运行时候右键运行：

```powershell
# 自动申请管理员权限
$currentUser = [Security.Principal.WindowsIdentity]::GetCurrent()
$principal = New-Object Security.Principal.WindowsPrincipal($currentUser)

if (-not $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) {
    Start-Process powershell.exe -Verb RunAs -ArgumentList @(
        '-NoProfile'
        '-ExecutionPolicy', 'Bypass'
        '-File', "`"$PSCommandPath`""
    )
    exit
}

Write-Host "正在清理 USB 设备历史..." -ForegroundColor Cyan
$ErrorActionPreference = "Continue"

# USB 设备历史
Remove-Item 'HKLM:\SYSTEM\CurrentControlSet\Enum\USBSTOR' -Recurse -Force
# 普通 USB 设备历史
Remove-Item 'HKLM:\SYSTEM\CurrentControlSet\Enum\USB' -Recurse -Force
# 当前用户的盘符/卷挂载痕迹
Remove-Item 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\MountPoints2' -Recurse -Force
# SetupAPI 设备安装日志
Remove-Item "$env:WINDIR\INF\SetupAPI.dev.log" -Force -ErrorAction SilentlyContinue
Remove-Item "$env:WINDIR\INF\SetupAPI.app.log" -Force -ErrorAction SilentlyContinue
# 设备相关事件日志
wevtutil cl Microsoft-Windows-DriverFrameworks-UserMode/Operational
wevtutil cl Microsoft-Windows-DeviceSetupManager/Admin
wevtutil cl Microsoft-Windows-DeviceSetupManager/Operational

Write-Host ""
Write-Host "清理完成。" -ForegroundColor Green
Write-Host "按任意键退出..." -ForegroundColor Gray
[Console]::ReadKey($true) | Out-Null0
```

如果觉得在`.ps1`上右键运行麻烦，也可以在相同目录下放一个`cleanUSBHistory.bat`，写入以下内容后双击运行即可：

```bat
@echo off
powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0cleanUSBHistory.ps1"
```

## End

> 天下人苦深信服久矣(bushi)(狗头保命)

深信服的网络相关服务确实能解决很多问题，但深信服软件给我的感觉是“功能健壮、过度运行、想用我的软件我就是老大”：

1. 不论是准入服务还是一个普通的VPN，管理员权限安装后就给你注册一些自启动服务，不论你是否需要相关服务，反正就赖在后台运行着，强制杀掉就自动重启。
2. 个人认为深某服产品经理没有在客户角度考虑，安装时候不提供安装位置选项、不列举安装过程都进行了哪些操作、一系列过度的后台和保活操作…… 给人的感觉就是产品经理：“想用我的软件吗？先叫声爸爸，以后我的软件在你电脑上就是爹，你管不了”。产品的健壮性是得到了保证，但对于“对自己电脑有过度掌控欲”的用户而言简直就是在侮辱。

所以笔者才会在闲暇之余研究这么一个解决方案出来，可能是软件提供方与使用者所处的立场和思考的角度不同吧。这也给我自己了一个提醒，以后设计产品一定要多多站在用户视角考虑。

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166846736)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/29/Other-Windows-Killing_Disabling_andReusingARogueSoftwareService_Sangfor/)哦~
