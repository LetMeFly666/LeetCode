import time
import paramiko
import chardet

traffic_data = {}  
stop_events = {}  

def traffic_remote_generate(ip, username, password):
    port = 22
    command = (
        f'cd C:\\Users\\{username}\\Desktop && '
        'powershell -ExecutionPolicy Bypass -File .\\ftp_download.ps1'
    )
    with paramiko.SSHClient() as ssh:
        ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        ssh.connect(ip, port, username, password)
        stdin, stdout, stderr = ssh.exec_command(command)

        last_upload = None
        last_download = None
        last_time = None
        try:
            while not stop_events[ip].is_set():
            # while True:
                line = stdout.readline()
                if not line:
                    break
                encoding = chardet.detect(line.encode())['encoding'] or 'utf-8'
                line = line.strip().encode(encoding, errors='replace').decode(encoding, errors='replace')
                if line.startswith("upload") and "download" in line:
                    parts = line.split()
                    try:
                        upload = int(parts[1])
                        download = int(parts[3])
                    except Exception:
                        continue

                    now = time.time()
                    if last_upload is not None and last_download is not None and last_time is not None:
                        delta_time = now - last_time
                        up_speed = (upload - last_upload) / delta_time / (1024 * 1024)
                        down_speed = (download - last_download) / delta_time / (1024 * 1024)
                        if down_speed > 100: down_speed  = 90 + down_speed % 10
                        traffic_data[ip] = {
                            'ip': ip,
                            'upload': up_speed,
                            'download': down_speed   
                        }
                        # print(f"IP: {ip}, Upload Speed: {up_speed:.2f} MB/s, Download Speed: {down_speed:.2f} MB/s")
                    last_upload = upload
                    last_download = download
                    last_time = now
        except KeyboardInterrupt:
            print("中断，退出。")
        stdin.close()
        stdout.channel.shutdown_write()
        stdout.close()
        stderr.close()

# def test():
#     ip = "10.112.108.78"
#     username = "27272"
#     password = "AnQing666666zhao"
#     traffic_remote_generate(ip, username, password)

# test()