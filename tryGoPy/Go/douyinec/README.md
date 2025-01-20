<!--
 * @Author: LetMeFly
 * @Date: 2025-01-17 11:32:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-17 11:36:09
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