/*
 * @Author: LetMeFly
 * @Date: 2024-12-31 15:31:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-01 17:58:11
 */
很棒，我已经完成了签名的验证。现在我想要将一个commit重新签名，其他信息不变。
可以做到吗？



git本地有两个用户，如何分别为其配置ssh公钥密钥



python写一个脚本：

从HEAD开始往前遍历，直到遇到可验证的签名为止。
将HEAD开始的所有连续的不可验证的签名重新签名。




git log --pretty=online可不可以指定显示数量




git log --pretty=online有没有办法从某次commit开始显示



只输出commit hash



git某次commit的下一次commit



不，比如我HEAD~1是HEAD的上一次commit
我如何表示一个commitHash的下一次commit



为何我执行`git filter-branch -f --commit-filter 'git commit-tree -S "$@";' HEAD~2..HEAD`命令的时候
在终端中直接执行就能正常运行，而在python中调用os.system执行就会报错：

```
Proceeding with filter-branch...

fatal: ambiguous argument 'commit-tree': unknown revision or path not in the working tree.
Use '--' to separate paths from revisions, like this:
'git <command> [<revision>...] -- [<file>...]'
```




执行如下代码时报错：

```
result = subprocess.run(
        ["git", "filter-branch", "-f", "--commit-filter", """'git commit-tree -S "$@";'""", f"{commit_hash}..HEAD"],
        check=True,
        text=True,
        # stdout=subprocess.PIPE,
        # stderr=subprocess.PIPE,
    )
    print(result.stdout)
```

```
Rewrite bde2a1b75e8881d2911ec557aa0ae97414b75a47 (1/2) (0 seconds passed, remaining 0 predicted)    git commit-tree: line 52: git commit-tree -S "$@";: command not found
could not write rewritten commit
Traceback (most recent call last):
  File "F:\OtherApps\Program\Git\Store\Store20_LeetCode\reassign.py", line 65, in <module>
    main()
  File "F:\OtherApps\Program\Git\Store\Store20_LeetCode\reassign.py", line 49, in main
    re_assign('HEAD~2')
  File "F:\OtherApps\Program\Git\Store\Store20_LeetCode\reassign.py", line 36, in re_assign
    result = subprocess.run(
  File "F:\OtherApps\Program\Python\Python\lib\subprocess.py", line 528, in run
    raise CalledProcessError(retcode, process.args,
subprocess.CalledProcessError: Command '['git', 'filter-branch', '-f', '--commit-filter', '\'git commit-tree -S "$@";\'', 'HEAD~2..HEAD']' returned non-zero exit status 1.
```





很棒，这个问题解决了。
但是我发现了一个新的问题，在进行上述操作时，会显示如下warning并卡住几秒。
```
Store\Store20_LeetCode\OtherSource\gitcode_knowledge
WARNING: git-filter-branch has a glut of gotchas generating mangled history
         rewrites.  Hit Ctrl-C before proceeding to abort, then use an
         alternative filtering tool such as 'git filter-repo'
         (https://github.com/newren/git-filter-repo/) instead.  See the
         filter-branch manual page for more details; to squelch this warning,
         set FILTER_BRANCH_SQUELCH_WARNING=1.
Proceeding with filter-branch...
```
我有没有办法让他不显示这个提示并且不卡住？




```
    env = os.environ.copy()
    env['FILTER_BRANCH_SQUELCH_WARNING'] = 1
    result = subprocess.run(
        ["git", "filter-branch", "-f", "--commit-filter", 'git commit-tree -S "$@";', f"{commit_hash}..HEAD"],
        check=True,
        text=True,
        # stdout=subprocess.PIPE,
        # stderr=subprocess.PIPE,
        env=env,
    )
```
报错：
```
  File "F:\OtherApps\Program\Git\Store\Store20_LeetCode\reassign.py", line 68, in <module>
    main()
  File "F:\OtherApps\Program\Git\Store\Store20_LeetCode\reassign.py", line 52, in main
    re_assign('HEAD~2')
  File "F:\OtherApps\Program\Git\Store\Store20_LeetCode\reassign.py", line 38, in re_assign
    result = subprocess.run(
  File "F:\OtherApps\Program\Python\Python\lib\subprocess.py", line 505, in run
    with Popen(*popenargs, **kwargs) as process:
  File "F:\OtherApps\Program\Python\Python\lib\subprocess.py", line 951, in __init__
    self._execute_child(args, executable, preexec_fn, close_fds,
  File "F:\OtherApps\Program\Python\Python\lib\subprocess.py", line 1420, in _execute_child
    hp, ht, pid, tid = _winapi.CreateProcess(executable, args,
TypeError: environment can only contain strings
```



subprocess.CalledProcessError: Command '['git', 'filter-branch', '-f', '--commit-filter', 'git commit-tree -S "$@";', 'HEAD..HEAD']' returned non-zero exit status 2.
Found nothing to rewrite