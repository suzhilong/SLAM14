cmake_minimum_required(VERSION 2.8)

project(ch5)

set(CMAKE_BUILD_TYPE "Debug")
#添加 c++11 标准支持
set(CMAKE_CXX_FLAGS "-std=c++11")

#寻找OpenCV库
find_package( OpenCV REQUIRED)
#添加头文件
include_directories( ${OpenCV_INCLUDE_DIRS} )

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )

#pcl
find_package( PCL REQUIRED COMPONENT common io )
include_directories(  ${PCL_INCLUDE_DIRS} )
add_definitions( ${PCL_DEFINITIONS} )
list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")

#Eigen
include_directories( "/usr/include/eigen3" )

#Pangolin
find_package(Pangolin REQUIRED) #P要大写
include_directories(${Pangolin_INCLUDE_DIRS})

add_executable( undistort_image undistort_image.cpp )
target_link_libraries( undistort_image ${OpenCV_LIBS} )

add_executable( disparity disparity.cpp )
target_link_libraries( disparity ${OpenCV_LIBS} ${PCL_LIBRARIES} ${Pangolin_LIBRARIES} )

add_executable( gaussnewton gaussnewton.cpp )
target_link_libraries( gaussnewton ${OpenCV_LIBS} )