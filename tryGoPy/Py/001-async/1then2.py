'''
Author: LetMeFly
Date: 2024-12-13 16:05:26
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-13 16:08:32
'''
import asyncio


async def some_async_function():
    print("Some Begin")
    await asyncio.sleep(1)  # 异步等待
    print("Some End")

async def my_coroutine():
    print("开始")
    await some_async_function()
    print("结束")

async def another_async_function():
    print("Another Begin")
    await asyncio.sleep(2)
    print("Another End")


async def main():
    await asyncio.gather(my_coroutine(), another_async_function())


asyncio.run(main())

"""
开始
Some Begin
Another Begin
Some End
结束
Another End
"""