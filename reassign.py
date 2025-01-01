'''
Author: LetMeFly
Date: 2024-12-31 16:51:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-01 18:00:25
'''
import os
import subprocess


# 判断一个commit是否按配置签名
def verify_commit(commit_hash: str) -> bool:
    result = subprocess.run(
        ['git', 'verify-commit', commit_hash],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    return not result.returncode


# 获取一个commit的上一个commit
def get_parent_commit(commit_hash: str) -> str:
    result = subprocess.run(
        ['git', 'log', commit_hash, '--pretty=%H', '-n', '2'],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    return result.stdout.decode('utf-8').strip().split()[-1]


# 将从某次commit开始至HEAD的所有commit重新签名
def re_assign(commit_hash: str) -> None:
    # cmd = f'git filter-branch -f --commit-filter \'git commit-tree -S "$@";\' {commit_hash}..HEAD'
    # print(cmd)
    # os.system(cmd)
    env = os.environ.copy()
    env['FILTER_BRANCH_SQUELCH_WARNING'] = "1"
    result = subprocess.run(
        ["git", "filter-branch", "-f", "--commit-filter", 'git commit-tree -S "$@";', f"{commit_hash}..HEAD"],
        env=env,
    )
    print(result.returncode)
    # subprocess.Popen(cmd)


def main():
    os.chdir('OtherSource/gitcode_knowledge')
    # re_assign('HEAD~2')
    # return
    if verify_commit('HEAD'):  # HEAD的签名也能被验证
        return
    notVerified = 'HEAD'
    while True:
        next = get_parent_commit(notVerified)
        if next == notVerified:
            break
        notVerified = next
        if verify_commit(next):
            break
    print(notVerified)
    re_assign(notVerified)


if __name__ == '__main__':
    main()
