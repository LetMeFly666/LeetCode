'''
Author: LetMeFly
Date: 2024-12-23 23:48:30
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-24 10:25:38
'''
import requests
import json
from Secret import passKey

BASE_URL = 'https://api.letmefly.xyz/calendar'
BASE_URL = 'http://127.0.0.1:8787/calendar'
headers = {
    'Content-Type': 'application/json',
    'Cookie': f'passKey={passKey}'
}

def createTag():
    url = f'{BASE_URL}/tags'
    data = {
        'tagName': '学习',
        'tagColor': '#16bc79'
    }
    response = requests.post(url, headers=headers, data=json.dumps(data))
    print('Create Tag Respnose:', response.status_code, response.text)

def getTags():
    url = f'{BASE_URL}/tags'
    response = requests.get(url, headers=headers)
    print('Get Tags Response:', response.status_code, response.text)

def deleteTag(tagId):
    url = f'{BASE_URL}/tags'
    data = {
        'tagId': tagId
    }
    response = requests.delete(url, headers=headers, data=json.dumps(data))
    print('Delete Tag Response:', response.status_code, response.text)


def alterTag():
    url = f'{BASE_URL}/tags'
    data = {
        'tagId': 4,
        'tagName': 'afterChange',
        'tagColor': '#ffffff'
    }
    response = requests.put(url, headers=headers, data=json.dumps(data))
    print('Alter Tag Response:', response.status_code, response.text)

if __name__ == '__main__':
    pass
    # createTag()
    # getTags()
    # deleteTag(3)
    alterTag()
