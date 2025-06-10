'''
Author: LetMeFly
Date: 2025-06-04 19:41:24
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-09 09:59:56
'''
import random
import string
from flask import Flask, request, render_template_string, send_file
import os
from datetime import datetime

app = Flask(__name__)

unmatched_requests = []
matched_pairs = []
# 固定校验位位置
FIXED_POSITIONS = [0, 2, 3, 7, 9, 12, 15]


def generate_string_pair(plaintext):
    """生成两个字符串用于编码明文"""
    # 将明文转换为二进制
    byte_data = plaintext.encode('utf-8')
    bin_str = ''.join(format(byte, '08b') for byte in byte_data)
    
    # 计算所需长度
    data_len = len(bin_str)
    fixed_count = len(FIXED_POSITIONS)
    total_len = data_len + fixed_count
    
    # 调整长度确保覆盖所有校验位
    min_len = max(FIXED_POSITIONS) + 1 if FIXED_POSITIONS else 0
    if total_len < min_len:
        padding = min_len - total_len
        bin_str = bin_str + '0' * padding
        total_len = min_len
    
    s1 = [''] * total_len
    s2 = [''] * total_len
    
    # 处理校验位
    for pos in FIXED_POSITIONS:
        if pos < total_len:
            char = random.choice(string.ascii_letters + string.digits)
            s1[pos] = char
            s2[pos] = char
    
    # 处理数据位
    data_index = 0
    chars = string.ascii_letters + string.digits
    sorted_chars = sorted(chars)
    
    for i in range(total_len):
        if i in FIXED_POSITIONS:
            continue
            
        if data_index < len(bin_str):
            bit = bin_str[data_index]
            data_index += 1
        else:
            bit = random.choice(['0', '1'])
            
        if bit == '0':  # s1 > s2
            idx2 = random.randint(0, len(sorted_chars)-2)
            s2_char = sorted_chars[idx2]
            s1_char = random.choice(sorted_chars[idx2+1:])
        else:  # s1 < s2
            idx2 = random.randint(1, len(sorted_chars)-1)
            s2_char = sorted_chars[idx2]
            s1_char = random.choice(sorted_chars[:idx2])
        
        s1[i] = s1_char
        s2[i] = s2_char
    
    return ''.join(s1), ''.join(s2)

def decode_strings(s1, s2):
    """从两个字符串解码出明文"""
    if len(s1) != len(s2):
        return None
        
    bin_list = []
    for i in range(len(s1)):
        if i in FIXED_POSITIONS:
            continue
        if i >= len(s1) or i >= len(s2):
            continue
            
        if s1[i] > s2[i]:
            bin_list.append('0')
        elif s1[i] < s2[i]:
            bin_list.append('1')
        else:  # 非校验位相等，无效
            return None
    
    bin_str = ''.join(bin_list)
    # 将二进制转换为字节
    byte_array = []
    for i in range(0, len(bin_str), 8):
        byte_str = bin_str[i:i+8]
        if len(byte_str) < 8:
            break
        byte_array.append(int(byte_str, 2))
    
    try:
        plaintext = bytes(byte_array).decode('utf-8')
        # 移除编码时可能添加的填充字符
        return plaintext.rstrip('\x00')
    except:
        return None

@app.route('/')
def home():
    """主页显示使用说明"""
    return """
    <h1>加解密系统</h1>
    <ul>
        <li><a href="/encode">编码页面</a> - 输入明文获取编码字符串</li>
        <li><a href="/admin">管理后台</a> - 查看匹配结果</li>
        <li>图片服务: /img/?s=编码字符串</li>
    </ul>
    """

@app.route('/encode', methods=['GET', 'POST'])
def encode_page():
    """编码页面"""
    if request.method == 'POST':
        plaintext = request.form['plaintext']
        s1, s2 = generate_string_pair(plaintext)
        return render_template_string('''
            <form method="post">
                明文: <input type="text" name="plaintext" value="{{ plaintext }}" size="50"><br>
                <input type="submit" value="编码">
            </form>
            <hr>
            {% if s1 and s2 %}
                <h3>生成的字符串:</h3>
                <p>字符串1: <code>{{ s1 }}</code></p>
                <p>字符串2: <code>{{ s2 }}</code></p>
                <h3>使用说明:</h3>
                <p>分别访问以下URL完成配对:</p>
                <p><a href="/img/?s={{ s1 }}">/img/?s={{ s1 }}</a></p>
                <p><a href="/img/?s={{ s2 }}">/img/?s={{ s2 }}</a></p>
            {% endif %}
        ''', plaintext=plaintext, s1=s1, s2=s2)
    
    return '''
        <form method="post">
            明文: <input type="text" name="plaintext" size="50"><br>
            <input type="submit" value="编码">
        </form>
    '''

