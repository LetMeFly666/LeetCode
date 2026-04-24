'''
Author: LetMeFly (with Claude)
Date: 2026-04-24 22:57:00
LastEditors: LetMeFly.xyz
LastEditTime: 2026-04-24 22:57:00
Command: python -m unittest test_newSolution
What's more: 单测 newSolution.py 中的纯函数
  - ensureTrailingBlankLine  (写源码: 末尾确保空行)
  - goSpaces2Tabs            (写源码: go 代码区 4 空格 -> tab)
  - stripTrailingBlankLines  (源码->题解: 去掉末尾空行)
  - goTabs2Spaces            (源码->题解: go 行首 tab -> 4 空格)
这些函数不依赖 sys.argv/git/subprocess, 所以用 ast 只把它们的定义拎出来执行,
避免触发 newSolution.py 顶层逻辑.
'''
import ast
import os
import unittest


def _load_funcs_from_newSolution():
    here = os.path.dirname(os.path.abspath(__file__))
    with open(os.path.join(here, 'newSolution.py'), 'r', encoding='utf-8') as f:
        src = f.read()
    tree = ast.parse(src)
    wanted = {
        'ensureTrailingBlankLine',
        'goSpaces2Tabs',
    }
    # stripTrailingBlankLines 和 goTabs2Spaces 是 genSolutionPart 的内嵌函数
    # 需要额外到 genSolutionPart 里掏
    ns = {}
    for node in tree.body:
        if isinstance(node, ast.FunctionDef) and node.name in wanted:
            mod = ast.Module(body=[node], type_ignores=[])
            exec(compile(mod, '<newSolution>', 'exec'), ns)
        if isinstance(node, ast.FunctionDef) and node.name == 'genSolutionPart':
            for sub in ast.walk(node):
                if isinstance(sub, ast.FunctionDef) and sub.name in (
                    'stripTrailingBlankLines', 'goTabs2Spaces'
                ):
                    mod = ast.Module(body=[sub], type_ignores=[])
                    exec(compile(mod, '<newSolution.genSolutionPart>', 'exec'), ns)
    missing = {'ensureTrailingBlankLine', 'goSpaces2Tabs',
               'stripTrailingBlankLines', 'goTabs2Spaces'} - ns.keys()
    assert not missing, f'未能从 newSolution.py 加载到函数: {missing}'
    return ns


_F = _load_funcs_from_newSolution()
ensureTrailingBlankLine = _F['ensureTrailingBlankLine']
goSpaces2Tabs = _F['goSpaces2Tabs']
stripTrailingBlankLines = _F['stripTrailingBlankLines']
goTabs2Spaces = _F['goTabs2Spaces']


