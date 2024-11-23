'''
Author: LetMeFly
Date: 2023-08-26 18:06:23
LastEditors: LetMeFly
LastEditTime: 2024-04-04 23:20:45
'''
datasets_prefix = '/root/paddlejob/workspace/train_data/datasets/'
# 数据集文件具体路径请在编辑项目状态下通过左侧导航「数据集」中文件路径拷贝按钮获取
ffmpegDir =  datasets_prefix + 'data236492/'
ffmpegPath =  'ffmpeg/ffmpeg'
dataDir = datasets_prefix + 'data236493/'
# 输出文件目录. 任务完成后平台会自动把该目录所有文件压缩为tar.gz包，用户可以通过「下载输出」可以将输出信息下载到本地.
outputDir = '/root/paddlejob/workspace/output/'
print('*' * 100)


import os

os.system('unzip ' + ffmpegDir + 'ffmpeg-6.0-i686-static.zip -d ffmpeg')
os.system('ls -l ' + 'ffmpeg')
os.system('chmod 777 ffmpeg')
os.system('chmod 777 ffmpeg/ffmpeg')

os.system('unzip ' + ffmpegDir + 'Fonts.zip -d Fonts')
os.system('ls Fonts')


print('*' * 100)


def merge(videoPath, assPath, outputName):
    cmd = f"""{ffmpegPath} -i "{videoPath}" -vf "ass='{assPath}':fontsdir=Fonts" -c:a copy "{outputName}" -y"""
    print(cmd)
    os.system(cmd)


def resize(videoPath, outputName):
    cmd = f'{ffmpegPath} -i "{videoPath}" "{outputName}" -y'
    print(cmd)
    os.system(cmd)


def resizeFlv(videoName):
    resize(dataDir + videoName + '.flv', outputDir + videoName + '.mp4')


def resizeMkv(videoName):
    resize(dataDir + videoName + '.mkv', outputDir + videoName + '.mp4')

def resizeMp4(videoName):
    resize(dataDir + videoName + '.mp4', outputDir + videoName + '.mp4')

