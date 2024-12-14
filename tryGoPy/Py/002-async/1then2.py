'''
Author: LetMeFly
Date: 2024-12-13 16:24:46
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-13 16:27:51
'''
import asyncio

async def first():
    print("first begin")
    await asyncio.sleep(1)
    print("first end")

async def second():
    print("second begin")
    await asyncio.sleep(2)
    print("second end")

async def main():
    await asyncio.gather(first(), second())

asyncio.run(main())

"""
first begin
second begin
first end
second end
"""