class TestEnsureTrailingBlankLine(unittest.TestCase):
    '''功能 1: 写源码时末尾恰好以一个 \\n 结尾 (POSIX 文件尾约定,
    与仓库 Codes/ 下既有文件保持一致——不要制造多余空行).'''

    def test_empty(self):
        self.assertEqual(ensureTrailingBlankLine(''), '\n')

    def test_no_trailing_newline(self):
        '''无尾换行 -> 补恰好 1 个 \\n (不是 2 个)'''
        self.assertEqual(ensureTrailingBlankLine('abc'), 'abc\n')

    def test_single_trailing_newline_unchanged(self):
        '''已经恰好 1 个 \\n -> 不动'''
        self.assertEqual(ensureTrailingBlankLine('abc\n'), 'abc\n')

    def test_double_trailing_newline_trimmed(self):
        '''末尾多余空行 (\\n\\n) 要被削到 1 个 \\n'''
        self.assertEqual(
            ensureTrailingBlankLine('class Solution:\n    pass\n\n'),
            'class Solution:\n    pass\n',
        )

    def test_many_trailing_newlines_trimmed(self):
        '''末尾任意多个 \\n 都削成 1 个'''
        self.assertEqual(ensureTrailingBlankLine('abc\n\n\n\n'), 'abc\n')

    def test_python_solution_with_trailing_spaces_preserved(self):
        '''Python Solution 后仅空格的一行, 自身以 \\n 结尾即可, 空格行保留(是数据)'''
        src = 'class Solution:\n    pass\n    \n'
        got = ensureTrailingBlankLine(src)
        # 末尾恰好 1 个 \n, 不应被补成 \n\n
        self.assertTrue(got.endswith('\n'))
        self.assertFalse(got.endswith('\n\n'))
        # 空格行本身保留
        self.assertIn('    \n', got)
        # 确认等价
        self.assertEqual(got, 'class Solution:\n    pass\n    \n')

    def test_python_solution_with_trailing_tab_preserved(self):
        src = 'class Solution:\n    pass\n\t\n'
        got = ensureTrailingBlankLine(src)
        self.assertTrue(got.endswith('\n'))
        self.assertFalse(got.endswith('\n\n'))
        self.assertIn('\t\n', got)
        self.assertEqual(got, 'class Solution:\n    pass\n\t\n')

    def test_rust_typical_no_newline(self):
        '''复现真实 bug: rust 源码末尾 "...  }\\n}" 无 \\n 结尾 -> 补 1 个'''
        src = 'impl Solution {\n    pub fn f() -> i32 {\n        0\n    }\n}'
        got = ensureTrailingBlankLine(src)
        self.assertTrue(got.endswith('}\n'))
        self.assertFalse(got.endswith('\n\n'))

    def test_idempotent(self):
        '''多次调用结果不变 (幂等)'''
        for s in ['', 'abc', 'abc\n', 'abc\n\n', 'abc\n\n\n',
                  'class Solution:\n    pass\n    \n\n']:
            once = ensureTrailingBlankLine(s)
            twice = ensureTrailingBlankLine(once)
            self.assertEqual(once, twice, f'not idempotent for {s!r}')

    def test_always_ends_with_single_newline(self):
        '''调用后输出一定恰好以 1 个 \\n 结尾, 不多也不少'''
        for s in ['', 'a', 'a\n', 'a\n\n', 'a\n\n\n', 'a\n   \n', 'a\n\t\n',
                  'a\nb', 'a\nb\n', 'a\nb\n\n']:
            got = ensureTrailingBlankLine(s)
            self.assertTrue(got.endswith('\n'),
                            f'not newline-terminated for {s!r}, got {got!r}')
            # 不应以 \n\n 结尾 (除非是单独的 '\n' 这种极端)
            if got != '\n':
                self.assertFalse(
                    got.endswith('\n\n'),
                    f'extra blank line for {s!r}, got {got!r}',
                )


class TestGoSpaces2Tabs(unittest.TestCase):
    '''功能 2: go 源码 4 空格 -> tab, 且不误伤字符串/注释'''

    def test_basic_indent(self):
        src = 'func f() {\n    x := 1\n        y := 2\n}\n'
        exp = 'func f() {\n\tx := 1\n\t\ty := 2\n}\n'
        self.assertEqual(goSpaces2Tabs(src), exp)

    def test_odd_indent_kept(self):
        '''3 空格不是 4 的整数倍, 保留原样'''
        src = '   oddIndent := 3\n    good := 4\n'
        exp = '   oddIndent := 3\n\tgood := 4\n'
        self.assertEqual(goSpaces2Tabs(src), exp)

    def test_raw_string_literal_preserved(self):
        '''reg: 反引号内行首空格是数据, 不得改动'''
        src = (
            'package main\n'
            'var s = `\n'
            '    four spaces in raw string\n'
            '        eight spaces in raw string\n'
            '`\n'
            'func f() {\n'
            '    x := 1\n'
            '}\n'
        )
        exp = (
            'package main\n'
            'var s = `\n'
            '    four spaces in raw string\n'
            '        eight spaces in raw string\n'
            '`\n'
            'func f() {\n'
            '\tx := 1\n'
            '}\n'
        )
        self.assertEqual(goSpaces2Tabs(src), exp)

    def test_block_comment_preserved(self):
        src = '/*\n    注释内 4 空格\n*/\nfunc g() {\n    return\n}\n'
        exp = '/*\n    注释内 4 空格\n*/\nfunc g() {\n\treturn\n}\n'
        self.assertEqual(goSpaces2Tabs(src), exp)

    def test_line_comment_does_not_swallow_next_line(self):
        '''// 注释遇到 \\n 结束, 下一行的行首缩进应正常处理'''
        src = 'func h() {\n    // a comment\n    x := 1\n}\n'
        exp = 'func h() {\n\t// a comment\n\tx := 1\n}\n'
        self.assertEqual(goSpaces2Tabs(src), exp)

    def test_double_quoted_string_same_line(self):
        src = 'func h() {\n    s := "hello"\n}\n'
        exp = 'func h() {\n\ts := "hello"\n}\n'
        self.assertEqual(goSpaces2Tabs(src), exp)

    def test_escaped_backtick_not_applicable(self):
        '''go 的 raw string 里不识别转义, \\` 不会关闭字符串 - 这是 go 规范'''
        # raw string 无转义, 以第一个 ` 结束. 测试行为一致
        src = 'var s = `abc`\nfunc f() {\n    x := 1\n}\n'
        exp = 'var s = `abc`\nfunc f() {\n\tx := 1\n}\n'
        self.assertEqual(goSpaces2Tabs(src), exp)

    def test_no_leading_spaces(self):
        src = 'package main\nfunc f() {}\n'
        self.assertEqual(goSpaces2Tabs(src), src)


