📘 第 4 章：精简练习清单
🔹 练习 1：查看文件基本信息（使用 stat）
编写一个程序，打印一个指定文件的大小、访问权限、最后访问时间等属性。

函数：stat(), struct stat, printf()

字段：st_size, st_mode, st_atime 等

工具函数：ctime(), S_ISREG() 等宏判断

🔹 练习 2：判断文件类型（常用于遍历目录时）
编写程序判断输入文件是普通文件、目录、符号链接或字符设备。

使用 stat() + 文件类型宏：

S_ISREG(), S_ISDIR(), S_ISLNK(), S_ISCHR(), S_ISBLK()

🔹 练习 3：读取符号链接信息（使用 lstat）
写一个程序分别用 stat() 和 lstat() 查看符号链接本身与其指向文件的属性。

stat() 跟随符号链接

lstat() 返回符号链接本身属性

🔹 练习 4：修改文件权限（使用 chmod）
把一个文件的权限修改为 rw-r--r--（即 0644）

使用 chmod(filename, 0644)

可结合 stat() 查看修改前后权限变化

🔹 练习 5：修改文件属主（使用 chown）
编写程序将一个文件的属主修改为指定 UID/GID

函数：chown(filename, new_uid, new_gid)

建议使用 getuid() 作为测试（无需特权）

说明 chown 需要超级用户权限（可在 sudo ./a.out 下运行）

🔹 练习 6：构建一个简单的 ls -l 工具
打印文件的详细信息，格式仿照 ls -l（权限、大小、类型、修改时间）

使用：stat() + S_IRUSR 等权限宏 + strftime() 格式化时间

输出样例：

yaml
复制
编辑
-rw-r--r-- 1234 2025-07-10  hello.txt
🔹 练习 7（进阶）：批量处理多个文件属性
使用循环处理多个文件路径，批量打印其信息（仿 ls file1 file2 ...）

用 argc/argv 处理参数

可使用 stat()/lstat() + 类型判断宏
