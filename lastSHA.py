'''
Author: LetMeFly
Date: 2025-03-12 10:38:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-12 10:38:22
'''
import subprocess

def get_latest_commit_sha() -> str:
    try:
        # 执行 git log 命令获取最后一次提交的 SHA
        sha = subprocess.check_output(['git', 'log', '-1', '--pretty=format:%H']).decode('utf-8').strip()
        return sha
    except subprocess.CalledProcessError as e:
        print(f"Error: {e}")
        return None

last_sha = get_latest_commit_sha()
print(last_sha)