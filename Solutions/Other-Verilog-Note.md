---
title: Verilog学习笔记 - 极简极入门级
date: 2023-01-06 19:02:59
tags: [Verilog, 简单, Notes]
---

# Verilog小总结

## 01 语言风格、语法

Verilog语法和C语言较像，每句结尾同样需要分号。

```verilog
assign a = b ? c : d;
```

注释方式和C语言一致，可以单行注释（在```//```之后），也可以多行注释（在```/*```和```*/```之间）

## 02 module模块

Verilog语言绝大多数内容需要包括在```module```和```endmodule```之间

```verilog
module Demo(a, b, c, d);
    assign a = b ? c : d;
endmodule
```

其中module后的参数列表写法比较灵活，可以只写参数名（如上），也可以加上参数类型；可以写到一行，也可以随意换行（或缩进）；也可以写明那个参数是输入，那个参数是输出

```verilog
module Demo(
    input reg a,
    output wire[0:3] b
);
endmodule
```

## 03 赋值

wire类型的数据需要用assign来赋值。因为线是连通的，所以假设```assign a = b```，那么当```b```变化时，```a```会随之发生变化

reg类型的数据需要在always语句块中进行赋值

always用法：

```verilog
always @ (event) begin
	[multiple statements]
end
```

例如

```verilog
// module ...

always @ (a) begin  // 此处空格非必须
    b = a;  // 不需要写assign，也不能写assign，因为b是reg类型的
end
// endmodule
```

上述代码的意思是，当a发生变化时，执行always语句块中的语句（```b = a```）

其中```event```可以有```*```（代表所有事件）、```变量名```、```posedge```（上升沿）、```negedge```（下降沿）  （等）

## 04 testbench、延时

Verilog可以编写testbench来对信号进行赋值

一般方法为，再建立一个Verilog源代码文件，其中写一个module，在这个module中对编写好的待测module进行测试（赋值以便观察仿真结果等）

例如，写了一个加法module（可以另存为Test.v等）

```verilog
module Test (
    input a,
    input b,
    output c
  );
  assign c = a + b;
endmodule
```

则可以编写测试文件（可以另存为Source.v等）

```verilog
`timescale 1ns/1ps  // 时延单位1ns，时延精度1ps
module source;
 
  reg signal_a;
  reg signal_b;
  wire signal_c;
 
  add U0(
     .a(signal_a),
     .b(signal_b),
     .c(signal_c)
    );
  initial
    begin
      signal_a = 0;
      signal_b = 0;
      #10;  // 延时10毫秒
      signal_a = 0;
      signal_b = 1;
      #10;
      signal_a = 1;
      signal_b = 0;
      #10;
      signal_a = 1;
      signal_b = 1;
      #10;
      $stop;
    end
 
endmodule
```

赋值部分一般写到```initial ... begin```和```end```之间。

其中延时为```#```加上要延时的时间

## 05 数字表示

Verilog中数字很多时候使用“```位宽``` ```'``` ```进制``` ```数值```”的方式表示，例如

```4'b1001```代表二进制下的四位数```1001```

## End

<center><font size="6px" face="Ink Free">The End, thanks!</font></center>

> 原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/01/03/Other-Verilog-Note/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128584160](https://letmefly.blog.csdn.net/article/details/128584160)
