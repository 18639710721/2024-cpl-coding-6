# 2024-cpl-coding-6
202 CPL Coding Class 6

课程网站
https://docs.cpl.icu/

[官方公开刷题网站](https://public.oj.cpl.icu/)
[ant老师 github代码](https://github.com/courses-at-nju-by-hfwei/2024-cpl-coding-6/tree/main)
[C language Reference](https://en.cppreference.com/w/c/language)


### Lecture 1
任意一个高级的程序都可以表示为顺序(sequence),选择(selection), iteration(循环) 三种结构
可以参考[structured program theorem](https://en.wikipedia.org/wiki/Structured_program_theorem)和
[Flow Diagrams, Turing Machines
And Languages With Only Two
Formation Rules
](https://www.cs.unibo.it/~martini/PP/bohm-jac.pdf)这篇论文

物理世界基本是真随机的，而计算机里面的随机数序列基本都是伪随机且可预测(周期性的)，
通过诸如平方取中法以及线性同余等等算法利用`函数迭代`生成伪造随机数序列，
其中第一个参数x称之为随机数种子,由于随机数序列是可预测的，所以采用系统时间戳
作为种子以增加不可预测性，在`安全编程`中禁用该可能被预测到的随机数序列

#### Reference
* [蒙特卡洛求PI](https://www.jianshu.com/p/e6bf15a779ce)
* [顺序、分支、循环三种编程语句为什么就能表达所有计算机程序逻辑呢？](https://www.zhihu.com/question/19719270)
* [Flow Diagrams, Turing Machines And Languages With Only Two Formation Rules](https://dl.acm.org/doi/pdf/10.1145/355592.365646)

### Lecture 2
declare
init
assignment
expression
statement

address vs value
一个变量是有两层语义的
一是它本身的地址(address),可以通过&变量取得
二是地址所对应的值(value)


任意进制的本质是什么?(数论) 已解决

为什么计算机内部是使用的补码 (模运算 数电)

为什么变量在编译的时候会被解释为地址

简化if else的三目运算符
min = a >= b ?b : a;

[如何优化大量的if else](https://www.zhihu.com/question/441518636)
[卫语句? 优化if else](https://www.bilibili.com/video/BV1r2xueXEQG)

### Lecture 3
[如何优雅的使用for语句](https://www.bilibili.com/video/BV1pjDQYDEPq/?vd_source=3504703962e656bc1d62a64f50fb3aa1)

### Lecture 4
生命游戏感觉像一个函数由初始状态迭代生成(元细胞自动机)


#### Reference
* [个人项目开发示例：生命游戏](https://zhuanlan.zhihu.com/p/29102071)