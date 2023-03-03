'''
Author: LetMeFly
Date: 2023-02-24 11:15:31
LastEditors: LetMeFly
LastEditTime: 2023-03-03 20:07:50
'''
a = []
temp = [0 for _ in range(10010)]

def mergeSort(l: int, r: int) -> None:
    if l + 1 == r:
        return
    m = (l + r) >> 1
    mergeSort(l, m)
    mergeSort(m, r)
    ll, lr = l, m
    lt = l
    while ll < m and lr < r:
        if a[ll] < a[lr]:
            temp[lt] = a[ll]
            lt += 1
            ll += 1
        else:
            temp[lt] = a[lr]
            lt += 1
            lr += 1
    while ll < m:
        temp[lt] = a[ll]
        lt += 1
        ll += 1
    while lr < r:
        temp[lt] = a[lr]
        lt += 1
        lr += 1
    for i in range(l, r):
        a[i] = temp[i]


T = int(input())
for _CASE in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    mergeSort(0, n)
    # for i in a:
    #     print(i, end=' ')
    # print()
    print(*a)