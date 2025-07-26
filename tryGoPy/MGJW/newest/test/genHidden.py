'''
Author: LetMeFly
Date: 2025-07-26 16:11:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-26 16:22:31
'''
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))
from app.redirect import generate_string_pair


URL_FORMAT = 'http://127.0.0.1:86/redirect/webexteams://s={}&messageId=1111111'
s1List = []
s2List = []


with open('texts.txt', 'r', encoding='utf-8') as f:
    texts = f.readlines()


for text in texts:
    text = text.strip()
    s1, s2 = generate_string_pair(text)
    s1List.append(URL_FORMAT.format(s1))
    s2List.append(URL_FORMAT.format(s2))


with open('s1.txt', 'w', encoding='utf-8') as f:
    f.write('\n'.join(s1List))
with open('s2.txt', 'w', encoding='utf-8') as f:
    f.write('\n'.join(s2List))
