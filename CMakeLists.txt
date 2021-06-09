cmake_minimum_required(VERSION 3.0.2)
project(turtle_prj)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES turtle_prj
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)


include_directories(
include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/turtle_prj_node.cpp)

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
 )


