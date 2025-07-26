<!--
 * @Author: LetMeFly
 * @Date: 2025-07-26 16:03:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-26 16:59:18
-->
1. genText.py 生成明文 texts.txt - 如果不满意可以手动修改
2. genHidden.py 读取texts.txt生成密文链接 - s1.txt、s2.txt用于webex解密 beacon.txt用于owa解密
3. request.txt可以请求一个生成的密文链接文件中的所有网址 - 你可以通过FILE_NAME来指定要访问的链接文件

其中text_webex.py是直接测试加解密两个函数