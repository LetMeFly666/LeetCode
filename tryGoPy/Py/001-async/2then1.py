'''
Author: LetMeFly
Date: 2024-12-13 16:20:50
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-13 16:21:00
'''
import asyncio
import time


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
    start_time = time.time()
    while time.time() - start_time < 2:  # 模拟死循环2秒
        pass
    print("Another End")


async def main():
    await asyncio.gather(my_coroutine(), another_async_function())


asyncio.run(main())

"""
开始
Some Begin
Another Begin
Another End
Some End
结束
"""