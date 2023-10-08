---
title: Docker学习笔记 - 极简极入门级
date: 2023-10-07 10:05:23
tags: [Docker, 简单, Notes]
---

# Docker学习笔记 - 极简极入门级

## 前言

Docker主打一个“极小成本”的虚拟环境的一键部署，使用少量的系统资源占用实现项目在不同宿主机上的无缝迁移。

## 架构

下面两图来自[Bilibili@BV1HP4118797](https://www.bilibili.com/video/BV1HP4118797)

![Docker架构](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/60089d8e00474d35bc1ff9a901d800dc.png)

![Docker命令图](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/d664febdce444dbbae1a0a08d142f023.png)

## 命令

|命令|说明|文档地址|
|:--:|:--:|:--:|
|[docker pull](#docker-pull)|拉取镜像|[pull](https://docs.docker.com/engine/reference/commandline/pull/)|
|[docker push](#docker-push)|推送镜像到DockerRegistry|[push](https://docs.docker.com/engine/reference/commandline/push/)|
|[docker images](#docker-images)|查看本地镜像|[images](https://docs.docker.com/engine/reference/commandline/images/)|
|[docker rmi](#docker-rmi)|删除本地镜像|[rmi](https://docs.docker.com/engine/reference/commandline/rmi/)|
|[docker run](#docker-run)|创建并运行容器（不能重复创建）|[run](https://docs.docker.com/engine/reference/commandline/run/)|
|[docker stop](#docker-stopstartrestart)|停止指定容器|[stop](https://docs.docker.com/engine/reference/commandline/stop/)|
|[docker start](#docker-stopstartrestart)|启动指定容器|[start](https://docs.docker.com/engine/reference/commandline/start/)|
|[docker restart](#docker-stopstartrestart)|重新启动容器|[restart](https://docs.docker.com/engine/reference/commandline/restart/)|
|[docker rm](#docker-rm)|删除指定容器|[rm](https://docs.docker.com/engine/reference/commandline/rm/)|
|[docker ps](#docker-ps)|查看容器|[ps](https://docs.docker.com/engine/reference/commandline/ps/)|
|[docker exec](#docker-exec)|进入容器（执行指令）|[exec](https://docs.docker.com/engine/reference/commandline/exec/)|
|[docker logs](#docker-logs)|查看容器运行日志|[logs](https://docs.docker.com/engine/reference/commandline/logs/)|
|[docker save](#docker-saveload)|保存镜像到本地压缩文件|[save](https://docs.docker.com/engine/reference/commandline/save/)|
|[docker load](#docker-saveload)|加载本地压缩文件到镜像|[load](https://docs.docker.com/engine/reference/commandline/load/)|
|[docker inspect](#docker-inspect)|查看容器详细信息|[inspect](https://docs.docker.com/engine/reference/commandline/inspect/)|
|[docker build](#docker-build)|打包镜像（通过Dockerfile）|[build](https://docs.docker.com/engine/reference/builder/)|
|[docker network](#docker-network)|网络|[network](https://docs.docker.com/engine/reference/commandline/network/)|
|[docker volume](#docker-volume)|数据卷|volume [create](https://docs.docker.com/engine/reference/commandline/volume_create/)/[inspect](https://docs.docker.com/engine/reference/commandline/volume_inspect/)/[ls](https://docs.docker.com/engine/reference/commandline/volume_ls/)/[prune](https://docs.docker.com/engine/reference/commandline/volume_prune/)/[rm](https://docs.docker.com/engine/reference/commandline/volume_rm/)/[update](https://docs.docker.com/engine/reference/commandline/volume_update/)|
|[docker compose](#docker-compose)|关联容器的快速部署（可通过docker-compose.yml）|[compose](https://docs.docker.com/compose/compose-file/compose-file-v3/)|


可以在几乎任何时候使用```--help```来查看帮助。例如```docker --help```、```docker pull --help```

### docker pull

拉取镜像。

```bash
docker pull [OPTIONS] NAME[:TAG|@DIGEST]
```

OPTIONS说明：

+ -a :拉取所有 tagged 镜像
+ --disable-content-trust :忽略镜像的校验,默认开启

实例（以nginx为例）：

```bash
docker pull nginx
```

这样的话docker会默认拉取最新(latest)的nginx镜像到本地。

其实不拉取镜像也可以，在```docker run```时若还未拉取过镜像，则docker会自动拉取。

### docker push

将本地的镜像上传到镜像仓库,要先登陆到镜像仓库。

```bash
docker push [OPTIONS] NAME[:TAG]
```

OPTIONS说明：

+ --disable-content-trust :忽略镜像的校验,默认开启

实例：

```bash
docker push mynginx
```

### docker images

列出本地镜像。执行过```docker pull```或```docker run```后镜像可能会被保存。

```bash
docker images [OPTIONS] [REPOSITORY[:TAG]]
```

OPTIONS说明：

+ -a :列出本地所有的镜像（含中间映像层，默认情况下，过滤掉中间映像层）

实例：

```bash
docker images
```

```bash
docker images ubuntu
```

将会得到本地所有版本的ubuntu镜像。

### docker rmi

删除本地一个或多个镜像。

```bash
docker rmi [OPTIONS] IMAGE [IMAGE...]
```

OPTIONS说明：

+ -f :强制删除

实例：

```bash
docker rmi -f nginx
```

有容器正在使用nginx镜像，但还是会被强制删除。

### docker run

创建一个新的容器并运行一个命令。若镜像不存在则会自动拉取(pull)镜像。

```bash
docker run [OPTIONS] IMAGE [COMMAND] [ARG...]
```

OPTIONS说明：

+ -a stdin: 指定标准输入输出内容类型，可选 STDIN/STDOUT/STDERR 三项
+ -d: 后台运行容器，并返回容器ID
+ -i: 以交互模式运行容器，通常与 -t 同时使用
+ -P: 随机端口映射，容器内部端口随机映射到主机的端
+ -p: 指定端口映射，格式为：主机(宿主)端口:容器端
+ -t: 为容器重新分配一个伪输入终端，通常与 -i 同时使用
+ &ndash;&ndash;name="nginx-lb": 为容器指定一个名称
+ &ndash;&ndash;dns 8.8.8.8: 指定容器使用的DNS服务器，默认和宿主一致
+ &ndash;&ndash;dns-search example.com: 指定容器DNS搜索域名，默认和宿主一致
+ -h "mars": 指定容器的hostname
+ -e username="ritchie": 设置环境变量
+ &ndash;&ndash;env-file=[]: 从指定文件读入环境变量
+ &ndash;&ndash;cpuset="0-2" or &ndash;&ndash;cpuset="0,1,2": 绑定容器到指定CPU运行
+ -m :设置容器使用内存最大值
+ &ndash;&ndash;net="bridge": 指定容器的网络连接类型，支持 bridge/host/none/container: 四种类型。详情请见[docker network](#docker-network)
+ &ndash;&ndash;link=[]: 添加链接到另一个容器
+ &ndash;&ndash;expose=[]: 开放一个端口或一组端口
+ &ndash;&ndash;volume , -v: 绑定一个卷，格式为：宿主机路径或卷名:容器中对应的路径。详情请见[docker volume](#docker-volume)

一般都会加上参数```-d```，否则容器会在当前终端运行，一旦```Ctrl + C```容器就停止运行了。

对于卷绑定```-v```：

+ 只能创建容器时绑定，后续无法新增或修改
+ 一旦进行了绑定，则```容器中对应的路径```会被强制修改为```被绑定的卷 或 路径```。例如我绑定了宿主机的一个**空**的文件夹到容器的```/usr/share/nginx/html```下，则容器将会存在```/usr/share/nginx/html```这个路径，且其中的内容为空。若宿主机对应目录中本来有文件，则容器中将同样存在对应文件。
+ 若绑定宿主机的卷名，直接输入卷名即可。若绑定宿主机的路径，则需以```/```或```./```开头（Windows系统中```F:\forDocker\nginx1```应写为```/F/forDocker/nginx1```。

实例<span id='createMyNginx'></span>：

```bash
mkdir C:\Users\LetMeFly\Desktop\docker\nginx1\html
echo 666 > C:\Users\LetMeFly\Desktop\docker\nginx1\html\index.html
docker run -d --name=myNginx -p80:80 -v/C/Users/LetMeFly/Desktop/docker/nginx1/html:/usr/share/nginx/html nginx
```

则是创建了一个名为```myNginx```的以```nginx```为镜像的容器，将主机的80端口映射到了容器的80端口，将主机的```C:\Users\LetMeFly\Desktop\docker\nginx1\html```目录映射到了容器的```/usr/share/nginx/html```目录，并在后台运行。

在浏览器中访问[localhost](http://localhost/)可以看到```666```。

<span id='createdMysql1'></span>

```bash
docker run -d --name mysql1 -p 3306:3306 -e MYSQL_ROOT_PASSWORD=123 mysql
```

创建了一个mysql容器，端口映射3306到3306，通过环境变量```MYSQL_ROOT_PASSWORD=123```配置了mysql用户root的初始密码为123。

之后可以使用[docker exec命令](#docker-exec)进入容器配置数据库。

### docker stop/start/restart

docker stop：停止一个运行中的容器

docker start：启动一个或多个已经被停止的容器

docker restart：重启容器

```bash
docker stop [OPTIONS] CONTAINER [CONTAINER...]
docker start [OPTIONS] CONTAINER [CONTAINER...]
docker restart [OPTIONS] CONTAINER [CONTAINER...]
```

实例：

```bash
docker stop myNginx
```

### docker rm

删除一个或多个容器。

```bash
docker rm [OPTIONS] CONTAINER [CONTAINER...]
```

OPTIONS说明：

+ -f :强制删除一个(运行中的)容器
+ -l :移除容器间的网络连接，而非容器本身
+ -v :删除与容器关联的卷

实例：

```bash
docker rm -f nginx1 nginx2
```

### docker ps

列出容器。

```bash
docker ps [OPTIONS]
```

OPTIONS说明：

+ -a/&ndash;&ndash;all :显示所有的容器，包括未运行的
+ &ndash;&ndash;format :指定返回值的模板文件

实例：

```bash
docker ps
```

只列出运行中的容器。

```bash
docker ps -a
```

列出所有容器。

```bash
docker ps -a --format "table {{.ID}}\t{{.Image}}\t{{.Ports}}\t{{.Status}}\t{{.Names}}"
```

列出所有容器，以表格 容器ID、镜像名、端口、运行状态、容器名 的形式展示。

运行结果：

```
CONTAINER ID   IMAGE     PORTS                                                  STATUS                     NAMES
f77aedf96ccf   mysql     0.0.0.0:3306->3306/tcp, :::3306->3306/tcp, 33060/tcp   Up 3 hours                 mysql1
7419372ed7d7   nginx                                                            Exited (137) 3 hours ago   myNginx
```

### docker exec

在运行的容器中执行命令。

```bash
docker exec [OPTIONS] CONTAINER COMMAND [ARG...]
```

OPTIONS说明：

+ -d :分离模式: 在后台运行
+ -i :即使没有附加也保持STDIN 打开
+ -t :分配一个伪终端

实例：

```bash
docker exec -it mysql1 bash
```

这样就进入到了[刚刚创建的mysql容器](#createdMysql1)了，并且运行了一个可交换的```bash```终端。

接着使用命令```mysql -u root -p```，输入密码```123```并回车，就连接上mysql了。

因为做了3306端口的映射，所以在宿主机上执行```mysql -u root -p```的话也能连接上容器中的mysql。

### docker logs

获取容器的日志。

```bash
docker logs [OPTIONS] CONTAINER
```

OPTIONS说明：

+ -f : 跟踪日志输出
+ &ndash;&ndash;since :显示某个开始时间的所有日志
+ -t : 显示时间戳
+ &ndash;&ndash;tail :仅列出最新N条容器日志

实例：

```bash
docker logs -f myNginx
```

持续查看myNginx的输出。

```bash
docker logs --since="2023-10-07" --tail=10 myNginx
```

查看myNginx从2023.10.7后的最新10条输出。

### docker save/load

docker save：将指定镜像保存成```tar```归档文件。

docker load：导入使用```docker save```命令导出的镜像。

```bash
docker save [OPTIONS] IMAGE [IMAGE...]
docker load [OPTIONS]
```

实例：

```bash
docker save -o nginx.tar nginx
```

上述```-o```指输出到的文件名，这个选项是必须的。命令含义是“将镜像nginx保存成nginx.tar”。执行完后，在当前目录下可看到多出来了一个```nginx.tar```。

将保存的nginx.tar发送给别人，别人就可以使用一下命令来加载了：

```bash
docker load -i nginx.tar
```

或

```bash
docker load < nginx.tar
```

其中默认是从STDIN载入，```-i/--input```是从指定文件载入。

### docker inspect

获取容器/镜像的详细信息。

```bash
docker inspect [OPTIONS] NAME|ID [NAME|ID...]
```

OPTIONS说明：

+ -f：指定返回值的模板文件

实例：

```bash
docker inspect nginx  # 查看镜像信息
docker inspect myNginx  # 查看容器信息
docker inspect --format='{{range.NetworkSettings.Networks}}{{.IPAddress}}{{end}}' myNginx  # 查看(运行中)容器的IP
```

### docker build

用来构建镜像。

```bash
docker build [OPTIONS] PATH | URL | -
```

OPTIONS说明：

+ -f：指定要使用的Dockerfile路径（若为当前路径则可以省略）
+ &ndash;&ndash;tag/-t：镜像的名字及标签，通常```name:tag```或者```name```(则默认标签latest)格式；可以在一次构建中为一个镜像设置多个标签

关于```Dockerfile```的编写，常用命令有：

|指令|说明|示例|
|:--:|:--:|:--:|
|FROM|指定基础镜像|```FROM centos:6```|
|ENV|设置环境变量，可在后面指令使用|```ENV key value```|
|COPY|拷贝本地文件到镜像的指定目录|```COPY ./xx.jar /tmp/app.jar```|
|RUN|执行Linux的shell命令，一般是安装过程的命令|```RUN yum install gcc```|
|EXPOSE|指定容器运行时监听的端口，是给镜像使用者看的|```EXPOSE 8080```|
|ENTRYPOINT|镜像中应用的启动命令，容器运行时调用|```ENTRYPOINT java -jar xx.jar```|

实例：

在当前路径下创建一个名为```Dockerfile```的文件并将内容设置为：

```docker
FROM nginx:latest
# 环境变量-设置时区
ENV TZ=Asia/Shanghai
COPY ./html /usr/share/nginx/html
RUN echo Hello from nginx-demo
EXPOSE 80
EXPOSE 443
# 若带有参数可以写成["java", "-jar", "/demo.jar"]
ENTRYPOINT ["nginx"]
```

然后执行以下脚本，新建“html”文件夹，并在文件夹中新增内容为“666”的“index.html”

```bash
mkdir html
echo demo > html/index.html
```

接着执行指令即可构建镜像：

```bash
docker build -t nginx-demo .
```

使用命令```docker images```就能看到刚才构建的```nginx-demo```这个镜像了；使用```docker run -d --name run-nginx-demo -p80:80 nginx-demo```命令运行容器，在浏览器中访问[localhost](http://localhost/)可以看到```demo```了。

### docker network

docker网络。

|命令|说明|文档地址|
|:--:|:--:|:--:|
|docker network create|创建一个网络|[create](https://docs.docker.com/engine/reference/commandline/network_create/)|
|docker network ls|查看所有网络|[ls](https://docs.docker.com/engine/reference/commandline/network_ls/)|
|docker network rm|删除指定网络|[rm](https://docs.docker.com/engine/reference/commandline/network_rm/)|
|docker network prune|清除未使用的网络|[prune](https://docs.docker.com/engine/reference/commandline/network_prune/)|
|docker network connect|使指定容器连接加入某网络|[connect](https://docs.docker.com/engine/reference/commandline/network_connect/)|
|docker network disconnect|使指定容器连接离开某网络|[disconnect](https://docs.docker.com/engine/reference/commandline/network_disconnect/)|
|docker network inspect|查看网络详细信息|[inspect](https://docs.docker.com/engine/reference/commandline/network_inspect/)|

Docker在启动容器时会创建一个虚拟网络，一般为```172.17.0.x```。但是下次再运行这个容器时ip可能就变了。因此多容器的网络互联必须借助docker的网络功能来实现。

容器创建后，后期可以将容器添加到新的网络中。在同一网络中的容器才能互相ping通。也可以在容器创建时指定网络，则容器只会加入指定的网络而不会加入默认的网络。

```bash
# 1. 首先创建一个名为net-demo的网络
docker network create net-demo
# 接着查看网络列表
docker network ls
# 结果：
# NETWORK ID     NAME       DRIVER    SCOPE
# 719ed574ee85   bridge     bridge    local
# 73a470a33af4   host       host      local
# c15ea9caa0d0   net-demo   bridge    local
# bdd1ae507185   none       null      local

# 2. 将容器mysql1和新建的容器nginx2加入网络net-demo，并给容器起别名（可以起多个别名）
docker network connect net-demo mysql1 --alias db
docker run -d --name nginx2 --net=net-demo nginx
# 查看一下网络net-demo中是否纳入了上述两个容器
docker network inspect -f "{{range .Containers}}{{println .Name}}{{end}}" net-demo
# 结果：
# nginx2
# mysql1

# 3. 进入新创建的容器nginx2，用别名db访问容器mysql1
docker exec -it nginx2 bash
# 安装ping命令
apt-get update
apt -y install iputils-ping
# 开始ping
ping db
# 结果：
# PING db (172.18.0.3) 56(84) bytes of data.
# 64 bytes from mysql1.net-demo (172.18.0.3): icmp_seq=1 ttl=64 time=8.11 ms
# 64 bytes from mysql1.net-demo (172.18.0.3): icmp_seq=2 ttl=64 time=0.055 ms
```

OK，现在无需记住IP地址也可以实现容器互联了。

### docker volume

数据卷（volume）是一个虚拟目录，是容器内目录与宿主机目录之间映射的桥梁。

Linux系统下，数据卷的位置为```/var/lib/docker/volumes```，其下具体的数据卷的格式为```/数据卷名/_data```

|命令|说明|文档地址|
|:--:|:--:|:--:|
|docker volume create|创建数据卷|[create](https://docs.docker.com/engine/reference/commandline/volume_create/)|
|docker volume ls|查看所有数据卷|[ls](https://docs.docker.com/engine/reference/commandline/volume_ls/)|
|docker volume rm|删除指定数据卷|[rm](https://docs.docker.com/engine/reference/commandline/volume_rm/)|
|docker volume inspect|查看某个数据卷的详情|[inspect](https://docs.docker.com/engine/reference/commandline/volume_inspect/)|
|docker volume prune|清除数据卷|[prune](https://docs.docker.com/engine/reference/commandline/volume_prune/)|

在[创建MyNginx](#createMyNginx)时已经演示过其中的部分功能了。

### docker compose

```bash
docker compose [OPTIONS] [COMMAND]
```

<table>
<thead><tr><th>类型</th><th>参数或指令</th><th>说明</th></tr></thead>
<tbody>
    <tr><td rowspan='2'>Options</td><td>-f</td><td>指定compose文件的路径和名称</td></tr>
    <tr><td>-p</td><td>指定project名称。project就是当前compose文件中设置的多个service的集合，是逻辑概念</td></tr>
    <tr><td rowspan='9'>Commands</td><td>up</td><td>创建并启动所有service容器</td></tr>
    <tr><td>down</td><td>停止并移除所有容器、网络</td></tr>
    <tr><td>ps</td><td>列出所有启动的容器</td></tr>
    <tr><td>logs</td><td>查看指定容器的日志</td></tr>
    <tr><td>stop</td><td>停止容器</td></tr>
    <tr><td>start</td><td>启动容器</td></tr>
    <tr><td>restart</td><td>重启容器</td></tr>
    <tr><td>top</td><td>查看运行的进程</td></tr>
    <tr><td>exec</td><td>在指定的运行中容器中执行命令</td></tr>
</tbody>
</table>

假设在```/root/demo/```路径下执行的```docker compose up -d```命令，则移除时还应在此目录或其子目录下。（否则直接```docker compose down```的话会“no configuration file provided: not found”。

&nbsp;```docker-compose.yml```的编写 与 ```docker run```命令的对比：

|docker run 参数|docker compose 指令|说明|
|:--:|:--:|:--:|
|&ndash;&ndash;name|container_name|容器名称|
|-p|ports|端口映射|
|-e|environment|环境变量|
|-v|volumes|数据卷配置|
|&ndash;&ndash;network|networks|网络|

实例：

新建一个文件夹并在终端中进入，新建```server.py```文件并写入以下内容：

```python
from flask import Flask
import pymysql

app = Flask('demo')
MYSQL_HOST = 'mysql'
inited = False


def initdb():  # 创建数据表
    conn = pymysql.connect(host=MYSQL_HOST, user='root', passwd='123')
    cursor = conn.cursor()
    cursor.execute('CREATE DATABASE IF NOT EXISTS demo;')
    cursor.execute('USE demo;')
    cursor.execute('CREATE TABLE IF NOT EXISTS times(num INT, times INT);')
    cursor.execute('SELECT * FROM times;')
    if not cursor.fetchone():
        cursor.execute('INSERT INTO times (num, times) VALUES (1, 1)')
        conn.commit()
    cursor.close()
    conn.close()


@app.route('/')
def count():
    global inited
    if not inited:
        try:
            initdb()
            inited = True
        except Exception as e:
            print(e)
    try:
        conn = pymysql.connect(host=MYSQL_HOST, user='root', database='demo', passwd='123')
        cursor = conn.cursor()
        cursor.execute('SELECT * FROM times;')
        now = cursor.fetchone()[1]
        cursor.execute(f'UPDATE times SET times = {now + 1} WHERE num = 1;')
        conn.commit()
        cursor.close()
        conn.close()
        return f'the {now}-th'
    except Exception as e:
        return f'{e}\n请耐心等待至Mysql初始化完成后重试'


if __name__ == '__main__':
    app.run(host='0.0.0.0')
```

新建```Dockerfile```文件并写入以下内容：

```docker
FROM python
LABEL maintainer="LetMeFly"
WORKDIR /root
COPY ./server.py /root/
RUN pip3 install pymysql -i https://mirrors.aliyun.com/pypi/simple
RUN pip3 install flask -i https://mirrors.aliyun.com/pypi/simple
RUN pip3 install cryptography -i https://mirrors.aliyun.com/pypi/simple
ENTRYPOINT ["python3", "server.py"]
EXPOSE 5000
```

新建```docker-compose.yml```文件并写入以下内容：

```yaml
version: "1.0"

services:
  mysql:
    image: mysql
    container_name: mysql1
    ports:
      - "3306:3306"
    environment:
      TZ: Asia/Shanghai
      MYSQL_ROOT_PASSWORD: 123
    networks:
      - flask
  
  python:
    build:
      context: .
    image: flask-img-counttime
    container_name: flask-server
    ports:
      - "80:5000"
    networks:
      - flask
    depends_on:
      - mysql

networks:
  flask:
    name: flask
```

接着在终端中执行命令

```bash
docker compose up -d
```

等待容器构建完成，访问[localhost](http://localhost/)即可看到Flask中的信息。

Mysql容器启动后可能需要很久才能建立连接，因此刚开始访问[localhost](http://localhost/)时，看到的是“connection refused 请耐心等待mysql初始化完成”。

过了可能好几分钟，硬盘占用突然降低，Mysql初始化完成，容器```flask-img-counttime```能够访问到容器```mysql1```，再次访问[localhost](http://localhost/)，可以看到“the 1-th”。刷新后变成了“the 2-th”，再刷新“the 3-th”，......。

这说明我们使用```docker compose```成功实现了关联容器的快速部署。（若想一键清除，可以在当前目录下```docker compose down```）

另附：将docker commands转为docker-compose的[在线网站](https://www.composerize.com/)

## 其他设置

编辑```deamon.json```或者直接在Docker Desktop的settings中修改配置文件即可更改docker的一些设置。

### 镜像加速

阿里云为个人提供了免费的Docker镜像加速服务。位置：[控制台 -> 容器镜像服务 -> 镜像加速器](https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors)。

复制```加速器地址```（xxx.mirror.aliyuncs.com）并在```deamon.json```中新增一项即可：

```json
"registry-mirrors": ["xxx.mirror.aliyuncs.com"]
```

阿里云明确说明只给个人使用，因此不要分享这个私有地址。

## 个人的话

文章到这里可以说是已经结束了。以下是我个人在使用过程中的一些想说的话：

docker环境的底层似乎是Linux系统，因此感觉在Windows上的适配/体验并不算特别好。

在Windows上运行Docker时官方推荐的方法是使用WSL(Windows Subsystem for Linux)，结果就是Docker在安装过程中完全不给选择安装路径，并且默认开机自启xxx。

还有就是docker-windows的内存回收做得不够到位。我的主机是32G内存的，日常使用一般占用20%~30%，但开个Docker再运行个nginx的容器能飙到70%多。

后台运行Docker-Desktop时进程```Vmmem```大约会占据1-2G内存，再运行一个nginx能占据4~6G。总觉得虚拟机的内存占用是不会完全显示在任务管理器中的，常常在运行虚拟机时任务管理器中所有进程的内存占用加起来 要比 真正的内存总占用小（未细算）。

退出Docker-Desktop后```Vmmem```占据的内存并不会被主动释放，使用命令```wsl --shutdown```后可以看到任务管理器中```Vmmem```消失了，但是总的内存占用并没有明显下降。（也就是说日常二十多的内存占用，开启Docker并运行一个容器后，只要不关机，我就没找到让内存占用低于70%的方法）

退出docker并且关闭了wsl后，再次运行Docker，似乎并未使用之前分配的内存，会多出一个1G多的```Vmmem```进程，总内存占用就飙到85%~90%了，其他应用使用起来能感到较为明显的小卡。这可是32G内存的主机欸。```任务管理器 -> 用户```看到```xxx@hotmail.com```的内存总占用是1.7G，而```任务管理器 -> 用户```看到的实际占用是27.4G。

![用户内存占用](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/c0c5ea88673e49c597b81915c3d00bd6.png)

![总占用](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/92f2409eb64e49b686d003c8959304e1.png)

所以，求一个有效的Windows上使用Docker后释放内存的好办法（重启除外）[Doge]

## 参考链接

+ [Bilibili@BV1HP4118797: 黑马程序员Docker快速入门到项目部署](https://www.bilibili.com/video/BV1HP4118797)
+ [飞书文档：day02-Docker（和上述视频配套）](https://b11et3un53m.feishu.cn/wiki/MWQIw4Zvhil0I5ktPHwcoqZdnec)
+ [菜鸟教程：docker 命令大全](https://www.runoob.com/docker/docker-command-manual.html)

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/10/07/Other-Docker-Note/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133633479](https://letmefly.blog.csdn.net/article/details/133633479)