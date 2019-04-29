CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(Computational-Graph)


ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(basic_calc_pack)
ADD_SUBDIRECTORY(advanced_calc_pack)
ADD_SUBDIRECTORY(compare_calc_pack)

AUX_SOURCE_DIRECTORY(. Computational-Graph-SRC)

ADD_EXECUTABLE(main ${Computational-Graph-SRC})
TARGET_LINK_LIBRARIES(main Lib Basic_Calc_Pack Advanced_Calc_Pack Compare_Calc_Pack)