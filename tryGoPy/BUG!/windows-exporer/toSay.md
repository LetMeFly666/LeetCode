<!--
 * @Author: LetMeFly
 * @Date: 2026-09-03 10:52:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-03 10:52:09
-->
今日Windows上剪切某目录卡死，究其原因发现源文件夹中存在一个2021年10月5日创建的快捷方式，所指向位置已不存在。
强制关闭任务管理器并重新创建快捷方式后剪切完成。