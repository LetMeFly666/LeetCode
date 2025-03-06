'''
Author: LetMeFly
Date: 2025-03-05 10:09:12
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-05 16:58:00
'''
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from password import sender_password

# 邮件配置
smtp_server = 'smtp.qq.com'
smtp_port = 587
sender_email = 'LetMeFly666@qq.com'
sender_password = sender_password
receiver_email = 'tf.li@qq.com'

# 创建邮件内容
subject = '今日指令'
body = '一切正常，和昨天一样'
msg = MIMEMultipart()
msg['From'] = sender_email
msg['To'] = receiver_email
msg['Subject'] = subject
msg.attach(MIMEText(body, 'plain'))

# 发送邮件
try:
    server = smtplib.SMTP(smtp_server, smtp_port)
    server.starttls()
    server.login(sender_email, sender_password)
    server.sendmail(sender_email, receiver_email, msg.as_string())
    print("邮件发送成功")
except Exception as e:
    print(f"邮件发送失败: {e}")
finally:
    server.quit()
