git log --oneline --no-merges master..2179

7312920de52 (origin/2179, 2179) revert: do it in recent work
5baad222dfe revert: do it in recent work
b2da1d48942 revert: do it in recent work
fe55524f49a feat: newSolution.py新生成issue时带上[newSolution]前缀(#879)
9ed9037aa86 dbg.fix: no error found(#879)
552780b48d0 clean: learn DL(#879)
0edad0c7fe6 config: auto generated(#879)
0e0fe09b2da teachDL: yesterday(#879)
75222df2763 teachDL: yesterday(#879)
7f768fc8d06 WA: cpp(#879)
520e19c124c WA: cpp
5d8255b87bf word: en words (#879) - 2025.4.19 19:50



git log -2 --pretty=%H 5d8255b87bf

5d8255b87bff347ecb735e40a6f12dd700b05da6
d70b2f0861847e58f0ff0d09e5a36cbb9a5964ed



git diff d70b2f0861 7312920de52 > 2179.diff

# cmd可以，VsCode中的PowerShell不可



git branch

master



git switch -c 2179-continue



git apply 2179.diff