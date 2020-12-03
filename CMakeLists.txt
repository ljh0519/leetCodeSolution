cmake_minimum_required(VERSION 2.8)
project(leetCodeSolution)

if (CMAKE_VERSION VERSION_LESS "3.1")
    add_definitions(-std=c++14)
else ()
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif ()

if (APPLE) 
     set(CMAKE_MACOSX_RPATH ON) 
     set(CMAKE_SKIP_BUILD_RPATH TRUE) 
     set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
     set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE) 
endif () 

include_directories(src)
include_directories(list)

set(STRUCT_UTIL_SOURCE
    src/listUtil.hpp
    src/treeUtil.hpp
    src/vectorUtil.hpp
    src/solution.cpp
    src/solution.hpp
    src/timer.hpp)

add_library(struct_core_static STATIC ${STRUCT_UTIL_SOURCE})

link_libraries(struct_core_static)

add_executable(leetCodeSolution
    main.cpp
    )

# target_link_libraries(leetCodeSolution
#     ${THIZ_LIBRARIES}
#     # ${BRIDGE_LIB}
#     )