# '''
# ffmpeg -i "0.flv" -vf "ass=0.ass:fontsdir=Fonts" -c:a copy "output.flv"
# '''
# resizeQingYinShaoNv('第01集  废部！')
# resizeQingYinShaoNv('第02集  乐器！')
# resizeQingYinShaoNv('第03集  特训！')
# resizeQingYinShaoNv('第04集  住宿集训!')
# resizeQingYinShaoNv('第05集  顾问！')
# resizeFlv('第06集  校庆！')
# resizeQingYinShaoNv('第07集  圣诞节！')
# resizeQingYinShaoNv('第08集  欢迎新生！')
# resizeQingYinShaoNv('第09集  新成员！')
# resizeQingYinShaoNv('第10集  再度住宿集训！')
# resizeFlv('第11集  危机！')
# resizeQingYinShaoNv('第12集  轻音！')
# resizeMkv('第13集  冬至日！')
# resizeMkv('第14集  Live House!')
# resizeFlv('第01集  高三！')
# resizeFlv('第02集  整顿！')
# resizeFlv('第03集  鼓手！')
# resizeFlv('第04集  修学旅行！')
# resizeFlv('第05集  看家！')
# resizeFlv('第06集  梅雨！')
# resizeFlv('第07集  茶会！')
# resizeFlv('第08集  志愿！')
# resizeFlv('第09集  期末考试！')
# resizeFlv('第10集  老师！')
# resizeFlv('第11集  好热！')
# resizeFlv('第12集  夏日祭！')
# resizeFlv('第13集  残暑问候!')
# resizeFlv('第14集  夏季讲座！')
# resizeFlv('第15集  马拉松大会！')
# resizeFlv('第16集  前辈！')
# resizeFlv('第17集  没有活动室！')
# resizeFlv('第18集  主角！')
# resizeFlv('第19集  罗密朱丽！')
# resizeFlv('第20集  还是校庆！')
# resizeFlv('第21集  毕业纪念册！')
# resizeFlv('第22集  考试！')
# resizeFlv('第23集  放学后！')
# resizeFlv('第24集  毕业典礼！')
# resizeFlv('K-ON！(轻音少女剧场版）')
# resizeFlv('ova 1 冬之日！')
# resizeFlv('ova 2 Live House！')
# resizeFlv('ova 3  企划会议！')
# resizeFlv('ova 4  访问！')
# resizeFlv('ova 5  计划！')
# resizeMp4('OAD_高清 1080P+') # 工作细胞
# resizeMp4('《工作细胞 第二季》第1话 肿包_高清 1080P+')
# resizeMp4('《工作细胞 第二季》第2话 获得性免疫 派尔集合淋巴结_高清 1080P+')
# resizeMp4('《工作细胞 第二季》第3话 登革热 痤疮_高清 1080P+')
# resizeMp4('《工作细胞 第二季》第4话 幽门螺旋杆菌 抗原变异_高清 1080P+')
# resizeMp4('《工作细胞 第二季》第5话 细胞因子_高清 1080P+')
# resizeMp4('《工作细胞 第二季》第6话 有害菌_高清 1080P+')
# resizeMp4('《工作细胞 第二季》第7话 癌细胞Ⅱ（前篇）_高清 1080P+')
# resizeMp4('《工作细胞 第二季》第8话 癌细胞Ⅱ（后篇）_高清 1080P+')
# resizeMp4('原版_高清 1080P+')  # failed three times 不试了
# resizeMp4('《工作细胞BLACK》第1话 吸烟、细菌、终焉的开始_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第2话 肝脏、酒精、荣耀。_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第3话 兴奋、膨胀、虚无。_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第4话 最前线、淋球菌、纠葛。_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第5话 超负荷劳动、脱发、错乱。_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第6话 肾脏、尿路结石、眼泪。_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第7话 咖啡因、诱惑、嫉妒。_高清 1080P+')  # failed twice 不试了
# resizeMp4('《工作细胞BLACK》第8话 小腿肚、肺血栓、急中生智。_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第9话 异变、足癣、工作的意义。_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第10话 胃溃疡、友情、丧失。_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第11话 自暴自弃、痛风、叛乱。_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第12话 回归、心脏、终焉。_高清 1080P+')
# resizeMp4('《工作细胞BLACK》第13话 心肌梗塞、苏醒、变化。_高清 1080P+')
# resizeMp4('《炎炎消防队》第1话 森罗日下部 入队_高清 1080P+')
# resizeMp4('《炎炎消防队》第2话 消防官之心_高清 1080P+')
# resizeMp4('《炎炎消防队》第3话 消防官新人大赛_高清 1080P+')
# resizeMp4('《炎炎消防队》第4话 英雄与公主_高清 1080P+')  # failed once
# resizeMp4('《炎炎消防队》第5话 开战_高清 1080P+')
# resizeMp4('《炎炎消防队》第6话 约定的火华（花）_高清 1080P+')
# resizeMp4('《炎炎消防队》第7话 第一队调查开始_高清 1080P+')
# resizeMp4('《炎炎消防队》第8话 焰虫_高清 1080P+')
# resizeMp4('《炎炎消防队》第9话 扩燃的恶意_高清 1080P+')
# resizeMp4('《炎炎消防队》第10话 约定_高清 1080P+')
# resizeMp4('《炎炎消防队》第11话 第八特殊消防队结成_高清 1080P+')
# resizeMp4('《炎炎消防队》第12话 浅草开战前夜_高清 1080P+')
# resizeMp4('《炎炎消防队》第13话 设好的陷阱_高清 1080P+')
# resizeMp4('《炎炎消防队》第14话 火焰为谁而燃_高清 1080P+')
# resizeMp4('《炎炎消防队》第15话 铁匠的梦想_高清 1080P+')
# resizeMp4('《炎炎消防队》第16话 我们是一家人_高清 1080P+')
# resizeMp4('《炎炎消防队》第17话 黑与白与灰色_高清 1080P+')
# resizeMp4('《炎炎消防队》第18话 起火的秘诀_高清 1080P+')
# resizeMp4('《炎炎消防队》第19话 通往地下_高清 1080P+')
# resizeMp4('《炎炎消防队》第20话 荣耀加身_高清 1080P+')
# resizeMp4('《炎炎消防队》第21话 相连之人_高清 1080P+')
# resizeMp4('《炎炎消防队》第22话 兄长的执念_高清 1080P+')
# resizeMp4('《炎炎消防队》第23话 笑容_高清 1080P+')
# resizeMp4('《炎炎消防队》第24话 燃烧的过去_高清 1080P+')
# # resizeMp4('花木兰')  # failed once
# resizeMp4('01.消防官的战斗')  # 第二季
# resizeMp4('02.狂乱的烈焰')
# resizeMp4('03.新的火种')
# resizeMp4('04.火中摸索')  # failed twice 已放弃
# resizeMp4('05.恶魔之型')
# resizeMp4('06.抉择时刻')
# resizeMp4('07.通往乐园的道路')
# resizeMp4('08.暗中燃烧的恶意')
# resizeMp4('09.核心')
# resizeMp4('10.黑袍女')
# resizeMp4('11.黑暗英雄')
# resizeMp4('12.神光下的阴影')
# resizeMp4('13.针锋相对的独眼')
# resizeMp4('14.灰色死神')
# resizeMp4('15.三色混战')  # failed twice 压制失败
# resizeMp4('16.爆发之心')
# resizeMp4('17.少年啊，保持住你的弱小')  # failed once
# resizeMp4('18.圣女的苦恼')
# resizeMp4('19.尾濑一门')
# resizeMp4('20.破坏兵器')
# resizeMp4('21.接敌')
# resizeMp4('22.灭亡的阴谋')
# resizeMp4('23.炎猫')
# resizeMp4('24.剧变征兆')
# resizeMkv('月色真美01')
# resizeMkv('月色真美02')
# resizeMkv('月色真美03')
# resizeMkv('月色真美04')
# resizeMkv('月色真美05')
# resizeMkv('月色真美06')
# resizeMkv('月色真美07')
# resizeMkv('月色真美08')  # failed twice 压制失败
# resizeMkv('月色真美09')
# resizeMkv('月色真美10')
# resizeMkv('月色真美11')
# resizeMkv('月色真美12')
# resizeMkv('在下坂本，有何贵干？01')  # 在下坂本，有何贵干？
# resizeMkv('在下坂本，有何贵干？02')
# resizeMkv('在下坂本，有何贵干？03')
# resizeMkv('在下坂本，有何贵干？04')
# resizeMkv('在下坂本，有何贵干？05')
# resizeMkv('在下坂本，有何贵干？06')
# resizeMkv('在下坂本，有何贵干？07')
# resizeMkv('在下坂本，有何贵干？08')
# resizeMkv('在下坂本，有何贵干？09')
# resizeMkv('在下坂本，有何贵干？10')
# resizeMkv('在下坂本，有何贵干？11')
# resizeMkv('在下坂本，有何贵干？12')
# resizeMkv('在下坂本，有何贵干？13')
# resizeMkv('モブサイコ100 第01話')  # 灵能百分百
# resizeMkv('モブサイコ100 第02話')
# resizeMkv('モブサイコ100 第03話')
# resizeMkv('モブサイコ100 第04話')
# resizeMkv('モブサイコ100 第05話')
# resizeMkv('モブサイコ100 第06話')  # failed once
# resizeMkv('モブサイコ100 第07話')
# resizeMkv('モブサイコ100 第08話')  # failed once
# resizeMkv('モブサイコ100 第09話')
# resizeMkv('モブサイコ100 第10話')
# resizeMkv('モブサイコ100 第11話')  # failed once
# resizeMkv('モブサイコ100 第12話')
# resizeMkv('モブサイコ100II 第01話')  # 第二季
# resizeMkv('モブサイコ100II 第02話')
# resizeMkv('モブサイコ100II 第03話')
# resizeMkv('モブサイコ100II 第04話')
# resizeMkv('モブサイコ100II 第05話')
# resizeMkv('モブサイコ100II 第06話')
# resizeMkv('モブサイコ100II 第07話')
# resizeMkv('モブサイコ100II 第08話')
# resizeMkv('モブサイコ100II 第09話')
# resizeMkv('モブサイコ100II 第10話')
# resizeMkv('モブサイコ100II 第11話')
# resizeMkv('モブサイコ100II 第12話')
# resizeMkv('モブサイコ100II 第13話')
# resizeMkv('01')  # 斩！赤红之瞳
# resizeMkv('02')
# resizeMkv('03')  # failed once
# resizeMkv('04')
# resizeMkv('05')
# resizeMkv('06')
# resizeMkv('07')
# resizeMkv('08')
# resizeMkv('09')
# resizeMkv('10')
# resizeMkv('11')
# resizeMkv('12')
# resizeMkv('13')
# resizeMkv('14')
# resizeMkv('15')
# resizeMkv('16')
# resizeMkv('17')
# resizeMkv('18')
# resizeMkv('19')
# resizeMkv('20')
# resizeMkv('21')
# resizeMkv('22')
# resizeMkv('23')
# resizeMkv('24')
# resizeMkv('笨蛋测验召唤兽S2E01')  # 笨蛋、测验、召唤兽s2
# resizeMkv('笨蛋测验召唤兽S2E02')
# resizeMkv('笨蛋测验召唤兽S2E03')
# resizeMkv('笨蛋测验召唤兽S2E04')
# resizeMkv('笨蛋测验召唤兽S2E05')
# resizeMkv('笨蛋测验召唤兽S2E06')  # failed once
# resizeMkv('笨蛋测验召唤兽S2E07')
# resizeMkv('笨蛋测验召唤兽S2E08')
# resizeMkv('笨蛋测验召唤兽S2E09')  # failed once
# resizeMkv('笨蛋测验召唤兽S2E10')  # failed once
# resizeMkv('笨蛋测验召唤兽S2E11')
# resizeMkv('笨蛋测验召唤兽S2E12')
# resizeMkv('笨蛋测验召唤兽S2E13')
# resizeMkv('01')  # 月刊少女野崎君
# resizeMkv('02')
# resizeMkv('03')
# resizeMkv('04')  # failed once
# resizeMkv('05')
# resizeMkv('06')
# resizeMkv('07')
# resizeMkv('08')
# resizeMkv('09')
# resizeMkv('10')
# resizeMkv('11')
# resizeMkv('12')
# resizeMkv('钢之炼金术师剧场版：叹息之丘的圣星')  # 钢之炼金术师
# resizeMkv('钢之炼金术师剧场版：香巴拉的征服者')
# resizeMp4('[Nekomoe kissaten][SPYxFAMILY][26][1080p][CHS]')  # 间谍过家家
# resizeMp4('[Nekomoe kissaten][SPYxFAMILY][27][1080p][CHS]')
# resizeMp4('[Nekomoe kissaten][SPYxFAMILY][28][1080p][CHS]')
# resizeMp4('[Nekomoe kissaten][SPYxFAMILY][29][1080p][CHS]')
# resizeMp4('[Nekomoe kissaten][SPYxFAMILY][30][1080p][CHS]')
# resizeMp4('[Nekomoe kissaten][SPYxFAMILY][31][1080p][CHS]')
# resizeMp4('[Nekomoe kissaten][SPYxFAMILY][32][1080p][CHS]')  # twice
# resizeMp4('[Nekomoe kissaten][SPYxFAMILY][33][1080p][CHS]')
# resizeMp4('[Nekomoe kissaten][SPYxFAMILY][34][1080p][CHS]')
# resizeMp4('[Nekomoe kissaten][SPYxFAMILY][35][1080p][CHS]')
# merge(dataDir + '[SubsPlease] Spy x Family-36(1080p) [FA8451BB].mkv', dataDir + '36.ass', outputDir + '[SubsPlease] Spy x Family-36(1080p) [FA8451BB].mp4')
merge(dataDir + '[SubsPlease] Spy x Family-37(1080p) [3DDFF97D].mkv', dataDir + '37.ass', outputDir + '[SubsPlease] Spy x Family-37(1080p) [3DDFF97D].mp4')


