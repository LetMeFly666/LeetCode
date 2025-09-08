-- 创建按键记录日志表
CREATE TABLE Logs_Keyboard_Website (
    log_id INTEGER PRIMARY KEY AUTOINCREMENT,
    url VARCHAR(500) NOT NULL,                    -- 调用方网站地址
    record_time DATETIME NOT NULL,               -- 记录时间
    client_ip VARCHAR(50),                       -- 客户端IP地址
    keyboard_data TEXT NOT NULL,                 -- 按键记录数据（字符串格式）
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP -- 创建时间戳
);