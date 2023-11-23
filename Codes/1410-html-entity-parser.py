dic = [
    ('&quot;', '"'),
    ('&apos;', "'"),
    ('&gt;', '>'),
    ('&lt;', '<'),
    ('&frasl;', '/'),
    ('&amp;', '&')
]

class Solution:
    def entityParser(self, text: str) -> str:
        ans = ''
        i = 0
        while i < len(text):
            matched = False
            if text[i] == '&':
                for from_, to in dic:
                    if text[i: len(from_) + i] == from_:
                        matched = True
                        ans += to
                        i += len(from_)
                        break
            if not matched:
                ans += text[i]
                i += 1
        return ans