---
title: 循环队列的纯C语言实现
date: 2022-12-01 12:56:57
tags: [其他, 数据结构, 循环队列]
---

# 循环队列的纯C语言实现

其中SIZE为5，实则只能存放最多4个元素（否则需要专门记录元素个数是0还是5）

本来想用结构体实现的，但纯C的结构体没有```private```或者```成员函数```，因此就开全局变量了。

```c
#include <stdio.h>
#include <string.h>
#define SIZE 5

int a[SIZE];
int head = 0, tail = 0;

int next(int now) {
    return (now + 1) % SIZE;
}

void push(int n) {
    a[tail] = n;
    tail = next(tail);
}

int pop() {
    int val = a[head];
    head = next(head);
    return val;
}

int size() {
    return (tail - head + SIZE) % SIZE;
}

int main() {
    while (1) {
        char op[10];
        puts("push or pop or size or exit? ");
        scanf("%s", op);
        if (!strcmp(op, "push")) {
            if (size() == SIZE) {
                puts("Error! no more space");
            }
            else {
                int t;
                puts("push what? ");
                scanf("%d", &t);
                push(t);
            }
        }
        else if (!strcmp(op, "pop")) {
            if (!size()) {
                puts("Error! The queue is empty!");
            }
            else {
                printf("%d\n", pop());
            }
        }
        else if (!strcmp(op, "size")) {
            int nowSize = size();
            printf("The size of the queue is %d\n", nowSize);
        }
        else if (!strcmp(op, "exit")) {
            puts("Bye~");
            break;
        }
        else {
            puts("Error option!");
        }
    }
    return 0;
}
```

> 原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/12/01/Other-Datastruct-XunHuanDuiLie/)哦~
> [https://leetcode.letmefly.xyz/2022/12/01/Other-Datastruct-XunHuanDuiLie/](https://leetcode.letmefly.xyz/2022/12/01/Other-Datastruct-XunHuanDuiLie/)
