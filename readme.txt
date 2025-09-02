检测push swap

norminette

1. make
2. ./push_swap 2 1 3
3. ./push_swap 2 1 3 | ./checker_linux 2 1 3 将命令通过管道传给checker_linux检测是OK/KO
3. make bonus
4. ./check 2 1 3
5. 输入“sa”命令和回车， ctrl+d结束 检测命令是否能够正确排序

bash:
ARG=$(seq 1 100 | shuf)
./push_swap $ARG | ./checker $ARG
-->ok

ARG="3 2 1"
./push_swap $ARG | ./checker $ARG   # 应输出 OK
./checker $ARG                      # 手动输入操作sa rra，验证输出

输入非法情况：
非数字：      ./push_swap a b c       → 输出 Error 并退出
超出 int：    ./push_swap 2147483648  → Error
重复数字：    ./push_swap 1 2 2       → Error
空参数：      ./push_swap ""          → Error
⚠️ 必须只打印 "Error\n" 到 stderr，不能有额外信息

内存管理：
valgrind --leak-check=full ./push_swap 2 1 3
valgrind --leak-check=full ./checker





push_swap_tester
1. cd push_swap_tester
2. make
3. ./complexity 100 100 700 （100个数字， 100次循环，<=700的执行次数)
   ./complexity 500 100 5500 (...)




push_swap_visualizer
1. cd push_swap_visualizer
2. mkdir build
3. cd build
4. cmake ..
5. make
6. ./bin/visualizer运行程序

