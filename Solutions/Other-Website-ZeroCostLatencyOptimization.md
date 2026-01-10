---
title: 网站访问耗时优化 - 从数十秒到几百毫秒的“零成本”优化过程 - 阿里云子域GeoDNS国内外分流
title_en: "Website Latency Optimization: A Zero-Cost Journey from Tens of Seconds to Hundreds of Milliseconds"
date: 2026-01-10 09:53:54
tags: [其他, Website, 建站, 服务器, Linux, Nginx, DNS, Cloudflare]
categories: [技术思考]
---

# 网站访问耗时优化 - 从数十秒到几百毫秒的“零成本”优化过程 - 阿里云子域GeoDNS国内外分流

> * Website Latency Optimization: A Zero-Cost Journey from Tens of Seconds to Hundreds of Milliseconds
> * From 30 Seconds to 300 Milliseconds: Zero-Cost Website Performance Optimization

## 背景

之前为了保护我那台孱弱的小服务器的真实ip免受攻击，我将服务器的所有HTTP(s)服务限制为仅能通过域名访问，且把域名托管在了**Cloudflare**上开启了代理小云朵。

就这样几年过去了，越来越觉得网站访问是真的慢（不管有没有特殊网络都很慢）。并且有👇，所以决定优化一手。

> [CloudFlare: 网站性能如何影响转化率](https://www.cloudflare.com/learning/performance/more/website-performance-conversion-rates/)
>
> 沃尔玛发现，页面加载时间每减少 1 秒，转化数就会增加 2％...

**最终，从每次访问“快则好几秒平均十来秒慢则好几十秒”到“粗略统计全球访问平均几百毫秒”的性能优化，并且几乎没有修改代码。**（理想状态平均几十毫秒）

## 耗时原因分析

众所周知，正常情况下锅内外的网络传输都要不可避免地经过TheGreatWall，来保障国民的网络信息安全。

为什么CDN服务器遍布全球的赛博菩萨Cloudflare在锅内会变成减速CDN呢？大概率是经过了上面的它↑。

为了实锤一下，在服务器上执行命令

```bash
for i in {1..20}; do curl -o /dev/null -s -w "%{time_connect} %{time_starttransfer} %{time_total}\n" https://nextcloud.letmefly.xyz; done
```

得到结果20次请求的连接耗时、首字节返回耗时、总耗时：

```
0.726453 4.388203 4.388237
1.346249 7.263477 7.263509
2.228933 10.111719 10.111752
2.660601 9.483325 9.483393
1.028620 3.424524 3.424555
0.795678 3.197058 3.197130
1.114911 3.688075 3.688237
0.697664 5.477339 5.477411
0.821841 26.322082 26.322112
0.916166 3.698248 3.698305
1.404712 4.999771 4.999802
0.772932 3.323453 3.323484
2.204168 5.768386 5.768476
1.264734 3.941814 3.941846
0.788361 6.344063 6.344097
3.425116 0.000000 72.185861
2.303902 9.694897 9.695196
0.919144 6.506560 6.506636
0.778423 4.272682 4.272722
0.527677 8.258768 8.258819
```

第二列和第三列几乎相同，说明服务端数据处理非常迅速，耗时几乎为0，而整个网络开销几乎均耗时在网络传输上（服务器--cloudflare--服务器），然后就有了第三列这灾难级别的耗时。

## Geo-DNS分流

既然知道了网络开销的巨大头主要来自HTTP的跨境行为，所以让国内用户访问我的国内服务器，国外用户访问国外Github Pages（纯静态页面）不就好了么，具体访问的哪个IP对用户是无感的，且一个域名就能实现。

由于主域名[`letmefly.xyz`](https://letmefly.xyz)托管在cloudflare上且仍有其用，而cloudflare的GeoDNS成本大约每个月几十美元(未详细统计确认)，比小服务器贵很多，所以决定将`blog.letmefly.xyz`子域托管到免费的阿里云DNS服务上。（腾讯云DNS也有类似免费服务，但由于该域名购买自阿里云，所以选择了托管在阿里云上）

### blog.letmefly.xyz子域托管

在cloudflare控制面板修改[blog.letmefly.xyz](https://blog.letmefly.xyz)的DNS记录为`NS`，值为`ns1.alidns.com`，再新建一个`NS`值为`ns2.alidns.com`。

在阿里云DNS解析控制台添加域名`blog.letmefly.xyz`，进行TXT校验（在cloudflare添加`alidnscheck.letmefly.xyz`的`TXT`类型的记录）。

添加记录：

| 主机记录 | 记录类型 | 解析请求来源 | 记录值          |
| -------- | -------- | ------------ | --------------- |
| @        | AAAA     | 境外         | 2606:50c:0:8003::153 |
| @        | AAAA     | 境外         | 2606:50c:0:8002::153 |
| @        | AAAA     | 境外         | 2606:50c:0:8001::153 |
| @        | AAAA     | 境外         | 2606:50c:0:8000::153 |
| @        | A        | 境外         | 185.199.111.153 |
| @        | A        | 境外         | 185.199.110.153 |
| @        | A        | 境外         | 185.199.109.153 |
| @        | A        | 境外         | 185.199.108.153 |
| @        | A        | 中国地区     | 39.105.42.186   |

前面8个是Github（[官方文档](https://docs.github.com/zh/pages/configuring-a-custom-domain-for-your-github-pages-site/managing-a-custom-domain-for-your-github-pages-site)），最后一个是我的服务器。

是的，就这么简单，完事了！

## 服务器拉取Github脚本

服务器上设计为：启动一个webhook listener，当github仓库website分支更新时向服务器发送通知，服务器拉取最新源码，并原子化链接整个目录到nginx配置的目录。

```go
/*
 * @LastEditTime: 2026-01-08 18:54:37
 */
package main

import (
    "crypto/hmac"
    "crypto/rand"
    "crypto/sha256"
    "encoding/hex"
    "encoding/json"
    "io"
    "log"
    "math/big"
    "net/http"
    "os"
    "os/exec"
    "path/filepath"
    "regexp"
    "strings"
    "time"
)

const (
    listenAddr = "127.0.0.1:1209"
    secretFile = ".secret"
)

type RepoConfig struct {
    BaseDir   string
    RepoURL   string
    TargetRef string
    Branch    string
}

var repos = map[string]RepoConfig{
    "/hook/github/leetcode": {
        BaseDir:   "/www/blog",
        RepoURL:   "git@github.com:LetMeFly666/LeetCode.git",
        TargetRef: "refs/heads/website",
        Branch:    "website",
    },
    "/hook/github/various": {
        BaseDir:   "/www/various",
        RepoURL:   "git@github.com:LetMeFly666/various.git",
        TargetRef: "refs/heads/master",
        Branch:    "master",
    },
}

type PushEvent struct {
    Ref string `json:"ref"`
}

var secret []byte

func loadSecret() {
    data, err := os.ReadFile(secretFile)
    if err != nil {
        log.Fatal("read secret failed:", err)
    }
    secret = []byte(strings.TrimSpace(string(data)))
}

func verifySignature(body []byte, signature string) bool {
    mac := hmac.New(sha256.New, secret)
    mac.Write(body)
    expected := "sha256=" + hex.EncodeToString(mac.Sum(nil))
    return hmac.Equal([]byte(signature), []byte(expected))
}

func handler(cfg RepoConfig) http.HandlerFunc {
    return func(w http.ResponseWriter, r *http.Request) {
        body, _ := io.ReadAll(r.Body)

        sig := r.Header.Get("X-Hub-Signature-256")
        if !verifySignature(body, sig) {
            http.Error(w, "invalid signature", http.StatusForbidden)
            return
        }

        var event PushEvent
        if err := json.Unmarshal(body, &event); err != nil {
            http.Error(w, "bad payload", http.StatusBadRequest)
            return
        }

        if event.Ref != cfg.TargetRef {
            w.Write([]byte("ignored\n"))
            return
        }

        w.Write([]byte("accepted\n"))

        go deployWebsite(cfg)
    }
}

func randomSuffix() string {
    n, _ := rand.Int(rand.Reader, big.NewInt(1_000_000))
    return n.String()
}

func deployWebsite(cfg RepoConfig) {
    ts := time.Now().Format("20060102_150405")
    newDir := filepath.Join(cfg.BaseDir, "website_"+ts+"_"+randomSuffix())
    currentLink := filepath.Join(cfg.BaseDir, "website")

    if err := os.MkdirAll(newDir, 0755); err != nil {
        log.Println("mkdir failed:", err)
        return
    }

    cmd := exec.Command(
        "git", "clone",
        "-b", cfg.Branch,
        "--depth=1",
        cfg.RepoURL,
        newDir,
    )
    if out, err := cmd.CombinedOutput(); err != nil {
        log.Println("git clone failed:", string(out))
        return
    }

    cmd = exec.Command("ln", "-sfn", newDir, currentLink)
    if out, err := cmd.CombinedOutput(); err != nil {
        log.Println("ln -sfn failed:", string(out))
        return
    }

    cleanupOldReleases(cfg.BaseDir, newDir)

    log.Println("deploy success:", newDir)
}

var releaseRegexp = regexp.MustCompile(`^website_\d{8}_\d{6}_\d+$`)

func cleanupOldReleases(baseDir, keepDir string) {
    entries, err := os.ReadDir(baseDir)
    if err != nil {
        return
    }

    for _, e := range entries {
        if !e.IsDir() {
            continue
        }
        name := e.Name()
        if !releaseRegexp.MatchString(name) {
            continue
        }
        full := filepath.Join(baseDir, name)
        if full == keepDir {
            continue
        }
        _ = os.RemoveAll(full)
    }
}

func main() {
    loadSecret()

    for path, cfg := range repos {
        http.HandleFunc(path, handler(cfg))
    }

    log.Println("listening on", listenAddr)
    log.Fatal(http.ListenAndServe(listenAddr, nil))
}
```

在github对应仓库--settings--webhook--新增--输入密钥（随机字符串，可由`openssl rand -hex 32`命令生成）--类型选择json--不需要额外数据。

本地在程序执行目录创建一个`.secret`文件并写入生成的密钥，后台运行该监听脚本即可。（上面方法俺设计的，嘻嘻）

## 结果

### 国内

在服务器上执行`for i in {1..20}; do curl -o /dev/null -s -w "%{time_connect} %{time_starttransfer} %{time_total}\n" https://nextcloud.letmefly.xyz; done`，结果：

```
0.007227 0.079349 0.079377
0.005464 0.081657 0.081687
0.005054 0.074545 0.074576
0.456098 0.524839 0.524884
0.469940 0.541030 0.541060
0.006224 0.081239 0.081265
0.005814 0.080448 0.080479
0.006077 0.077889 0.077928
0.005238 0.079339 0.079365
0.004949 0.076759 0.076791
0.005104 0.079881 0.079907
0.005950 0.082108 0.082139
0.006417 0.082243 0.082295
0.005584 0.081760 0.081788
0.455143 0.551400 0.551427
0.005367 0.084855 0.084886
0.455233 0.535178 0.535216
0.005935 0.084052 0.084079
0.004623 0.101036 0.101117
0.005021 0.082109 0.082138
```

这个应该是直接走Localhost了?。

强制走公网：

```bash
for i in {1..20}; do curl -o /dev/null -s --resolve nextcloud.letmefly.xyz:443:39.105.42.186 -w "%{time_connect} %{time_starttransfer} %{time_total}\n" https://nextcloud.letmefly.xyz; done
tcpdump -i eth0 host 39.105.42.186 and port 443
```

并另外启动一个窗口抓包：

```bash
tcpdump -i eth0 host 39.105.42.186 and port 443
```

可以看到：

```bash
tisfy.https → 39.105.42.186.38608
39.105.42.186.38608 → tisfy.https
```

说明走了公网。

诶，还是很快。

直接使用一台手中的设备测试，不在服务器上测试了

```
0.030351 0.122197 0.122252
0.012166 0.094488 0.094556
0.013372 0.118933 0.119127
0.015152 0.121100 0.121195
0.012782 0.093575 0.093694
0.011981 0.090665 0.090767
0.012699 0.092128 0.092318
0.014691 0.167777 0.167850
0.013061 0.207214 0.207498
0.013980 0.273402 0.273721
0.014736 0.186312 0.186655
0.015405 0.170255 0.170587
0.075688 0.263535 0.263765
0.014979 0.154608 0.154884
0.014043 0.276435 0.276624
0.014873 0.180383 0.180700
0.014767 0.260764 0.260981
0.015220 0.166855 0.167178
0.013348 0.176619 0.176928
0.014471 0.171316 0.171636
```

这下没办法了，走的wifi连的服务器，还是很快。

### 国外

由于没有在国外的设备，所以临时写了个github action测下

```yml
name: Test blog.letmefly.xyz latency - 境外访问延迟测试

on:
   workflow_dispatch:

jobs:
  latency-test:
    runs-on: ubuntu-latest

    steps:
      - name: Print debug info
        run: |
          echo "==== Debug Info ===="
          echo "Runner hostname: $(hostname)"
          echo "GitHub runner public IP:"
          curl -s https://ifconfig.me || echo "Failed to get public IP"
          echo "==================="

      - name: Resolve target IP
        id: resolve
        run: |
          TARGET=blog.letmefly.xyz
          IP=$(dig +short $TARGET | head -n1)
          echo "Target: $TARGET"
          echo "Resolved IP: $IP"
          echo "IP=$IP" >> $GITHUB_OUTPUT

      - name: Test latency 20 times
        run: |
          TARGET=blog.letmefly.xyz
          IP=${{ steps.resolve.outputs.IP }}
          echo "time_connect time_starttransfer time_total"
          
          # 初始化累加器
          sum_connect=0
          sum_starttransfer=0
          sum_total=0
          
          for i in {1..20}; do
            # 取三个时间
            read connect starttransfer total <<< $(curl -o /dev/null -s \
                 --resolve $TARGET:443:$IP \
                 -w "%{time_connect} %{time_starttransfer} %{time_total}" \
                 https://$TARGET)
                 
            # 累加
            sum_connect=$(echo "$sum_connect + $connect" | bc)
            sum_starttransfer=$(echo "$sum_starttransfer + $starttransfer" | bc)
            sum_total=$(echo "$sum_total + $total" | bc)
            
            # 输出
            echo "$connect $starttransfer $total"
          done
          
          # 计算平均
          avg_connect=$(echo "scale=4; $sum_connect/20" | bc)
          avg_starttransfer=$(echo "scale=4; $sum_starttransfer/20" | bc)
          avg_total=$(echo "scale=4; $sum_total/20" | bc)
          
          echo "AVERAGE $avg_connect $avg_starttransfer $avg_total"
```

Github上测Github Pages似乎有点小作弊(bushi)，但没办法了。

```
Runner hostname: runnervmi13qx
GitHub runner public IP:
172.212.165.69

Target: blog.letmefly.xyz
Resolved IP: 185.199.110.153

time_connect time_starttransfer time_total
0.013474 0.096664 0.101290
0.011528 0.091032 0.095257
0.012259 0.053301 0.058006
0.011481 0.049095 0.053492
0.009328 0.046950 0.050534
0.008894 0.042994 0.047134
0.013758 0.056136 0.061113
0.011655 0.059527 0.063557
0.014356 0.054987 0.060360
0.011576 0.049023 0.053552
0.011710 0.049211 0.053547
0.011660 0.048587 0.052985
0.011670 0.057137 0.061753
0.008896 0.045748 0.049883
0.014311 0.053899 0.059477
0.013615 0.053529 0.059438
0.011551 0.049421 0.053476
0.013896 0.060151 0.065085
0.014129 0.090222 0.095611
0.013318 0.052731 0.057438
AVERAGE .0121 .0580 .0626
```

### 国内外

也可以在[itdog](blog.letmefly.xyz)上测试国内外访问，网络质量及其不确定因素会增多，耗时结果稍高。

但HTTP请求只要不经过墙墙，平均还是比较快的。

国内外访问良民网站的DNS服务，也很快（并且还有缓存）；国外访问Github(Anycast)本来就很快。

## End

What's more：

> 这次估计触发了关键词，在CSDN上发布时不是先发后审了。

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156789088)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/10/Other-Website-ZeroCostLatencyOptimization/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)