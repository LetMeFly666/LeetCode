'''
Author: LetMeFly
Date: 2024-12-13 16:28:04
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-13 16:30:42
'''
import asyncio
import time

async def first():
    print("first begin")
    await asyncio.sleep(1)
    print("first end")

async def second():
    print("second begin")
    start = time.time()
    while time.time() - start < 2:
        pass
    print("second end")

async def main():
    await asyncio.gather(first(), second())

asyncio.run(main())

"""
first begin
second begin
second end
first end
"""