'''
Author: LetMeFly
Date: 2025-08-08 10:20:20
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-08 10:20:21
'''
toName = "0904-fruit-into-baskets_20250805.rs"

with open("lib.rs", "r+", encoding="utf-8") as f:
    content = f.read()
    import re
    content = re.sub(r'include!\(".*?"\);', f'include!("{toName}");', content, count=1)
    f.seek(0)
    f.write(content)
    f.truncate()