class TestStripTrailingBlankLines(unittest.TestCase):
    '''功能 3: 源码 -> 题解时删掉末尾空行 (含纯空白行)'''

    def test_multiple_newlines(self):
        self.assertEqual(stripTrailingBlankLines('abc\n\n\n'), 'abc')

    def test_whitespace_lines(self):
        self.assertEqual(stripTrailingBlankLines('abc\n   \n\t\n'), 'abc')

    def test_no_trailing(self):
        self.assertEqual(stripTrailingBlankLines('abc'), 'abc')

    def test_mid_blank_lines_kept(self):
        '''只去掉尾部空行, 中间的空行不动'''
        self.assertEqual(
            stripTrailingBlankLines('a\n\nb\n\n'),
            'a\n\nb',
        )

    def test_all_blank(self):
        self.assertEqual(stripTrailingBlankLines('\n\n   \n'), '')

    def test_empty(self):
        self.assertEqual(stripTrailingBlankLines(''), '')


class TestGoTabs2Spaces(unittest.TestCase):
    '''功能 4: 源码 -> 题解时 go 行首 tab -> 4 空格'''

    def test_basic(self):
        src = 'func f() {\n\tx := 1\n\t\ty := 2\n}\n'
        exp = 'func f() {\n    x := 1\n        y := 2\n}\n'
        self.assertEqual(goTabs2Spaces(src), exp)

    def test_no_leading_tab(self):
        src = 'package main\nfunc f() {}\n'
        self.assertEqual(goTabs2Spaces(src), src)

    def test_only_leading_tabs_replaced(self):
        '''行首以外的 tab 不动 (比如行中间出现的 tab)'''
        src = '\tx\t:= 1\n'
        exp = '    x\t:= 1\n'
        self.assertEqual(goTabs2Spaces(src), exp)

    def test_roundtrip_on_tab_aligned_code(self):
        '''对"只用 tab 缩进"的代码, tab->space 再 space->tab 能还原'''
        src = 'func f() {\n\tif x {\n\t\treturn 1\n\t}\n\treturn 0\n}\n'
        self.assertEqual(goSpaces2Tabs(goTabs2Spaces(src)), src)


class TestIntegration(unittest.TestCase):
    '''几个"写源码 → 读源码写题解"的端到端流程场景'''

    def test_go_file_written_then_read_for_solution(self):
        '''模拟:
        1) 刚从 leetcode 拿到的 go 代码 (4 空格缩进, 无尾 \\n)
        2) 经 goSpaces2Tabs + ensureTrailingBlankLine 落盘
        3) 写题解时读回, 经 goTabs2Spaces + stripTrailingBlankLines
        4) 与原始代码等价 (仅缩进规范化, 首尾不多余)
        '''
        original = 'func twoSum(nums []int) int {\n    return 0\n}'
        on_disk = ensureTrailingBlankLine(goSpaces2Tabs(original))
        # 落盘后: tab 缩进 + 末尾恰好 1 个 \n (不是 \n\n, 与仓库惯例一致)
        self.assertIn('\t', on_disk)
        self.assertTrue(on_disk.endswith('\n'))
        self.assertFalse(on_disk.endswith('\n\n'))
        # 读出写进题解
        for_solution = stripTrailingBlankLines(goTabs2Spaces(on_disk))
        # 题解里: 4 空格缩进, 无尾空行
        self.assertNotIn('\t', for_solution)
        self.assertFalse(for_solution.endswith('\n'))
        self.assertEqual(for_solution, original)

    def test_rust_file_written_gets_trailing_newline(self):
        '''复现 PR #1543 中的 rust bug: 写盘后必须以 \\n 结尾 (但不能多到 \\n\\n)'''
        original = 'impl Solution {\n    pub fn f() -> i32 {\n        0\n    }\n}'
        on_disk = ensureTrailingBlankLine(original)
        self.assertTrue(on_disk.endswith('}\n'))
        self.assertFalse(on_disk.endswith('\n\n'))


if __name__ == '__main__':
    unittest.main()

