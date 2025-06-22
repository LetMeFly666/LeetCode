'''
Author: LetMeFly
Date: 2025-06-22 13:15:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-22 13:15:11
'''
from flask import Flask, redirect, request

app = Flask(__name__)

@app.route('/', defaults={'path': ''})
@app.route('/<path:path>')
def redirect_all(path):
    # 获取完整的请求URL（不包括协议和域名部分）
    full_path = request.full_path.strip('?')
    # 构建目标URL（去掉开头的斜杠）
    target_url = full_path.lstrip('/')
    # 执行重定向
    return redirect(target_url, code=302)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=6000, debug=True)