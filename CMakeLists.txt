cmake_minimum_required(VERSION 3.4)
project(sara_shield_utils)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf2
  tf2_ros
  visualization_msgs
  geometry_msgs
  sensor_msgs
)


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES pose_verification
  CATKIN_DEPENDS
    roscpp
    tf2
    tf2_ros
    visualization_msgs
    geometry_msgs
    sensor_msgs
)

add_executable(motion_node
  src/motion_node.cc
)

add_dependencies(motion_node
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(motion_node PUBLIC
  ${catkin_LIBRARIES}
)

target_include_directories(motion_node SYSTEM PUBLIC
  ${catkin_INCLUDE_DIRS}
)

target_include_directories(motion_node PUBLIC
  include
)


add_executable(drive_to_position
  src/drive_to_position.cc
)

add_dependencies(drive_to_position
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(drive_to_position PUBLIC
  ${catkin_LIBRARIES}
)

target_include_directories(drive_to_position SYSTEM PUBLIC
  ${catkin_INCLUDE_DIRS}
)

target_include_directories(drive_to_position PUBLIC
  include
)

