'''
Author: LetMeFly
Date: 2026-02-15 12:00:05
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-15 12:01:08
'''
from enum import Enum
import subprocess


class User(Enum):
    Tisfy = "Tisfy"
    LetMeFly = "LetMeFly666"

def get_whoami() -> User:
    name = subprocess.check_output(
        ["git", "config", "user.name"],
        stderr=subprocess.DEVNULL
    ).decode().strip()
    return User(name)
WHOAMI = get_whoami()
print(WHOAMI)