@app.route('/img/')
def img_service():
    """图片服务（返回图片+记录请求）"""
    s = request.args.get('s', '')
    timestamp = datetime.now()
    
    # 查找匹配
    for item in unmatched_requests:
        if item['s'] == s:
            return send_file('static/default.jpg', mimetype='image/jpeg')
        
        match = True
        for pos in FIXED_POSITIONS:
            if pos >= len(s) or pos >= len(item['s']):
                match = False
                break
            if s[pos] != item['s'][pos]:
                match = False
                break
        
        if match:
            plaintext = decode_strings(item['s'], s)
            if plaintext:
                matched_pairs.append({
                    's1': item['s'],
                    's2': s,
                    'plaintext': plaintext,
                    'time1': item['time'],
                    'time2': timestamp
                })
                unmatched_requests.remove(item)
                return send_file('static/default.jpg', mimetype='image/jpeg')
    
    # 无匹配则添加新请求
    unmatched_requests.append({'s': s, 'time': timestamp})
    return send_file('static/default.jpg', mimetype='image/jpeg')

@app.route('/admin')
def admin_page():
    """管理后台"""
    matched_html = "<h2>已匹配的请求</h2><table border='1'><tr><th>字符串1</th><th>字符串2</th><th>明文</th><th>首次访问时间</th><th>二次访问时间</th></tr>"
    for pair in matched_pairs:
        matched_html += f"<tr><td>{pair['s1']}</td><td>{pair['s2']}</td><td>{pair['plaintext']}</td><td>{pair['time1']}</td><td>{pair['time2']}</td></tr>"
    matched_html += "</table>"
    
    unmatched_html = "<h2>未匹配的请求</h2><table border='1'><tr><th>字符串</th><th>访问时间</th></tr>"
    for req in unmatched_requests:
        unmatched_html += f"<tr><td>{req['s']}</td><td>{req['time']}</td></tr>"
    unmatched_html += "</table>"
    
    return f"""
    <html>
    <head><title>管理后台</title></head>
    <body>
        <h1>加解密系统管理后台</h1>
        {matched_html if matched_pairs else '<p>无已匹配请求</p>'}
        {unmatched_html if unmatched_requests else '<p>无未匹配请求</p>'}
        <p><a href="/">返回主页</a></p>
    </body>
    </html>
    """

def create_default_image():
    """创建默认图片（如果不存在）"""
    os.makedirs('static', exist_ok=True)
    if not os.path.exists('static/default.jpg'):
        # 创建一个简单的1x1像素白色图片
        with open('static/default.jpg', 'wb') as f:
            f.write(b'\xff\xd8\xff\xe0\x00\x10JFIF\x00\x01\x01\x01\x00H\x00H\x00\x00\xff\xdb\x00C\x00\x03\x02\x02\x03\x02\x02\x03\x03\x03\x03\x04\x03\x03\x04\x05\x08\x05\x05\x04\x04\x05\n\x07\x07\x06\x08\x0c\n\x0c\x0c\x0b\n\x0b\x0b\r\x0e\x12\x10\r\x0e\x11\x0e\x0b\x0b\x10\x16\x10\x11\x13\x14\x15\x15\x15\x0c\x0f\x17\x18\x16\x14\x18\x12\x14\x15\x14\xff\xc9\x00\x0b\x08\x00\x01\x00\x01\x01\x01\x11\x00\xff\xcc\x00\x06\x00\x10\x10\x05\xff\xda\x00\x08\x01\x01\x00\x00?\x00\xd2\xcf \xff\xd9')

if __name__ == '__main__':
    create_default_image()
    app.run(port=5000, debug=True, host='0.0.0.0')