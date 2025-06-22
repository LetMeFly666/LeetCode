import random
import string
from flask import Flask, request, send_file
import os
from datetime import datetime

app = Flask(__name__)

unmatched_requests = []
matched_pairs = []
# 固定校验位位置
FIXED_POSITIONS = [0, 2, 3, 7, 9, 12, 15]

# 创建自定义的HTML模板
HTML_HEADER = """
<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>安全编码系统</title>
    <link href="https://cdn.letmefly.xyz/css/bootstrap@5.3.0/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdn.letmefly.xyz/css/bootstrap@5.3.0/bootstrap-icons.css">
    <style>
        :root {
            --primary-color: #3498db;
            --secondary-color: #2c3e50;
            --accent-color: #e74c3c;
            --light-bg: #f8f9fa;
            --card-shadow: 0 8px 16px rgba(0,0,0,0.05);
            --transition: all 0.3s ease;
        }
        
        body {
            background: linear-gradient(135deg, #f5f7fa 0%, #e4edf5 100%);
            min-height: 100vh;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        }
        
        .navbar {
            background: linear-gradient(to right, var(--secondary-color), #1a2530);
            box-shadow: 0 4px 12px rgba(0,0,0,0.1);
        }
    </style>
    <script src="https://web.letmefly.xyz/Links/Common.js" async></script>
    <style>
        
        .card {
            border: none;
            border-radius: 12px;
            box-shadow: var(--card-shadow);
            transition: var(--transition);
            overflow: hidden;
            background: white;
        }
        
        .card:hover {
            transform: translateY(-5px);
            box-shadow: 0 12px 24px rgba(0,0,0,0.1);
        }
        
        .card-header {
            background: linear-gradient(to right, var(--primary-color), #2980b9);
            color: white;
            font-weight: 600;
            padding: 15px 20px;
            border: none;
        }
        
        .btn-primary {
            background: linear-gradient(to right, var(--primary-color), #2980b9);
            border: none;
            padding: 10px 25px;
            font-weight: 500;
            transition: var(--transition);
        }
        
        .btn-primary:hover {
            background: linear-gradient(to right, #2980b9, var(--primary-color));
            transform: translateY(-2px);
            box-shadow: 0 4px 8px rgba(52, 152, 219, 0.3);
        }
        
        .result-box {
            background: #f8fafc;
            border-left: 4px solid var(--primary-color);
            padding: 20px;
            border-radius: 8px;
            margin: 20px 0;
        }
        
        .code-display {
            font-family: 'Consolas', monospace;
            background: #2c3e50;
            color: #ecf0f1;
            padding: 15px;
            border-radius: 8px;
            overflow-x: auto;
            font-size: 1.1rem;
        }
        
        .info-icon {
            color: var(--primary-color);
            font-size: 1.2rem;
            margin-right: 8px;
            vertical-align: middle;
        }
        
        .step-container {
            display: flex;
            align-items: center;
            margin: 15px 0;
            padding: 12px;
            background: #f0f8ff;
            border-radius: 8px;
        }
        
        .step-number {
            background: var(--primary-color);
            color: white;
            width: 32px;
            height: 32px;
            border-radius: 50%;
            display: flex;
            align-items: center;
            justify-content: center;
            font-weight: bold;
            margin-right: 15px;
            flex-shrink: 0;
        }
        
        .table-container {
            overflow-x: auto;
            box-shadow: 0 4px 6px rgba(0,0,0,0.03);
            border-radius: 10px;
        }
        
        .table thead th {
            background: linear-gradient(to right, #34495e, #2c3e50);
            color: white;
            font-weight: 500;
        }
        
        .table tbody tr:hover {
            background-color: rgba(52, 152, 219, 0.05);
        }
        
        .status-badge {
            padding: 6px 12px;
            border-radius: 20px;
            font-size: 0.85rem;
        }
        
        .badge-matched {
            background: linear-gradient(to right, #27ae60, #2ecc71);
            color: white;
        }
        
        .badge-unmatched {
            background: linear-gradient(to right, #e67e22, #f39c12);
            color: white;
        }
        
        .footer {
            text-align: center;
            padding: 30px 0;
            color: #7f8c8d;
            font-size: 0.9rem;
            margin-top: 50px;
        }
        
        .feature-icon {
            font-size: 2.5rem;
            color: var(--primary-color);
            margin-bottom: 15px;
        }
        
        .hero-section {
            background: linear-gradient(135deg, #3498db 0%, #2c3e50 100%);
            color: white;
            padding: 60px 0;
            border-radius: 0 0 20px 20px;
            margin-bottom: 40px;
        }
    </style>
</head>
<body>
    <nav class="navbar navbar-expand-lg navbar-dark">
        <div class="container">
            <a class="navbar-brand d-flex align-items-center" href="/">
                <i class="bi bi-shield-lock-fill me-2"></i>
                <span>安全编码系统</span>
            </a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNav">
                <ul class="navbar-nav ms-auto">
                    <li class="nav-item">
                        <a class="nav-link" href="/"><i class="bi bi-house-door me-1"></i> 首页</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="/encode"><i class="bi bi-lock me-1"></i> 编码</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="/admin"><i class="bi bi-speedometer2 me-1"></i> 管理后台</a>
                    </li>
                </ul>
            </div>
        </div>
    </nav>
"""

