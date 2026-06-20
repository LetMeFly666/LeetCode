---
title: MacOS：使用纯C++创建一个简单的MacAPP的Demo(可以双击运行的那种)
date: 2026-06-20 15:25:21
tags: [VsCode, 简单, Mac, MacOS]
categories: [技术思考]
---

# MacOS：使用纯C++创建一个简单的MacAPP的Demo(可以双击运行的那种)

有没有想过Mac上那些app是怎么做出来的？里面都包含了什么东西？今天就来做一个最简单的Mac APP。

## 背景

Mac的app安装方式就是把xx.app拖拽到/Applications目录下，且/Applications目录下有很多文件夹(对应着一个个的软件)。每个xx.app其实都是一个文件夹，里面有可执行文件、资源、元信息等，只是Mac把这种特殊的文件夹显示为应用图标并且在你双击这种文件夹的时候直接按照元信息运行其中的可执行程序罢了。

## 超小的.app制作

新建一个空的文件夹如“testMacAPP”，进入这个文件夹，创建一个main.cpp并写入如下内容：

```cpp
#include <cstdlib>

int main() {
    system("osascript -e 'tell application \"Terminal\" to activate'");
    system("osascript -e 'tell application \"Terminal\" to do script \"echo Hello from C++ App; read\"'");
    return 0;
}
```

在此文件夹下创建`Hello.app/Contents/MacOS`子文件夹，编译上述cpp源码并将可执行程序放到`Hello.app/Contents/MacOS`文件夹下：

```bash
clang++ main.cpp -o Hello.app/Contents/MacOS/Hello
```

接下来在`Hello.app/Contents`文件夹下创建`Info.plist`文件并写入以下内容：

```xml
<?xml version="1.0" encoding="UTF-8"?>
<plist version="1.0">
<dict>
    <key>CFBundleExecutable</key>
    <string>Hello</string>

    <key>CFBundleIdentifier</key>
    <string>xyz.letmefly.example.simpleapp.hello</string>

    <key>CFBundleName</key>
    <string>Let's Hello</string>
</dict>
</plist>
```

然后你的app就做好了。最终结构如下：

```
testMacAPP
├── Hello.app
│   └── Contents
│       ├── Info.plist
│       └── MacOS
│           └── Hello
└── main.cpp
```

这个Hello.app文件夹就是一个可以双击运行的Mac app。

现在打开`testMacApp`文件夹，可以看到`Hello.app`不是一个普通文件夹的图标，而是一个默认应用的图标。

双击这个应用，会弹出弹窗问是否允许这个应用控制“终端”，点击允许后重新运行下这个应用，可以看到弹出了一个终端，上面有如下类似的字样：

```bash
echo Hello from C++ App; read
➜  ~ echo Hello from C++ App; read
Hello from C++ App
```

等你随便输入一些东西并按下回车后将会变成一个普通的终端。

## 小app一键生成脚本

也可以运行下面的脚本一键生成：

```bash
mkdir -p Hello.app/Contents/MacOS

cat > main.cpp << 'EOF'
#include <cstdlib>

int main() {
    system("osascript -e 'tell application \"Terminal\" to activate'");
    system("osascript -e 'tell application \"Terminal\" to do script \"echo Hello from C++ App; read\"'");
    return 0;
}
EOF

clang++ main.cpp -o Hello.app/Contents/MacOS/Hello
chmod +x Hello.app/Contents/MacOS/Hello

cat > Hello.app/Contents/Info.plist << 'EOF'
<?xml version="1.0" encoding="UTF-8"?>
<plist version="1.0">
<dict>
    <key>CFBundleExecutable</key>
    <string>Hello</string>

    <key>CFBundleIdentifier</key>
    <string>xyz.letmefly.example.simpleapp.hello</string>

    <key>CFBundleName</key>
    <string>Let's Hello</string>
</dict>
</plist>
EOF
```

# The End

<center><font size="6px" face="Ink Free">The End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162148634)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/20/Other-MacOS-SimpleAppDemo/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
