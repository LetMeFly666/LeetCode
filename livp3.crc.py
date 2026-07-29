'''
Author: LetMeFly
Date: 2026-07-29 14:53:22
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-29 15:00:30
'''
import zlib
import sys

filename = sys.argv[1]
data = open(filename, 'rb').read()
crc32 = zlib.crc32(data)
print(hex(crc32))
