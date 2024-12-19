CREATE TABLE Calendar_Tags (
    tagId INTEGER PRIMARY KEY AUTOINCREMENT,
    tagName VARCHAR(255) NOT NULL,
    tagColor VARCHAR(7) NOT NULL -- 十六进制的RGB值，例如 "#FF5733"
);

CREATE TABLE Calendar_Tags (
    tagId INTEGER PRIMARY KEY AUTOINCREMENT,
    tagName VARCHAR(255) NOT NULL,
    tagColor VARCHAR(7) NOT NULL
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
    FOREIGN KEY (taskId) REFERENCES Calendar_Tasks(taskId),
    FOREIGN KEY (tagId) REFERENCES Calendar_Tags(tagId)
);
