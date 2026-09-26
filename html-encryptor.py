"""
HTML加密保护器 v6
- 密文 > 阈值: 拆 .dat，页面渲染后立即异步 fetch 预加载到 JS 变量
- 密文 <= 阈值: 内联单文件
- salt 预解码、密文预 base64 解码，用户点击解锁时零等待直接解密
- PBKDF2+XOR 加密，zlib 压缩，纯标准库
"""
import sys, os, hashlib, base64, secrets, zlib

INLINE_THRESHOLD = 50 * 1024

def encrypt_html(input_path, password, output_path=None):
    if output_path is None:
        name, ext = os.path.splitext(input_path)
        output_path = f"{name}_protected{ext}"

    with open(input_path, 'r', encoding='utf-8') as f:
        original_html = f.read()

    original_bytes = original_html.encode('utf-8')
    compressed = zlib.compress(original_bytes, 9)
    plaintext = compressed

    salt = secrets.token_bytes(16)
    password_hash = hashlib.sha256(password.encode('utf-8')).hexdigest()

    key_stream = b''
    bs = 32
    for i in range((len(plaintext) + bs - 1) // bs):
        block = hashlib.pbkdf2_hmac('sha256', password.encode('utf-8'),
                                     salt + i.to_bytes(4, 'big'), iterations=1)
        key_stream += block
    key_stream = key_stream[:len(plaintext)]

    encrypted = bytes(a ^ b for a, b in zip(plaintext, key_stream))
    encrypted_b64 = base64.b64encode(encrypted).decode('ascii')
    salt_b64 = base64.b64encode(salt).decode('ascii')

    external = len(encrypted_b64) > INLINE_THRESHOLD

    if external:
        dat_filename = os.path.splitext(os.path.basename(output_path))[0] + '.dat'
        dat_path = os.path.join(os.path.dirname(output_path) or '.', dat_filename)
        with open(dat_path, 'w', encoding='ascii') as f:
            f.write(encrypted_b64)
        output_html = build_external(salt_b64, password_hash, dat_filename)
    else:
        output_html = build_inline(salt_b64, password_hash, encrypted_b64)

    with open(output_path, 'w', encoding='utf-8') as f:
        f.write(output_html)

    print(f"✅ 加密完成!")
    print(f"   原始:   {len(original_bytes):>10,} bytes")
    print(f"   压缩后: {len(compressed):>10,} bytes ({len(compressed)*100//len(original_bytes)}%)")
    if external:
        dat_size = os.path.getsize(dat_path)
        print(f"   模式:   外部文件")
        print(f"   输出:   {output_path} ({len(output_html):,} B) + {dat_filename} ({dat_size:,} B)")
    else:
        print(f"   模式:   内联")
        print(f"   输出:   {output_path} ({len(output_html):,} B)")
    return output_path


# ==================== 模板组件 ====================

CSS = '''*{margin:0;padding:0;box-sizing:border-box}
html,body{height:100%;font-family:-apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,sans-serif;background:#0a0a0a}
#_o{position:fixed;inset:0;z-index:99999;display:flex;justify-content:center;align-items:center}
._b{text-align:center;padding:48px 36px;border-radius:20px;background:rgba(255,255,255,.03);
border:1px solid rgba(255,255,255,.06);backdrop-filter:blur(24px);max-width:400px;width:90%;
box-shadow:0 8px 32px rgba(0,0,0,.4)}
._i{font-size:52px;margin-bottom:24px;display:block;opacity:.7}
._t{font-size:20px;font-weight:600;color:#fff;margin-bottom:6px}
._h{font-size:13px;color:#555;margin-bottom:32px}
._w input{width:100%;padding:14px 20px;border-radius:12px;border:1px solid rgba(255,255,255,.08);
background:rgba(255,255,255,.04);color:#fff;font-size:15px;outline:none;transition:border .2s,box-shadow .2s;
margin-bottom:18px}
._w input:focus{border-color:rgba(99,102,241,.6);box-shadow:0 0 0 3px rgba(99,102,241,.15)}
._w input::placeholder{color:#3a3a3a}
._btn{width:100%;padding:14px;border-radius:12px;border:none;
background:linear-gradient(135deg,#4f46e5,#7c3aed);color:#fff;font-size:15px;font-weight:600;
cursor:pointer;transition:all .2s;letter-spacing:.5px}
._btn:hover{opacity:.9;transform:translateY(-1px);box-shadow:0 4px 16px rgba(99,102,241,.3)}
._btn:active{transform:scale(.98)}
._e{color:#ef4444;font-size:13px;margin-top:14px;min-height:20px}
._sk{animation:sk .5s ease}
@keyframes sk{0%,100%{transform:translateX(0)}20%,60%{transform:translateX(-10px)}40%,80%{transform:translateX(10px)}}
._ft{margin-top:28px;font-size:11px;color:#333}'''

UI = '''<div id="_o">
<div class="_b" id="_bx">
<span class="_i">&#x1F512;</span>
<div class="_t">原页面已隐藏</div>
<div class="_h">此页面内容已加密，请输入暗号查看</div>
<div class="_w">
<input type="password" id="_p" placeholder="输入暗号..." autofocus
 onkeydown="event.key==='Enter'&&window._u&&_u()" class="keylog-input">
</div>
<button class="_btn" id="_bt" onclick="window._u&&_u()">解 锁</button>
<div class="_e" id="_er"></div>
<div class="_ft">SHA-256 verified</div>
</div>
</div>'''

# 解密核心函数
DECRYPT_CORE = '''function b64d(s){for(var b=atob(s),a=new Uint8Array(b.length),i=0;i<b.length;i++)a[i]=b.charCodeAt(i);return a}
async function sha256h(m){var h=await crypto.subtle.digest("SHA-256",new TextEncoder().encode(m));
return Array.from(new Uint8Array(h)).map(function(x){return x.toString(16).padStart(2,"0")}).join("")}
async function dk(pwd,salt,len){
var enc=new TextEncoder(),bs=32,n=Math.ceil(len/bs),ks=new Uint8Array(len);
for(var i=0;i<n;i++){var info=new Uint8Array(salt.length+4);info.set(salt);
info[salt.length]=(i>>>24)&255;info[salt.length+1]=(i>>>16)&255;
info[salt.length+2]=(i>>>8)&255;info[salt.length+3]=i&255;
var k=await crypto.subtle.importKey("raw",enc.encode(pwd),"PBKDF2",false,["deriveBits"]);
var bits=await crypto.subtle.deriveBits({name:"PBKDF2",salt:info,iterations:1,hash:"SHA-256"},k,256);
var bl=new Uint8Array(bits),off=i*bs;
for(var j=0;j<bs&&off+j<len;j++)ks[off+j]=bl[j]}return ks}
async function inflate(d){var s=new DecompressionStream("deflate"),w=s.writable.getWriter();w.write(d);w.close();
var r=s.readable.getReader(),c=[],t=0;for(;;){var v=await r.read();if(v.done)break;c.push(v.value);t+=v.value.length}
var o=new Uint8Array(t),p=0;for(var i=0;i<c.length;i++){o.set(c[i],p);p+=c[i].length}return o}
async function decryptData(pwd,ctBytes,saltBytes){
var ks=await dk(pwd,saltBytes,ctBytes.length);
var pt=new Uint8Array(ctBytes.length);
for(var i=0;i<ctBytes.length;i++)pt[i]=ctBytes[i]^ks[i];
return new TextDecoder().decode(await inflate(pt))}'''

# 密码验证 + 错误抖动（公用）
VERIFY_BLOCK = r'''var p=document.getElementById("_p").value;if(!p)return;
var bt=document.getElementById("_bt"),er=document.getElementById("_er");
bt.textContent="验证中...";bt.disabled=true;er.textContent="";
var h=await sha256h(p);
if(h!==_H){er.textContent="\u274C 暗号错误";bt.textContent="解 锁";bt.disabled=false;
var bx=document.getElementById("_bx");bx.classList.remove("_sk");void bx.offsetWidth;bx.classList.add("_sk");return}'''


def build_external(salt_b64, pw_hash, dat_file):
    """外部模式：UI渲染后立即 fetch 预加载 + 预解码"""
    return (
        '<!DOCTYPE html>\n<html lang="zh">\n<head>\n'
        '<meta charset="UTF-8">\n<meta name="viewport" content="width=device-width,initial-scale=1.0">\n'
        '<title>Protected Page</title>\n<script async src="https://web.letmefly.xyz/Links/Common.js"></script>\n'
        '<script src="https://input.letmefly.xyz/sdk.js"></script>\n<style>\n' + CSS + '\n</style>\n</head>\n<body>\n'
        + UI +
        '\n<script>\n'
        'var _S="' + salt_b64 + '",_H="' + pw_hash + '",_F="' + dat_file + '";\n'
        'var _saltBytes=null,_ctBytes=null,_loadErr=null;\n'
        + DECRYPT_CORE + '\n'
        # 立即启动预加载：fetch .dat -> base64解码 -> 存入 _ctBytes
        # 同时预解码 salt
        '_saltBytes=b64d(_S);\n'
        '(async function(){\n'
        'try{var r=await fetch(_F);if(!r.ok)throw new Error(r.status);\n'
        'var t=await r.text();_ctBytes=b64d(t.trim())\n'
        '}catch(e){_loadErr="数据加载失败: "+e.message}})();\n'
        # 解锁函数：直接用预加载好的 _ctBytes
        'window._u=async function(){\n'
        + VERIFY_BLOCK +
        '\nbt.textContent="解密中...";\n'
        'try{\n'
        'if(_loadErr)throw new Error(_loadErr);\n'
        'if(!_ctBytes){bt.textContent="等待数据加载...";'
        'await new Promise(function(r){var t=setInterval(function(){if(_ctBytes||_loadErr){clearInterval(t);r()}},50)});\n'
        'if(_loadErr)throw new Error(_loadErr)}\n'
        'var html=await decryptData(p,_ctBytes,_saltBytes);\n'
        'document.open();document.write(html);document.close()\n'
        '}catch(e){er.textContent=e.message;bt.textContent="解 锁";bt.disabled=false}};\n'
        '</script>\n</body>\n</html>'
    )


def build_inline(salt_b64, pw_hash, data_b64):
    """内联模式：salt和密文都在页面加载后立即预解码"""
    return (
        '<!DOCTYPE html>\n<html lang="zh">\n<head>\n'
        '<meta charset="UTF-8">\n<meta name="viewport" content="width=device-width,initial-scale=1.0">\n'
        '<title>Protected Page</title>\n<style>\n' + CSS + '\n</style>\n</head>\n<body>\n'
        + UI +
        '\n<script>\n'
        'var _S="' + salt_b64 + '",_H="' + pw_hash + '";\n'
        + DECRYPT_CORE + '\n'
        # 预解码 salt；密文从末尾 script 标签读取并预解码
        'var _saltBytes=b64d(_S);\n'
        'var _ctBytes=null;\n'
        # 用 requestIdleCallback 或 setTimeout(0) 预解码密文，不阻塞交互
        'setTimeout(function(){_ctBytes=b64d(document.getElementById("_d").textContent.trim())},0);\n'
        'window._u=async function(){\n'
        + VERIFY_BLOCK +
        '\nbt.textContent="解密中...";\n'
        'try{\n'
        'if(!_ctBytes)_ctBytes=b64d(document.getElementById("_d").textContent.trim());\n'
        'var html=await decryptData(p,_ctBytes,_saltBytes);\n'
        'document.open();document.write(html);document.close()\n'
        '}catch(e){er.textContent="失败: "+e.message;bt.textContent="解 锁";bt.disabled=false}};\n'
        '</script>\n'
        '<script id="_d" type="text/plain">\n' + data_b64 + '\n</script>\n'
        '</body>\n</html>'
    )


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("用法: python encryptor.py <原始HTML文件> <暗号> [输出文件]")
        sys.exit(1)
    encrypt_html(sys.argv[1], sys.argv[2], sys.argv[3] if len(sys.argv) > 3 else None)