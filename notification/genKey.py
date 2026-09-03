'''
Author: LetMeFly
Date: 2026-09-02 13:53:19
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-02 13:53:20
'''
from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives import serialization


private_key = ec.generate_private_key(ec.SECP256R1())

# 私钥
with open("vapid_private.pem", "wb") as f:
    f.write(
        private_key.private_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PrivateFormat.PKCS8,
            encryption_algorithm=serialization.NoEncryption(),
        )
    )

# 公钥
public_key = private_key.public_key()

with open("vapid_public.pem", "wb") as f:
    f.write(
        public_key.public_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PublicFormat.SubjectPublicKeyInfo,
        )
    )

print("生成完成")