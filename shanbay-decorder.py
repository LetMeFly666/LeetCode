#!/usr/bin/env python3
"""
Decoder for the custom encoding scheme found in the JS source code.

Algorithm summary:
1. The first 4 characters of the encoded string are a "seed" (key).
2. A Tinymt32-like PRNG is seeded with those 4 characters.
3. Using the PRNG, a trie-based substitution table is built:
   - Each of the 64 base64 characters (A-Z, a-z, 0-9, +, /) is mapped to
     a variable-length code composed of base32 alphabet characters (A-Z, 2-7).
   - The code lengths follow the pattern [1,2,2,2,2,2] indexed by (charIndex+1)/11.
4. A validation check is performed on the first 4 chars:
   ((32 * k(c[0]) + k(c[1])) * k(c[2]) + k(c[3])) % 32 <= 1
   where k(c) = ord(c) - 65 if ord(c) >= 65 else ord(c) - 65 + 41
5. The remaining characters are decoded using the trie back to base64.
6. The base64 string is then decoded to the final plaintext.
"""

import base64
import json


def u32(x):
    """Ensure unsigned 32-bit integer."""
    return x & 0xFFFFFFFF


def xor(a, b):
    return u32(u32(a) ^ u32(b))


def and_(a, b):
    return u32(u32(a) & u32(b))


def mul(a, b):
    """Emulate JS unsigned 32-bit multiplication."""
    hi = u32((u32(a) & 0xFFFF0000) >> 0) * b
    lo = (u32(a) & 0xFFFF) * b
    return u32(u32(hi) + u32(lo))


def or_(a, b):
    return u32(u32(a) | u32(b))


def shl(a, b):
    return u32(u32(a) << b)


def shr(a, b):
    return u32(a) >> b


def neg_and(n, one):
    """Compute -and_(n, 1) as unsigned 32-bit."""
    val = and_(n, one)
    return u32(-val)  # Python handles this: u32 will mask to 32 bits


class TinyMT:
    """TinyMT32-like PRNG as implemented in the JS source."""

    def __init__(self):
        self.status = [0, 0, 0, 0]
        self.mat1 = 0
        self.mat2 = 0
        self.tmat = 0

    def seed(self, key_str):
        # Initialize status from first 4 chars of key
        for i in range(4):
            if i < len(key_str):
                self.status[i] = u32(ord(key_str[i]))
            else:
                self.status[i] = u32(110)  # 'n'

        self.mat1 = self.status[1]
        self.mat2 = self.status[2]
        self.tmat = self.status[3]
        self._init()

    def _init(self):
        for t in range(7):
            idx = (t + 1) & 3
            prev = t & 3
            val = xor(
                self.status[idx],
                (t + 1) + mul(1812433253, xor(self.status[prev], shr(self.status[prev], 30)))
            )
            self.status[idx] = u32(val)

        # Check for zero state
        if (and_(self.status[0], 2147483647) == 0 and
                self.status[1] == 0 and
                self.status[2] == 0 and
                self.status[3] == 0):
            self.status[0] = 66  # 'B'
            self.status[1] = 65  # 'A'
            self.status[2] = 89  # 'Y'
            self.status[3] = 83  # 'S'

        for _ in range(8):
            self.next_state()

    def next_state(self):
        s = self.status
        t = s[3]
        e = xor(and_(s[0], 2147483647), xor(s[1], s[2]))
        e = xor(e, shl(e, 1))
        t = xor(t, xor(shr(t, 1), e))

        s[0] = s[1]
        s[1] = s[2]
        s[2] = xor(e, shl(t, 10))
        s[3] = t

        s[1] = xor(s[1], and_(neg_and(t, 1), self.mat1))
        s[2] = xor(s[2], and_(neg_and(t, 1), self.mat2))

    def generate(self, mod):
        self.next_state()
        s = self.status
        t = s[3]
        n = xor(s[0], shr(s[2], 8))
        t = xor(t, n)
        t = xor(and_(neg_and(n, 1), self.tmat), t)
        return u32(t) % mod


B32_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567"
B64_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
CODE_LENGTHS = [1, 2, 2, 2, 2, 2]  # indexed by int((charIndex+1)/11)


class TrieNode:
    def __init__(self):
        self.char = "."
        self.children = {}


class Decoder:
    def __init__(self):
        self.random = TinyMT()
        self.sign = ""
        self.inter = {}
        self.head = TrieNode()

    def init(self, key):
        self.random.seed(key)
        self.sign = key

        for i in range(64):
            b64_char = B64_ALPHABET[i]
            code_len = CODE_LENGTHS[int((i + 1) / 11)]
            self.add_symbol(b64_char, code_len)

        self.inter["="] = "="

    def add_symbol(self, char, length):
        node = self.head
        code = ""
        for _ in range(length):
            c = B32_ALPHABET[self.random.generate(32)]
            while c in node.children and node.children[c].char != ".":
                c = B32_ALPHABET[self.random.generate(32)]
            code += c
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.char = char
        self.inter[char] = code
        return code

    def decode(self, encoded):
        result = ""
        i = 4  # skip the first 4 characters (seed/key)
        while i < len(encoded):
            if encoded[i] != "=":
                node = self.head
                while i < len(encoded) and encoded[i] in node.children:
                    node = node.children[encoded[i]]
                    i += 1
                result += node.char
            else:
                result += "="
                i += 1
        return result


def k(char):
    """Character to numeric value."""
    t = ord(char)
    if t >= 65:
        return t - 65
    else:
        return t - 65 + 41


def validate_key(key):
    """Check if the first 4 characters form a valid key."""
    val = ((32 * k(key[0]) + k(key[1])) * k(key[2]) + k(key[3])) % 32
    return val <= 1


def decrypt(data):
    """Full decryption: validate key, build trie, decode base32->base64, then base64->plaintext."""
    key = data[:4]

    if not validate_key(key):
        return f"ERROR: Invalid key '{key}' (validation failed)"

    decoder = Decoder()
    decoder.init(key)

    # Decode from custom encoding back to base64
    b64_str = decoder.decode(data)

    # Decode base64 to plaintext
    try:
        plaintext = base64.b64decode(b64_str).decode("utf-8")
    except Exception as e:
        return f"Base64 decode result (raw): {b64_str}\nError decoding: {e}"

    return plaintext


# ============ Test with the two provided data strings ============

data1 = "7DB67KFCC4BM5OGLXNCU2V7XNNXC7X5Q5KLLDUTU2HCIBNNXCKF6QARIQKW6QXTJYJ5X7XLX6Q77CFTF25KKZKFM5FCTJY5KNWNWHM"

data2 = "xxx"
data2 = data1

print("=" * 80)
print("DECRYPTING DATA 1:")
print("=" * 80)
result1 = decrypt(data1)
print(result1)

print("\n" + "=" * 80)
print("DECRYPTING DATA 2:")
print("=" * 80)
result2 = decrypt(data2)
print(result2[:2000])  # Print first 2000 chars since data2 is very long
print("..." if len(result2) > 2000 else "")

with open ('result2.json', 'w', encoding='utf-8') as f:
    f.write(result2)
