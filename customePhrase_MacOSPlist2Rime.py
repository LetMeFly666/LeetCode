'''
Author: LetMeFly
Date: 2026-07-22 20:56:24
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-22 21:13:57
Description: 把MacOS的自定义短语导出为Rime可使用版本（词Tab拼写）
Description: 首先需要在 设置-键盘-自定义短句-全部选中-导出为plist
'''
import plistlib

"""
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<array>
	<dict>
		<key>phrase</key>
		<string>北京邮电大学</string>
		<key>shortcut</key>
		<string>bjyd</string>
	</dict>
	<dict>
		<key>phrase</key>
		<string>≠</string>
		<key>shortcut</key>
		<string>budengyu</string>
	</dict>
    ...
</array>
</plist>
"""

INPUT = "/Users/tisfy/Downloads/自定义短语.plist"
OUTPUT = "output.txt"


def main():
    with open(INPUT, "rb") as f:
        data = plistlib.load(f)

    with open(OUTPUT, "w", encoding="utf-8") as f:
        for item in data:
            phrase = item.get("phrase")
            shortcut = item.get("shortcut")

            if phrase and shortcut:
                f.write(f"{phrase}\t{shortcut}\n")
            else:
                print(f"'{phrase}'\t'{shortcut}'")


if __name__ == "__main__":
    main()
