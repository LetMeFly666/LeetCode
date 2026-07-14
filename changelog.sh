git rebase -i HEAD~4 --exec 'git commit --amend --no-edit --author="Tisfy <Tisfy@foxmail.com>" --date="$(git show -s --format=%aI HEAD)"'

pick 0f572f87b init: by hand (解决下重复任务在日历中显示多次的问题)
exec git commit --amend --no-edit --author="Tisfy <Tisfy@foxmail.com>" --date="$(git show -s --format=%aI HEAD)"
pick 5e627fea3 copilot: v1
exec git commit --amend --no-edit --author="Tisfy <Tisfy@foxmail.com>" --date="$(git show -s --format=%aI HEAD)"
pick aff01680a copilot: v2 - read one calendar
exec git commit --amend --no-edit --author="Tisfy <Tisfy@foxmail.com>" --date="$(git show -s --format=%aI HEAD)"
pick 62e7ba669 feat: cli+clean(脱敏) - 真是屎山中的屎山
exec git commit --amend --no-edit --author="Tisfy <Tisfy@foxmail.com>" --date="$(git show -s --format=%aI HEAD)"

修改前：

commit 62e7ba669bfc554dd8b212132facc162284fea78 (HEAD -> feat/caldav)
Author: LetMeFly666 <Tisfy@qq.com>
Date:   Wed May 27 22:17:34 2026 +0800

    feat: cli+clean(脱敏) - 真是屎山中的屎山

commit aff01680a294696eb1e4c44bf29e077ce1ed74a9
Author: LetMeFly666 <Tisfy@qq.com>
Date:   Tue May 26 23:39:01 2026 +0800

    copilot: v2 - read one calendar

commit 5e627fea3cc39f2542bfb21b0250206ae90f3c32
Author: LetMeFly666 <Tisfy@qq.com>
Date:   Thu May 21 14:21:58 2026 +0800

    copilot: v1

commit 0f572f87b1d6cae74d549352fb07c8cd26d451d9
Author: LetMeFly666 <Tisfy@qq.com>
Date:   Thu May 21 12:29:27 2026 +0800

    init: by hand (解决下重复任务在日历中显示多次的问题)

commit 4f2c31de759b5bc9873300572df43c91599346ab
Author: LetMeFly666 <Tisfy@qq.com>
Date:   Tue May 19 18:05:26 2026 +0800

    update: 添加问题“2540.最小公共值”的代码和题解 (#1598)


修改后：

commit 6cb5bd2a3dd4dc0be39cc2a770e4ea08918f54d2 (HEAD -> feat/caldav)
Author: Tisfy <Tisfy@foxmail.com>
Date:   Wed May 27 22:17:34 2026 +0800

    feat: cli+clean(脱敏) - 真是屎山中的屎山

commit a8e4db6b5ce6aad5e01eb089a633ecec921d3b7a
Author: Tisfy <Tisfy@foxmail.com>
Date:   Tue May 26 23:39:01 2026 +0800

    copilot: v2 - read one calendar

commit 0b4c8cb961ccab587eb2549a54b49fb0d776e26f
Author: Tisfy <Tisfy@foxmail.com>
Date:   Thu May 21 14:21:58 2026 +0800

    copilot: v1

commit e0ef4aeb9c2800102d2edbf682f35a9a69e24450
Author: Tisfy <Tisfy@foxmail.com>
Date:   Thu May 21 12:29:27 2026 +0800

    init: by hand (解决下重复任务在日历中显示多次的问题)

commit 4f2c31de759b5bc9873300572df43c91599346ab
Author: LetMeFly666 <Tisfy@qq.com>
Date:   Tue May 19 18:05:26 2026 +0800

    update: 添加问题“2540.最小公共值”的代码和题解 (#1598)


不过co-auther是LetMeFly666

git config user.name "Tisfy"
git config user.email "Tisfy@foxmail.com"

再执行一次

git rebase -i HEAD~4 --exec 'git commit --amend --no-edit --author="Tisfy <Tisfy@foxmail.com>"'

commit db80fddc9624e385728ea555307a62aafb74ccd4 (HEAD -> feat/caldav)
Author: Tisfy <Tisfy@foxmail.com>
Date:   Wed May 27 22:17:34 2026 +0800

    feat: cli+clean(脱敏) - 真是屎山中的屎山

commit bc03f2221de999171659836ebd518f3778d265dd
Author: Tisfy <Tisfy@foxmail.com>
Date:   Tue May 26 23:39:01 2026 +0800

    copilot: v2 - read one calendar

commit bf6133b8fcfa456d713d0e6519d48a78a2c929dc
Author: Tisfy <Tisfy@foxmail.com>
Date:   Thu May 21 14:21:58 2026 +0800

    copilot: v1

commit 6667e69cce4b9cc210348544f3779a56b3871fda
Author: Tisfy <Tisfy@foxmail.com>
Date:   Thu May 21 12:29:27 2026 +0800

    init: by hand (解决下重复任务在日历中显示多次的问题)

commit 4f2c31de759b5bc9873300572df43c91599346ab
Author: LetMeFly666 <Tisfy@qq.com>
Date:   Tue May 19 18:05:26 2026 +0800

    update: 添加问题“2540.最小公共值”的代码和题解 (#1598)






其中这个code-server的上次commit:

commit 9ca6097a1e9f5cbf85bf83b8956bb00ad71afaf6 (HEAD -> master, origin/master, origin/HEAD)
Author: LetMeFly666 <Tisfy@qq.com>
Date:   Wed May 27 00:17:22 2026 +0800



