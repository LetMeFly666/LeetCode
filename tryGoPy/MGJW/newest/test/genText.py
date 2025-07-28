'''
Author: LetMeFly
Date: 2025-07-26 16:06:12
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-26 16:10:43
'''
from string import ascii_letters, ascii_lowercase, ascii_uppercase
from random import choices, randint


TEST_TIMES = 150
TEXT = ascii_letters + ascii_lowercase + ascii_uppercase
TEXT_MIN_LENGTH = 5
TEXT_MAX_LENGTH = 20
generatedTexts = []


for _ in range(TEST_TIMES):
    generatedTexts.append('TEXT:{' + ''.join(choices(TEXT, k=randint(TEXT_MIN_LENGTH, TEXT_MAX_LENGTH))) + '}')

with open('texts.txt', 'w', encoding='utf-8') as f:
    f.write('\n'.join(generatedTexts))