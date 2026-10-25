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
## 三.图像画面相关
 图像在计算机中以像素矩阵的形式储存，，矩阵每个元素对应一个像素
像素：图像最小组成单位，记录亮度或颜色
分辨率：图像中像素数量，决定细节
通道数：单个像素的分量组数
位深：单通道占用比特数，数值越大颜色变化越细腻
(2)存储差异：灰度图是单通道，只保存亮度信息，占用空间小；彩色图是三通道，存储空间是灰色图的三倍
mat：存放图像，矩阵信息的数据结构，头部信息区记录宽,高,通道...，拷贝只复制头部信息，不重复复制像素内存，节省内存。访问单像素方式.at<T>(y,x)
(3)灰度化：将三通道彩色图像转化为单通道灰度图，舍弃色彩，保留亮度信息，场景：自瞄消除色彩干扰
二值化：设定阈值，将像素分为黑白两类，场景：识别灯条
ROI感兴趣区域：在原图中划分一块矩形区域，只对该区域做图像处理，场景：云庙锁定，节省算力
图像缩放：放大或缩小像素尺寸，场景：缩小加快图像识别速度，放大增加画面细节