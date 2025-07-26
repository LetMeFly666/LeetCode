import paramiko
from scp import SCPClient
import os

def analyze_pcap_on_linux(local_pcap_path, remote_filename, linux_ip, linux_username, linux_password):
    # 1. 连接Linux服务器
    LINUX_PCAP_DIR = f"/{linux_username}/pcap_linux/pcap_files"
    LINUX_ANALYZE_SCRIPT = f"/{linux_username}/pcap_linux/pcap_analysis.py"
    LINUX_IP = linux_ip
    LINUX_USER = linux_username
    LINUX_PASS = linux_password
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    ssh.connect(LINUX_IP, username=LINUX_USER, password=LINUX_PASS)
    # 2. 上传文件
    with SCPClient(ssh.get_transport()) as scp:
        scp.put(local_pcap_path, LINUX_PCAP_DIR)
    remote_path = os.path.join(LINUX_PCAP_DIR, remote_filename)
    # # 3. 远程执行分析脚本
    cmd = f" /{linux_username}/.local/share/mamba/envs/myenv/bin/python {LINUX_ANALYZE_SCRIPT} {remote_path}"
    stdin, stdout, stderr = ssh.exec_command(cmd)
    result = stdout.read().decode()
    ssh.close()
    return result
