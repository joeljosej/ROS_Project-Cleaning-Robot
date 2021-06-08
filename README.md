# ROS_Project
This is a turtlesim based ROS project

In this project a turtle makes the space dirty while moving and another turtle cleans the space by following it.

Commands are

Clone this package to turtle_prj folder

catkin_ws$ mkdir -p /src/turtle_prj

catkin_ws$ catkin build

catkin_ws$ roscore

catkin_ws$ rosrun turtlesim turtlesim_node

catkin_ws$ rosrun turtle_prj turtle_prj_node

catkin_ws$ rosrun turtlesim turtle_teleop_key

Let all commands be executed in individual windows

![turtle_prj_01](https://user-images.githubusercontent.com/81626993/121247342-c4250000-c8bf-11eb-9a34-afd12741d536.png)

Node graph of this project is given as follows

![ros_node_graph](https://user-images.githubusercontent.com/81626993/121247770-40b7de80-c8c0-11eb-8ed7-d08e979d1563.png)

