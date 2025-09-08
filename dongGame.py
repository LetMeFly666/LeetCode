'''
Author: LetMeFly
Date: 2025-09-06 18:45:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-06 18:48:02
'''
import requests

"""
https://dongdozizi.github.io/Lava-Vanguard/Gold/
https://github.com/dongdozizi/Lava-Vanguard
"""

url = 'https://firestore.googleapis.com/v1/projects/csci526teamsevenranking/databases/(default)/documents/noRevive'
response = requests.post(
    url,
    data="""
    {
      "fields": {
        "name":   { "stringValue": "LetMeFly" },
        "wave":   { "integerValue": "32" },
        "killed": { "integerValue": "10150" }
      }
    }
    """
    )
print(response)
print(response.text)