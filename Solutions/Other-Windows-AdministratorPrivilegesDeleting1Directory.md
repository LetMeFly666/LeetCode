---
title: Windows - 管理员权限 - 删除需要管理员权限才能删掉的目录
date: 2023-08-13 09:23:23
tags: [其他, Windows]
categories: [技术思考]
description: 你需要来自xxx的权限才能对此文件进行更改
---

# Windows - 管理员权限 - 删除需要管理员权限才能删掉的目录

## 前言

Windows上有些目录很难删掉，即使给了管理员权限，有的依旧是无法删除。

网上说的方法“```右键 -> 属性 -> 安全 -> 编辑 -> 添加 -> 高级 -> 立即查找 -> ... -> 应用```”对于一些文件夹有效，对于一些文件夹仍然无效。

经过搜索，发现了知乎上的[一个帖子](https://zhuanlan.zhihu.com/p/82036101)，经过不完全测试，方法比较有效。

## 方法

### 一、将“获取管理权限”添加至右键菜单

新建```.reg```文件（也可以新建文本文件再改后缀），写入如下代码

```reg
Windows Registry Editor Version 5.00

[-HKEY_CLASSES_ROOT\*\shell\runas]

[HKEY_CLASSES_ROOT\*\shell\runas]
@="获取超级管理员权限"
"Icon"="C:\\Windows\\System32\\imageres.dll,-78"
"NoWorkingDirectory"=""

[HKEY_CLASSES_ROOT\*\shell\runas\command]
@="cmd.exe /c takeown /f \"%1\" && icacls \"%1\" /grant administrators:F"
"IsolatedCommand"="cmd.exe /c takeown /f \"%1\" && icacls \"%1\" /grant administrators:F"

[-HKEY_CLASSES_ROOT\Directory\shell\runas]

[HKEY_CLASSES_ROOT\Directory\shell\runas]
@="获取超级管理员权限"
"Icon"="C:\\Windows\\System32\\imageres.dll,-78"
"NoWorkingDirectory"=""

[HKEY_CLASSES_ROOT\Directory\shell\runas\command]
@="cmd.exe /c takeown /f \"%1\" /r /d y && icacls \"%1\" /grant administrators:F /t"
"IsolatedCommand"="cmd.exe /c takeown /f \"%1\" /r /d y && icacls \"%1\" /grant administrators:F /t"

[-HKEY_CLASSES_ROOT\dllfile\shell]

[HKEY_CLASSES_ROOT\dllfile\shell\runas]
@="获取超级管理员权限"
"HasLUAShield"=""
"NoWorkingDirectory"=""

[HKEY_CLASSES_ROOT\dllfile\shell\runas\command]
@="cmd.exe /c takeown /f \"%1\" && icacls \"%1\" /grant administrators:F"
"IsolatedCommand"="cmd.exe /c takeown /f \"%1\" && icacls \"%1\" /grant administrators:F"

[-HKEY_CLASSES_ROOT\Drive\shell\runas]

[HKEY_CLASSES_ROOT\Drive\shell\runas]
@="获取超级管理员权限"
"Icon"="C:\\Windows\\System32\\imageres.dll,-78"
"NoWorkingDirectory"=""

[HKEY_CLASSES_ROOT\Drive\shell\runas\command]
@="cmd.exe /c takeown /f \"%1\" /r /d y && icacls \"%1\" /grant administrators:F /t"
"IsolatedCommand"="cmd.exe /c takeown /f \"%1\" /r /d y && icacls \"%1\" /grant administrators:F /t"
```

代码解释：

1. 删除所有文件类型、文件夹、DLL文件和驱动器的右键菜单中现有的"runas"键。
1. 为所有文件类型、文件夹、DLL文件和驱动器的右键菜单添加一个新的"runas"键。
1. 将"runas"选项的显示名称设置为"获取超级管理员权限"。
1. 将"runas"选项的图标设置为位于"C:\Windows\System32"目录下的"imageres.dll"文件。
1. 禁用"runas"选项的工作目录（NoWorkingDirectory=""）。
1. 设置当选择"runas"选项时要执行的命令。该命令使用"cmd.exe"运行"takeown"和"icacls"命令，以获取所选项目的所有权并授予管理员组完全控制权限。"%1"占位符表示所选项目的路径。"IsolatedCommand"值用于与旧版Windows的兼容性。

### 二、添加到注册表、删除删不掉的文件夹

保存为```.reg```文件后，双击运行，授予管理员权限。

这样，在一个文件夹上点击鼠标右键时，就会多出一个```获取超级管理员权限```的选项。

只需要```右键待删文件夹 -> 获取超级管理员权限```，你就有权限删除这个文件夹了。（```delete```即可删除）

### 三、移除第一步添加的右键菜单（可选）

如果已经删除了目录，不想让右键“获取管理权限”的菜单保留，可以新建```.reg```文件写入以下代码并运行：

```reg
Windows Registry Editor Version 5.00

[-HKEY_CLASSES_ROOT\*\shell\runas]

[-HKEY_CLASSES_ROOT\Directory\shell\runas]

[-HKEY_CLASSES_ROOT\dllfile\shell]

[-HKEY_CLASSES_ROOT\Drive\shell\runas]

[-HKEY_CLASSES_ROOT\exefile\shell\runas]

[HKEY_CLASSES_ROOT\exefile\shell\runas]
"HasLUAShield"=""

[HKEY_CLASSES_ROOT\exefile\shell\runas\command]
@="\"%1\" %*"
"IsolatedCommand"="\"%1\" %*"
```

代码解释：

1. 删除所有文件类型的右键菜单中的"runas"键。
1. 删除所有目录的右键菜单中的"runas"键。
1. 删除所有DLL文件的右键菜单中的"runas"键。
1. 删除所有驱动器的右键菜单中的"runas"键。
1. 删除所有可执行文件的右键菜单中的"runas"键（例如，.exe文件）。
1. 为可执行文件的右键菜单添加一个新的"runas"键。
1. 设置"runas"选项的显示名称为默认值。
1. 设置当选择"runas"选项时要执行的命令，即运行所选可执行文件本身，并传递任何命令行参数。
1. "IsolatedCommand"值与"command"键相同，用于与旧版Windows的兼容性。

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/08/13/Other-Windows-AdministratorPrivilegesDeleting1Directory/)哦~
> [https://blog.letmefly.xyz/2023/08/13/Other-Windows-AdministratorPrivilegesDeleting1Directory/](https://blog.letmefly.xyz/2023/08/13/Other-Windows-AdministratorPrivilegesDeleting1Directory/)
