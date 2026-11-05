# C语言基础
## 函数：

1. `strcmp`函数：
    - 原型：`int strcmp(const char *s1, const char *s2);`
    - 作用：逐字符比较字符大小（按编码值大小），左边大于右边时为正数
    - 要求字符串以`\0`结尾
2. `strcpy`函数：
    - 原型：`char *strcpy(char *dest, const char *src);`
    - 作用：把 src（包括结尾的 '\0'）复制到 dest，返回 dest。
3. `strlen`函数：
    - 原型：`size_t strlen(const char *s);`
    - 作用：返回字符串 s 中第一个 '\0' 之前的字符个数，不包含 '\0' 本身。
    - 必须以`\0`结尾
4. `fgets`函数：
    - 原型：`char *fgets(char *str, int n, FILE *stream);`
    - 作用：从文件流中读取至多n个字符并存入字符串str中，其中常用的文件流是stdin,表示从键盘输入，且此函数会读入换行符。
    - 与`scanf`区别在于可以读取空白字符，且不会发生溢出
5. `rand`函数
    - 作用：用来生成伪随机数
6. `srand`函数
    - 用来为`rand`函数生成种子
7. `time`函数
    - 常用来作为`srand`函数的时间戳
## 逻辑

1. `for(;;)`与`while(1)`都表示不停止的逻辑，用break跳出。
2. 使用`int`类型输入时，会将整个数字存入。而使用`char`类型时可以一个一个存入，此时可以用`getchar`或`fgets`。
    