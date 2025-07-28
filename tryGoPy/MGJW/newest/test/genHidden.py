'''
Author: LetMeFly
Date: 2025-07-26 16:11:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-26 17:13:28
'''
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))
from app.redirect import generate_string_pair
from app.owa import encrypt_aes
from app.owa import KEY as OWA_KEY
from typing import List


WEBEX_URL_FORMAT = 'http://127.0.0.1:86/redirect/webexteams://s={}&messageId=1111111'
OWA_URL_FORMAT = 'http://127.0.0.1:86/img/?jwt={}'
s1List = []
s2List = []
beaconList = []


with open('texts.txt', 'r', encoding='utf-8') as f:
    texts = f.readlines()


for text in texts:
    text = text.strip()
    s1, s2 = generate_string_pair(text)
    s1List.append(WEBEX_URL_FORMAT.format(s1))
    s2List.append(WEBEX_URL_FORMAT.format(s2))
    s_beacon = encrypt_aes(text, OWA_KEY).hex()
    beaconList.append(OWA_URL_FORMAT.format(s_beacon))


def write1file(fileName: str, strList: List[str]) -> None:
    with open(fileName, 'w', encoding='utf-8') as f:
        f.write('\n'.join(strList))

write1file('s1.txt', s1List)
write1file('s2.txt', s2List)
write1file('beacon.txt', beaconList)
