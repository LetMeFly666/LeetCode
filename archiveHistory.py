'''
Author: LetMeFly
Date: 2024-06-11 21:59:50
LastEditors: LetMeFly
LastEditTime: 2024-06-11 22:21:22
'''
"""
写一个Python脚本，实现以下功能：
在一个Git仓库中，将每次commit打包成Zip文件。
文件命名格式为对应commit的{日期}{时间}{commitHash}.zip，例如20240622-220603-54a2e7fe41081489e8913436daa7bee5ae878d26.zip
"""
import os
import zipfile
import git
from datetime import datetime
import shutil

def zip_commit(repo_path, commit: git.Commit):
    # 提取 commit 日期和时间
    print(commit.message)
    commit_datetime = datetime.fromtimestamp(commit.committed_date)
    date_str = commit_datetime.strftime('%Y%m%d')
    time_str = commit_datetime.strftime('%H%M%S')
    
    # 构造 zip 文件名
    zip_filename = f"archived/{date_str}-{time_str}-{commit.hexsha}.zip"
    
    # 创建一个临时目录来存储这个 commit 的文件
    temp_dir = f"temp"
    os.makedirs(temp_dir, exist_ok=True)
    
    # 导出 commit 的文件
    repo.git.checkout(commit)
    for item in repo.tree().traverse():
        if item.type == 'blob':  # 确保这是一个文件而不是一个子目录
            item_path = os.path.join(repo_path, item.path)
            os.makedirs(os.path.dirname(os.path.join(temp_dir, item.path)), exist_ok=True)
            with open(item_path, 'rb') as fsrc, open(os.path.join(temp_dir, item.path), 'wb') as fdst:
                fdst.write(fsrc.read())

    # 打包成 zip 文件
    with zipfile.ZipFile(zip_filename, 'w') as zipf:
        for root, _, files in os.walk(temp_dir):
            for file in files:
                zipf.write(os.path.join(root, file), os.path.relpath(os.path.join(root, file), temp_dir))
    
    # 清理临时目录
    shutil.rmtree(temp_dir)

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
