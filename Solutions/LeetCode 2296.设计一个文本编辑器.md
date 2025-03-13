---
title: 2296.设计一个文本编辑器：对顶栈-主要是要细心下标问题（ASCII字符通俗语言描述）
date: 2025-02-27 10:56:51
tags: [题解, LeetCode, 困难, 栈, 设计, 链表, 字符串, 双向链表, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2296.设计一个文本编辑器：对顶栈-主要是要细心下标问题（ASCII字符通俗语言描述）

力扣题目链接：[https://leetcode.cn/problems/design-a-text-editor/](https://leetcode.cn/problems/design-a-text-editor/)

<p>请你设计一个带光标的文本编辑器，它可以实现以下功能：</p>

<ul>
	<li><strong>添加：</strong>在光标所在处添加文本。</li>
	<li><strong>删除：</strong>在光标所在处删除文本（模拟键盘的删除键）。</li>
	<li><strong>移动：</strong>将光标往左或者往右移动。</li>
</ul>

<p>当删除文本时，只有光标左边的字符会被删除。光标会留在文本内，也就是说任意时候&nbsp;<code>0 &lt;= cursor.position &lt;= currentText.length</code>&nbsp;都成立。</p>

<p>请你实现&nbsp;<code>TextEditor</code>&nbsp;类：</p>

<ul>
	<li><code>TextEditor()</code>&nbsp;用空文本初始化对象。</li>
	<li><code>void addText(string text)</code>&nbsp;将&nbsp;<code>text</code>&nbsp;添加到光标所在位置。添加完后光标在&nbsp;<code>text</code>&nbsp;的右边。</li>
	<li><code>int deleteText(int k)</code>&nbsp;删除光标左边&nbsp;<code>k</code>&nbsp;个字符。返回实际删除的字符数目。</li>
	<li><code>string cursorLeft(int k)</code> 将光标向左移动&nbsp;<code>k</code>&nbsp;次。返回移动后光标左边&nbsp;<code>min(10, len)</code>&nbsp;个字符，其中&nbsp;<code>len</code>&nbsp;是光标左边的字符数目。</li>
	<li><code>string cursorRight(int k)</code>&nbsp;将光标向右移动&nbsp;<code>k</code>&nbsp;次。返回移动后光标左边&nbsp;<code>min(10, len)</code>&nbsp;个字符，其中&nbsp;<code>len</code>&nbsp;是光标左边的字符数目。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["TextEditor", "addText", "deleteText", "addText", "cursorRight", "cursorLeft", "deleteText", "cursorLeft", "cursorRight"]
[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]
<strong>输出：</strong>
[null, null, 4, null, "etpractice", "leet", 4, "", "practi"]

<strong>解释：</strong>
TextEditor textEditor = new TextEditor(); // 当前 text 为 "|" 。（'|' 字符表示光标）
textEditor.addText("leetcode"); // 当前文本为 "leetcode|" 。
textEditor.deleteText(4); // 返回 4
                          // 当前文本为 "leet|" 。
                          // 删除了 4 个字符。
textEditor.addText("practice"); // 当前文本为 "leetpractice|" 。
textEditor.cursorRight(3); // 返回 "etpractice"
                           // 当前文本为 "leetpractice|". 
                           // 光标无法移动到文本以外，所以无法移动。
                           // "etpractice" 是光标左边的 10 个字符。
textEditor.cursorLeft(8); // 返回 "leet"
                          // 当前文本为 "leet|practice" 。
                          // "leet" 是光标左边的 min(10, 4) = 4 个字符。
textEditor.deleteText(10); // 返回 4
                           // 当前文本为 "|practice" 。
                           // 只有 4 个字符被删除了。
textEditor.cursorLeft(2); // 返回 ""
                          // 当前文本为 "|practice" 。
                          // 光标无法移动到文本以外，所以无法移动。
                          // "" 是光标左边的 min(10, 0) = 0 个字符。
textEditor.cursorRight(6); // 返回 "practi"
                           // 当前文本为 "practi|ce" 。
                           // "practi" 是光标左边的 min(10, 6) = 6 个字符。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length, k &lt;= 40</code></li>
	<li><code>text</code>&nbsp;只含有小写英文字母。</li>
	<li>调用 <code>addText</code>&nbsp;，<code>deleteText</code>&nbsp;，<code>cursorLeft</code> 和&nbsp;<code>cursorRight</code>&nbsp;的 <strong>总</strong> 次数不超过&nbsp;<code>2 * 10<sup>4</sup></code>&nbsp;次。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能设计并实现一个每次调用时间复杂度为 <code>O(k)</code> 的解决方案吗？</p>


    
## 解题方法：左右两个栈

栈长这样：

```
+-------
| 1 2 3
+-------
```

使用左右两个栈，右边的栈画成方向向左：

```
+-------    -------+
| 1 2 3      4 5 6 |
+-------    -------+
          ↑
        cursor
```

那么鼠标指向的位置不就是两栈的中间么？

+ 添加：

    直接将新字符串依次入栈左栈

+ 删除：

    直接左栈出栈

+ 左移：

    直接左栈出栈并加入到右栈

+ 右移：

    直接右栈出栈并加入到左栈

这题考的就是是否细心(下标是否挣钱以及是否越界问题)。

+ 时间复杂度：初始化$O(1)$，添加$O(len(text))$，左右移$O(k)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-27 09:48:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-27 10:04:48
 */
class TextEditor {
private:
    stack<char> left, right;

    string leftMax10() {
        string ans;
        for (int op = min(10, (int)left.size()); op > 0; op--) {
            ans += left.top();
            left.pop();
        }
        reverse(ans.begin(), ans.end());
        for (char c : ans) {
            left.push(c);
        }
        return ans;
    }
public:
    TextEditor() {}
    
    void addText(string text) {
        for (char c : text) {
            left.push(c);
        }
    }
    
    int deleteText(int k) {  // 假设k≥0
        int ans = 0;
        while (k-- && left.size()) {
            left.pop();
            ans++;
        }
        return ans;
    }
    
    string cursorLeft(int k) {
        while (k-- && left.size()) {
            right.push(left.top());
            left.pop();
        }
        return leftMax10();
    }
    
    string cursorRight(int k) {
        while (k-- && right.size()) {
            left.push(right.top());
            right.pop();
        }
        return leftMax10();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-27 10:05:13
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-27 10:19:35
'''
class TextEditor:
    def __init__(self) -> None:
        self.left = []  # 这里不能放到TextEditor下，因为多个测试用例会调用同一个TextEditor实例
        self.right = []
        
    def __10text(self) -> str:
        return ''.join(self.left[-10:])

    def addText(self, text: str) -> None:
        self.left.extend(text)

    def deleteText(self, k: int) -> int:
        # print(self.left)
        ans = min(len(self.left), k)
        del self.left[-k:]
        return ans

    def cursorLeft(self, k: int) -> str:
        while k and len(self.left):
            k -= 1
            self.right.append(self.left.pop())
        return self.__10text()

    def cursorRight(self, k: int) -> str:
        while k and len(self.right):
            k -= 1
            self.left.append(self.right.pop())
        return self.__10text()


# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-27 10:34:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-27 10:55:47
 */
package main

type TextEditor struct {
    left, right []byte
}


func Constructor() TextEditor {
    return TextEditor{};
}

func (this *TextEditor) text() string {
    return string(this.left[max(0, len(this.left) - 10):])
}


func (this *TextEditor) AddText(text string)  {
    this.left = append(this.left, text...)
}


func (this *TextEditor) DeleteText(k int) int {
    k = min(k, len(this.left))
    this.left = this.left[:len(this.left) - k]
    return k
}


func (this *TextEditor) CursorLeft(k int) string {
    for ; k > 0 && len(this.left) > 0; k-- {
        this.right = append(this.right, this.left[len(this.left) - 1])
        this.left = this.left[:len(this.left) - 1]
    }
    return this.text()
}


func (this *TextEditor) CursorRight(k int) string {
    for ; k > 0 && len(this.right) > 0; k-- {
        this.left = append(this.left, this.right[len(this.right) - 1])
        this.right = this.right[:len(this.right) - 1]
    }
    return this.text()
}


/**
 * Your TextEditor object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddText(text);
 * param_2 := obj.DeleteText(k);
 * param_3 := obj.CursorLeft(k);
 * param_4 := obj.CursorRight(k);
 */
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145898693)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/27/LeetCode%202296.%E8%AE%BE%E8%AE%A1%E4%B8%80%E4%B8%AA%E6%96%87%E6%9C%AC%E7%BC%96%E8%BE%91%E5%99%A8/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
