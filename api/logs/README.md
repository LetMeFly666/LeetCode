# Logs模块

## 概述

Logs模块用于处理各种日志记录功能，目前包含按键记录API。

## 子模块

### keyboard_website

按键记录API，用于接收和存储第三方网站的用户按键数据。

#### 功能特性
- 支持跨域调用（CORS）
- 自动记录客户端IP和时间戳
- RESTful API设计
- 数据安全存储

#### 文件结构
```
logs/
├── url.js                    # 主路由配置
└── keyboard_website/
    ├── url.js               # 子路由配置
    ├── handler.js           # API处理逻辑
    ├── create_table.sql     # 数据库表创建脚本
    ├── migration.md         # 数据库迁移说明
    ├── demo.html           # API使用演示页面
    └── README.md           # 详细API文档
```

#### 快速开始

1. **创建数据库表**
   ```bash
   npx wrangler d1 execute CALENDAR_DB --file=logs/keyboard_website/create_table.sql
   ```

2. **API调用示例**
   ```javascript
   fetch('https://api.letmefly.xyz/logs/keyboard_website/', {
       method: 'POST',
       headers: {
           'Content-Type': 'application/json',
       },
       body: JSON.stringify({
           url: 'https://example.com',
           keyboardData: 'hello world'
       })
   })
   ```

3. **查看演示页面**
   打开 `keyboard_website/demo.html` 查看完整的使用示例

## 路由结构

```
/logs/keyboard_website/  → 按键记录API
```

## 技术栈

- Cloudflare Workers
- Cloudflare D1 数据库
- JavaScript ES6+
- RESTful API

## 部署说明

1. 确保数据库表已创建（参考migration.md）
2. 部署Cloudflare Workers应用
3. 测试API功能是否正常

## 扩展计划

未来可以在logs模块下添加更多日志记录功能：
- 用户行为日志
- 错误日志记录
- 性能监控日志
- 安全审计日志