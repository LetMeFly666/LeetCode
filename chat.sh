###
 # @Author: LetMeFly
 # @Date: 2026-03-24 23:16:39
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-03-24 23:18:55
### 
我linux想默认4534端口ssh登录，而22端口使用一个蜜罐程序监听
这个蜜罐程序在用户尝试连接时不论输入什么密码都会连接成功，然后提示一句Welcome，you idot，之后是一个假shell。
我想让这个shell尽可能真实，你帮我设计一下。

使用go实现，尽量不要使用第三方依赖。