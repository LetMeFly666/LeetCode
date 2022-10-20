---
title: 力扣2022年1024卡牌活动，程序员怎么判断自己的卡牌能否组成1024？那就愉快地编程实现吧！
date: 2022-10-19 19:01:20
tags: [其他, LeetCode, 1024, 程序员]
---

# 力扣2022年1024卡牌活动，程序员怎么判断自己的卡牌能否组成1024？那就愉快地编程实现吧！

> 如果你已经了解了此活动，直接跳到代码处即可。

和去年类似，今年的力扣又举行了1024程序员节的活动。

活动地址为[https://leetcode.cn/2022-1024/](https://leetcode.cn/2022-1024/)

活动攻略为[https://leetcode.cn/circle/discuss/OV9VUd/](https://leetcode.cn/circle/discuss/OV9VUd/)

先说明哈，这篇文章**不是广告**，因为有很多程序员都直到力扣的，根本不需要我这无流量小博主宣传。

大概玩法就是通过各种途径获得卡牌

卡牌分为*数字卡*和*符合卡*

通过四个数的三次运算，得到结果```1024```，则会获得一枚“1024币”

![截图01](https://img-blog.csdnimg.cn/33cee57d374443e78f1587c61eaf3f77.png)

很快，自己就会拥有很多张牌，那么问题来了，我这么多牌，到底能否组成1024呢？

那就愉快地编程实现吧！

只需要把下方Python代码中的“数字”和“运算符”改为自己的，然后运行这个脚本就可以。

程序会自动计算出你的卡牌能否经过“四数三算”得到1024。

比如我自己目前的卡牌有：```[2, 13, 4, 26, 2, 2, 14, 18, 2]```和```[">>", "&", "|", "|", "%"]```

那么运行结果就是：

```Python
[]
```

┭┮﹏┭┮

![榜一大神](https://img-blog.csdnimg.cn/5d7b238ab5da426ea951211e4c20ba5c.png)

但是如果“全网第一个合成成功的大神的卡牌”：```[16, 2, 16, 0]```和```["<<", "*", "+"]```

那么运行结果就是

```Python
['(((16<<2)*16)+0)', '(((16<<2)+0)*16)', '(((16*16)<<2)+0)', '(((16*16)+0)<<2)', '(((16+0)<<2)*16)', '(((16+0)*16)<<2)', '(((16*16)<<2)+0)', '(((16*16)+0)<<2)', '(((16<<2)*16)+0)', '(((16<<2)+0)*16)', '(((16+0)*16)<<2)', '(((16+0)<<2)*16)', '(((0+16)<<2)*16)', '(((0+16)*16)<<2)', '(((0+16)*16)<<2)', '(((0+16)<<2)*16)']
```

有很多种组成1024的方法。

好了，废话不多说了，上代码：

## 版本1

```Python
'''
Author: LetMeFly
Date: 2022-10-19 15:41:14
LastEditors: LetMeFly
LastEditTime: 2022-10-19 18:25:27
'''

# 将这里的数字牌和符号牌改成自己的即可
numbers = [2, 13, 4, 26, 2, 2, 14, 18, 2]
operators = [">>", "&", "|", "|", "%"]


ok = []

for n1 in range(len(numbers)):
    for n2 in range(len(numbers)):
        for n3 in range(len(numbers)):
            for n4 in range(len(numbers)):
                for o1 in range(len(operators)):
                    for o2 in range(len(operators)):
                        for o3 in range(len(operators)):
                            if (n1 == n2 or n1 == n3 or n1 == n4 or n2 == n3 or n2 == n4 or n3 == n4) or (o1 == o2 or o2 == o3 or o1 == o3):
                                continue
                            string = f"((({numbers[n1]}{operators[o1]}{numbers[n2]}){operators[o2]}{numbers[n3]}){operators[o3]}{numbers[n4]})"
                            if eval(string) == 1024:
                                ok.append(string)

print(ok)
```

## 版本2（更新于2022-10-20 10:22:52）

1. 修复了取模或者除法运算时，被除数可能为0的BUG
2. 显示了尝试次数

```python
'''
Author: LetMeFly
Date: 2022-10-19 15:41:14
LastEditors: LetMeFly
LastEditTime: 2022-10-20 10:22:52
'''

# numbers = [16, 2, 16, 0]
# operators = ["<<", "*", "+"]
numbers = [0, 12, 5, 2, 3, 19, 2, 18, 2, 13, 4, 26, 2, 2, 14]
operators = ["*", ">>", "&", "|", "|", "%"]


ok = []

print(f"{len(numbers)} ^ 4 * {len(operators)} ^ 3 = {len(numbers) ** 4 * len(operators) ** 3}")

for n1 in range(len(numbers)):
    for n2 in range(len(numbers)):
        for n3 in range(len(numbers)):
            for n4 in range(len(numbers)):
                for o1 in range(len(operators)):
                    for o2 in range(len(operators)):
                        for o3 in range(len(operators)):
                            if (n1 == n2 or n1 == n3 or n1 == n4 or n2 == n3 or n2 == n4 or n3 == n4) or (o1 == o2 or o2 == o3 or o1 == o3):
                                continue
                            string = f"((({numbers[n1]}{operators[o1]}{numbers[n2]}){operators[o2]}{numbers[n3]}){operators[o3]}{numbers[n4]})"
                            try:
                                if eval(string) == 1024:
                                    ok.append(string)
                            except:
                                pass

print(ok)
```

俺写这篇文章的目的有两个，一个是分享，一个是想涨点粉😻

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/19/Other-LeetCode1024-2022/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127413787](https://letmefly.blog.csdn.net/article/details/127413787)
