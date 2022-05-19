import os
import requests

GITHUBLEETCODEDEPLOYKEY = os.environ["GITHUBLEETCODEDEPLOYKEY"]
FORPYTHONDEBUG = os.environ["FORPYTHONDEBUG"]
response = requests.post("https://www.letmefly.xyz/URLdebug/", data={"GITHUBLEETCODEDEPLOYKEY": GITHUBLEETCODEDEPLOYKEY, "FORPYTHONDEBUG": FORPYTHONDEBUG})
print(response)
print(response.text)
