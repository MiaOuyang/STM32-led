# 1 使用CubeMX生成相关代码
## 1.1 安装STM32CubeMX
1. 官网下载
[https://www.st.com/en/development-tools/stm32cubemx.html?sc=stm32cubemx](https://www.st.com/en/development-tools/stm32cubemx.html?sc=stm32cubemx)
需要绑定邮箱或者注册，比较麻烦
2. 网盘下载地址（6.4.0）
[https://pan.baidu.com/s/15MZnIpdp_XYLH7zLn4YQgA?pwd=ed58](https://pan.baidu.com/s/15MZnIpdp_XYLH7zLn4YQgA?pwd=ed58)
提取码：ed58

## 1.2 安装HAL库
什么是HAL固件库？

STM32 HAL固件库是*Hardware Abstraction Layer*的缩写，中文名称是：硬件抽象层。HAL库是ST公司为STM32的MCU最新推出的抽象层嵌入式软件，为更方便的实现跨STM32产品的最大可移植性。HAL库的推出，可以说ST也慢慢的抛弃了原来的标准固件库，这也使得很多老用户不满。但是HAL库推出的同时，也加入了很多第三方的中间件，有RTOS，USB，TCP / IP和图形等等。

和标准库对比起来，STM32的HAL库更加的抽象，ST最终的目的是要实现在STM32系列MCU之间无缝移植，甚至在其他MCU也能实现快速移植。

并且从16年开始，ST公司就逐渐停止了对标准固件库的更新，转而倾向于HAL固件库和 Low-layer底层库的更新，停止标准库更新，也就表示了以后使用STM32CubeMX配置HAL/LL库是主流配置环境；

HAL库，有`在线安装`、`离线安装`两种方式。

本文仅介绍**在线安装**方法
***

1. 打开安装好的 STM32CubeMX 软件  点上面的Help -> Manage embedded software packages
![在这里插入图片描述](https://img-blog.csdnimg.cn/97f451bcd35d4c859ea9f137199bd369.png)
2. 勾选所要安装的HAL库，点击Install Now
![在这里插入图片描述](https://img-blog.csdnimg.cn/5b4b6748e9794c6e8d08fc3599d76ab9.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/d6b869834f134fe6b97a63e64bf8555c.png)

## 1.3 新建项目
1. 点击左上角File->New Project

![在这里插入图片描述](https://img-blog.csdnimg.cn/0f06bceee88f412589559016ae05f738.png)

之后选择芯片
![在这里插入图片描述](https://img-blog.csdnimg.cn/84b6ce9db05041b4bb7983769602eccc.png)
选择完毕后，点击信息栏中的具体芯片信息选中，点击start project

2. 点击system core，进入SYS，在debug下选择serial wire
![在这里插入图片描述](https://img-blog.csdnimg.cn/00d7415f8d9c4fa784f86bdb75823596.png)
3. 配置时钟
进入上面的rcc，点击Clock Configuration，按下图勾选，同时把8MHz改成72

![在这里插入图片描述](https://img-blog.csdnimg.cn/7492936656eb4bf992349e7ef5c32405.png)


4. 将HSE按下图设置
![在这里插入图片描述](https://img-blog.csdnimg.cn/d05be5be90a148248f92150ae8b04b73.png)
5. 配置引脚功能
点击GPIO，点击相应的引脚设置输出寄存器，我使用的是PA5，PB9，PC14引脚
![在这里插入图片描述](https://img-blog.csdnimg.cn/aab447d146724f41890dfd6ee937d264.png)

配置好后如图所示

![在这里插入图片描述](https://img-blog.csdnimg.cn/e742a37907da402b855c8ca3b5a3869e.png)

此时，不知为何rcc处有警告，PC14引脚有冲突，改为pc13，警告消失

## 1.4 生成相关代码
点击project manager，配置好自己的路径和项目名，然后IDE那项改为MDK-ARM

![在这里插入图片描述](https://img-blog.csdnimg.cn/616035bc81054e1084eb3066f7c25a65.png)
按下图勾选，然后点击generate code
![在这里插入图片描述](https://img-blog.csdnimg.cn/99a39d1663dc45fc8eaabb2a3f1d935f.png)
完成后，点击open project，直接进入keil中
