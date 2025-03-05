'''
Author: LetMeFly
Date: 2025-03-05 11:15:50
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-05 12:10:38
'''
import imaplib
import email
from email.header import decode_header

# 邮件配置
imap_server = 'imap.qq.com'  # IMAP服务器地址
imap_port = 993  # IMAP服务器端口
email_address = 'your_email@example.com'  # 邮箱地址
email_password = 'your_password'  # 邮箱密码

# 连接到IMAP服务器
try:
    mail = imaplib.IMAP4_SSL(imap_server, imap_port)
    mail.login(email_address, email_password)
    mail.select('inbox')  # 选择收件箱

    # 搜索邮件
    status, messages = mail.search(None, 'ALL')  # 获取所有邮件
    if status != 'OK':
        print("没有找到邮件")
        exit()

    # 获取邮件列表
    mail_ids = messages[0].split()
    latest_mail_id = mail_ids[-1]  # 获取最新的一封邮件

    # 获取邮件内容
    status, msg_data = mail.fetch(latest_mail_id, '(RFC822)')
    if status != 'OK':
        print("无法获取邮件内容")
        exit()

    # 解析邮件内容
    for response_part in msg_data:
        if isinstance(response_part, tuple):
            msg = email.message_from_bytes(response_part[1])
            subject, encoding = decode_header(msg['Subject'])[0]
            if isinstance(subject, bytes):
                subject = subject.decode(encoding if encoding else 'utf-8')
            from_ = msg.get('From')
            print(f"主题: {subject}")
            print(f"发件人: {from_}")

            # 获取邮件正文
            if msg.is_multipart():
                for part in msg.walk():
                    content_type = part.get_content_type()
                    content_disposition = str(part.get("Content-Disposition"))
                    if content_type == 'text/plain' and 'attachment' not in content_disposition:
                        body = part.get_payload(decode=True).decode()
                        print(f"正文: {body}")
            else:
                body = msg.get_payload(decode=True).decode()
                print(f"正文: {body}")

except Exception as e:
    print(f"接收邮件失败: {e}")
finally:
    mail.logout()