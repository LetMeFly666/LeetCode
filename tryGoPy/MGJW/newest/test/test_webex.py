'''
Author: LetMeFly
Date: 2025-07-26 14:27:09
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-26 15:51:15
'''
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))
from app.redirect import generate_string_pair, decode_strings
from string import ascii_letters, ascii_lowercase, ascii_uppercase
from random import choices, randint
from typing import Tuple


TEST_TIMES = 150
TEXT = ascii_letters + ascii_lowercase + ascii_uppercase
TEXT_MIN_LENGTH = 5
TEXT_MAX_LENGTH = 20


def generate1text() -> str:
    return 'TEXT:{' + ''.join(choices(TEXT, k=randint(TEXT_MIN_LENGTH, TEXT_MAX_LENGTH))) + '}'


def testOnce() -> Tuple[bool, str]:
    text = generate1text()
    s1, s2 = generate_string_pair(text)
    decoded = decode_strings(s1, s2)
    if text == decoded:
        return True, ''
    return False, f'{text} -> {{{s1}}}+{{{s2}}} -> {decoded}'


def test():
    successTimes = 0
    for case in range(TEST_TIMES):
        success, error = testOnce()
        print(f'[{case+1:03d}/150]:', end=' ')
        if success:
            print('success')
            successTimes += 1
        else:
            print(f'failed, {error}')
    print(f'success rate: {successTimes / TEST_TIMES * 100}%')


if __name__ == '__main__':
    test()

