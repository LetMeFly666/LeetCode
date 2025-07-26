from flask import Blueprint, request, render_template
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import json
import os

owa_blueprint = Blueprint('owa', __name__)


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

@owa_blueprint.route('/', methods=['GET', 'POST'])
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
        html = "<img src=\'https://10.129.208.167:86/backend/image?jwt={}\'>".format(beacon_id)
        with open('test.html', 'w') as f:
            f.write(html)
        save_data(data)
        
    return render_template('server-beacon-index.html', beacon_id=beacon_id)

@owa_blueprint.route('/list')
def show_list():
    data = load_data()
    return render_template('server-beacon-list.html', entries=data)
