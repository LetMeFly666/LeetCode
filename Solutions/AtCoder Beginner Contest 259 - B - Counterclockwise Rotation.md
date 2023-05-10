---
title: AtCoder Beginner Contest 259 - B - Counterclockwise Rotation
date: 2022-07-09 22:09:34
tags: [题解, AtCoder, 中等, 数学, 坐标, 旋转, 直角坐标与极坐标的转换]
---

Time Limit: 2 sec / Memory Limit: 1024 MB

<span class="lang-en" style="display: inline;">
<p>Score : <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>200</mn></mrow><annotation encoding="application/x-tex">200</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">2</span><span class="mord">0</span><span class="mord">0</span></span></span></span></span></var> points</p>

<div class="part">
<section>
<h3>Problem Statement</h3><p>In an <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>x</mi><mi>y</mi></mrow><annotation encoding="application/x-tex">xy</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.625em; vertical-align: -0.19444em;"></span><span class="mord mathnormal">x</span><span class="mord mathnormal" style="margin-right: 0.03588em;">y</span></span></span></span></span></var>-coordinate plane whose <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>x</mi></mrow><annotation encoding="application/x-tex">x</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.43056em; vertical-align: 0em;"></span><span class="mord mathnormal">x</span></span></span></span></span></var>-axis is oriented to the right and whose <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>y</mi></mrow><annotation encoding="application/x-tex">y</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.625em; vertical-align: -0.19444em;"></span><span class="mord mathnormal" style="margin-right: 0.03588em;">y</span></span></span></span></span></var>-axis is oriented upwards, rotate a point <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mo stretchy="false">(</mo><mi>a</mi><mo separator="true">,</mo><mi>b</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">(a, b)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord mathnormal">a</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord mathnormal">b</span><span class="mclose">)</span></span></span></span></span></var> around the origin <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>d</mi></mrow><annotation encoding="application/x-tex">d</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.69444em; vertical-align: 0em;"></span><span class="mord mathnormal">d</span></span></span></span></span></var> degrees counterclockwise and find the new coordinates of the point.</p>
</section>
</div>

<div class="part">
<section>
<h3>Constraints</h3><ul>
<li><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mo>−</mo><mn>1000</mn><mo>≤</mo><mi>a</mi><mo separator="true">,</mo><mi>b</mi><mo>≤</mo><mn>1000</mn></mrow><annotation encoding="application/x-tex">-1000 \leq a,b \leq 1000</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.78041em; vertical-align: -0.13597em;"></span><span class="mord">−</span><span class="mord">1</span><span class="mord">0</span><span class="mord">0</span><span class="mord">0</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">≤</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 0.88888em; vertical-align: -0.19444em;"></span><span class="mord mathnormal">a</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord mathnormal">b</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">≤</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">1</span><span class="mord">0</span><span class="mord">0</span><span class="mord">0</span></span></span></span></span></var></li>
<li><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn><mo>≤</mo><mi>d</mi><mo>≤</mo><mn>360</mn></mrow><annotation encoding="application/x-tex">1 \leq d \leq 360</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.78041em; vertical-align: -0.13597em;"></span><span class="mord">1</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">≤</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 0.83041em; vertical-align: -0.13597em;"></span><span class="mord mathnormal">d</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">≤</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">3</span><span class="mord">6</span><span class="mord">0</span></span></span></span></span></var></li>
<li>All values in input are integers.</li>
</ul>
</section>
</div>

<hr>
<div class="io-style">
<div class="part">
<section>
<h3>Input</h3><p>Input is given from Standard Input in the following format:</p>
<pre><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>a</mi></mrow><annotation encoding="application/x-tex">a</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.43056em; vertical-align: 0em;"></span><span class="mord mathnormal">a</span></span></span></span></span></var> <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>b</mi></mrow><annotation encoding="application/x-tex">b</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.69444em; vertical-align: 0em;"></span><span class="mord mathnormal">b</span></span></span></span></span></var> <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>d</mi></mrow><annotation encoding="application/x-tex">d</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.69444em; vertical-align: 0em;"></span><span class="mord mathnormal">d</span></span></span></span></span></var>
</pre>
</section>
</div>

