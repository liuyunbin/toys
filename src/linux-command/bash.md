
## Bash 常用快捷键

Ctrl+A             # 将光标移到行首
Ctrl+B             # 将光标向左移动一个字符
Ctrl+C             # 向前台进程组发送 SIGINT, 默认终止进程
Ctrl+D             # 删除光标前的字符 或 产生 EOF 或 退出终端
Ctrl+E             # 将光标移到行尾
Ctrl+F             # 将光标向右移动一个字符
Ctrl+G             # 退出当前编辑
Ctrl+H             # 删除光标前的一个字符
Ctrl+K             # 删除光标处到行尾的字符
Ctrl+L             # 清屏
Ctrl+N             # 查看历史命令中的下一条命令
Ctrl+O             # 类似回车，但是会显示下一行历史
Ctrl+P             # 查看历史命令中的上一条命令
Ctrl+Q             # 解锁终端
Ctrl+R             # 历史命令反向搜索, 使用 Ctrl+G 退出搜索
Ctrl+S             # 锁定终端 或 历史命令正向搜索, 使用 Ctrl+G 退出搜索
Ctrl+T             # 交换前后两个字符
Ctrl+U             # 删除光标处到行首的字符
Ctrl+V                          # 输入字符字面量，先按 Ctrl+V 再按任意键 ?
Ctrl+W             # 删除光标左边的一个单词
Ctrl+X                          # 列出可能的补全 ?
Ctrl+Y             # 粘贴被删除的字符
Ctrl+Z             # 暂停前台进程返回 bash，需要时可用 fg 将其切换回前台
Ctrl+/             # 撤销之前的操作
Ctrl+\             # 产生 SIGQUIT, 默认杀死进程, 并生成 core 文件

Esc+B              # 移动到当前单词的开头(左边)
Esc+F              # 移动到当前单词的结尾(右边)

Alt+B              # 向后（左边）移动一个单词
Alt+d              # 删除光标后（右边）一个单词
Alt+F              # 向前（右边）移动一个单词
Alt+t              # 交换字符 ?
Alt+BACKSPACE      # 删除光标前面一个单词，类似 Ctrl+W，但不影响剪贴板
Ctrl+X Ctrl+X      # 连续按两次 Ctrl+X，光标在当前位置和行首来回跳转
Ctrl+X Ctrl+E      # 用你指定的编辑器，编辑当前命令
Ctrl+insert        # 复制命令行内容
shift+insert       # 粘贴命令行内容

!!                 # 执行上一条命令
!l                 # 执行最近使用的以 l 打头的命令
!l:p               # 输出最近使用的以 l 打头的命令
!num               # 执行历史命令列表的第 num 条命令
!$                 # 表示上一条命令的最后一个参数

Esc+.              # 获取上一条命令的最后的部分

## Linux 常用命令
#### bash
v=(1 2 3)         # 定义数组
echo ${v[1]}      # 输出数组中指定元素的值
echo ${v[*]}      # 输出数组中所有元素的值
echo ${#v[*]}     # 输出数组中所有元素的个数
echo ${v[@]}      # 输出数组中所有元素的值
v=$[1+3]          # 定义变量，包括数学运算
ls -l `which ls`    # 命令替换，首先执行 which ls
ls -l $(which ls)   # 命令替换，首先执行 which ls
ls -l "$(which ls)" # 命令替换，首先执行 which ls, 保留换行符

declare -A v=(["a"]="a" ["b"]="b") # map
v[a]=a
v[b]=b

${v[*]}  # 获取值
${v[@]}
${!v[*]} # 获取 key
${!v[@]}
${#v[*]}  # 获取长度
${#v[@]}

length=${#val}    # 输出字符串的长度
${val:起始位置:长度} # 获取字串

${var}   # 取变量的值
$[1+2]   # 计算
$(ls -l) # 命令替换

IFS=$'\n' # 将字段分割符改成 '\n'
IFS=:     # 将字段分割符改成 :

vim
h:左移
j:下移
k:上移
l:下移
Ctrl+B 上翻一屏
Ctrl+F 下翻一屏
G      移到最后一行
gg     移到第一行
num gg 移到第 num 行

:w filename  # 保存为指定文件

x            # 删除光标所在位置的字符
dd           # 删除光标所在行
dw           # 删除光标所在位置的单词
d$           # 删除光标所在位置到行尾的字符
d^           # 删除光标所在位置到行首的字符
J            # 删除光标所在行尾的换行符
u            # 撤销上一命令
a            # 在光标后追加数据
A            # 在光标所在行尾追加数据
r char       # 使用 char 替换光标所在位置的单个字符
R text       #

:s/old/new/g    # 替换一行所有 old
:n,ms/old/new/g # 替换行号 n 和 m 之间所有 old
:%s/old/new/g   # 替换整个文件中的所有 old
:%s/old/new/gc  # 替换整个文件中的所有 old，但在每次出现时提示

#### dpkg
dpkg -L vim        # 列出 vim 软件包安装的全部文件
dpkg --search /... # 查看该文件是哪个软件包安装的, 使用绝对路径

问号（?）代表一个字符；
星号（*）代表零个或多个字符。
[123]
[1-5]
[!a]

du -sh # 某一目录的使用大小
df -Th # 所挂载的系统的使用情况

#### ps
ps -ef                  # 显示所有进程的详细信息
ps -o pid,ppid,command  # 按指定格式显示进程的信息
ps -f 123               # 显示指定进程的信息

tar -cvf  /path/to/foo.tar --exclude=\*.o /path/to/foo/ # foo         --> foo.tar, 忽略 .o 文件
tar -cvf  /path/to/foo.tar                /path/to/foo/ # foo         --> foo.tar
tar -czvf /path/to/foo.tgz                /path/to/foo/ # foo         --> foo.tgz
tar -czvf /path/to/foo.tar.gz             /path/to/foo/ # foo         --> foo.tar.gz
tar -cjvf /path/to/foo.tar.bz2            /path/to/foo/ # foo         --> foo.tar.bz2
tar -xvf  /path/to/foo.tar                              # foo.tar     --> foo
tar -xzvf /path/to/foo.tgz                              # foo.tgz     --> foo
tar -xzvf /path/to/foo.tar.gz                           # foo.tar.gz  --> foo
tar -xjvf /path/to/foo.tar.bz2                          # foo.tar.bz2 --> foo
tar -xjvf /path/to/foo.tar.bz2 -C /path/to/destination/ # foo.tar.bz2 --> foo, 指定工作目录

#### Linux 的三个特殊权限
set-user-ID  (SUID) # 可执行文件执行时将拥有程序所有者的权限
set-group-ID (SGID) # 可执行文件执行时将拥有程序所属的组的权限
sticky              # 此目录下的文件只有文件作者 或 root 可以删除

