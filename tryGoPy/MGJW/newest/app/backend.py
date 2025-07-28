'''
Author: LetMeFly
Date: 2025-06-28 13:31:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-28 13:56:19
'''
from flask import Flask, request, send_file
import io
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
from binascii import unhexlify
import os
import json

from flask import Blueprint, render_template

backend_blueprint = Blueprint('backend', __name__)


app = Flask('LetMeFly_xyz - Flask(MGJW)')

# 1x1像素的PNG图片
minimal_image = b'\x89PNG\r\n\x1a\n\x00\x00\x00\rIHDR\x00\x00\x00\x01\x00\x00\x00\x01\x08\x02\x00\x00\x00\x90wS\xde\x00\x00\x00\x0cIDAT\x08\xd7c\xf8\x0f\x00\x01\x01\x01\x00\x1f\x9d\x8e\xf4\x00\x00\x00\x00IEND\xaeB`\x82'


# 初始化时读取历史信息，断电恢复也不怕哈哈哈，但是没有考虑并发问题(虽然现实生活中用户很难快速打开一封邮件并触发信标两次)。
if os.path.exists('count.tfsp') and os.path.isfile('count.tfsp'):
    with open('count.tfsp', 'r') as f:
        data = json.loads(f.read())
else:
    data = {}


def decrypt_aes(ciphertext: str) -> str:
    ciphertext = unhexlify(ciphertext)
    key = bytes.fromhex('e3a9a39b3c95c109257aeb8c09cb8ad331779647c54de1a40a66d308f8e4a882')  # 演示用
    iv = ciphertext[:AES.block_size]
    ct = ciphertext[AES.block_size:]  # 密文
    cipher = AES.new(key, AES.MODE_CBC, iv)
    pt = unpad(cipher.decrypt(ct), AES.block_size)
    return pt.decode()


# @app.route('/image', methods=['GET'])
@backend_blueprint.route('/image', methods=['GET'])
def get_image():
    # 获取查询参数
    jwt = request.args.get('jwt', default='', type=str)
    print(jwt)
    global data
    if jwt in data:
        data[jwt] += 1
    else:
        data[jwt] = 1
    with open('count.tfsp', 'w') as f:
        f.write(json.dumps(data))
    decrypted = decrypt_aes(jwt)
    
    with open('decrypted.txt', 'a') as f:
        f.write(decrypted + '\n')
    print(decrypted)
    # 返回图片
    return send_file(
        io.BytesIO(minimal_image),
        mimetype='image/png',
        as_attachment=False
    )


# @app.route('/count')
@backend_blueprint.route('/count')
def get_count():
    jwt = request.args.get('jwt', default='', type=str)
    print(jwt)
    if jwt in data:
        return str(data[jwt])
    return str(0)


# @app.route('/')
@backend_blueprint.route('/')
def index():
    return "Hello World"