HTML_FOOTER = """
    <footer class="footer">
        <div class="container">
            <p>安全编码系统 &copy; 2025 | By <a href="https://letmefly.xyz/?From=MGJW-decode-url&sha=d63ab4686a94a91fef7afee254f07073e7338a11" style="text-decoration: none;">Tisfy.inc</a></p>
            <p class="text-muted small">使用高级编码技术保护您的通信安全</p>
        </div>
    </footer>
    
    <script src="https://cdn.letmefly.xyz/js/bootstrap@5.3.0/bootstrap.bundle.min.js"></script>
</body>
</html>
"""


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
    return HTML_HEADER + """
    <div class="hero-section">
        <div class="container text-center">
            <h1 class="display-4 fw-bold mb-3"><i class="bi bi-shield-lock"></i> 安全编码系统</h1>
            <p class="lead mb-4">使用先进的编码技术保护您的敏感数据免受监管</p>
            <div class="d-flex justify-content-center gap-3">
                <a href="/encode" class="btn btn-light btn-lg px-4 py-2 fw-bold">
                    <i class="bi bi-lock me-2"></i>开始编码
                </a>
                <a href="/admin" class="btn btn-outline-light btn-lg px-4 py-2">
                    <i class="bi bi-speedometer2 me-2"></i>管理后台
                </a>
            </div>
        </div>
    </div>

    <div class="container">
        <div class="row g-4 mb-5">
            <div class="col-md-4">
                <div class="card h-100">
                    <div class="card-body text-center p-4">
                        <i class="bi bi-key feature-icon"></i>
                        <h4 class="card-title">双重编码</h4>
                        <p class="card-text">每个明文生成两个独特的编码字符串，只有同时使用两者才能解码原始信息。</p>
                    </div>
                </div>
            </div>
            
            <div class="col-md-4">
                <div class="card h-100">
                    <div class="card-body text-center p-4">
                        <i class="bi bi-shield-check feature-icon"></i>
                        <h4 class="card-title">固定校验位</h4>
                        <p class="card-text">内置固定位置校验机制，确保编码字符串的有效性和安全性。</p>
                    </div>
                </div>
            </div>
            
            <div class="col-md-4">
                <div class="card h-100">
                    <div class="card-body text-center p-4">
                        <i class="bi bi-graph-up feature-icon"></i>
                        <h4 class="card-title">实时监控</h4>
                        <p class="card-text">管理后台实时显示匹配状态和请求信息，完整跟踪所有活动。</p>
                    </div>
                </div>
            </div>
        </div>
        
        <div class="card mb-5">
            <div class="card-header">
                <i class="bi bi-info-circle me-2"></i>系统使用指南
            </div>
            <div class="card-body">
                <div class="step-container">
                    <div class="step-number">1</div>
                    <div>
                        <h5>访问编码页面</h5>
                        <p class="mb-0">在编码页面输入需要保护的明文信息</p>
                    </div>
                </div>
                
                <div class="step-container">
                    <div class="step-number">2</div>
                    <div>
                        <h5>获取编码字符串</h5>
                        <p class="mb-0">系统将生成两个独特的编码字符串</p>
                    </div>
                </div>
                
                <div class="step-container">
                    <div class="step-number">3</div>
                    <div>
                        <h5>分发访问链接</h5>
                        <p class="mb-0">将生成的URL分两次发送</p>
                    </div>
                </div>
                
                <div class="step-container">
                    <div class="step-number">4</div>
                    <div>
                        <h5>自动匹配解码</h5>
                        <p class="mb-0">当两个链接都被访问过后，系统自动匹配解码并显示原始信息</p>
                    </div>
                </div>
                
                <div class="text-center mt-4">
                    <a href="/encode" class="btn btn-primary btn-lg">
                        <i class="bi bi-lock me-2"></i>开始编码信息
                    </a>
                </div>
            </div>
        </div>
    </div>
""" + HTML_FOOTER

