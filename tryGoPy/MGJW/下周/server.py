'''
Author: LetMeFly
Date: 2025-03-21 15:44:59
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-21 16:29:00
'''
from flask import Flask, request, send_file
import io

app = Flask(__name__)

# 1x1 像素的 PNG 图片（最小字节）
minimal_image = b'\x89PNG\r\n\x1a\n\x00\x00\x00\rIHDR\x00\x00\x00\x01\x00\x00\x00\x01\x08\x02\x00\x00\x00\x90wS\xde\x00\x00\x00\x0cIDAT\x08\xd7c\xf8\x0f\x00\x01\x01\x01\x00\x1f\x9d\x8e\xf4\x00\x00\x00\x00IEND\xaeB`\x82'


@app.route('/image', methods=['GET'])
def get_image():
    # 获取查询参数
    jwt = request.args.get('jwt', default='', type=str)
    print(jwt)
    # 返回图片
    return send_file(
        io.BytesIO(minimal_image),
        mimetype='image/png',
        as_attachment=False
    )


if __name__ == '__main__':
    app.run(debug=True)
