'''
Author: LetMeFly
Date: 2026-09-02 15:05:08
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-02 15:16:46
Description: 将XML中除了name以外的属性全部删除
'''
import sys
import xml.etree.ElementTree as ET


def main():
    if len(sys.argv) != 3:
        print(f"用法: python {sys.argv[0]} <输入文件> <输出文件>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    tree = ET.parse(input_file)
    root = tree.getroot()

    for menu in root.iter("menu"):
        name = menu.get("name")

        menu.attrib.clear()

        if name is not None:
            menu.set("name", name)

    tree.write(
        output_file,
        encoding="UTF-8",
        xml_declaration=True
    )


if __name__ == "__main__":
    main()