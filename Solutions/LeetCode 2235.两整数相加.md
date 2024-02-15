---
title: 2235.两整数相加：19种语言解法（力扣全解法）
date: 2023-08-19 09:05:57
tags: [题解, LeetCode, 简单, 数学]
---

# 【LetMeFly】2235.两整数相加：19种语言解法（力扣全解法）

力扣题目链接：[https://leetcode.cn/problems/add-two-integers/](https://leetcode.cn/problems/add-two-integers/)

给你两个整数&nbsp;<code>num1</code> 和 <code>num2</code>，返回这两个整数的和。
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = 12, num2 = 5
<strong>输出：</strong>17
<strong>解释：</strong>num1 是 12，num2 是 5 ，它们的和是 12 + 5 = 17 ，因此返回 17 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = -10, num2 = 4
<strong>输出：</strong>-6
<strong>解释：</strong>num1 + num2 = -6 ，因此返回 -6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-100 &lt;= num1, num2 &lt;= 100</code></li>
</ul>


    
## 方法一：返回num1 + num2

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};
```

#### C

```c
int sum(int num1, int num2){
    return num1 + num2;
}
```

#### Python

```python
class Solution:
    def sum(self, num1: int, num2: int) -> int:
        return num1 + num2
```

#### Python2

```python
class Solution(object):
    def sum(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        return num1 + num2
```

#### Java

```java
class Solution {
    public int sum(int num1, int num2) {
        return num1 + num2;
    }
}
```

#### C#

```csharp
public class Solution {
    public int Sum(int num1, int num2) {
        return num1 + num2;
    }
}
```

#### Javascript

```javascript
var sum = function(num1, num2) {
    return num1 + num2;
};
```

#### Ruby

```ruby
def sum(num1, num2)
    return num1 + num2
end
```

#### Swift

```swift
class Solution {
    func sum(_ num1: Int, _ num2: Int) -> Int {
        return num1 + num2
    }
}
```

#### Go

```go
func sum(num1 int, num2 int) int {
    return num1 + num2;
}
```

#### Scala

```scala
object Solution {
    def sum(num1: Int, num2: Int): Int = {
        num1 + num2
    }
}
```

#### Kotlin

```kotlin
class Solution {
    fun sum(num1: Int, num2: Int): Int {
        return num1 + num2
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn sum(num1: i32, num2: i32) -> i32 {
        return num1 + num2;
    }
}
```

#### PHP

```php
class Solution {

    /**
     * @param Integer $num1
     * @param Integer $num2
     * @return Integer
     */
    function sum($num1, $num2) {
        return $num1 + $num2;
    }
}
```

#### TypeScript

```typescript
function sum(num1: number, num2: number): number {
    return num1 + num2
};
```

#### Racket

```racket
(define/contract (sum num1 num2)
  (-> exact-integer? exact-integer? exact-integer?)
    (+ num1 num2)
  )
```

#### Erlang

```erlang
-spec sum(Num1 :: integer(), Num2 :: integer()) -> integer().
sum(Num1, Num2) ->
  Num1 + Num2.
```

#### Elixir

```elixir
defmodule Solution do
  @spec sum(num1 :: integer, num2 :: integer) :: integer
  def sum(num1, num2) do
    num1 + num2
  end
end
```

#### Dart

```dart
class Solution {
  int sum(int num1, int num2) {
    return num1 + num2;
  }
}
```

![result.png](https://pic.leetcode.cn/1692410144-yjwoIV-result.png)

<!-- ![result.png](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/img_convert/7bfad96251ad5d10960e098a60bec84f.png) -->

> 同步发文于CSDN，原创不易，喜欢了点个赞再走吧[原文链接](https://blog.letmefly.xyz/2023/08/19/LeetCode%202235.%E4%B8%A4%E6%95%B4%E6%95%B0%E7%9B%B8%E5%8A%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132376238](https://letmefly.blog.csdn.net/article/details/132376238)
