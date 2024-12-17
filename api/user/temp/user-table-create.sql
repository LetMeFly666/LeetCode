CREATE TABLE Users (
    userid INTEGER PRIMARY KEY AUTOINCREMENT, 
    username VARCHAR(255) UNIQUE NOT NULL, 
    password VARCHAR(255) NOT NULL
);

CREATE TABLE User_LoginInfo (
    login_id INTEGER PRIMARY KEY AUTOINCREMENT,
    userid INTEGER NOT NULL,
    loginTime DATETIME NOT NULL,
    loginIp VARCHAR(50),
    passKey VARCHAR(255) NOT NULL,
    FOREIGN KEY (userid) REFERENCES Users(userid)
);
