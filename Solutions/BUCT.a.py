'''
Author: LetMeFly
Date: 2023-02-24 11:15:31
LastEditors: LetMeFly
LastEditTime: 2023-03-02 21:02:10
'''

# Copy

MAXBIT=100
MAXVALUE=10000
MAXLEAF=30
MAXNODE=MAXLEAF*2-1
n=int(input("请输入共有多少个字符：n="))
weight=[0.0]*(2*n-1)
parent=[-1]*(2*n-1)
lchild=[-1]*(2*n-1)
rchild=[-1]*(2*n-1)
value=[""]*(2*n-1)
print(value)
bit=[1]*n
#start=[i for i in range(n)]
num=1
HCodeType=[[bit,num] for i in range(MAXLEAF)]
print(HCodeType)
for i in range(n):
    print("Please input the value and weight of leaf node: ",i+1)
    value[i]=str(input("value:"))
    weight[i]=float(input("weight:"))
HNodeType=[[weight[i],parent[i],lchild[i],rchild[i],value[i]] for i in range(2*n-1)]
print((HNodeType))
def HuffmanTree(HNodeType,n):
    #i、j循环变量，m1、m2：构造哈夫曼树不同过程中两个最小权值结点的权值，x1、x2：构造哈夫曼树不同过程中两个权值结点在数组中的序号
    for i in range(n-1):#n-1次组合
        m1=m2=MAXVALUE#初始化为最大值
        x1=-1
        x2=-1
        #找出所有节点中，权值最小、无双亲结点的两个结点
        for j in range(n+i):
            if HNodeType[j][0]<m1 and HNodeType[j][1]==-1 :
                m2=m1
                x2=x1
                m1=HNodeType[j][0]
                x1=j
            elif HNodeType[j][0]<m2 and HNodeType[j][1]==-1:#用以处理两个结点权值相同的情况（利用m1=m2的特性）
                m2=HNodeType[j][0]
                x2=j
        HNodeType[x1][1]=n+i#x1的父亲(前驱节点)为新结点编号n+i
        HNodeType[x2][1]=n+i#x2的父亲为新结点编号n+i
        HNodeType[n+i][0]=m1+m2
        HNodeType[n+i][2]=x1
        HNodeType[n+i][3]=x2
#输出哈夫曼编码
 
def HuffmanCode(HCodeType,n):
    for i in range(n):
        start = n - 1
        c=i
        p=HNodeType[c][1]
        while p!=-1 :
            if HNodeType[p][2]==c :
                bit[start]=0
            else:bit[start]=1
            start-=1
            c=p
            p=HNodeType[c][1]
        for j in range(start+1,n):
            HCodeType[i][0][j]=bit[j]
        HCodeType[i][1]=start
HuffmanTree(HNodeType,n)
HuffmanCode(HCodeType,n)
for i in range(n):
    print(HNodeType[i][4],": Huffman code is : ",end="")
    for j in range(HCodeType[i][1]+1,n):
        print(HCodeType[i][0][j],end="")
    print(" ")