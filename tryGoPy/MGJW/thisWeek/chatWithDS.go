<!--
 * @Author: LetMeFly
 * @Date: 2025-03-06 10:26:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-06 10:26:40
-->
这段代码可以修改对应的http响应
```
def response(flow: http.HTTPFlow) -> None:
    # 修改响应
    logger_url.info(flow.request.pretty_url)
    if "web.letmefly.xyz" in flow.request.pretty_url and 'text/html' in flow.response.headers.get('content-type', ''):
    # if flow.request.pretty_url == 'https://web.letmefly.xyz/':
        logger_url.info('replace HTML to LMTH')
        # logger_text.info(flow.response.text)
        flow.response.text = flow.response.text.replace("HTML", "LMTH")
```

这段代码可以通过smtp协议发送邮件
```
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
```

我想做到以下功能：
当使用这段代码发送邮件时，mitmproxy可以修改邮件内容，在body中添加一段后缀签名。

---

使用QQ邮箱网页版发送邮件时，会向`https://mail.qq.com/cgi-bin/compose_send?sid=xxxxx`发送一个POST请求，表单数据包括：

```
to: "Let"<Tisfy@qq.com>
swap3: 
cc: 
subject: 今日指令
content__html: 一切正常，和昨天一样
sendmailname: tisfy@foxmail.com
......
```

现在我已经配置好了python的mitmproxy，我想实现以下内容：

当主机上有向`https://mail.qq.com/cgi-bin/compose_send?sid=xxxxx`的请求时，修改表单中的`content__html`字段，在原有内容的基础上加上*******签名*******