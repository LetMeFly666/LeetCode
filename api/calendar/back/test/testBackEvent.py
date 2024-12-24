'''
Author: LetMeFly
Date: 2024-12-20 22:07:11
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-23 23:48:24
'''
import requests
import json
from Secret import passKey

# 基本的URL和API
BASE_URL = 'https://api.letmefly.xyz/calendar'
# BASE_URL = 'http://127.0.0.1:8787/calendar'

# 用于模拟请求的headers，包含cookie
headers = {
    'Content-Type': 'application/json',
    'Cookie': f'passKey={passKey}'
}

# 测试创建事件的API（POST /events）
def create_event():
    url = f'{BASE_URL}/events'
    data = {
        'title': '开发',
        'description': 'LetCalendar开发',
        'startTime': '2024-12-20T10:00:00',
        'during': 60,  # 任务持续时长，单位为分钟
        'tags': [1]
    }
    
    response = requests.post(url, headers=headers, data=json.dumps(data))
    print('Create Event Response:', response.status_code, response.text)

# 测试获取事件的API（GET /events）
def get_events():
    url = f'{BASE_URL}/events'
    response = requests.get(url, headers=headers)
    print('Get Events Response:', response.status_code, response.text)

# 测试删除事件的API（DELETE /events）
def delete_event(task_id):
    url = f'{BASE_URL}/events'
    data = {
        'taskId': task_id  # 传递taskId在请求体中
    }
    
    response = requests.delete(url, headers=headers, data=json.dumps(data))
    print('Delete Event Response:', response.status_code, response.text)

# # 测试创建一个事件
# create_event()

# # 测试获取所有事件
# get_events()

# # 测试删除某个事件
# delete_event(12)  # 无法删除不存在的id
# delete_event(14)
