'''
Author: LetMeFly
Date: 2024-06-11 21:59:50
LastEditors: LetMeFly
LastEditTime: 2024-06-11 22:50:32
'''
"""
写一个Python脚本，实现以下功能：
在一个Git仓库中，将每次commit打包成Zip文件。
文件命名格式为对应commit的{日期}{时间}{commitHash}.zip，例如20240622-220603-54a2e7fe41081489e8913436daa7bee5ae878d26.zip
"""
import os
import git
from datetime import datetime
import os

def zip_commit(repo_path, commit: git.Commit):
    # 提取 commit 日期和时间
    print(commit.message)
    commit_datetime = datetime.fromtimestamp(commit.committed_date)
    date_str = commit_datetime.strftime('%Y%m%d')
    time_str = commit_datetime.strftime('%H%M%S')
    
    # 导出 commit 的文件
    repo.git.checkout(commit)
    
    # 构造 zip 文件名
    zip_filename = f"../archived/{date_str}-{time_str}-{commit.hexsha}.zip"

    # 使用zip命令压缩repo文件夹(默认不会压缩.git目录)
    zip_command = f"cd repo && zip -r {zip_filename} ."
    os.system(zip_command)

if __name__ == "__main__":
    # 指定你的 Git 仓库路径
    repo_path = 'repo'
    os.makedirs('archived', exist_ok=True)
    
    # 打开仓库
    repo = git.Repo(repo_path)
    
    # 遍历所有的 commit
    for commit in repo.iter_commits():
        zip_commit(repo_path, commit)
    
    # 切换回默认分支（例如 'main' 或 'master'）
    repo.git.checkout('master')
