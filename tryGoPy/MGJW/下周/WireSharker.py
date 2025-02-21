'''
Author: LetMeFly
Date: 2025-01-07 17:02:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-07 17:16:48
'''
import pyshark
import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft

# 设置支持中文的字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # 使用黑体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# 定义函数：提取数据包到达时间间隔
def extract_packet_intervals(pcap_file, tshark_path):
    cap = pyshark.FileCapture(pcap_file, tshark_path=tshark_path)
    timestamps = []
    previous_time = None
    for packet in cap:
        if previous_time is not None:
            timestamps.append(float(packet.sniff_timestamp) - previous_time)
        previous_time = float(packet.sniff_timestamp)
    cap.close()
    return timestamps

# 定义函数：计算频域特性
def compute_frequency_domain(timestamps):
    fft_result = fft(timestamps)
    n = len(timestamps)
    timestep = 1  # 假设时间间隔为1秒
    frequencies = np.fft.fftfreq(n, d=timestep)
    return frequencies, np.abs(fft_result)

# 文件路径
tshark_path = 'F:/OtherApps/Editor/Wireshark/Apps/tshark.exe'
pcap_file1 = 'C:/Users/LetMeFly/Desktop/M国J网/binaryFiles/files/Win10-正常网络环境（很多噪声）-发送邮件.pcap'
pcap_file2 = 'C:/Users/LetMeFly/Desktop/M国J网/binaryFiles/files/WinServer2019-正常网络环境（一些噪声）-接收和发送给邮件.pcap'

# 提取数据包到达时间间隔
timestamps1 = extract_packet_intervals(pcap_file1, tshark_path)
timestamps2 = extract_packet_intervals(pcap_file2, tshark_path)

# 计算频域特性
frequencies1, fft_result1 = compute_frequency_domain(timestamps1)
frequencies2, fft_result2 = compute_frequency_domain(timestamps2)

# 绘制对比图
plt.figure(figsize=(12, 6))

# 绘制第一个文件的频域图
plt.subplot(1, 2, 1)
plt.plot(frequencies1, fft_result1, color='blue', label='Win10 - 发送邮件')
plt.title('Win10 - 发送邮件 (频域)')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Amplitude')
plt.grid()
plt.legend()

# 绘制第二个文件的频域图
plt.subplot(1, 2, 2)
plt.plot(frequencies2, fft_result2, color='red', label='WinServer2019 - 接收和发送邮件')
plt.title('WinServer2019 - 接收和发送邮件 (频域)')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Amplitude')
plt.grid()
plt.legend()

plt.tight_layout()
plt.show()