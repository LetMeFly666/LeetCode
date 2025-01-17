'''
Author: LetMeFly
Date: 2025-01-17 09:39:51
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-17 10:22:11
'''
import requests
import urllib.request

response = requests.get(
    url='https://www.baidu.com',
    proxies={'http': 'http://127.0.0.1:8888', 'https': 'https://127.0.0.1:8888'},
    verify=False
)
print(response)
exit()
response = requests.get(
    url='https://mp.mhealth100.com/gateway/registration/appointment/scheduleNew/find?branchCode=100238001&deptId=1150101&deptName=%25E8%25BF%2590%25E5%258A%25A8%25E5%258C%25BB%25E5%25AD%25A6%25E9%2597%25A8%25E8%25AF%258A&deptType=&startDate=2025-01-20&endDate=2025-01-20&ajaxConfig=true',
    proxies = urllib.request.getproxies(),
)
print(response)
print(response.json())