'''
Author: LetMeFly
Date: 2025-06-22 14:51:38
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-22 14:51:42
'''
from flask import Flask, render_template, request, redirect, url_for
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
# import base64
import json
import os


app = Flask('LetMeFly_xyz - Flask(MGJW) - beacon')

KEY = bytes.fromhex('e3a9a39b3c95c109257aeb8c09cb8ad331779647c54de1a40a66d308f8e4a882')  # 演示用，实际可别公布
DATA_FILE = 'beacon.tfsp'


def encrypt_aes(plaintext: str, key: bytes) -> bytes:
    cipher = AES.new(key, AES.MODE_CBC)
    ct_bytes = cipher.encrypt(pad(plaintext.encode(), AES.block_size))
    return cipher.iv + ct_bytes


def load_data():
    if not os.path.exists(DATA_FILE):
        return []
    with open(DATA_FILE, 'r') as f:
        return json.load(f)


def save_data(data):
    with open(DATA_FILE, 'w') as f:
        json.dump(data, f, indent=2)


@app.route('/', methods=['GET', 'POST'])
def index():
    beacon_id = None
    if request.method == 'POST':
        email = request.form['email']
        encrypted = encrypt_aes(email, KEY)
        # beacon_id = base64.b64encode(encrypted).decode('utf-8')  # 算了，还是先不base64了
        beacon_id = encrypted.hex()
        
        data = load_data()
        data.append({
            "email": email,
            "beacon_id": beacon_id
        })
        save_data(data)
        
    return render_template('server-beacon-index.html', beacon_id=beacon_id)


@app.route('/list')
def show_list():
    data = load_data()
    return render_template('server-beacon-list.html', entries=data)


if __name__ == '__main__':
    app.run(debug=True)