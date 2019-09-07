# xv6-1909

湖南大学2018-2019夏季小学期操作系统课程设计（2019.09）

作者：湖南大学计算机科学与技术1603班 严裕东（上传者） 张伟麟 张祉健 刘轩玮 周默

新实现功能：

（1）内核多线程clone和join函数：proc.c
（2）clone、join函数的用户态实现：sysproc.c
（3）RR、Stride、FCFS三种调度算法，支持调度性能测试
（4）丰富的调度性能测试程序：test_matrix.c，test_IO.c和test_fd分别为计算型、内存型、文件型测试程序（单线程）；多线程测试程序为test_thread_xx.c
（5）更多的系统调用：ps命令打印进程信息、chpr命令修改进程优先级等

用法：

（1）编译运行：make/make qemu/make qemu-nox
（2）CPU核心数量控制：Makefile 226行
（3）调度算法指定：proc.c的标记位，USE_FCS和USE_stride均为0时运行RR调度，USE_FCS为1运行FCFS调度，USE_stride为1时运行stride调度，两个标记位不可同为1

未解决：

（1）暂时无法说明与分析：当存在多核心时，进程具体在哪个CPU上运行
（2）暂无混合类型测试程序
