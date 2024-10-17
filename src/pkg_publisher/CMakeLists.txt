cmake_minimum_required(VERSION 3.0.2)
project(publisher2)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
   std_msgs
)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(publisher2 src/publisher2.cpp)

target_link_libraries(publisher2 
      ${catkin_LIBRARIES})cmake_minimum_required(VERSION 3.0.2)
project(publisher2)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  std_msgs
)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(publisher2 src/publisher2.cpp)

target_link_libraries(publisher2 
      ${catkin_LIBRARIES})
