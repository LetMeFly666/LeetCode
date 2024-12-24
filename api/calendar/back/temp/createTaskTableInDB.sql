-- CREATE TABLE Calendar_Tags (
--     tagId INTEGER PRIMARY KEY AUTOINCREMENT,
--     tagName VARCHAR(255) NOT NULL,
--     tagColor VARCHAR(7) NOT NULL -- 十六进制的RGB值，例如 "#FF5733"
-- );

-- CREATE TABLE Calendar_Tags (
--     tagId INTEGER PRIMARY KEY AUTOINCREMENT,
--     tagName VARCHAR(255) NOT NULL,
--     tagColor VARCHAR(7) NOT NULL
-- );

-- -- 步骤1: 在 Calendar_Tags 表中添加 creater 列
-- ALTER TABLE Calendar_Tags
-- ADD COLUMN creater INT;
-- -- 步骤1: 在 Calendar_Tags 表中添加 creater 列
-- ALTER TABLE Calendar_Tags
-- ADD CONSTRAINT fk_creater
-- FOREIGN KEY (creater) REFERENCES Users(userid)
-- ON DELETE SET CASCADE;  -- 可根据需要修改删除行为，如 SET NULL 或 CASCADE


-- -- 步骤1: 创建一个新表并定义外键约束
-- CREATE TABLE Calendar_Tags_new (
--     id INTEGER PRIMARY KEY,
--     tag_name TEXT,
--     creater INTEGER,
--     FOREIGN KEY (creater) REFERENCES Users(userid)
--     ON DELETE CASCADE
-- );

-- -- 步骤2: 将旧表中的数据复制到新表
-- INSERT INTO Calendar_Tags_new (id, tag_name, creater)
-- SELECT id, tag_name, creater FROM Calendar_Tags;

-- -- 步骤3: 删除旧表
-- DROP TABLE Calendar_Tags;

-- -- 步骤4: 将新表重命名为原来的表名
-- ALTER TABLE Calendar_Tags_new RENAME TO Calendar_Tags;


-- -- 创建一个新表，添加 creater 列并设置外键约束
-- CREATE TABLE Calendar_Tags (
--     tagId INTEGER PRIMARY KEY AUTOINCREMENT,
--     tagName VARCHAR(255) NOT NULL,
--     tagColor VARCHAR(7) NOT NULL,  -- 十六进制的RGB值，例如 "#FF5733"
--     creater INTEGER NOT NULL,
--     FOREIGN KEY (creater) REFERENCES Users(userid)
-- );

-- CREATE TABLE Calendar_Tags (
--     tagId INTEGER PRIMARY KEY AUTOINCREMENT,
--     tagName VARCHAR(255) NOT NULL,
--     tagColor VARCHAR(7) NOT NULL,
--     creater INTEGER NOT NULL,
--     FOREIGN KEY (creater) REFERENCES Users(userid)
-- );

CREATE TABLE Calendar_Tags (
    tagId INTEGER PRIMARY KEY AUTOINCREMENT,
    tagName VARCHAR(255) NOT NULL,
    tagColor VARCHAR(7) NOT NULL,
    creator INTEGER NOT NULL,
    FOREIGN KEY (creator) REFERENCES Users(userid)
);



-- CREATE TABLE Tasks (
--     taskId INTEGER PRIMARY KEY AUTOINCREMENT,     -- 任务的唯一标识
--     title VARCHAR(255) NOT NULL,                  -- 任务标题
--     description TEXT,                             -- 任务描述
--     startTime DATETIME NOT NULL,                  -- 任务开始时间
--     during INTEGER NOT NULL,                      -- 任务持续时长（以分钟为单位）
--     userid INTEGER NOT NULL,                      -- 用户ID，关联Users表
--     FOREIGN KEY (userid) REFERENCES Users(userid) -- 外键，确保任务只能由已存在的用户创建
-- );

-- CREATE TABLE Tasks (
--     taskId INTEGER PRIMARY KEY AUTOINCREMENT,     
--     title VARCHAR(255) NOT NULL,                  
--     description TEXT,                             
--     startTime DATETIME NOT NULL,                  
--     during INTEGER NOT NULL,                      
--     userid INTEGER NOT NULL,                      
--     FOREIGN KEY (userid) REFERENCES Users(userid) 
-- );

-- CREATE TABLE Calendar_Tasks (
--     taskId INTEGER PRIMARY KEY AUTOINCREMENT,
--     title VARCHAR(255) NOT NULL,
--     description TEXT,
--     startTime DATETIME NOT NULL,
--     during INTEGER NOT NULL, -- 任务持续时长，以分钟为单位
--     tagId INTEGER,
--     userid INTEGER NOT NULL,
--     FOREIGN KEY (tagId) REFERENCES Calendar_Tags(tagId),
--     FOREIGN KEY (userid) REFERENCES Users(userid)
-- );

-- CREATE TABLE Calendar_Tasks (
--     taskId INTEGER PRIMARY KEY AUTOINCREMENT,
--     title VARCHAR(255) NOT NULL,
--     description TEXT,
--     startTime DATETIME NOT NULL,
--     during INTEGER NOT NULL,
--     tagId INTEGER,
--     userid INTEGER NOT NULL,
--     FOREIGN KEY (tagId) REFERENCES Calendar_Tags(tagId),
--     FOREIGN KEY (userid) REFERENCES Users(userid)
-- );

CREATE TABLE Calendar_Tasks (
    taskId INTEGER PRIMARY KEY AUTOINCREMENT,
    title VARCHAR(255) NOT NULL,
    description TEXT,
    startTime DATETIME NOT NULL, -- 任务开始时间
    during INTEGER NOT NULL, -- 任务持续时长，单位：分钟
    userid INTEGER NOT NULL,
    FOREIGN KEY (userid) REFERENCES Users(userid)
);

CREATE TABLE Calendar_Tasks (
    taskId INTEGER PRIMARY KEY AUTOINCREMENT,
    title VARCHAR(255) NOT NULL,
    description TEXT,
    startTime DATETIME NOT NULL,
    during INTEGER NOT NULL,
    userid INTEGER NOT NULL,
    FOREIGN KEY (userid) REFERENCES Users(userid)
);

-- Task

CREATE TABLE Calendar_TaskTag (
    taskId INTEGER NOT NULL,
    tagId INTEGER NOT NULL,
    PRIMARY KEY (taskId, tagId),
    FOREIGN KEY (taskId) REFERENCES Calendar_Tasks(taskId) ON DELETE CASCADE,
    FOREIGN KEY (tagId) REFERENCES Calendar_Tags(tagId) ON DELETE CASCADE
);
