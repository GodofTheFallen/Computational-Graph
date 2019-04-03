CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(Computational-Graph)

FILE(GLOB Computational-Graph-SRC
        "*.h"
        "*.cpp"
        )

ADD_EXECUTABLE(main ${Computational-Graph-SRC})