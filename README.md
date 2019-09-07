# xv6-1909

## 湖南大学2018-2019夏季小学期操作系统课程设计（2019.09）

作者：湖南大学计算机科学与技术1603班 严裕东（上传者） 张伟麟 张祉健 刘轩玮 周默

### 新实现功能：

（1）内核多线程clone和join函数：proc.c；  
（2）clone、join函数的用户态实现：sysproc.c；  
（3）RR、Stride、FCFS三种调度算法，支持调度性能测试；  
（4）丰富的调度性能测试程序：test_matrix.c，test_IO.c和test_fd分别为计算型、内存型、文件型测试程序（单线程）；多线程测试程序为test_thread_xx.c；  
（5）更多的系统调用：ps命令打印进程信息、chpr命令修改进程优先级等。  

### 用法：

（1）编译运行：make/make qemu/make qemu-nox；  
（2）CPU核心数量控制：Makefile 226行；  
（3）调度算法指定：proc.h的标记位，USE_FCS和USE_stride均为0时运行RR调度，USE_FCS为1运行FCFS调度，USE_stride为1时运行stride调度，两个标记位不可同为1。  

### 未解决：

（1）暂时无法说明与分析：当存在多核心时，进程具体在哪个CPU上运行；  
（2）暂无混合类型测试程序。  

### 相关教程：

xv6加入用户应用程序：https://blog.csdn.net/yyd19981117/article/details/95199634  
xv6加入系统调用：https://blog.csdn.net/yyd19981117/article/details/95200267

## Hunan University 2018-2019 Summer semester —— Operating System Course project (2019.09)  

Author: College of Computer Science and Electronic Engineering (CSEE), Hunan University, Hunan, China  
Yudong Yan (uploader), Weilin Zhang, Zhijian Zhang, Xuanwei Liu, Mo Zhou  

### New implementation features:  

(1) kernel multi-threaded clone and join function in proc.c;  
(2) User mode implementation of clone and join functions in sysproc.c;  
(3) RR, Stride, FCFS scheduling algorithms, with supports of scheduling performance test;  
(4) Rich scheduling performance test programs: test_matrix.c, test_IO.c and test_fd are respectively computational, memory IO, file-type test programs (single-threaded); multi-threaded test program are named as test_thread_xx.c;  
(5) More system calls: ps command - print process information; chpr - command to modify process priority, etc.  

### Usage:  

(1) Compile and run: make/make qemu/make qemu-nox;  
(2) CPU core quantity control: Makefile line 226;  
(3) The scheduling algorithm specifies: the flag bit of proc.h, when the USE_FCS and USE_stride are both 0, the RR scheduling is running; to run the FCFS scheduling, set USE_FCS to 1, and set USE_stride to 1 if to run the stride scheduling. The two flag bits cannot be both 1.  

### Unsolved:

(1) Unable to explain and analyze: When there are multiple cores, which CPU is the processes exactly running on;  
(2) No mixed type test program.  

### Related work:

Add user application to xv6: https://blog.csdn.net/yyd19981117/article/details/95199634  
Add system calls to xv6: https://blog.csdn.net/yyd19981117/article/details/95200267
