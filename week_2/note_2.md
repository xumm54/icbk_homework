# 第二期作业笔记
## 一.git相关
1.**git clone 链接**
将git中仓库克隆到本地中，方便以后上传
2.**mkdir**
新建文件夹
3.**.gitignore**
"..../",自动忽略该类文件
4.日常更新  git add暂存，git commit -m"备注“，git push origin main推送到远程仓库，git pull origin main远程到本地
## 二.CMake相关
CMake 是**编译管理工具**，本身不是编译器。
 它读取 `CMakeLists.txt`，自动生成 Makefile，然后 make 调用gcc/g++编译C++代码。
 CMakeLists.txt基础语句说明：
 ```cmake
 cmake_minimum_required(VERSION 3.10)   # 要求CMake最低版本
 project(cv_test)                        # 标记项目名称，项目名
 set(CMAKE_CXX_STANDARD 14)              # 指定C++标准为C++14
 find_package(OpenCV REQUIRED)            # 查找OpenCV库，找不到直接报错
 include_directories(${OpenCV_INCLUDE_DIRS}) # 导入OpenCV头文件目录
 add_executable(cv_version cv_version.cpp)   # 源码文件，生成可执行程序cv_version，可执行程序名字，与target中一致
 target_link_libraries(cv_version ${OpenCV_LIBS}) # 程序链接OpenCV库