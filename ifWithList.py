'''
Author: LetMeFly
Date: 2025-09-05 10:21:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-05 10:24:29
'''
import ast
import re

def normalize_code(code: str) -> str:
    """给不完整的class/def补上 pass"""
    lines = code.splitlines()
    new_lines = []
    for i, line in enumerate(lines):
        new_lines.append(line)
        if re.match(r'^\s*def\s+\w+\(.*\)\s*(->\s*.*)?:\s*$', line):
            new_lines.append(" " * (len(line) - len(line.lstrip()) + 4) + "pass")
    if re.match(r'^\s*class\s+\w+\s*.*:\s*$', lines[-1]):
        new_lines.append("    pass")
    return "\n".join(new_lines)


def needs_typing_list(code: str) -> bool:
    code = normalize_code(code)  # 先补全
    tree = ast.parse(code)

    class ListChecker(ast.NodeVisitor):
        def __init__(self):
            self.uses_list = False

        def visit_Name(self, node):
            if node.id == "List":
                self.uses_list = True
            self.generic_visit(node)

        def visit_Attribute(self, node):
            if isinstance(node.value, ast.Name) and node.value.id == "typing" and node.attr == "List":
                self.uses_list = True
            self.generic_visit(node)

    checker = ListChecker()
    checker.visit(tree)
    return checker.uses_list



code1 = """
class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        pass
"""

code2 = """
class Solution:
    def add(self, a: int, b: int) -> int:
        return a + b
"""

code3 = """
class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        
"""

print(needs_typing_list(code1))  # True
print(needs_typing_list(code2))  # False
print(needs_typing_list(code3))  # not full py code
