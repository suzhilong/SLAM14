cmake_minimum_required( VERSION 2.8 )
project( ch3Hw )

set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-O3" )

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )

# in osx and brew install
# include_directories( /usr/local/Cellar/eigen/3.3.3/include/eigen3 )

add_executable (sloveFun sloveFun.cpp )

add_executable (useQuaternion useQuaternion.cpp)
