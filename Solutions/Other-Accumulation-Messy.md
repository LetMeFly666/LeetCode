---
title: 日积月累 - 一些小知识 - 杂乱 - 啥都有
date: 2023-10-19 20:13:39
tags: [其他, 小杂, 知识, 中等, Github]
---

# 日积月累 - 一些小知识 - 杂乱 - 啥都有

这里准备放一些日积月累的小知识，但是相比于[日积月累 - 一些小知识](https://blog.letmefly.xyz/2023/02/21/Other-Accumulation-SomeTips/)而言，本文更加随意（杂乱）。

## Github 在issue中引用代码的代码段

方法：在Github的[代码页](https://github.com/LetMeFly666/LeetCode/blob/master/newSolution.py)，点击其中一行的数字，按住shift，再点击零一行的数字，会发现这几行有了背景色。点一下上面那行左边的“三个点的按钮”，点击```Reference in new issue```，即可在新的issue页面获取所引用代码的[链接](https://github.com/LetMeFly666/LeetCode/blob/9c603112d33f885842b37bd368267063d7a5fe3b/newSolution.py#L132-L139)。

效果：[Github@LetMeFly666/LeetCode/issue#32](https://github.com/LetMeFly666/LeetCode/issues/32)

## 轻量级Flask搭建小Web服务

```python
from flask import send_file, Flask

app = Flask('1')

@app.route('/file/')
def download_file():
    return send_file(r'C:\Users\LetMeFly\Desktop\image.png', 'a.png', as_attachment=True)


@app.route('/')
def hello_world():
    return 'Hello World!'

print(app.url_map)
app.run(host='0.0.0.0', port='80', debug=True)
```

这样，访问```ip/file/```时就会开始下载文件，访问```ip/```时会看到```Hello World!```

## C++ auto&&

```cpp
queue<pair<int, int>> q;
auto&& [x, y] = q.front();
q.pop();
```

其中```q.pop()```将会导致```x```和```y```的值失效！ 详情可见一个De了1个多小时的BUG：[7d4f27d](https://github.com/LetMeFly666/LeetCode/commit/7d4f27da29d30e4d7a38fd91b34dbff9af52d154)

## 一点关于华为云空间计算方法以及备份内容的探究

华为云空间有5G免费额度，但很快就满了。于是简单探究了下这5G都备份了啥，发现问题有2：

1. 备份内容重复问题
2. 强制备份应用列表问题

**备份内容重复问题：**

如果我既备份“图库”，又在“文件管理－我的－设置－自动上传文件至云盘－微信文件/QQ文件”中勾选备份“图片/视频”的话，这些图片就会被备份两次，一共占据两次云空间容量。

**强制备份应用列表问题：**

备份“当前设备”时，会强制备份“系统数据”。系统数据中包含很多设置，同时还包含“应用列表”。

如果是在华为应用市场下载的应用，那么基本上就是存了个“下载链接”；但若是从第三方下载的应用，则会直接将应用安装包给备份上去。

这个选项无法单独关闭，是个空间消耗无底洞，轻轻松松以GB为单位。

有个**投机取巧但不值得做**的办法：删除“当前设备”并重新备份，系统会首先备份其他数据（正好是你想要的），最后备份“应用列表”。备份应用列表的过程中空间满了，备份终止，但你想备份的数据也已经备份完了。

## 安卓应用独占蓝牙信道

使用蓝牙耳机进行腾讯系列软件通话时（包括但不限于腾讯会议、微信视频），软件会独占蓝牙信道，使得：

1. 蓝牙无法同时播放音乐
2. 蓝牙声音奇大无比震耳欲聋，调到最小也很大，想调到0调不到

电脑上腾讯系软件也这样，但是可用通过`在声音图标上右键 -> 声音 -> 播放 -> 双击蓝牙设备 -> 高级 -> 取消勾选“允许应用程序独占控制该设备”`解决。

安卓上暂未找到可行办法。。。emm，我说你个tx，不给用户一个选项么，上来就独占，如果我不想让你独占呢。。。

还有使用腾讯会议时经常弹出的“监测到音量过小，建议调整到50%以上”。好家伙，最低音量（6%）我都觉得震耳欲聋，你这样是想让用户报工伤吗？

## 司法人工智能

### Large Legal Fictions: Profiling LegalHallucinations in Large Language Models

```bibtex
@article{dahl2024large,
  title={Large legal fictions: Profiling legal hallucinations in large language models},
  author={Dahl, Matthew and Magesh, Varun and Suzgun, Mirac and Ho, Daniel E},
  journal={Journal of Legal Analysis},
  volume={16},
  number={1},
  pages={64--93},
  year={2024},
  publisher={Oxford University Press UK}
}
```

看完觉得主要就是测评了一些大模型在回答司法问题时的“幻觉问题”。

**实验部分：**

<style>
    /* 为 details 添加边框 */
    details {
        border: 2px solid #3b82f6; /* 边框颜色和宽度 */
        border-radius: 8px; /* 圆角 */
        padding: 10px; /* 内边距 */
        margin: 10px 0; /* 外边距 */
    }
    /* 为 summary 添加样式 */
    summary {
        font-weight: bold; /* 加粗字体 */
        cursor: pointer; /* 鼠标悬停时显示手型 */
        padding: 5px; /* 内边距 */
        background-color: #eff6ff; /* 背景颜色 */
        border-radius: 4px; /* 圆角 */
    }
</style>

<details><summary><a href="https://chat.deepseek.com/a/chat/s/41cd4665-98f6-4443-8dd9-186cbb36c251">Chat with DeepSeek</a><span title="手动调整了格式。。。">.</span></summary>

<iframe id="chatWithDeepseek" style="border: none;" scrolling="no" srcdoc='
<html>
<head>
<style>
/* 气泡框样式 */
.bubble {
background-color: #eff6ff; /* 背景颜色 */
padding: 15px; /* 内边距 */
border-radius: 10px; /* 圆角 */
position: relative; /* 相对定位 */
box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1); /* 阴影效果 */
width: fit-content; /* 宽度根据内容自适应 */
margin-left: auto; /* 使 div 居右 */
margin-right: 0;
}
/* 气泡框的三角形箭头 */
.bubble::after {
content: "";
position: absolute;
right: -10px; /* 箭头位置 */
top: 50%; /* 垂直居中 */
transform: translateY(-50%);
width: 0;
height: 0;
border-top: 10px solid transparent; /* 上边框透明 */
border-bottom: 10px solid transparent; /* 下边框透明 */
border-left: 10px solid #eff6ff; /* 左边框颜色 */
}
body { width: 100%; margin: 0; padding: 0; overflow-x: hidden; }
/* latex源码不显示 */
annotation {
display: none;
}
/* 不想要的也不显示 */
.hidden {
display: none;
}
</style>
</head>
<body>
<div>
<div>
<div>
<div>
<div></div>
<div class="bubble">
<div>Large Legal Fictions Profiling LegalHallucinations in Large Language Models.pdf</div>
<div>PDF 3.51MB</div>
</div>
</div>
</div>
</div>
<div>
<div class="bubble">请仔细阅读这篇文章<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
</div>
</div>
<div>
<div></div>
<div>
<p>这篇文章《大型法律虚构：剖析大型语言模型中的法律幻觉》（<strong>Large Legal Fictions: Profiling Legal Hallucinations in Large
Language Models</strong>）由Matthew Dahl、Varun Magesh、Mirac Suzgun和Daniel E.
Ho撰写，发表于2024年6月26日。文章探讨了大型语言模型（LLMs）在法律领域的应用及其产生的“幻觉”问题，即模型生成的文本与法律事实不一致的现象。</p>
<h3>主要内容和发现：</h3>
<ol>
<li>
<p><strong>研究背景</strong>：</p>
<ul>
<li>
<p>LLMs如OpenAI的ChatGPT在法律实践、教育和研究中被广泛应用，但其生成的文本可能存在与法律事实不符的“幻觉”。</p>
</li>
<li>
<p>文章首次系统地研究了这些幻觉在公开LLMs中的性质和频率，并分析了其在不同司法管辖区、法院、时间段和案件中的表现。</p>
</li>
</ul>
</li>
<li>
<p><strong>研究方法</strong>：</p>
<ul>
<li>
<p>使用OpenAI的ChatGPT 4、ChatGPT 3.5、Google的PaLM 2和Meta的Llama 2等模型，对随机选取的联邦法院案件进行法律知识查询。
</p>
</li>
<li>
<p>查询任务分为低复杂度、中复杂度和高复杂度三类，涵盖案件存在性、法院、引用、作者、判决结果、引用案例、案件背景、法律核心问题等。</p>
</li>
</ul>
</li>
<li>
<p><strong>主要发现</strong>：</p>
<ul>
<li>
<p><strong>幻觉频率</strong>：LLMs在回答直接、可验证的法律问题时，幻觉率在58%（ChatGPT 4）到88%（Llama 2）之间。</p>
</li>
<li>
<p><strong>任务复杂度</strong>：随着任务复杂度的增加，幻觉率显著上升。高复杂度任务如法律核心问题和案件核心判决的幻觉率尤其高。</p>
</li>
<li>
<p><strong>法院层级</strong>：LLMs在最高法院（SCOTUS）的表现最好，而在地区法院（USDC）的表现最差。</p>
</li>
<li>
<p><strong>司法管辖区</strong>：LLMs在第九巡回法院（涵盖加利福尼亚等州）和第二巡回法院（涵盖纽约等州）的表现较好，而在哥伦比亚特区巡回法院的表现较差。
</p>
</li>
<li>
<p><strong>案件年份</strong>：LLMs对20世纪中期的案件表现较好，而对非常古老或非常新的案件表现较差。</p>
</li>
<li>
<p><strong>模型差异</strong>：GPT 4表现最好，其次是GPT 3.5、PaLM 2和Llama 2。</p>
</li>
</ul>
</li>
<li>
<p><strong>其他发现</strong>：</p>
<ul>
<li>
<p><strong>反事实偏差</strong>：LLMs倾向于接受用户提出的错误法律前提，并基于这些前提生成看似合理的错误答案。</p>
</li>
<li>
<p><strong>模型校准</strong>：LLMs在回答法律问题时往往过度自信，无法准确预测自己是否在产生幻觉。</p>
</li>
</ul>
</li>
<li>
<p><strong>结论与建议</strong>：</p>
<ul>
<li>
<p>LLMs在法律知识方面的幻觉问题严重，尤其是在复杂任务和低层级法院的表现较差。</p>
</li>
<li>
<p>文章建议谨慎使用LLMs进行法律任务，特别是对于资源有限的诉讼当事人，LLMs可能会加剧现有的法律服务不平等。</p>
</li>
<li>
<p>未来的研究应关注如何减少幻觉，并开发更可靠的法律LLMs。</p>
</li>
</ul>
</li>
</ol>
<h3>贡献与意义：</h3>
<ul>
<li>
<p>文章为LLMs在法律领域的应用提供了实证依据，揭示了其在实际应用中的局限性。</p>
</li>
<li>
<p>提出了法律幻觉的分类，为未来的研究提供了理论框架。</p>
</li>
<li>
<p>强调了LLMs在提高法律信息可及性方面的潜力，但也指出了其当前的技术缺陷可能带来的风险。</p>
</li>
</ul>
<h3>未来研究方向：</h3>
<ul>
<li>
<p>进一步研究如何通过技术手段（如检索增强生成、高级提示、微调等）减少LLMs的幻觉。</p>
</li>
<li>
<p>探讨LLMs在不同法律任务中的表现，并开发更精准的评估方法。</p>
</li>
<li>
<p>研究LLMs在法律教育和研究中的应用，确保其不会引入知识偏见。</p>
</li>
</ul>
<p>这篇文章为法律界和AI研究者提供了重要的参考，揭示了LLMs在法律应用中的潜力和挑战，并呼吁在未来的技术开发中更加注重模型的准确性和可靠性。</p>
</div>
<div>
<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
<div></div>
</div>
</div>
<div>
<div class="bubble">介绍这篇文章的实验部分<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
</div>
</div>
<div>
<div></div>
<div>
<p>这篇文章的实验部分旨在系统地评估大型语言模型（LLMs）在法律知识查询中的表现，特别是它们在生成与法律事实一致的文本时的准确性。实验设计严谨，涵盖了多个维度的法律查询任务，并通过大量数据验证了LLMs的“幻觉”现象。以下是实验部分的详细介绍：
</p>
<h3>1. <strong>实验目标</strong>：</h3>
<ul>
<li>
<p>评估LLMs在不同复杂度、不同法院层级、不同司法管辖区和不同年份案件中的法律知识掌握情况。</p>
</li>
<li>
<p>测量LLMs在回答法律问题时的“幻觉”频率，即生成与法律事实不符的文本的概率。</p>
</li>
<li>
<p>探讨LLMs在处理错误法律前提（反事实偏差）时的表现，以及它们在回答法律问题时的自信程度（模型校准）。</p>
</li>
</ul>
<h3>2. <strong>实验设计</strong>：</h3>
<ul>
<li>
<p><strong>数据集构建</strong>：</p>
<ul>
<li>
<p>从美国联邦法院系统的三个层级（最高法院SCOTUS、上诉法院USCOA、地区法院USDC）中随机选取了15,000个案件（每个层级5,000个）。</p>
</li>
<li>
<p>使用Caselaw Access Project、Supreme Court
Database等来源的元数据作为参考标准，构建了包含案件存在性、法院、引用、作者、判决结果等信息的查询任务。</p>
</li>
</ul>
</li>
<li>
<p><strong>查询任务</strong>：</p>
<ul>
<li>
<p>查询任务分为三类，按复杂度递增：</p>
<ol>
<li>
<p><strong>低复杂度任务</strong>：案件存在性、法院、引用、作者。</p>
</li>
<li>
<p><strong>中复杂度任务</strong>：判决结果、引用案例、案件被推翻的年份。</p>
</li>
<li>
<p><strong>高复杂度任务</strong>：案件背景、程序性立场、后续历史、法律核心问题、核心判决。</p>
</li>
</ol>
</li>
</ul>
</li>
<li>
<p><strong>模型选择</strong>：</p>
<ul>
<li>
<p>使用了四个流行的LLMs：OpenAI的ChatGPT 4、ChatGPT 3.5、Google的PaLM 2和Meta的Llama 2。</p>
</li>
</ul>
</li>
<li>
<p><strong>实验设置</strong>：</p>
<ul>
<li>
<p>每个查询任务在“零样本”（zero-shot）和“三样本”（three-shot）两种提示设置下进行。零样本设置直接提问，三样本设置在提问前提供几个示例问题及答案，以帮助模型进行上下文学习。
</p>
</li>
<li>
<p>总共执行了超过80万次查询（每个模型20万次以上）。</p>
</li>
</ul>
</li>
</ul>
<h3>3. <strong>实验方法</strong>：</h3>
<ul>
<li>
<p><strong>基于参考的查询</strong>：</p>
<ul>
<li>
<p>对于低复杂度和中复杂度任务，使用外部元数据作为参考标准，直接比较模型的回答与已知的正确答案。</p>
</li>
<li>
<p>计算幻觉率（π），即模型回答与正确答案不符的比例。</p>
</li>
</ul>
</li>
<li>
<p><strong>无参考的查询</strong>：</p>
<ul>
<li>
<p>对于高复杂度任务，由于缺乏明确的参考标准，采用无参考的查询方法。通过多次查询模型并比较其回答的一致性来检测幻觉。</p>
</li>
<li>
<p>如果模型在不同查询中生成矛盾的答案，则认为其产生了幻觉。</p>
</li>
<li>
<p>使用GPT 4来评估模型回答之间的逻辑矛盾。</p>
</li>
</ul>
</li>
</ul>
<h3>4. <strong>实验结果</strong>：</h3>
<ul>
<li>
<p><strong>幻觉频率</strong>：</p>
<ul>
<li>
<p>LLMs在回答直接、可验证的法律问题时，幻觉率在58%（ChatGPT 4）到88%（Llama 2）之间。</p>
</li>
<li>
<p>随着任务复杂度的增加，幻觉率显著上升。高复杂度任务如法律核心问题和案件核心判决的幻觉率尤其高。</p>
</li>
</ul>
</li>
<li>
<p><strong>法院层级</strong>：</p>
<ul>
<li>
<p>LLMs在最高法院（SCOTUS）的表现最好，而在地区法院（USDC）的表现最差。</p>
</li>
</ul>
</li>
<li>
<p><strong>司法管辖区</strong>：</p>
<ul>
<li>
<p>LLMs在第九巡回法院（涵盖加利福尼亚等州）和第二巡回法院（涵盖纽约等州）的表现较好，而在哥伦比亚特区巡回法院的表现较差。</p>
</li>
</ul>
</li>
<li>
<p><strong>案件年份</strong>：</p>
<ul>
<li>
<p>LLMs对20世纪中期的案件表现较好，而对非常古老或非常新的案件表现较差。</p>
</li>
</ul>
</li>
<li>
<p><strong>模型差异</strong>：</p>
<ul>
<li>
<p>GPT 4表现最好，其次是GPT 3.5、PaLM 2和Llama 2。</p>
</li>
</ul>
</li>
<li>
<p><strong>反事实偏差</strong>：</p>
<ul>
<li>
<p>LLMs倾向于接受用户提出的错误法律前提，并基于这些前提生成看似合理的错误答案。</p>
</li>
</ul>
</li>
<li>
<p><strong>模型校准</strong>：</p>
<ul>
<li>
<p>LLMs在回答法律问题时往往过度自信，无法准确预测自己是否在产生幻觉。</p>
</li>
</ul>
</li>
</ul>
<h3>5. <strong>实验结论</strong>：</h3>
<ul>
<li>
<p>LLMs在法律知识方面的幻觉问题严重，尤其是在复杂任务和低层级法院的表现较差。</p>
</li>
<li>
<p>文章建议谨慎使用LLMs进行法律任务，特别是对于资源有限的诉讼当事人，LLMs可能会加剧现有的法律服务不平等。</p>
</li>
<li>
<p>未来的研究应关注如何减少幻觉，并开发更可靠的法律LLMs。</p>
</li>
</ul>
<h3>6. <strong>实验的局限性与未来工作</strong>：</h3>
<ul>
<li>
<p>实验主要关注美国联邦法院系统，未来可以扩展到其他司法管辖区和法律体系。</p>
</li>
<li>
<p>无参考的查询方法只能提供幻觉率的下限，未来可以开发更精确的评估方法。</p>
</li>
<li>
<p>实验未考虑LLMs在处理多语言法律文本时的表现，未来可以探讨跨语言的法律知识查询。</p>
</li>
</ul>
<p>通过这一系列的实验，文章系统地揭示了LLMs在法律应用中的潜力和挑战，为未来的研究和实践提供了重要的参考。</p>
</div>
<div>
<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
<div></div>
</div>
</div>
<div>
<div class="bubble">1. 请详细解释零样本和三样本。<br/>
2. 作者是怎么比较模型回答和已知正确答案的。<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
</div>
</div>
<div>
<div></div>
<div>
<h3>1. <strong>零样本（Zero-shot）和三样本（Three-shot）的解释</strong>：</h3>
<p>在自然语言处理（NLP）中，<strong>零样本</strong>和<strong>三样本</strong>是两种不同的提示（prompting）策略，用于引导大型语言模型（LLMs）生成回答。它们的区别在于是否在提问前提供示例。
</p>
<ul>
<li>
<p><strong>零样本（Zero-shot）</strong>：</p>
<ul>
<li>
<p>在零样本设置中，模型直接根据用户的提问生成回答，<strong>没有任何示例或上下文</strong>。</p>
</li>
<li>
<p>例如，如果用户问：“马伯里诉麦迪逊案的判决结果是什么？”，模型会直接生成回答，而不需要任何关于如何回答类似问题的示例。</p>
</li>
<li>
<p>零样本测试的是模型在没有额外提示的情况下，能否理解任务并生成正确的回答。</p>
</li>
</ul>
</li>
<li>
<p><strong>三样本（Three-shot）</strong>：</p>
<ul>
<li>
<p>在三样本设置中，模型在回答用户的问题之前，会<strong>先看到三个示例问题和对应的答案</strong>。这些示例帮助模型理解任务的格式和内容。</p>
</li>
<li>
<p>例如，在问“马伯里诉麦迪逊案的判决结果是什么？”之前，模型可能会先看到以下三个示例：</p>
<ol>
<li>
<p>问题：“布朗诉教育委员会案的判决结果是什么？” 答案：“最高法院判决种族隔离违宪。”</p>
</li>
<li>
<p>问题：“罗伊诉韦德案的判决结果是什么？” 答案：“最高法院判决妇女有权选择堕胎。”</p>
</li>
<li>
<p>问题：“吉迪恩诉温赖特案的判决结果是什么？” 答案：“最高法院判决被告有权获得律师帮助。”</p>
</li>
</ol>
</li>
<li>
<p>三样本测试的是模型在通过示例学习后，能否更好地理解任务并生成正确的回答。</p>
</li>
</ul>
</li>
</ul>
<h3>2. <strong>作者如何比较模型回答和已知正确答案</strong>：</h3>
<p>作者使用了两种主要方法来比较模型的回答与已知的正确答案：<strong>基于参考的查询</strong>和<strong>无参考的查询</strong>。</p>
<h4><strong>基于参考的查询（Reference-based Querying）</strong>：</h4>
<ul>
<li>
<p>对于低复杂度和中复杂度任务，作者使用了外部元数据作为参考标准，直接比较模型的回答与已知的正确答案。</p>
</li>
<li>
<p>具体步骤如下：</p>
<ol>
<li>
<p><strong>构建参考标准</strong>：使用Caselaw Access Project、Supreme Court
Database等来源的元数据，构建了每个案件的正确答案。例如，案件的法院、引用、作者、判决结果等。</p>
</li>
<li>
<p><strong>生成模型回答</strong>：对于每个查询任务，模型生成一个回答。</p>
</li>
<li>
<p><strong>比较回答与参考标准</strong>：将模型的回答与已知的正确答案进行比较，判断是否一致。</p>
</li>
<li>
<p><strong>计算幻觉率</strong>：如果模型的回答与正确答案不符，则认为模型产生了幻觉。幻觉率（π）的计算公式为：</p>
<span><span><span><math>
<semantics>
<mrow>
<mi>π</mi>
<mo>=</mo>
<mfrac>
<mn>1</mn>
<mi>N</mi>
</mfrac>
<mo>∑</mo>
<mn>1</mn>
<mo>[</mo>
<mtext>response</mtext>
<mo>≠</mo>
<msup>
<mtext>response</mtext>
<mo>∗</mo>
</msup>
<mo>]</mo>
</mrow>
<annotation>\pi = \frac{1}{N} \sum 1[\text{response} \neq
\text{response}^*]</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>π</span><span></span><span>=</span><span></span></span><span><span></span><span><span></span><span><span><span><span><span><span></span><span><span>N</span></span></span><span><span></span><span></span></span><span><span></span><span><span>1</span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span><span></span></span><span></span><span>∑</span><span></span><span>1</span><span>[</span><span><span>response</span></span><span></span><span><span><span><span><span><span></span><span><span><span></span></span></span><span></span></span></span></span></span><span>=</span></span><span></span></span><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span>∗</span></span></span></span></span></span></span></span><span>]</span></span></span></span></span>
<p>其中，<span><span><math>
<semantics>
<mrow>
<mi>N</mi>
</mrow>
<annotation>N</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>N</span></span></span></span>是查询的总数，<span><span><math>
<semantics>
<mrow>
<mtext>response</mtext>
</mrow>
<annotation>\text{response}</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span>response</span></span></span></span></span>是模型的回答，<span><span><math>
<semantics>
<mrow>
<msup>
<mtext>response</mtext>
<mo>∗</mo>
</msup>
</mrow>
<annotation>\text{response}^*</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span>∗</span></span></span></span></span></span></span></span></span></span></span>是已知的正确答案。
</p>
</li>
</ol>
</li>
</ul>
<h4><strong>无参考的查询（Reference-free Querying）</strong>：</h4>
<ul>
<li>
<p>对于高复杂度任务，由于缺乏明确的参考标准，作者采用了无参考的查询方法。通过多次查询模型并比较其回答的一致性来检测幻觉。</p>
</li>
<li>
<p>具体步骤如下：</p>
<ol>
<li>
<p><strong>多次查询模型</strong>：对于每个查询任务，模型在非贪婪温度（temperature=1）下生成两个回答（<span><span><math>
<semantics>
<mrow>
<msup>
<mtext>response</mtext>
<mrow>
<mo>(</mo>
<mn>1</mn>
<mo>)</mo>
</mrow>
</msup>
</mrow>
<annotation>\text{response}^{(1)}</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span><span>(</span><span>1</span><span>)</span></span></span></span></span></span></span></span></span></span></span></span>和<span><span><math>
<semantics>
<mrow>
<msup>
<mtext>response</mtext>
<mrow>
<mo>(</mo>
<mn>2</mn>
<mo>)</mo>
</mrow>
</msup>
</mrow>
<annotation>\text{response}^{(2)}</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span><span>(</span><span>2</span><span>)</span></span></span></span></span></span></span></span></span></span></span></span>）。
</p>
</li>
<li>
<p><strong>比较两个回答</strong>：如果两个回答之间存在逻辑矛盾，则认为模型产生了幻觉。</p>
</li>
<li>
<p><strong>使用GPT 4评估矛盾</strong>：为了自动化矛盾检测，作者使用GPT 4来评估两个回答是否矛盾。</p>
</li>
<li>
<p><strong>计算幻觉率的下限</strong>：由于无参考方法只能检测到矛盾的回答，因此幻觉率的下限（<span><span><math>
<semantics>
<mrow>
<mover>
<mi>π</mi>
<mo>^</mo>
</mover>
</mrow>
<annotation>\hat{\pi}</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span><span><span><span></span><span>π</span></span><span><span></span><span><span>^</span></span></span></span></span></span></span></span></span></span>）的计算公式为：
</p><span><span><span><math>
<semantics>
<mrow>
<mover>
<mi>π</mi>
<mo>^</mo>
</mover>
<mo>=</mo>
<mfrac>
<mn>1</mn>
<mi>N</mi>
</mfrac>
<mo>∑</mo>
<mn>1</mn>
<mo>[</mo>
<msup>
<mtext>response</mtext>
<mrow>
<mo>(</mo>
<mn>1</mn>
<mo>)</mo>
</mrow>
</msup>
<mo>≠</mo>
<msup>
<mtext>response</mtext>
<mrow>
<mo>(</mo>
<mn>2</mn>
<mo>)</mo>
</mrow>
</msup>
<mo>]</mo>
</mrow>
<annotation>\hat{\pi} = \frac{1}{N} \sum 1[\text{response}^{(1)}
\neq \text{response}^{(2)}]</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span><span><span><span></span><span>π</span></span><span><span></span><span><span>^</span></span></span></span></span></span></span><span></span><span>=</span><span></span></span><span><span></span><span><span></span><span><span><span><span><span><span></span><span><span>N</span></span></span><span><span></span><span></span></span><span><span></span><span><span>1</span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span><span></span></span><span></span><span>∑</span><span></span><span>1</span><span>[</span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span><span>(</span><span>1</span><span>)</span></span></span></span></span></span></span></span></span><span></span><span><span><span><span><span><span></span><span><span><span></span></span></span><span></span></span></span></span></span><span>=</span></span><span></span></span><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span><span>(</span><span>2</span><span>)</span></span></span></span></span></span></span></span></span><span>]</span></span></span></span></span>
<p>这意味着，即使两个回答一致，它们仍然可能是错误的，因此实际的幻觉率可能更高。</p>
</li>
</ol>
</li>
</ul>
<h3>总结：</h3>
<ul>
<li>
<p><strong>零样本</strong>和<strong>三样本</strong>是两种不同的提示策略，分别测试模型在没有示例和通过示例学习后的表现。</p>
</li>
<li>
<p><strong>基于参考的查询</strong>通过直接比较模型的回答与已知的正确答案来计算幻觉率。</p>
</li>
<li>
<p><strong>无参考的查询</strong>通过比较模型在不同查询中的回答一致性来检测幻觉，并使用GPT 4评估矛盾。</p>
</li>
</ul>
<p>通过这些方法，作者系统地评估了LLMs在法律知识查询中的表现，揭示了其在不同任务和设置下的幻觉现象。</p>
</div>
<div>
<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
<div></div>
</div>
</div>
<div>
<div class="bubble">什么是非贪婪温度<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
</div>
</div>
<div>
<div></div>
<div>
<p>**非贪婪温度（Non-greedy
temperature）**是大型语言模型（LLMs）生成文本时的一个重要参数，用于控制模型在生成每个词（或“token”）时的随机性。理解非贪婪温度需要先了解模型生成文本的基本机制。</p>
<h3>1. <strong>模型生成文本的基本机制</strong>：</h3>
<ul>
<li>
<p>当LLMs生成文本时，它们会根据输入的提示（prompt）预测下一个最可能的词（token）。模型会计算一个概率分布，表示每个可能的词在下一个位置出现的概率。</p>
</li>
<li>
<p>在**贪婪采样（greedy sampling）**模式下，模型总是选择概率最高的词作为下一个词。这种模式生成的文本通常是确定性的，即每次生成相同的回答。</p>
</li>
</ul>
<h3>2. <strong>温度参数的作用</strong>：</h3>
<ul>
<li>
<p>**温度（temperature）**是一个控制模型生成文本时随机性的参数。它通过调整概率分布的“平滑度”来影响模型的选择。</p>
</li>
<li>
<p>当温度 <span><span><math>
<semantics>
<mrow>
<mi>T</mi>
<mo>=</mo>
<mn>0</mn>
</mrow>
<annotation>T = 0</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>T</span><span></span><span>=</span><span></span></span><span><span></span><span>0</span></span></span></span>
时，模型的行为类似于贪婪采样，总是选择概率最高的词，生成的结果是确定性的。</p>
</li>
<li>
<p>当温度 <span><span><math>
<semantics>
<mrow>
<mi>T</mi>
<mo>&gt;</mo>
<mn>0</mn>
</mrow>
<annotation>T &gt; 0</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>T</span><span></span><span>&gt;</span><span></span></span><span><span></span><span>0</span></span></span></span>
时，模型会根据调整后的概率分布进行随机采样。温度越高，概率分布越平滑，模型选择低概率词的可能性越大，生成的文本越随机和多样化。</p>
</li>
</ul>
<h3>3. <strong>非贪婪温度（Non-greedy temperature）</strong>：</h3>
<ul>
<li>
<p><strong>非贪婪温度</strong>通常指的是温度 <span><span><math>
<semantics>
<mrow>
<mi>T</mi>
<mo>&gt;</mo>
<mn>0</mn>
</mrow>
<annotation>T &gt; 0</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>T</span><span></span><span>&gt;</span><span></span></span><span><span></span><span>0</span></span></span></span>
的情况，即模型在生成文本时引入一定的随机性，而不是总是选择概率最高的词。</p>
</li>
<li>
<p>在非贪婪温度下，模型可能会选择概率较低但仍有意义的词，从而生成更加多样化和创造性的文本。</p>
</li>
<li>
<p>例如，如果温度 <span><span><math>
<semantics>
<mrow>
<mi>T</mi>
<mo>=</mo>
<mn>1</mn>
</mrow>
<annotation>T = 1</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>T</span><span></span><span>=</span><span></span></span><span><span></span><span>1</span></span></span></span>，模型会根据原始的概率分布进行采样；如果温度
<span><span><math>
<semantics>
<mrow>
<mi>T</mi>
<mo>=</mo>
<mn>2</mn>
</mrow>
<annotation>T = 2</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>T</span><span></span><span>=</span><span></span></span><span><span></span><span>2</span></span></span></span>，概率分布会更加平滑，模型选择低概率词的可能性更大。
</p>
</li>
</ul>
<h3>4. <strong>非贪婪温度在实验中的应用</strong>：</h3>
<ul>
<li>
<p>在本文的实验中，作者使用非贪婪温度（temperature=1）来进行<strong>无参考的查询</strong>。具体步骤如下：</p>
<ol>
<li>
<p>对于每个查询任务，模型在非贪婪温度下生成两个回答（<span><span><math>
<semantics>
<mrow>
<msup>
<mtext>response</mtext>
<mrow>
<mo>(</mo>
<mn>1</mn>
<mo>)</mo>
</mrow>
</msup>
</mrow>
<annotation>\text{response}^{(1)}</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span><span>(</span><span>1</span><span>)</span></span></span></span></span></span></span></span></span></span></span></span>和<span><span><math>
<semantics>
<mrow>
<msup>
<mtext>response</mtext>
<mrow>
<mo>(</mo>
<mn>2</mn>
<mo>)</mo>
</mrow>
</msup>
</mrow>
<annotation>\text{response}^{(2)}</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span><span>(</span><span>2</span><span>)</span></span></span></span></span></span></span></span></span></span></span></span>）。
</p>
</li>
<li>
<p>由于非贪婪温度引入了随机性，模型可能会生成不同的回答。</p>
</li>
<li>
<p>如果两个回答之间存在逻辑矛盾，则认为模型产生了幻觉。</p>
</li>
<li>
<p>使用GPT 4来评估这两个回答是否矛盾。</p>
</li>
</ol>
</li>
</ul>
<h3>5. <strong>非贪婪温度的影响</strong>：</h3>
<ul>
<li>
<p><strong>增加多样性</strong>：非贪婪温度可以使模型生成更加多样化的回答，避免总是生成相同的文本。</p>
</li>
<li>
<p><strong>增加幻觉风险</strong>：由于非贪婪温度允许模型选择低概率的词，生成的文本可能更加不准确或与事实不符，从而增加幻觉的风险。</p>
</li>
<li>
<p><strong>检测幻觉</strong>：在无参考的查询中，非贪婪温度帮助作者通过比较模型在不同查询中的回答一致性来检测幻觉。</p>
</li>
</ul>
<h3>总结：</h3>
<p><strong>非贪婪温度</strong>是控制LLMs生成文本时随机性的参数。当温度 <span><span><math>
<semantics>
<mrow>
<mi>T</mi>
<mo>&gt;</mo>
<mn>0</mn>
</mrow>
<annotation>T &gt; 0</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>T</span><span></span><span>&gt;</span><span></span></span><span><span></span><span>0</span></span></span></span>
时，模型会根据调整后的概率分布进行随机采样，生成更加多样化和创造性的文本。在本文的实验中，非贪婪温度用于无参考的查询，通过比较模型在不同查询中的回答一致性来检测幻觉。</p>
</div>
<div>
<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
<div></div>
</div>
</div>
<div>
<div class="bubble">1. 在基于参考的查询中，作者如何判断一个回答是否正确，难道要手动判断这几十万次回答吗？<br/>2.
在无参考的查询中，作者是如何让ChatGPT帮忙判断回答是否一致的。GPT能判断正确吗？这里会不会引入不信任度的问题？<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
</div>
</div>
<div>
<div></div>
<div>
<h3>1. <strong>在基于参考的查询中，作者如何判断一个回答是否正确？</strong></h3>
<p>在基于参考的查询中，作者使用了<strong>自动化方法</strong>来判断模型的回答是否正确，而不是手动判断几十万次回答。具体步骤如下：</p>
<ul>
<li>
<p><strong>构建参考标准</strong>：</p>
<ul>
<li>
<p>作者使用了多个外部法律数据库（如Caselaw Access Project、Supreme Court
Database等）的元数据作为参考标准。这些数据库包含了每个案件的详细信息，如法院、引用、作者、判决结果等。</p>
</li>
<li>
<p>这些元数据被整理成结构化的形式，作为每个查询任务的正确答案。</p>
</li>
</ul>
</li>
<li>
<p><strong>自动化比较</strong>：</p>
<ul>
<li>
<p>对于每个查询任务，模型生成一个回答后，系统会自动将这个回答与参考标准进行比较。</p>
</li>
<li>
<p>例如，如果查询任务是“马伯里诉麦迪逊案的法院是什么？”，模型生成的回答是“美国最高法院”，而参考标准也是“美国最高法院”，则回答被判定为正确。</p>
</li>
<li>
<p>如果模型生成的回答与参考标准不符，则回答被判定为错误（即幻觉）。</p>
</li>
</ul>
</li>
<li>
<p><strong>模糊匹配</strong>：</p>
<ul>
<li>
<p>在某些任务中，作者允许一定程度的模糊匹配。例如，在“作者”任务中，如果模型生成的法官姓名与参考标准中的姓名大致相同（如“John Roberts”与“John G.
Roberts”），则回答被判定为正确。</p>
</li>
</ul>
</li>
<li>
<p><strong>自动化工具</strong>：</p>
<ul>
<li>
<p>作者使用了自动化工具（如<code>eyecite</code>）来解析和比较法律引用，确保引用的格式和内容与参考标准一致。</p>
</li>
</ul>
</li>
</ul>
<p>通过这种自动化方法，作者能够高效地处理大量查询任务，而无需手动判断每个回答。</p>
<h3>2. <strong>在无参考的查询中，作者是如何让ChatGPT帮忙判断回答是否一致的？GPT能判断正确吗？这里会不会引入不信任度的问题？</strong></h3>
<p>在无参考的查询中，作者使用GPT 4来帮助判断模型生成的两个回答是否一致。具体步骤如下：</p>
<ul>
<li>
<p><strong>生成两个回答</strong>：</p>
<ul>
<li>
<p>对于每个查询任务，模型在非贪婪温度（temperature=1）下生成两个回答（<span><span><math>
<semantics>
<mrow>
<msup>
<mtext>response</mtext>
<mrow>
<mo>(</mo>
<mn>1</mn>
<mo>)</mo>
</mrow>
</msup>
</mrow>
<annotation>\text{response}^{(1)}</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span><span>(</span><span>1</span><span>)</span></span></span></span></span></span></span></span></span></span></span></span>和<span><span><math>
<semantics>
<mrow>
<msup>
<mtext>response</mtext>
<mrow>
<mo>(</mo>
<mn>2</mn>
<mo>)</mo>
</mrow>
</msup>
</mrow>
<annotation>\text{response}^{(2)}</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span><span>(</span><span>2</span><span>)</span></span></span></span></span></span></span></span></span></span></span></span>）。
</p>
</li>
<li>
<p>由于非贪婪温度引入了随机性，模型可能会生成不同的回答。</p>
</li>
</ul>
</li>
<li>
<p><strong>使用GPT 4评估一致性</strong>：</p>
<ul>
<li>
<p>作者将这两个回答输入GPT 4，并要求GPT 4判断它们是否一致。</p>
</li>
<li>
<p>例如，GPT 4可能会收到以下提示：“请判断以下两个回答是否一致：回答1：‘马伯里诉麦迪逊案确立了司法审查原则。’
回答2：‘马伯里诉麦迪逊案确认了最高法院的违宪审查权。’”</p>
</li>
<li>
<p>GPT 4会生成一个判断，如“一致”或“不一致”。</p>
</li>
</ul>
</li>
<li>
<p><strong>验证GPT 4的判断</strong>：</p>
<ul>
<li>
<p>为了确保GPT 4的判断准确性，作者手动标注了一部分回答对，并与GPT 4的判断进行比较，进行了<strong>编码者间可靠性分析</strong>（intercoder
reliability analysis）。</p>
</li>
<li>
<p>结果显示，GPT 4的判断与人类标注的一致性较高，表明GPT 4能够较为准确地判断回答是否一致。</p>
</li>
</ul>
</li>
</ul>
<h4><strong>GPT 4能判断正确吗？这里会不会引入不信任度的问题？</strong></h4>
<ul>
<li>
<p><strong>GPT 4的判断准确性</strong>：</p>
<ul>
<li>
<p>虽然GPT 4在大多数情况下能够准确判断回答是否一致，但它并非完美无缺。在某些复杂或模糊的情况下，GPT 4可能会做出错误的判断。</p>
</li>
<li>
<p>为了减少这种误差，作者进行了手动验证，并使用了编码者间可靠性分析来确保GPT 4的判断质量。</p>
</li>
</ul>
</li>
<li>
<p><strong>引入不信任度的问题</strong>：</p>
<ul>
<li>
<p>使用GPT 4来判断回答是否一致确实可能引入一定的不信任度，因为GPT 4本身也可能产生幻觉或错误判断。</p>
</li>
<li>
<p>然而，作者通过手动验证和编码者间可靠性分析，尽量减少这种不信任度的影响。</p>
</li>
<li>
<p>此外，无参考的查询方法本身只能提供幻觉率的下限，因此即使GPT 4的判断存在一定误差，也不会显著影响整体结论。</p>
</li>
</ul>
</li>
</ul>
<h3>总结：</h3>
<ul>
<li>
<p>在<strong>基于参考的查询</strong>中，作者使用自动化方法和外部法律数据库的元数据来判断模型的回答是否正确，避免了手动判断大量回答的繁琐工作。</p>
</li>
<li>
<p>在<strong>无参考的查询</strong>中，作者使用GPT 4来帮助判断模型生成的两个回答是否一致，并通过手动验证和编码者间可靠性分析确保GPT
4的判断准确性。虽然这种方法可能引入一定的不信任度，但作者通过多种手段尽量减少其影响。</p>
</li>
</ul>
</div>
<div>
<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
<div></div>
</div>
</div>
<div>
<div class="bubble">本文的统计指标有哪些？<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
</div>
</div>
<div>
<div></div>
<div>
<p>本文使用了多种统计指标来评估大型语言模型（LLMs）在法律知识查询中的表现，特别是幻觉的频率和相关因素。以下是本文中使用的主要统计指标及其解释：</p>
<h3>1. <strong>幻觉率（Hallucination Rate）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：幻觉率是指模型生成的回答与正确答案不符的比例。</p>
</li>
<li>
<p><strong>计算公式</strong>：</p><span><span><span><math>
<semantics>
<mrow>
<mi>π</mi>
<mo>=</mo>
<mfrac>
<mn>1</mn>
<mi>N</mi>
</mfrac>
<mo>∑</mo>
<mn>1</mn>
<mo>[</mo>
<mtext>response</mtext>
<mo>≠</mo>
<msup>
<mtext>response</mtext>
<mo>∗</mo>
</msup>
<mo>]</mo>
</mrow>
<annotation>\pi = \frac{1}{N} \sum 1[\text{response} \neq \text{response}^*]
</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>π</span><span></span><span>=</span><span></span></span><span><span></span><span><span></span><span><span><span><span><span><span></span><span><span>N</span></span></span><span><span></span><span></span></span><span><span></span><span><span>1</span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span><span></span></span><span></span><span>∑</span><span></span><span>1</span><span>[</span><span><span>response</span></span><span></span><span><span><span><span><span><span></span><span><span><span></span></span></span><span></span></span></span></span></span><span>=</span></span><span></span></span><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span>∗</span></span></span></span></span></span></span></span><span>]</span></span></span></span></span>
<p>其中，<span><span><math>
<semantics>
<mrow>
<mi>N</mi>
</mrow>
<annotation>N</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>N</span></span></span></span>是查询的总数，<span><span><math>
<semantics>
<mrow>
<mtext>response</mtext>
</mrow>
<annotation>\text{response}</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span>response</span></span></span></span></span>是模型的回答，<span><span><math>
<semantics>
<mrow>
<msup>
<mtext>response</mtext>
<mo>∗</mo>
</msup>
</mrow>
<annotation>\text{response}^*</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span>response</span></span><span><span><span><span><span><span></span><span><span>∗</span></span></span></span></span></span></span></span></span></span></span>是已知的正确答案。
</p>
</li>
<li>
<p><strong>应用</strong>：用于衡量模型在不同任务、法院层级、司法管辖区和案件年份中的幻觉频率。</p>
</li>
</ul>
<h3>2. <strong>标准误差（Standard Error）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：标准误差是样本统计量的标准差，用于衡量估计值的精确度。</p>
</li>
<li>
<p><strong>计算公式</strong>：</p><span><span><span><math>
<semantics>
<mrow>
<mi>S</mi>
<mi>E</mi>
<mo>=</mo>
<mfrac>
<mi>σ</mi>
<msqrt>
<mi>N</mi>
</msqrt>
</mfrac>
</mrow>
<annotation>SE = \frac{\sigma}{\sqrt{N}}</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>SE</span><span></span><span>=</span><span></span></span><span><span></span><span><span></span><span><span><span><span><span><span></span><span><span><span><span><span><span><span></span><span><span>N</span></span></span><span><span></span><span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span></span></span><span><span></span><span></span></span><span><span></span><span><span>σ</span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span><span></span></span></span></span></span></span>
<p>其中，<span><span><math>
<semantics>
<mrow>
<mi>σ</mi>
</mrow>
<annotation>\sigma</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>σ</span></span></span></span>是样本标准差，<span><span><math>
<semantics>
<mrow>
<mi>N</mi>
</mrow>
<annotation>N</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>N</span></span></span></span>是样本大小。</p>
</li>
<li>
<p><strong>应用</strong>：用于计算幻觉率的置信区间，评估估计值的可靠性。</p>
</li>
</ul>
<h3>3. <strong>预期校准误差（Expected Calibration Error, ECE）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：预期校准误差是模型置信度与其实证准确率之间的差异，用于衡量模型的校准程度。</p>
</li>
<li>
<p><strong>计算公式</strong>：</p><span><span><span><math>
<semantics>
<mrow>
<mi>E</mi>
<mi>C</mi>
<mi>E</mi>
<mo>=</mo>
<munderover>
<mo>∑</mo>
<mrow>
<mi>i</mi>
<mo>=</mo>
<mn>1</mn>
</mrow>
<mi>B</mi>
</munderover>
<mfrac>
<msub>
<mi>n</mi>
<mi>i</mi>
</msub>
<mi>N</mi>
</mfrac>
<mi>∣</mi>
<msub>
<mtext>acc</mtext>
<mi>i</mi>
</msub>
<mo>−</mo>
<msub>
<mtext>conf</mtext>
<mi>i</mi>
</msub>
<mi>∣</mi>
</mrow>
<annotation>ECE = \sum_{i=1}^{B} \frac{n_i}{N} |\text{acc}_i -
\text{conf}_i|</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>ECE</span><span></span><span>=</span><span></span></span><span><span></span><span><span><span><span><span><span></span><span><span><span>i</span><span>=</span><span>1</span></span></span></span><span><span></span><span><span>∑</span></span></span><span><span></span><span><span><span>B</span></span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span><span></span><span><span></span><span><span><span><span><span><span></span><span><span>N</span></span></span><span><span></span><span></span></span><span><span></span><span><span><span>n</span><span><span><span><span><span><span></span><span><span>i</span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span></span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span><span></span></span><span>∣</span><span><span><span>acc</span></span><span><span><span><span><span><span></span><span><span>i</span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span></span><span></span><span>−</span><span></span></span><span><span></span><span><span><span>conf</span></span><span><span><span><span><span><span></span><span><span>i</span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span></span><span>∣</span></span></span></span></span>
<p>其中，<span><span><math>
<semantics>
<mrow>
<mi>B</mi>
</mrow>
<annotation>B</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>B</span></span></span></span>是置信度区间的数量，<span><span><math>
<semantics>
<mrow>
<msub>
<mi>n</mi>
<mi>i</mi>
</msub>
</mrow>
<annotation>n_i</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span>n</span><span><span><span><span><span><span></span><span><span>i</span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span></span></span></span></span>是第<span><span><math>
<semantics>
<mrow>
<mi>i</mi>
</mrow>
<annotation>i</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>i</span></span></span></span>个区间中的样本数，<span><span><math>
<semantics>
<mrow>
<mi>N</mi>
</mrow>
<annotation>N</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>N</span></span></span></span>是总样本数，<span><span><math>
<semantics>
<mrow>
<msub>
<mtext>acc</mtext>
<mi>i</mi>
</msub>
</mrow>
<annotation>\text{acc}_i</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span>acc</span></span><span><span><span><span><span><span></span><span><span>i</span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span></span></span></span></span>是第<span><span><math>
<semantics>
<mrow>
<mi>i</mi>
</mrow>
<annotation>i</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>i</span></span></span></span>个区间中的实证准确率，<span><span><math>
<semantics>
<mrow>
<msub>
<mtext>conf</mtext>
<mi>i</mi>
</msub>
</mrow>
<annotation>\text{conf}_i</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span><span><span>conf</span></span><span><span><span><span><span><span></span><span><span>i</span></span></span></span><span>​</span></span><span><span><span></span></span></span></span></span></span></span></span></span>是第<span><span><math>
<semantics>
<mrow>
<mi>i</mi>
</mrow>
<annotation>i</annotation>
</semantics>
</math></span><span class="hidden"><span><span></span><span>i</span></span></span></span>个区间中的平均置信度。
</p>
</li>
<li>
<p><strong>应用</strong>：用于评估模型在回答法律问题时的自信程度，判断模型是否能够准确预测自己的幻觉倾向。</p>
</li>
</ul>
<h3>4. <strong>PageRank百分位数（PageRank Percentile）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：PageRank百分位数是衡量案件在引用网络中的中心性和重要性的指标。</p>
</li>
<li>
<p><strong>应用</strong>：用于评估案件的法律和政治显著性，分析幻觉率与案件重要性之间的关系。</p>
</li>
</ul>
<h3>5. <strong>反事实偏差（Contra-factual Bias）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：反事实偏差是指模型在回答基于错误前提的查询时，生成看似合理但错误的回答的倾向。</p>
</li>
<li>
<p><strong>应用</strong>：用于评估模型在处理错误法律前提时的表现，衡量模型是否能够识别并拒绝错误的查询。</p>
</li>
</ul>
<h3>6. <strong>编码者间可靠性（Intercoder Reliability）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：编码者间可靠性是不同编码者在相同任务上判断一致性的度量。</p>
</li>
<li>
<p><strong>应用</strong>：用于验证GPT 4在判断回答一致性时的准确性，确保无参考查询方法的可靠性。</p>
</li>
</ul>
<h3>7. <strong>置信度（Confidence）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：置信度是模型对自己生成回答的自信程度，通常以概率形式表示。</p>
</li>
<li>
<p><strong>应用</strong>：用于评估模型在回答法律问题时的自信程度，判断模型是否能够准确预测自己的幻觉倾向。</p>
</li>
</ul>
<h3>8. <strong>任务复杂度（Task Complexity）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：任务复杂度是指查询任务的难度级别，分为低复杂度、中复杂度和高复杂度。</p>
</li>
<li>
<p><strong>应用</strong>：用于分析幻觉率与任务复杂度之间的关系，评估模型在不同复杂度任务中的表现。</p>
</li>
</ul>
<h3>9. <strong>法院层级（Judicial Hierarchy）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：法院层级是指案件所属的法院级别，分为最高法院（SCOTUS）、上诉法院（USCOA）和地区法院（USDC）。</p>
</li>
<li>
<p><strong>应用</strong>：用于分析幻觉率与法院层级之间的关系，评估模型在不同级别法院中的表现。</p>
</li>
</ul>
<h3>10. <strong>司法管辖区（Jurisdiction）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：司法管辖区是指案件所属的地理区域或巡回法院。</p>
</li>
<li>
<p><strong>应用</strong>：用于分析幻觉率与司法管辖区之间的关系，评估模型在不同地区法院中的表现。</p>
</li>
</ul>
<h3>11. <strong>案件年份（Case Year）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：案件年份是指案件判决的年份。</p>
</li>
<li>
<p><strong>应用</strong>：用于分析幻觉率与案件年份之间的关系，评估模型在不同时间段案件中的表现。</p>
</li>
</ul>
<h3>总结：</h3>
<p>本文使用了多种统计指标来全面评估LLMs在法律知识查询中的表现，包括幻觉率、标准误差、预期校准误差、PageRank百分位数、反事实偏差、编码者间可靠性、置信度、任务复杂度、法院层级、司法管辖区和案件年份。这些指标帮助作者系统地分析了LLMs在不同任务和设置下的幻觉现象，并揭示了其在实际应用中的潜力和挑战。
</p>
</div>
<div>
<div>
<div>
<div></div>
</div>
<div>3 / 3</div>
<div>
<div></div>
</div>
</div>
<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
<div></div>
</div>
</div>
<div>
<div class="bubble">请继续<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
</div>
</div>
<div>
<div></div>
<div>
<h3>12. <strong>模型性能比较（Model Performance Comparison）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：模型性能比较是指不同LLMs在相同任务上的表现对比。</p>
</li>
<li>
<p><strong>应用</strong>：用于评估不同模型（如GPT 4、GPT 3.5、PaLM 2、Llama 2）在法律知识查询中的表现，确定哪个模型在减少幻觉方面表现最佳。</p>
</li>
</ul>
<h3>13. <strong>任务类型（Task Type）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：任务类型是指查询任务的具体内容，如案件存在性、法院、引用、作者、判决结果、引用案例、案件背景、法律核心问题等。</p>
</li>
<li>
<p><strong>应用</strong>：用于分析幻觉率与任务类型之间的关系，评估模型在不同类型任务中的表现。</p>
</li>
</ul>
<h3>14. <strong>回答一致性（Response Consistency）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：回答一致性是指模型在不同查询中生成相同或相似回答的程度。</p>
</li>
<li>
<p><strong>应用</strong>：在无参考的查询中，通过比较模型在不同查询中的回答一致性来检测幻觉。</p>
</li>
</ul>
<h3>15. <strong>置信度区间（Confidence Interval）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：置信度区间是估计值的范围，表示真实值可能落在这个范围内的概率。</p>
</li>
<li>
<p><strong>应用</strong>：用于计算幻觉率的置信区间，评估估计值的可靠性。</p>
</li>
</ul>
<h3>16. <strong>样本大小（Sample Size）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：样本大小是指用于分析的查询任务数量。</p>
</li>
<li>
<p><strong>应用</strong>：用于确保统计分析的可靠性和代表性，本文使用了15,000个案件（每个法院层级5,000个）作为样本。</p>
</li>
</ul>
<h3>17. <strong>分层随机抽样（Stratified Random Sampling）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：分层随机抽样是一种抽样方法，将总体分成若干层，然后从每层中随机抽取样本。</p>
</li>
<li>
<p><strong>应用</strong>：用于确保样本在时间、地点和案件类型上的平衡，提高统计分析的准确性。</p>
</li>
</ul>
<h3>18. <strong>编码者间可靠性分析（Intercoder Reliability Analysis）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：编码者间可靠性分析是评估不同编码者在相同任务上判断一致性的统计方法。</p>
</li>
<li>
<p><strong>应用</strong>：用于验证GPT 4在判断回答一致性时的准确性，确保无参考查询方法的可靠性。</p>
</li>
</ul>
<h3>19. <strong>置信度评分（Confidence Score）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：置信度评分是模型对自己生成回答的自信程度的量化指标。</p>
</li>
<li>
<p><strong>应用</strong>：用于评估模型在回答法律问题时的自信程度，判断模型是否能够准确预测自己的幻觉倾向。</p>
</li>
</ul>
<h3>20. <strong>任务难度（Task Difficulty）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：任务难度是指查询任务的复杂程度，分为低难度、中难度和高难度。</p>
</li>
<li>
<p><strong>应用</strong>：用于分析幻觉率与任务难度之间的关系，评估模型在不同难度任务中的表现。</p>
</li>
</ul>
<h3>21. <strong>案件重要性（Case Importance）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：案件重要性是指案件在法律和政治上的影响力。</p>
</li>
<li>
<p><strong>应用</strong>：用于分析幻觉率与案件重要性之间的关系，评估模型在重要案件中的表现。</p>
</li>
</ul>
<h3>22. <strong>时间趋势（Temporal Trend）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：时间趋势是指幻觉率随时间变化的趋势。</p>
</li>
<li>
<p><strong>应用</strong>：用于分析幻觉率与案件年份之间的关系，评估模型在不同时间段案件中的表现。</p>
</li>
</ul>
<h3>23. <strong>地理趋势（Geographical Trend）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：地理趋势是指幻觉率随地理区域变化的趋势。</p>
</li>
<li>
<p><strong>应用</strong>：用于分析幻觉率与司法管辖区之间的关系，评估模型在不同地区法院中的表现。</p>
</li>
</ul>
<h3>24. <strong>模型校准曲线（Calibration Curve）</strong>：</h3>
<ul>
<li>
<p><strong>定义</strong>：模型校准曲线是模型置信度与实证准确率之间的关系曲线。</p>
</li>
<li>
<p><strong>应用</strong>：用于评估模型在回答法律问题时的校准程度，判断模型是否能够准确预测自己的幻觉倾向。</p>
</li>
</ul>
<h3>总结：</h3>
<p>本文使用了多种统计指标来全面评估LLMs在法律知识查询中的表现，包括幻觉率、标准误差、预期校准误差、PageRank百分位数、反事实偏差、编码者间可靠性、置信度、任务复杂度、法院层级、司法管辖区、案件年份、模型性能比较、任务类型、回答一致性、置信度区间、样本大小、分层随机抽样、编码者间可靠性分析、置信度评分、任务难度、案件重要性、时间趋势、地理趋势和模型校准曲线。这些指标帮助作者系统地分析了LLMs在不同任务和设置下的幻觉现象，并揭示了其在实际应用中的潜力和挑战。
</p>
</div>
<div>
<div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
<div>
<div></div>
</div>
</div>
<div></div>
</div>
</div>
</div>
</body>
</html>
' width='100%'></iframe>

<script>
    const iframe = document.getElementById('chatWithDeepseek');

    iframe.onload = function() {
        const iframeDoc = iframe.contentDocument || iframe.contentWindow.document;

        // 创建 ResizeObserver 监听内容高度变化
        const resizeObserver = new ResizeObserver(entries => {
            const contentHeight = entries[0].target.scrollHeight;
            iframe.style.height = contentHeight + 20 + 'px';
        });

        // 监听 iframe 内容的 body 元素
        resizeObserver.observe(iframeDoc.body);
    };
</script>

</details>

我比较关心：

1. 请详细解释零样本和三样本。
2. 作者是怎么比较模型回答和已知正确答案的。（1. 在基于参考的查询中，作者如何判断一个回答是否正确，难道要手动判断这几十万次回答吗？2. 在无参考的查询中，作者是如何让ChatGPT帮忙判断回答是否一致的。GPT能判断正确吗？这里会不会引入不信任度的问题？）

大模型问答时，零样本是“模型直接根据任务描述或问题生成答案，不提供任何提示”，三样本是“回答前给几个示例”。

**如果做相关实验的话：**

1. 成本问题，例如GPT似乎需要开通会员才能充钱调用API，还有就是API的价格大概是一个什么样的价位。（1次对话1k token计算，ChatGPT-4o输入2.50美元/1M输出10美元/1M，1k次对话11美元，80w次对话得8.8k美元？）（当然这个是全估算，实际可能会相差好几倍，如果限制只输出“答案”不输出多余内容的话，一次输入1k，一次输出50，1k次对话2.5+0.5=3美元，80W次对话得2.4k美元）
2. 数据库来源问题，我能找到这么好的数据库并将其预处理好以便和LLM的回答直接匹配吗？如果LLM不按照格式回答怎么办？我如何处理LLM的回答为可直接对比的格式
3. 数据处理问题，几十万次查询总不能手动比结果，文章中好像也没说明白到底是怎么统计的。实际做实验的话，关于作者、法院、存在性是否正确等问题，需要一一想办法进行匹配。主要是本文未开源。
4. 需要想好都统计哪些指标，以及这些指标的规则细节（例如若大模型弃权回答不应算作幻觉）

一句话：数据处理上估计比较头疼，但应该还在可完成的范围。数据来源（数据集）上得找一下。要测试哪些指标，什么情况具体如何衡量，都需要仔细想好并设计。成本上如果进行80W次对话这种量级，初步预估可能需要个1W人民币左右的成本。

**总结：** (第一遍粗略阅读的总结，请[我的小读者](https://web.letmefly.xyz/He0/shykeke/)按批判的眼光看待)

这篇文章测试了4个模型，使用了零样本和三样本两种模型回答方式，统计了幻觉率、存在性、法院层级等很多指标(例如统计每种模型在非贪婪温度下的幻觉率)，帮助作者系统地分析了LLMs在不同任务和设置下的幻觉现象，并揭示了其在实际应用中的潜力和挑战。

模型如下：

+ OpenAI’s ChatGPT 4 (gpt-4-1106-preview, [OpenAI 2023a](https://doi.org/10.48550/arXiv.2303.08774))
+ OpenAI’s ChatGPT 3.5 (gpt-3.5-turbo-0613, [2023b](https://openai.com/blog/chatgpt))
+ Google’s PaLM 2 (text-bison-001, [Anil et al. 2023](https://doi.org/10.48550/arXiv.2305.10403))
+ Meta’s Llama 2 (Llama-2-13b-chat-hf, [Touvron et al. 2023](https://doi.org/10.48550/arXiv.2307.09288))

## GoLang

### Go的值类型和引用类型

Go中`a := b`，若`b`是值类型则会发生值拷贝，修改`a`不会修改`b`；但若`b`是引用类型，则赋值操作会传递引用，修改`a`也会导致`b`同步变化。

+ 常见值类型：基本类型（int、string、...）、数组、结构体
+ 常见引用类型：切片、映射、通道、函数、指针

### Kitex使用日记

From: [Github@LetMeFly666/LeetCode/tryGoPy/Go/douyinec/README.md](https://github.com/LetMeFly666/LeetCode/blob/b51c7e73c9798b0fd397ab2e131ba33868e47ad3/tryGoPy/Go/douyinec/README.md)

```bash
git clone git@cloudwego/kitex-examples.git
cd kitex-example
go run .  # 这里我本来使用的Go 1.19.5不支持go.mod里的toolchain，所以升级为了当前最新版go1.23.5
# 令起终端
go run ./client
```

#### 开了个私有仓库来记录kitex学习过程中的修改

[Github@LetMeFly666/kitex-examples](https://github.com/LetMeFly666/kitex-examples/)

起了个别名：

```bash
git config --local alias.pushLet "push Let main:master"
```

后续想要push到远端的时候直接`git pushLet`就好。

TODOED: 给CloudWeGo提PR，不sleep 1 秒。

可行吗？试试吧。像个办法看进程启动了还是异常退出了。

不行就不PR了。

TODOED: https://www.cloudwego.io/zh/docs/kitex/getting-started/tutorial/#%E6%8B%89%E5%8F%96%E4%BE%9D%E8%B5%96  的上面的代码段，build.sh后面有一个tab，导致渲染出来的注释不对齐

#### 自定义RPC函数

1. 修改`.thrift`文件
2. 使用`kitex`生成新代码文件
    
    ```bash
    kitex -module "github.com/cloudwego/kitex-examples" -service a.b.c hello.thrift
    ```

3. 更新`go`文件

    1. 更新`./handler.go`，实现自定义的RPC函数
    2. 更新`./client/main.go`，调用这个远程函数

## sth. about 漯河日报（特指网站） - 发现By [我](https://letmefly.xyz/)和[shy](https://web.letmefly.xyz/He0/shykeke/)

由一本书引发了漯河日报的[一篇文章](http://rb.lhrb.com.cn/html/2018-06/28/content_25454.htm)，然后开始了一点点对于日报官网的探究。

[`2018年12月21日`](http://rb.lhrb.com.cn/html/2018-12/21/node_2.htm)及其之前，页脚备案信息“都”是：

```
鄂ICP备05006816号
Copyright@1984-2006 China water transport. All Rights Reserved.
中国水运报刊社 版权所有 建议分辨率1024*768 IE6.0下浏览
```

[`2018年12月24日`](http://rb.lhrb.com.cn/html/2018-12/24/node_2.htm)及其之后（截至[`2018年12月31日13:55:55`](http://rb.lhrb.com.cn/html/2025-01/27/node_2.htm)），页脚备案信息变成了：

```
豫ICP备05015908号
互联网新闻信息服务许可证编号41120181101
Copyright© 2002-2018 漯河日报社版权所有 未经书面特别授权，请勿转载或建立镜像 建议分辨率1024*768 IE6.0下浏览
```

猜测可能是18年年底之前漯河日报没有“互联网新闻信息服务许可”，所以先用了中国水运报刊社的资格。

### 小槽点

1. 只支持`HTTP`而不支持`HTTPS`不是很安全。
2. 下方页脚未及时更新，估计是之前全部生成的静态页面而不是动态获取的。这样的话文件在服务器上有很大的“相同内容的冗余”，但还好。
3. 日报地址格式为`http://rb.lhrb.com.cn/html/YYYY-mm/dd/node_2.htm`，emm，不能简化一点么。并且将`node_2`修改为`node_1`后还能访问只是部分乱码了。

# End

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/19/Other-Accumulation-Messy)哦~
> [https://blog.letmefly.xyz/2023/10/19/Other-Accumulation-Messy](https://blog.letmefly.xyz/2023/10/19/Other-Accumulation-Messy)