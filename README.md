# Computational-Graph

## 运行环境

Linux ， Windows 平台皆可，推荐 Linux

软件包依赖 `CMake` ，要求版本 `3.10` 以上

## 测试代码编译命令

### Linux 环境

在 `.` 目录下运行
```
$ cmake CMakeLists.txt
$ make
$ ./main
```
### Windows 环境

请使用具体的 `CMake` 软件构建工程

构建成功后可执行文件为 `main.exe`

## 如果你想用我的库

请按如下格式编写 `CMakeLists.txt`

```cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(YOUR_PROJECT) #YOUR_PROJECT_NAME是你的工程名

ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(basic_calc_pack)
ADD_SUBDIRECTORY(advanced_calc_pack)
ADD_SUBDIRECTORY(compare_calc_pack)

ADD_EXECUTABLE(YOUR_EXECUTABLE ...) #YOUR_EXECUTABLE是你想编译的可执行文件名；...为该可执行文件依赖的你编写的所有源文件
TARGET_LINK_LIBRARIES(YOUR_EXECUTABLE Lib Basic_Calc_Pack Advanced_Calc_Pack Compare_Calc_Pack)
#如果你要生成多个可执行文件，请多次使用以上两行语句
```