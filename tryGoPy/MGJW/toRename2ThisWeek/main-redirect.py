# http://127.0.0.1:6000/webexteams://im?space=388bc8a0-4f23-11f0-9978-197e3894c22a&s=ljsjfl&message=5ce38670-4f23-11f0-8dc1-cf25d4d2274c
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
    app.run(host='127.0.0.1', port=5000, debug=True)