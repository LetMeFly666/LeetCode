非常棒！这样，我就把“签名”添加在发送邮件的后面。
当我接收邮件时，我想直接写个类似的脚本提取处签名，并将邮件还原为不带签名的内容。
通过签名，收发双方脚本能够确认各自信息身份，并且不影响用户对正常邮件的阅读。
签名的格式是*******签名*******，其中“签名”的具体内容可能会发生变化。

接收读取邮件时，会请求“https://mail.qq.com/cgi-bin/readmail”开头的地址，并得到一个html的response
```
<!DOCTYPE html>
<html>
    <head>
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
```


---

html头带有如下信息：

<meta http-equiv="Content-Type" content="text/html; charset=gb18030"/>

是通过gb18030编码的，不按照这个解码会导致中文乱码匹配失败

---

beautifulsoup解析一个编码格式为gb18030的html并修改后，新生成的内容编码格式为utf-8
我想保持原有格式，不做过多修改。
```
html_content = flow.response.content.decode("gb18030")
soup = BeautifulSoup(html_content, "lxml")
# 修改处理
flow.response.content = str(soup).encode("gb18030")
flow.response.headers["Content-Length"] = str(len(flow.response.content))
```

---

不行，你这相当于没有修改。
原有html：
```
<meta http-equiv="Content-Type" content="text/html; charset=gb18030"/>
```
经过beautifulSoup处理后：
```
<meta content="text/html; charset=utf-8" http-equiv="Content-Type"/>
```

---

python使用正则：

1. 提取*******签名*******中的签名，其中“签名”的具体内容可能会发生变化
2. 删掉“*******签名*******”

---

python watchdog观察本地letreceiver文件，内容发生变化时读取内容并显示到屏幕上

---

生成一段内容，模拟红警游戏中的一段军情。
内容一定要长

---

生成一些每天都一样的内容：

例如今天每人跑步10000米