https://github.com/LetMeFly666/LeetCode/tree/master/api
看到这个地址了吗？这其实是一个隐藏的sub git子项目，它是一个简单的cloudflare workers项目。
1. 读懂这个项目
2. 添加一个新路由（及其子路由），这个路由类似github/public，命名为logs/keyboard_website
3. 这个api支持第三方网站调用，调用时传入或自动记录（可以自动记录的不需要作为参数传入）以下几个参数：
    - url
    - 时间
    - ip
    - 按键记录(是一个字符串)
4. 网站可以往这个api上报用户按键记录，如a.com 按下了hello；a.com 按下了ok。
5. 将这些数据继续存放在api数据库中，新建一个数据表，表名Logs_Keyboard_Website。