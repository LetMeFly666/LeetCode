<!--
 * @Author: LetMeFly
 * @Date: 2026-06-23 09:45:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-23 09:48:02
-->
安装完xcode后某脚本报错，原来是：！！！

```
git                                             

You have not agreed to the Xcode and Apple SDKs license. You must agree to the license below in order to use Xcode.
Press enter to display the license:
```

stackoverflow上也有人“吐槽”： https://stackoverflow.com/questions/25970043/git-and-xcode-why-do-i-have-to-agree-to-xcodes-tcs-to-use-git

算了，那就`sudo xcodebuild -license`并`accept`吧。
