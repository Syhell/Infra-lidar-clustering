cmake_minimum_required(VERSION 3.8.0)
project(infra_lidar_clustering)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  pcl_ros
  geometry_msgs
  message_filters
  sensor_msgs
  itolab_senior_car_msgs
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O3 -Wall ${CMAKE_CXX_FLAGS}")
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

catkin_package(
INCLUDE_DIRS include  
CATKIN_DEPPENDS
  roscpp
  std_msgs
  geometry_msgs
  message_filters
  sensor_msgs
  itolab_senior_car_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp
  src/${PROJECT_NAME}_node.cpp
  src/${PROJECT_NAME}_node_main.cpp)

