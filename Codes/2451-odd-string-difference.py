from typing import List
from collections import defaultdict

class Solution:
    def oddString(self, words: List[str]) -> str:
        n = len(words[0])
        for j in range(0, n - 1):
            ma = defaultdict(int)
            for word in words:
                ma[ord(word[j + 1]) - ord(word[j])] += 1
            for word in words:
                if ma[ord(word[j + 1]) - ord(word[j])] == 1:
                    return word
        return ""  # FAKE RETURN