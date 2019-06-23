CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(Computational-Graph)

ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(basic_calc_pack)
ADD_SUBDIRECTORY(advanced_calc_pack)
ADD_SUBDIRECTORY(compare_calc_pack)

#AUX_SOURCE_DIRECTORY(. Computational-Graph-SRC)

ADD_EXECUTABLE(main1 main1.cpp)
TARGET_LINK_LIBRARIES(main1 Lib Basic_Calc_Pack Advanced_Calc_Pack Compare_Calc_Pack)
ADD_EXECUTABLE(main2 main2.cpp)
TARGET_LINK_LIBRARIES(main2 Lib Basic_Calc_Pack Advanced_Calc_Pack Compare_Calc_Pack)
ADD_EXECUTABLE(main3 main3.cpp)
TARGET_LINK_LIBRARIES(main3 Lib Basic_Calc_Pack Advanced_Calc_Pack Compare_Calc_Pack)
ADD_EXECUTABLE(main4 main4.cpp)
TARGET_LINK_LIBRARIES(main4 Lib Basic_Calc_Pack Advanced_Calc_Pack Compare_Calc_Pack)