# C语言基础
## 字符串操作：

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
    