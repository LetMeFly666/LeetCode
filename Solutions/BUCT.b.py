'''
Author: LetMeFly
Date: 2023-03-03 20:05:45
LastEditors: LetMeFly
LastEditTime: 2023-03-03 20:12:58
'''
# Copy from CSDN
# 归并排序
def merge_sort(num_list):
    length = len(num_list)

    # 递归终止退出条件
    if length <= 1:
        return num_list

    # 拆分
    mid = length // 2
    left_l = merge_sort(num_list[:mid])   # 对左侧的列表进行排序
    right_l = merge_sort(num_list[mid:])  # 对右侧的列表进行排序

    # merge 合并操作
    # 初始化两个指针p, q 初始位置为起始位置，初始化一个临时数组temp_list
    p, q, temp_list = 0, 0, list()
    len_left, len_right = len(left_l), len(right_l)  # 计算当前被合并的列表的长度

    while len_left > p and len_right > q:
        if left_l[p] <= right_l[q]:
            temp_list.append(left_l[p])
            p += 1
        else:
            temp_list.append(right_l[q])
            q += 1
    # 如果left 和 right 的长度不相等，把长的部分直接追加到列表中
    temp_list += left_l[p:]
    temp_list += right_l[q:]

    return temp_list


if __name__ == '__main__':
    T = int(input())
    for _CASE in range(T):
        n = int(input())
        a = list(map(int, input().split()))
        new_list = merge_sort(a)
        print(*new_list)
