from flask import Flask, request, send_file
import io
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
from binascii import unhexlify

app = Flask('LetMeFly_xyz - Flask(MGJW)')

# 1x1像素的PNG图片
minimal_image = b'\x89PNG\r\n\x1a\n\x00\x00\x00\rIHDR\x00\x00\x00\x01\x00\x00\x00\x01\x08\x02\x00\x00\x00\x90wS\xde\x00\x00\x00\x0cIDAT\x08\xd7c\xf8\x0f\x00\x01\x01\x01\x00\x1f\x9d\x8e\xf4\x00\x00\x00\x00IEND\xaeB`\x82'


def decrypt_aes(ciphertext: str) -> str:
    ciphertext = unhexlify(ciphertext)
    key = bytes.fromhex('e3a9a39b3c95c109257aeb8c09cb8ad331779647c54de1a40a66d308f8e4a882')  # 演示用
    iv = ciphertext[:AES.block_size]
    ct = ciphertext[AES.block_size:]  # 密文
    cipher = AES.new(key, AES.MODE_CBC, iv)
    pt = unpad(cipher.decrypt(ct), AES.block_size)
    return pt.decode()


@app.route('/image', methods=['GET'])
def get_image():
    # 获取查询参数
    jwt = request.args.get('jwt', default='', type=str)
    print(jwt)
    decrypted = decrypt_aes(jwt)
    print(decrypted)
    # 返回图片
    return send_file(
        io.BytesIO(minimal_image),
        mimetype='image/png',
        as_attachment=False
    )


@app.route('/')
def index():
    return "Hello World"


if __name__ == '__main__':
    app.run(debug=True, host='127.0.0.1', port=86)