# merge(dataDir + '变形金刚7.mkv', dataDir + '变形金刚7.ass', outputDir + '变形金刚7的4KHDR.Transformers.Rise.of.the.Beasts.2023.2160p.WEB-DL.DDP5.1.Atmos.HDR.H.265-APEX.mp4')

# def mergeGongZuoXiBao(videoName):
#     merge(dataDir + videoName + '.mp4', dataDir + videoName + '.ass', outputDir + videoName + '.mp4')

# merge(dataDir + '《工作细胞》第7话 癌细胞_高清 1080P+.mp4', dataDir + '《工作细胞》第7话 癌细胞_高清 1080P+.ass', outputDir + '《工作细胞》第7话 癌细胞_高清 1080P+.mp4')
# merge(dataDir + '《工作细胞》第8话 血液循环_高清 1080P+.mp4', dataDir + '《工作细胞》第8话 血液循环_高清 1080P+.ass', outputDir + '《工作细胞》第8话 血液循环_高清 1080P+.mp4')
# merge(dataDir + '《工作细胞》第9话 胸腺细胞_高清 1080P+.mp4', dataDir + '《工作细胞》第9话 胸腺细胞_高清 1080P+.ass', outputDir + '《工作细胞》第9话 胸腺细胞_高清 1080P+.mp4')
# merge(dataDir + '《工作细胞》第10话 金黄色葡萄球菌_高清 1080P+.mp4', dataDir + '《工作细胞》第10话 金黄色葡萄球菌_高清 1080P+.ass', outputDir + '《工作细胞》第10话 金黄色葡萄球菌_高清 1080P+.mp4')
# merge(dataDir + '《工作细胞》第11话 中暑_高清 1080P+.mp4', dataDir + '《工作细胞》第11话 中暑_高清 1080P+.ass', outputDir + '《工作细胞》第11话 中暑_高清 1080P+.mp4')
# merge(dataDir + '《工作细胞》第12话 失血性休克（前篇）_高清 1080P+.mp4', dataDir + '《工作细胞》第12话 失血性休克（前篇）_高清 1080P+.ass', outputDir + '《工作细胞》第12话 失血性休克（前篇）_高清 1080P+.mp4')
# mergeGongZuoXiBao('《工作细胞》第1话 肺炎链球菌_高清 1080P+')
# mergeGongZuoXiBao('《工作细胞》第2话 擦伤_高清 1080P+')
# mergeGongZuoXiBao('《工作细胞》第3话 流行性感冒_高清 1080P+')
# mergeGongZuoXiBao('《工作细胞》第4话 食物中毒_高清 1080P+')
# mergeGongZuoXiBao('《工作细胞》第13话 失血性休克（后篇）_高清 1080P+')
#mergeGongZuoXiBao('《工作细胞》第5话 杉树花粉过敏_高清 1080P+')
#mergeGongZuoXiBao('《工作细胞》第6话 成红血细胞和骨髓细胞_高清 1080P+')
#exit(0)
