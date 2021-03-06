## 简介
google-glog 是 Google 的一个开源的日志库

## 测试环境
* Ubuntu 18.04 LTS
* google-glog 0.3.5
* google-gflags 2.2.1

## 安装
```
$ sudo apt install libgflags-dev
$ sudo apt install libgoogle-glog-dev
```

## 使用
#### 1. 添加需要的头文件
```
#include <glog/logging.h>
```

#### 2. 设置使用文档（可选）
```
google::SetUsageMessage("How to use");
```

#### 3. 设置版本（可选）
```
google::SetVersionString("1.0.0");
```

#### 4. 配置 LOG（见下文）（可选）

#### 5. 解析命令行（可选）
```
google::ParseCommandLineFlags(&argc, &argv, true);
```

#### 6. 初始化 google-glog
```
google::InitGoogleLogging(argv[0]);
```

#### 7. 使用 LOG（见下文）

#### 8. 编译，链接动态库
```
$ g++ main.cc -lgflags -glog
```

## 配置 LOG
google-glog 日志分四类：INFO，WARNING，ERROR 和 FATAL。
对于 FATAL ，程序输出日志后将退出

### 常用配置选项如下：
#### 设置是否输出到标准错误，默认否，即输出到文件
##### 命令行参数配置
```
$ --logtostderr=1 # 1，true  和 yes（大小写均可）意思相同
$ --logtostderr=0 # 0，false 和 no （大小写均可）意思相同
```

##### 程序中配置
```
FLAGS_logtostderr = 1; # 1 和 true  意思相同
FLAGS_logtostderr = 0; # 0 和 false 意思相同
```

#### 设置将指定等级及其以上等级的日志输出到标准错误，默认为 ERROR
配置中 0 表示 INFO，1 表示 WARNING，2 表示 ERROR，3 表示 FATAL

##### 命令行参数配置
```
$ --stderrthreshold=2
```

##### 程序中配置
```
FLAGS_stderrthreshold = 2;
```

#### 设置输出指定等级及其以上等级的日志，默认为 INFO
配置中 0 表示 INFO，1 表示 WARNING，2 表示 ERROR，3 表示 FATAL

##### 命令行参数配置
```
$ --minloglevel=0
```

##### 程序内配置
```
FLAGS_minloglevel = 0;
```

#### 设置日志目录，默认为 /tmp
##### 命令行参数配置
```
$ --log_dir=/tmp
```

##### 程序内配置
```
FLAGS_log_dir = "/tmp";
```

#### 设置 log 是否使用颜色，默认不使用
##### 命令行参数配置
```
$ --colorlogtostderr=1 # 1，true  和 yes（大小写均可）意思相同
$ --colorlogtostderr=0 # 0，false 和 no （大小写均可）意思相同
```

##### 函数内配置
```
FLAGS_colorlogtostderr = 1; # 1 和 true  意思相同
FLAGS_colorlogtostderr = 0; # 0 和 false 意思相同
```

## 使用 LOG
### 常用的日志宏
#### 简单的输出日志
```
LOG(INFO) << "message";
```

#### 按条件输出日志
```
LOG_IF(INFO, a > 0) << "message";
```

#### 检查某个条件是否成立
```
CHECK(a > 0) << "message";
```

#### 检测两个值是否相等
```
CHECK_EQ(a, b) << "message";
```

#### 检测两个值是否不相等
```
CHECK_NE(a, b) << "message";
```

#### 检测是否为空指针，将返回该指针
```
CHECK_NOTNULL(p);
```

#### 打印系统错误
```
PLOG();
PLOG_IF();
PCHECK();
```

## 参考资源
* https://github.com/google/glog
* https://github.com/gflags/gflags

