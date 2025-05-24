'''
Author: LetMeFly
Date: 2025-05-24 09:40:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-24 09:48:33
'''
import datetime
date = '2025-05-23'
fileTime = datetime.datetime.strptime(date, "%Y-%m-%d").date()
today = datetime.date.today()
deltaDays = (today - fileTime).days
print(deltaDays)  # 1
