<!--
 * @Author: LetMeFly
 * @Date: 2025-01-17 11:32:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-07 11:40:33
-->
俺的开发小日志

## 跑起来CloudWeGo

```bash
git clone git@cloudwego/kitex-examples.git
cd kitex-example
go run .  # 这里我本来使用的Go 1.19.5不支持go.mod里的toolchain，所以升级为了当前最新版go1.23.5
# 令起终端
go run ./client
```

## 开了个私有仓库来记录kitex学习过程中的修改

[Github@LetMeFly666/kitex-examples](https://github.com/LetMeFly666/kitex-examples/)

起了个别名：

```bash
git config --local alias.pushLet "push Let main:master"
```

后续想要push到远端的时候直接`git pushLet`就好。

TODOED: 给CloudWeGo提PR，不sleep 1 秒。

可行吗？试试吧。像个办法看进程启动了还是异常退出了。

不行就不PR了。

TODOED: https://www.cloudwego.io/zh/docs/kitex/getting-started/tutorial/#%E6%8B%89%E5%8F%96%E4%BE%9D%E8%B5%96  的上面的代码段，build.sh后面有一个tab，导致渲染出来的注释不对齐

## 自定义RPC函数

1. 修改`.thrift`文件
2. 使用`kitex`生成新代码文件
    
    ```bash
    kitex -module "github.com/cloudwego/kitex-examples" -service a.b.c hello.thrift
    ```

3. 更新`go`文件

    1. 更新`./handler.go`，实现自定义的RPC函数
    2. 更新`./client/main.go`，调用这个远程函数
