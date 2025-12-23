'''
Author: LetMeFly
Date: 2025-12-23 22:37:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-23 22:43:45
'''

import re
from typing import Optional
from datetime import datetime

INPUT_FILE = "C:/Users/LetMe/Desktop/let_proc_snapshot.log"
OUTPUT_FILE = "C:/Users/LetMe/Desktop/proc_snapshot_5min.log"

# 匹配头部时间行
HEADER_RE = re.compile(r"^===== (.+) =====$")

def parse_time(line: str) -> Optional[datetime]:
    m = HEADER_RE.match(line.strip())
    if not m:
        return None
    return datetime.strptime(m.group(1), "%Y-%m-%d %H:%M:%S")

def should_keep(ts: datetime) -> bool:
    return ts.minute % 5 == 0

def main():
    with open(INPUT_FILE, "r", encoding="utf-8") as fin, \
         open(OUTPUT_FILE, "w", encoding="utf-8") as fout:

        block_lines = []
        block_time = None

        for line in fin:
            ts = parse_time(line)
            if ts:
                # 新 block 开始，先处理上一个
                if block_time and should_keep(block_time):
                    fout.writelines(block_lines)

                block_lines = [line]
                block_time = ts
            else:
                block_lines.append(line)

        # 文件结束，别忘了最后一个 block
        if block_time and should_keep(block_time):
            fout.writelines(block_lines)

    print(f"Resample done: {OUTPUT_FILE}")

if __name__ == "__main__":
    main()
