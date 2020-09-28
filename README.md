# prime

#### 介绍
一个使用C++查找素数的程序，有单线程和多线程版本

#### 使用说明
建议编译时加上`-O2`参数以获取更好的性能
##### Windows
使用Visual Studio添加`main.cpp`或者`main_mt.cpp`后，直接编译运行即可下载。或者下载MinGW后执行
```
g++ main.cpp
```
##### Linux/WSL
单线程版本：
```
g++ main.cpp
```
多线程版本:
```
g++ main_mt.cpp -lpthread
```

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request

