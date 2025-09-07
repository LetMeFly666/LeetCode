# 按键记录API

## 功能描述

此API用于接收第三方网站的用户按键记录数据，并将其存储到数据库中。支持跨域调用，适用于网站用户行为分析、按键统计等场景。

## API端点

```
POST /logs/keyboard_website/
```

## 请求参数

### 请求方法
- **POST**: 提交按键记录数据

### 请求头
```
Content-Type: application/json
```

### 请求体参数

| 参数名 | 类型 | 必需 | 描述 |
|--------|------|------|------|
| url | string | 是 | 调用方网站地址 |
| keyboardData | string | 是 | 按键记录数据（字符串格式） |

### 自动记录参数
以下参数由服务器自动记录，无需在请求中提供：
- **时间**: 服务器接收请求的时间戳
- **IP地址**: 客户端IP地址（通过CF-Connecting-IP等头部获取）

## 请求示例

### JavaScript fetch示例
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
.then(response => response.json())
.then(data => {
    console.log('Success:', data);
})
.catch((error) => {
    console.error('Error:', error);
});
```

### jQuery示例
```javascript
$.ajax({
    url: 'https://api.letmefly.xyz/logs/keyboard_website/',
    type: 'POST',
    contentType: 'application/json',
    data: JSON.stringify({
        url: window.location.href,
        keyboardData: 'user typed: hello'
    }),
    success: function(data) {
        console.log('Success:', data);
    },
    error: function(xhr, status, error) {
        console.error('Error:', error);
    }
});
```

### curl示例
```bash
curl -X POST https://api.letmefly.xyz/logs/keyboard_website/ \
  -H "Content-Type: application/json" \
  -d '{
    "url": "https://example.com",
    "keyboardData": "hello world"
  }'
```

## 响应格式

### 成功响应
```json
{
    "success": true,
    "message": "Keyboard data recorded successfully",
    "recordId": 123,
    "recordTime": "2025-01-07T12:00:00.000Z"
}
```

### 错误响应
```json
{
    "success": false,
    "error": "Missing required parameters: url and keyboardData"
}
```

## 状态码

| 状态码 | 描述 |
|--------|------|
| 200 | 成功记录数据 |
| 400 | 请求参数错误 |
| 405 | 请求方法不允许（仅支持POST） |
| 500 | 服务器内部错误 |

## 跨域支持

此API支持CORS跨域请求，允许任何域名调用。响应头包含：
- `Access-Control-Allow-Origin: *`
- `Access-Control-Allow-Methods: POST, OPTIONS`
- `Access-Control-Allow-Headers: Content-Type`

## 使用场景

1. **按键统计**: 记录用户在网站上的按键行为
2. **用户行为分析**: 分析用户输入模式
3. **网站交互监控**: 监控用户与网站的交互情况

## 数据存储

数据存储在 `Logs_Keyboard_Website` 表中，包含以下字段：
- `log_id`: 自增主键
- `url`: 调用方网站地址
- `record_time`: 记录时间
- `client_ip`: 客户端IP地址
- `keyboard_data`: 按键记录数据
- `created_at`: 创建时间戳

## 注意事项

1. 请确保传入的按键数据不包含敏感信息（如密码等）
2. 建议对按键数据进行适当的过滤和处理
3. API有基本的参数验证，但建议调用方也进行数据验证
4. 服务器会自动记录客户端IP和时间，无需手动传入