<div class="part">
<section>
<h3>Output</h3><p>Let the new coordinates of the point be <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mo stretchy="false">(</mo><msup><mi>a</mi><mo mathvariant="normal" lspace="0em" rspace="0em">′</mo></msup><mo separator="true">,</mo><msup><mi>b</mi><mo mathvariant="normal" lspace="0em" rspace="0em">′</mo></msup><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">(a', b')</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1.00189em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord"><span class="mord mathnormal">a</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.751892em;"><span class="" style="top: -3.063em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mtight">′</span></span></span></span></span></span></span></span></span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord"><span class="mord mathnormal">b</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.751892em;"><span class="" style="top: -3.063em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mtight">′</span></span></span></span></span></span></span></span></span><span class="mclose">)</span></span></span></span></span></var>. Print <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><msup><mi>a</mi><mo mathvariant="normal" lspace="0em" rspace="0em">′</mo></msup></mrow><annotation encoding="application/x-tex">a'</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.751892em; vertical-align: 0em;"></span><span class="mord"><span class="mord mathnormal">a</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.751892em;"><span class="" style="top: -3.063em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mtight">′</span></span></span></span></span></span></span></span></span></span></span></span></span></var> and <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><msup><mi>b</mi><mo mathvariant="normal" lspace="0em" rspace="0em">′</mo></msup></mrow><annotation encoding="application/x-tex">b'</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.751892em; vertical-align: 0em;"></span><span class="mord"><span class="mord mathnormal">b</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.751892em;"><span class="" style="top: -3.063em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mtight">′</span></span></span></span></span></span></span></span></span></span></span></span></span></var> in this order, with a space in between.<br>
Your output will be considered correct when, for each value printed, the absolute or relative error from the answer is at most <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn><msup><mn>0</mn><mrow><mo>−</mo><mn>6</mn></mrow></msup></mrow><annotation encoding="application/x-tex">10^{-6}</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.814108em; vertical-align: 0em;"></span><span class="mord">1</span><span class="mord"><span class="mord">0</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.814108em;"><span class="" style="top: -3.063em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mtight">−</span><span class="mord mtight">6</span></span></span></span></span></span></span></span></span></span></span></span></span></var>.</p>
</section>
</div>
</div>

<hr>
<div class="part">
<section>
<h3>Sample Input 1 </h3>

```
2 2 180
```

</section>
</div>

<div class="part">
<section>
<h3>Sample Output 1 </h3>

```
-2 -2
```

<p>When <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mo stretchy="false">(</mo><mn>2</mn><mo separator="true">,</mo><mn>2</mn><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">(2, 2)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord">2</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">2</span><span class="mclose">)</span></span></span></span></span></var> is rotated around the origin <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>180</mn></mrow><annotation encoding="application/x-tex">180</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">1</span><span class="mord">8</span><span class="mord">0</span></span></span></span></span></var> degrees counterclockwise, it becomes the symmetric point of <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mo stretchy="false">(</mo><mn>2</mn><mo separator="true">,</mo><mn>2</mn><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">(2, 2)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord">2</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">2</span><span class="mclose">)</span></span></span></span></span></var> with respect to the origin, which is <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mo stretchy="false">(</mo><mo>−</mo><mn>2</mn><mo separator="true">,</mo><mo>−</mo><mn>2</mn><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">(-2, -2)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord">−</span><span class="mord">2</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">−</span><span class="mord">2</span><span class="mclose">)</span></span></span></span></span></var>.</p>
</section>
</div>

<hr>
<div class="part">
<section>
<h3>Sample Input 2 </h3>

```
5 0 120
```


</section>
</div>

<div class="part">
<section>
<h3>Sample Output 2 </h3>

```
-2.49999999999999911182 4.33012701892219364908
```

<p>When <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mo stretchy="false">(</mo><mn>5</mn><mo separator="true">,</mo><mn>0</mn><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">(5, 0)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord">5</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">0</span><span class="mclose">)</span></span></span></span></span></var> is rotated around the origin <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>120</mn></mrow><annotation encoding="application/x-tex">120</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">1</span><span class="mord">2</span><span class="mord">0</span></span></span></span></span></var> degrees counterclockwise, it becomes <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mo stretchy="false">(</mo><mo>−</mo><mfrac><mn>5</mn><mn>2</mn></mfrac><mo separator="true">,</mo><mfrac><mrow><mn>5</mn><msqrt><mn>3</mn></msqrt></mrow><mn>2</mn></mfrac><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">(-\frac {5}{2} , \frac {5\sqrt{3}}{2})</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1.383em; vertical-align: -0.345em;"></span><span class="mopen">(</span><span class="mord">−</span><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.845108em;"><span class="" style="top: -2.655em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mtight">2</span></span></span></span><span class="" style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line" style="border-bottom-width: 0.04em;"></span></span><span class="" style="top: -3.394em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mtight">5</span></span></span></span></span><span class="vlist-s">&ZeroWidthSpace;</span></span><span class="vlist-r"><span class="vlist" style="height: 0.345em;"><span class=""></span></span></span></span></span><span class="mclose nulldelimiter"></span></span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 1.038em;"><span class="" style="top: -2.655em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mtight">2</span></span></span></span><span class="" style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line" style="border-bottom-width: 0.04em;"></span></span><span class="" style="top: -3.39901em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mtight">5</span><span class="mord sqrt mtight"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.912845em;"><span class="svg-align" style="top: -3em;"><span class="pstrut" style="height: 3em;"></span><span class="mord mtight" style="padding-left: 0.833em;"><span class="mord mtight">3</span></span></span><span class="" style="top: -2.87284em;"><span class="pstrut" style="height: 3em;"></span><span class="hide-tail mtight" style="min-width: 0.853em; height: 1.08em;"><svg width="400em" height="1.08em" viewBox="0 0 400000 1080" preserveAspectRatio="xMinYMin slice"><path d="M95,702
c-2.7,0,-7.17,-2.7,-13.5,-8c-5.8,-5.3,-9.5,-10,-9.5,-14
c0,-2,0.3,-3.3,1,-4c1.3,-2.7,23.83,-20.7,67.5,-54
c44.2,-33.3,65.8,-50.3,66.5,-51c1.3,-1.3,3,-2,5,-2c4.7,0,8.7,3.3,12,10
s173,378,173,378c0.7,0,35.3,-71,104,-213c68.7,-142,137.5,-285,206.5,-429
c69,-144,104.5,-217.7,106.5,-221
l0 -0
c5.3,-9.3,12,-14,20,-14
H400000v40H845.2724
s-225.272,467,-225.272,467s-235,486,-235,486c-2.7,4.7,-9,7,-19,7
c-6,0,-10,-1,-12,-3s-194,-422,-194,-422s-65,47,-65,47z
M834 80h400000v40h-400000z"></path></svg></span></span></span><span class="vlist-s">&ZeroWidthSpace;</span></span><span class="vlist-r"><span class="vlist" style="height: 0.127155em;"><span class=""></span></span></span></span></span></span></span></span></span><span class="vlist-s">&ZeroWidthSpace;</span></span><span class="vlist-r"><span class="vlist" style="height: 0.345em;"><span class=""></span></span></span></span></span><span class="mclose nulldelimiter"></span></span><span class="mclose">)</span></span></span></span></span></var>.<br>
This sample output does not precisely match these values, but the errors are small enough to be considered correct.</p>
</section>
</div>

<hr>
<div class="part">
<section>
<h3>Sample Input 3 </h3>

```
0 0 11
```

</section>
</div>

<div class="part">
<section>
<h3>Sample Output 3 </h3>

```
0.00000000000000000000 0.00000000000000000000
```

<p>Since <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mo stretchy="false">(</mo><mi>a</mi><mo separator="true">,</mo><mi>b</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">(a, b)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord mathnormal">a</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord mathnormal">b</span><span class="mclose">)</span></span></span></span></span></var> is the origin (the center of rotation), a rotation does not change its coordinates.</p>
</section>
</div>

<hr>
<div class="part">
<section>
<h3>Sample Input 4 </h3>

```
15 5 360
```

</section>
</div>

<div class="part">
<section>
<h3>Sample Output 4 </h3>

```
15.00000000000000177636 4.99999999999999555911
```

<p>A <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>360</mn></mrow><annotation encoding="application/x-tex">360</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">3</span><span class="mord">6</span><span class="mord">0</span></span></span></span></span></var>-degree rotation does not change the coordinates of a point.</p>
</section>
</div>

<hr>
<div class="part">
<section>
<h3>Sample Input 5</h3>

```
-505 191 278
```

</section>
</div>

<div class="part">
<section>
<h3>Sample Output 5 </h3>

```
118.85878514480690171240 526.66743699786547949770
```

</section>
</div>
</span>


# 题目大意

$x$轴正向朝右，$y$轴正向朝上的二维坐标平面上有一点的坐标为$(a, b)$

求 将这个点绕坐标原点逆时针旋转$d$°后 的坐标


# 解题思路

C++内置了$\sin、\cos、\arctan$等函数，但这些函数都是以弧度制为基础的。

先计将直角坐标转换为极坐标，然后把角度加上$d$，再转换为直角坐标即可。


---



# AC代码

## 赛时：较为复杂

后面会有简化及技巧

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

const double PI = acos(-1);

int main() {
    double a, b;
    cin >> a >> b;
    double l = sqrt(a * a + b * b);
    if (l < 1e-8) {
        puts("0 0");
        return 0;
    }
    double alpha;
    if (a == 0) {
        if (b > 0)
            alpha = PI / 2;
        else
            alpha = PI / 2 * 3;
    }
    alpha = atan(b / a);
    if (a < 0)
        alpha += PI;
    double d;
    cin >> d;
    double belta = alpha + d / 180 * PI;
    belta += 4 * PI;
    while (belta > 2 * PI)
        belta -= 2 * PI;
    double x = l * cos(belta);
    double y = l * sin(belta);
    printf("%.9lf %.9lf\n", x, y);
    return 0;
}
```

## 简化及技巧

### 用 hypot(a, b) 代替 sqrt(a * a + b * b)

```cpp
double l = sqrt(a * a + b * b);
```

👇

```cpp
double l = hypot(a, b);
```

### 直接用atan2求出四个象限下的角度

```cpp
double alpha;
if (a == 0) {
    if (b > 0)
        alpha = PI / 2;
    else
        alpha = PI / 2 * 3;
}
alpha = atan(b / a);
if (a < 0)
    alpha += PI;
```

👇

```cpp
double alpha = atan2(b, a);
```

### 取消掉映射到[0, 2π)

```cpp
belta += 4 * PI;
while (belta > 2 * PI)
    belta -= 2 * PI;
```

👇

```cpp

```

### 最终代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

const double PI = acos(-1);

int main() {
    double a, b;
    cin >> a >> b;
    double l = hypot(a, b);  // 代替sqrt(a * a + b * b);
    double alpha = atan2(b, a);  // 非常方便地求角
    double d;
    cin >> d;
    double belta = alpha + d / 180 * PI;
    double x = l * cos(belta);
    double y = l * sin(belta);
    printf("%.9lf %.9lf\n", x, y);  // 也可以：cout<<fixed<<setprecision(9)<<x<<' '<<y<<endl;
    return 0;
}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/09/AtCoder%20Beginner%20Contest%20259%20-%20B%20-%20Counterclockwise%20Rotation/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125699603](https://letmefly.blog.csdn.net/article/details/125699603)