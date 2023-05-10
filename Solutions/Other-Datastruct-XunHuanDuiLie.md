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

**执行结果：**

```
PS F:\OtherApps\Program\VsCode\Code> gcc MyQueue.c -o MyQueue
PS F:\OtherApps\Program\VsCode\Code> ./MyQueue.exe
push or pop or size or exit? 
size
The size of the queue is 0   
push or pop or size or exit? 
pop
Error! The queue is empty!   
push or pop or size or exit? 
push
push what? 
1
push or pop or size or exit? 
size
The size of the queue is 1   
push or pop or size or exit? 
pop
1
push or pop or size or exit? 
size
The size of the queue is 0
push or pop or size or exit?
push
push what? 
1
push or pop or size or exit? 
push
push what? 
2
push or pop or size or exit? 
push
push what? 
3
push or pop or size or exit? 
size
The size of the queue is 3
push or pop or size or exit?
pop
1
push or pop or size or exit?
size
The size of the queue is 2
push or pop or size or exit?
push
push what? 
4
push or pop or size or exit? 
size
The size of the queue is 3
push or pop or size or exit?
push 5
push what? 
push or pop or size or exit?
size
The size of the queue is 4
push or pop or size or exit?
push 5
Error! no more space
push or pop or size or exit?
Error option!
push or pop or size or exit?
push
Error! no more space
push or pop or size or exit?
pop
PS F:\OtherApps\Program\VsCode\Code> gcc MyQueue.c -o MyQueue
PS F:\OtherApps\Program\VsCode\Code> ./MyQueue.exe
push or pop or size or exit? 
push
push what? 
1
push or pop or size or exit? 
push
push what? 
2
push or pop or size or exit? 
size
The size of the queue is 2   
push or pop or size or exit? 
push
push what? 
3
push or pop or size or exit? 
size
The size of the queue is 3
push or pop or size or exit?
push 4
push what? 
push or pop or size or exit?
size
The size of the queue is 4
push or pop or size or exit?
push 5
push what? 
push or pop or size or exit?
size
The size of the queue is 0
push or pop or size or exit?
exit
Bye~
```

# 以下为非纯C实现

为[@LYL]()改了3个BUG（三个```// ----```为修改之处）

```cpp
#include <iostream>
using namespace std;
#define ERROR 0
#define OK 1
#define OVERFLOW 2 // --------------------------------------
#define MAXQSIZE 100
typedef int QElemType;
typedef int Status;

//队列的顺序存储结构
typedef struct {
	QElemType *base; //存储空间的基地址
	int front;		 //头指针
	int rear;		 //尾指针
} SqQueue;

Status InitQueue(SqQueue &);			//初始化队列
Status EnQueue(SqQueue &, QElemType);	//入队
Status DeQueue(SqQueue &, QElemType &); //出队
Status QueueLength(SqQueue);			//队列长度
Status QueueTraverse(SqQueue);			//输出队列
int main() {
	SqQueue S;
	int e, a;
	if (InitQueue(S))
		cout << "循环队列初始化成功！" << endl;
	else
		cout << "循环队列初始化失败！" << endl;
	while (1) {
		cout << "\n【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出" << endl;
		cout << "请选择要进行的操作：";
		cin >> a;
		switch (a) {
		case 1:
			int x, n;
			cout << "请输入要插入的元素个数：";
			cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "请输入第" << i + 1 << "元素值：";
				cin >> x;
				EnQueue(S, x);
			}
			cout << "入队完成！" << endl;
			break;  // ---------------------------------------------- 这里忘了break
		case 2:
			cout << "请输入要删除的元素个数：";
			cin >> n;
			for (int j = 0; j < n; j++) {
				if (!DeQueue(S, e))
					cout << "出队失败！" << endl;
				else
					cout << "第【" << j + 1 << "】个元素：" << e << " 出队成功！" << endl;
			}
			break;
		case 3:
			if (!QueueTraverse(S))
				cout << "队列为空!" << endl;
			break;
		case 4:
			QueueLength(S);
			break;
		case 0:
			return OK;
		default:
			return OK;
		}
	}
	return 0;
}
//循环队列的初始化
Status InitQueue(SqQueue &Q) { //构造一个空队列Q

	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW); //存储分配失败
	Q.front = Q.rear = 0;
	return OK;
}

//循环队列的入队
Status EnQueue(SqQueue &Q, QElemType e) { //插入元素e为Q的新的队尾元素

	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR; //尾指针在循环意义上加1后等于头指针，表明队满
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
//循环队列的出队
Status DeQueue(SqQueue &Q, QElemType &e) { //删除Q的队头元素，用e返回其值

	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
//输出循环队列
Status QueueTraverse(SqQueue Q) {
	cout << "当前队列为：";
	if (Q.front == Q.rear)
		return ERROR;
	while (Q.front != Q.rear) {  //队列非空
		cout << Q.base[Q.front] << " ";
		Q.front = (Q.front + 1) % MAXQSIZE;
	}
	cout << endl;
	return OK;  // ----------------------------------- 不返回结果的话 有的编译器无法编译通过
}

//求循环队列长度
Status QueueLength(SqQueue Q) {  //返回Q的元素个数

	int len = (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
	cout << "循环队列的长度为：" << len << endl;
	return OK;
}
```

执行结果

```
循环队列初始化成功！

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出
请选择要进行的操作：1
请输入要插入的元素个数：2
请输入第1元素值：1
请输入第2元素值：2
入队完成！

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出请选择要进行的操作：3
当前队列为：1 2 

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出
请选择要进行的操作：4
循环队列的长度为：2

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出
请选择要进行的操作：3
当前队列为：1 2 

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出
请选择要进行的操作：2
请输入要删除的元素个数：1
第【1】个元素：1 出队成功！

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出
请选择要进行的操作：3
当前队列为：2 

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出
请选择要进行的操作：4
循环队列的长度为：1

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出
请选择要进行的操作：1
请输入要插入的元素个数：5
请输入第1元素值：10
请输入第2元素值：20
请输入第3元素值：30
请输入第4元素值：40
请输入第5元素值：50
入队完成！

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出
请选择要进行的操作：4
循环队列的长度为：6

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出
请选择要进行的操作：3
当前队列为：2 10 20 30 40 50 

【1】入队  【2】出队  【3】输出队列  【4】求队列长度  【0】退出
请选择要进行的操作：0
```

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/01/Other-Datastruct-XunHuanDuiLie/)哦~
> [https://blog.tisfy.eu.org/2022/12/01/Other-Datastruct-XunHuanDuiLie/](https://blog.tisfy.eu.org/2022/12/01/Other-Datastruct-XunHuanDuiLie/)