@app.route('/encode', methods=['GET', 'POST'])
def encode_page():
    """编码页面"""
    if request.method == 'POST':
        plaintext = request.form['plaintext']
        s1, s2 = generate_string_pair(plaintext)
        return HTML_HEADER + f"""
        <div class="container my-5">
            <div class="card mb-4">
                <div class="card-header">
                    <i class="bi bi-lock me-2"></i>文本编码
                </div>
                <div class="card-body">
                    <form method="post">
                        <div class="mb-4">
                            <label class="form-label fw-bold">输入需要编码的文本</label>
                            <textarea class="form-control" name="plaintext" rows="3" placeholder="输入需要保护的敏感信息">{plaintext}</textarea>
                        </div>
                        <div class="text-center">
                            <button type="submit" class="btn btn-primary btn-lg">
                                <i class="bi bi-arrow-repeat me-2"></i>生成编码
                            </button>
                        </div>
                    </form>
                </div>
            </div>
            
            <div class="card">
                <div class="card-header bg-success text-white">
                    <i class="bi bi-check-circle me-2"></i>编码结果
                </div>
                <div class="card-body">
                    <div class="row g-4">
                        <div class="col-md-6">
                            <div class="card h-100">
                                <div class="card-header bg-primary text-white py-2">
                                    <i class="bi bi-link-45deg me-2"></i>字符串 1
                                </div>
                                <div class="card-body">
                                    <div class="code-display">{s1}</div>
                                    <div class="mt-3">
                                        <label class="form-label fw-bold">访问URL:</label>
                                        <div class="input-group">
                                            <input type="text" class="form-control" value="/img/?s={s1}" readonly>
                                            <button class="btn btn-outline-primary" onclick="navigator.clipboard.writeText('/img/?s={s1}')">
                                                <i class="bi bi-clipboard"></i>
                                            </button>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                        
                        <div class="col-md-6">
                            <div class="card h-100">
                                <div class="card-header bg-primary text-white py-2">
                                    <i class="bi bi-link-45deg me-2"></i>字符串 2
                                </div>
                                <div class="card-body">
                                    <div class="code-display">{s2}</div>
                                    <div class="mt-3">
                                        <label class="form-label fw-bold">访问URL:</label>
                                        <div class="input-group">
                                            <input type="text" class="form-control" value="/img/?s={s2}" readonly>
                                            <button class="btn btn-outline-primary" onclick="navigator.clipboard.writeText('/img/?s={s2}')">
                                                <i class="bi bi-clipboard"></i>
                                            </button>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    
                    <div class="alert alert-info mt-4">
                        <i class="bi bi-info-circle-fill me-2"></i>
                        <strong>使用说明:</strong> 请将两个URL分开存储/访问，只有当访问了所有的URL后，系统才会解码并显示原始信息。
                    </div>
                    
                    <div class="result-box mt-4">
                        <h5><i class="bi bi-send-check info-icon"></i>分发指南</h5>
                        <ul>
                            <li>将第一个URL发送给接收方A / 或者率先访问</li>
                            <li>将第二个URL发送给接收方B / 或者日后访问</li>
                            <li>系统将在双方都访问后自动解码信息</li>
                            <li>可在<a href="/admin">管理后台</a>查看匹配状态</li>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
        """ + HTML_FOOTER
    
    return HTML_HEADER + """
    <div class="container my-5">
        <div class="card">
            <div class="card-header">
                <i class="bi bi-lock me-2"></i>文本编码
            </div>
            <div class="card-body">
                <form method="post">
                    <div class="mb-4">
                        <label class="form-label fw-bold">输入需要编码的文本</label>
                        <textarea class="form-control" name="plaintext" rows="3" placeholder="输入需要保护的敏感信息"></textarea>
                    </div>
                    <div class="text-center">
                        <button type="submit" class="btn btn-primary btn-lg">
                            <i class="bi bi-arrow-repeat me-2"></i>生成编码
                        </button>
                    </div>
                </form>
                
                <div class="alert alert-info mt-4">
                    <i class="bi bi-lightbulb-fill me-2"></i>
                    <strong>提示:</strong> 系统将为每个输入生成两个独特的编码字符串，需要同时使用这两个字符串才能解码原始信息。
                </div>
            </div>
        </div>
    </div>
    """ + HTML_FOOTER


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
    # 创建表格HTML
    matched_html = """
    <div class="card mb-5">
        <div class="card-header d-flex justify-content-between align-items-center">
            <span><i class="bi bi-check-circle-fill me-2"></i>已匹配请求</span>
            <span class="badge bg-success rounded-pill">""" + str(len(matched_pairs)) + """</span>
        </div>
        <div class="card-body">
    """
    
    if matched_pairs:
        matched_html += """
            <div class="table-container">
                <table class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>字符串1</th>
                            <th>字符串2</th>
                            <th>明文</th>
                            <th>首次访问</th>
                            <th>二次访问</th>
                            <th>状态</th>
                        </tr>
                    </thead>
                    <tbody>
        """
        for pair in matched_pairs:
            matched_html += f"""
                        <tr>
                            <td><code>{pair['s1']}</code></td>
                            <td><code>{pair['s2']}</code></td>
                            <td><strong>{pair['plaintext']}</strong></td>
                            <td>{pair['time1'].strftime('%Y-%m-%d %H:%M:%S')}</td>
                            <td>{pair['time2'].strftime('%Y-%m-%d %H:%M:%S')}</td>
                            <td><span class="badge status-badge badge-matched">已匹配</span></td>
                        </tr>
            """
        matched_html += """
                    </tbody>
                </table>
            </div>
        """
    else:
        matched_html += """
            <div class="text-center py-5">
                <i class="bi bi-inbox" style="font-size: 3rem; color: #bdc3c7;"></i>
                <h5 class="mt-3">暂无已匹配请求</h5>
                <p class="text-muted">当有配对的请求时会显示在这里</p>
            </div>
        """
    
    matched_html += "</div></div>"
    
    # 未匹配请求部分
    unmatched_html = """
    <div class="card">
        <div class="card-header d-flex justify-content-between align-items-center">
            <span><i class="bi bi-hourglass-split me-2"></i>未匹配请求</span>
            <span class="badge bg-warning rounded-pill">""" + str(len(unmatched_requests)) + """</span>
        </div>
        <div class="card-body">
    """
    
    if unmatched_requests:
        unmatched_html += """
            <div class="table-container">
                <table class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>请求时间</th>
                            <th>编码字符串</th>
                            <th>状态</th>
                        </tr>
                    </thead>
                    <tbody>
        """
        for req in unmatched_requests:
            unmatched_html += f"""
                        <tr>
                            <td>{req['time'].strftime('%Y-%m-%d %H:%M:%S')}</td>
                            <td><code>{req['s']}</code></td>
                            <td><span class="badge status-badge badge-unmatched">等待匹配</span></td>
                        </tr>
            """
        unmatched_html += """
                    </tbody>
                </table>
            </div>
        """
    else:
        unmatched_html += """
            <div class="text-center py-5">
                <i class="bi bi-check2-circle" style="font-size: 3rem; color: #27ae60;"></i>
                <h5 class="mt-3">暂无未匹配请求</h5>
                <p class="text-muted">所有请求都已成功匹配</p>
            </div>
        """
    
    unmatched_html += "</div></div>"
    
    return HTML_HEADER + """
    <div class="container my-5">
        <div class="d-flex justify-content-between align-items-center mb-4">
            <h2 class="mb-0"><i class="bi bi-speedometer2 me-2"></i>管理控制台</h2>
            <a href="/encode" class="btn btn-primary">
                <i class="bi bi-plus-circle me-2"></i>新建编码
            </a>
        </div>
        
        <div class="row mb-4">
            <div class="col-md-4">
                <div class="card border-primary">
                    <div class="card-body text-center">
                        <h3 class="card-title">""" + str(len(matched_pairs)) + """</h3>
                        <p class="card-text text-muted">成功匹配对</p>
                        <div class="progress" style="height: 8px;">
                            <div class="progress-bar bg-success" style="width: """ + str(100 if matched_pairs else 0) + """%"></div>
                        </div>
                    </div>
                </div>
            </div>
            
            <div class="col-md-4">
                <div class="card border-warning">
                    <div class="card-body text-center">
                        <h3 class="card-title">""" + str(len(unmatched_requests)) + """</h3>
                        <p class="card-text text-muted">待匹配请求</p>
                        <div class="progress" style="height: 8px;">
                            <div class="progress-bar bg-warning" style="width: """ + str(100 if unmatched_requests else 0) + """%"></div>
                        </div>
                    </div>
                </div>
            </div>
            
            <div class="col-md-4">
                <div class="card border-info">
                    <div class="card-body text-center">
                        <h3 class="card-title">""" + str(len(matched_pairs) * 2 + len(unmatched_requests)) + """</h3>
                        <p class="card-text text-muted">总请求数</p>
                        <div class="progress" style="height: 8px;">
                            <div class="progress-bar bg-info" style="width: 100%"></div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        
        """ + matched_html + unmatched_html + """
    </div>
    """ + HTML_FOOTER

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