/*
 * @Author: LetMeFly
 * @Date: 2025-02-21 12:31:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-21 14:33:28
 */
class Solution {
private:
    unordered_map<int, int> cache;

    int dfs(string& floor, int n, int len) {

    }
public:
    int minimumWhiteTiles(string& floor, int numCarpets, int carpetLen) {
        
    }
};

这段代码中我需要多次调用dfs函数，因此需要多次传递floor这一参数。

我想将floor变成类里的私有成员，但是this->floor = floor的话似乎会发生内存拷贝导致占用两份空间。

我不想只存一个全局的指针，这样使用起来是string*类型而不是string类型。

我有没有什么办法？


---

每创建一个Solution类，minimumWhiteTiles函数只会执行一次。

似乎可以private: string& globalFloor？

请详细解释这种引用。

---

这样可行吗？

class Solution {
private:
    unordered_map<int, int> cache;
    string& floor;

    int dfs(string& floor, int n, int len) {

    }
public:
    int minimumWhiteTiles(string& floor, int numCarpets, int carpetLen) {
        this->floor = floor;
    }
};

内存中是怎么个机制？

---

请解释这段代码，以及s都可以怎样被初始化

class Test {
private:
    string& s;
public:
    void f(i) {

    }
}

---

private:
    string& s;

是C++的引用吗？必须在类初始化时赋值吗？请详细解释之。

---

golang判断一个键是否在map里

---

java创建int,int的map

请解释为什么这么创建

---

import java.util.Map;
import java.util.HashMap;

其中Map和HashMap有什么区别和联系

---

java String有哪些api

---

java String取下标