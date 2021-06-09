# ROS_Project
This is a turtlesim based ROS project

In this project a turtle makes the space dirty while moving and another turtle cleans the space by following it.

It is basically a cleaning Robot . There are two turtles . 

One turtle makes the workspace dirty while moving and another turtle cleans the space by following the first turtle autonomously

Commands are

1) catkin_ws$ mkdir -p /src/turtle_prj           // This is the working directory

2)catkin_ws/src/turtle_prj $ git clone https://github.com/joeljosej/ROS_Project  //Clone this package contents to turtle_prj folder

3)Copy the contents of ROS_Project folder to turtle_prj folder

4)catkin_ws$ catkin build        // build the package and executable turtle_prj_node is created

5) catkin_ws$ roscore          // Run ROS Master

6) catkin_ws$ rosrun turtlesim turtlesim_node  //Run an instance of turtlesim node

7)catkin_ws$ rosrun turtle_prj turtle_prj_node // Run an instance of  turtle_prj node

8)catkin_ws$ rosrun turtlesim turtle_teleop_key  // Run teleop_key node to move the turtle1 

Let all commands be executed in individual windows

Screenshot of Turtle_prj Cleaner

![turtle_prj_01](https://user-images.githubusercontent.com/81626993/121247342-c4250000-c8bf-11eb-9a34-afd12741d536.png)

Node graph of this project is given as follows

![ros_node_graph](https://user-images.githubusercontent.com/81626993/121247770-40b7de80-c8c0-11eb-8ed7-d08e979d1563.png)

Animation of Turtle_prj Cleaner

![Turtle_prj_01](https://user-images.githubusercontent.com/81626993/121249090-cf792b00-c8c1-11eb-9c1c-bb5bd71d5e09.gif)


