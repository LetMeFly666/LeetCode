使用相同的样式美化这3个HTML

<h1>加解密系统</h1>
<ul>
    <li><a href="/encode">编码页面</a> - 输入明文获取编码字符串</li>
    <li><a href="/admin">管理后台</a> - 查看匹配结果</li>
    <li>图片服务: /img/?s=编码字符串</li>
</ul>


<form method="post">
                明文: <input type="text" name="plaintext" value="{{ plaintext }}" size="50"><br>
    <input type="submit" value="编码">
</form>
<hr>
{% if s1 and s2 %}
    <h3>生成的字符串:</h3>
    <p>字符串1: <code>{{ s1 }}</code></p>
    <p>字符串2: <code>{{ s2 }}</code></p>
    <h3>使用说明:</h3>
    <p>分别访问以下URL完成配对:</p>
    <p><a href="/img/?s={{ s1 }}">/img/?s={{ s1 }}</a></p>
    <p><a href="/img/?s={{ s2 }}">/img/?s={{ s2 }}</a></p>
{% endif %}







