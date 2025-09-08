# 数据库迁移说明

## 创建Logs_Keyboard_Website表

在部署新的按键记录API之前，需要在Cloudflare D1数据库中创建新的数据表。

### 方法一：使用wrangler命令行工具

```bash
# 进入项目目录
cd LeetCode/api

# 执行SQL文件创建表
npx wrangler d1 execute CALENDAR_DB --file=logs/keyboard_website/create_table.sql

# 或者直接执行SQL命令
npx wrangler d1 execute CALENDAR_DB --command="
CREATE TABLE Logs_Keyboard_Website (
    log_id INTEGER PRIMARY KEY AUTOINCREMENT,
    url VARCHAR(500) NOT NULL,
    record_time DATETIME NOT NULL,
    client_ip VARCHAR(50),
    keyboard_data TEXT NOT NULL,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);"
```

### 方法二：通过Cloudflare Dashboard

1. 登录Cloudflare Dashboard
2. 进入D1数据库管理页面
3. 选择对应的数据库（database_id: 40bf17b1-b598-4ad2-aad0-860f2b282cee）
4. 在SQL控制台中执行以下SQL：

```sql
CREATE TABLE Logs_Keyboard_Website (
    log_id INTEGER PRIMARY KEY AUTOINCREMENT,
    url VARCHAR(500) NOT NULL,
    record_time DATETIME NOT NULL,
    client_ip VARCHAR(50),
    keyboard_data TEXT NOT NULL,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);
```

### 验证表创建

执行以下SQL验证表是否创建成功：

```sql
-- 查看所有表
SELECT name FROM sqlite_master WHERE type='table';

-- 查看表结构
PRAGMA table_info(Logs_Keyboard_Website);

-- 测试插入数据
INSERT INTO Logs_Keyboard_Website (url, record_time, client_ip, keyboard_data)
VALUES ('https://test.com', '2025-01-07T12:00:00.000Z', '192.168.1.1', 'test data');

-- 查询测试数据
SELECT * FROM Logs_Keyboard_Website LIMIT 5;
```

## 表结构说明

| 字段名 | 类型 | 约束 | 描述 |
|--------|------|------|------|
| log_id | INTEGER | PRIMARY KEY AUTOINCREMENT | 自增主键 |
| url | VARCHAR(500) | NOT NULL | 调用方网站地址 |
| record_time | DATETIME | NOT NULL | 记录时间 |
| client_ip | VARCHAR(50) | | 客户端IP地址 |
| keyboard_data | TEXT | NOT NULL | 按键记录数据 |
| created_at | DATETIME | DEFAULT CURRENT_TIMESTAMP | 创建时间戳 |

## 注意事项

1. 确保在生产环境中执行此迁移
2. 建议先在测试环境中验证表结构
3. 迁移完成后需要重新部署Cloudflare Workers应用
4. 可以考虑添加索引以提高查询性能：

```sql
-- 为url字段添加索引（可选）
CREATE INDEX idx_logs_keyboard_url ON Logs_Keyboard_Website(url);

-- 为record_time字段添加索引（可选）
CREATE INDEX idx_logs_keyboard_time ON Logs_Keyboard_Website(record_time);
```