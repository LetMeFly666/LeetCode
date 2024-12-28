'''
Author: LetMeFly
Date: 2024-12-27 19:09:51
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-27 19:13:32
'''
import pyshark

# 读取 pcap 文件
cap = pyshark.FileCapture('C:/Users/LetMeFly/Desktop/M国J网/binaryFiles/files/Win10-正常网络环境（很多噪声）-发送邮件.pcap', tshark_path='F:/OtherApps/Editor/Wireshark/Apps/tshark.exe')
print(cap)
print(len(cap))
# 遍历抓包文件中的每个数据包
for packet in cap:
    print(packet)
