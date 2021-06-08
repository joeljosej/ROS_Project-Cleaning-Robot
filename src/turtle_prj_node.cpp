#include <ros/ros.h>
#include <ros/topic.h>

#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <turtlesim/Color.h>
#include <turtlesim/TeleportAbsolute.h>

// Service includes
#include <std_srvs/Empty.h>
#include <turtlesim/Spawn.h>
#include <turtlesim/SetPen.h>
#include <math.h>

void setPoseAbs(double x, double y, double theta)
{
    turtlesim::TeleportAbsolute pose_abs;
    pose_abs.request.x = x;
    pose_abs.request.y = y;
    pose_abs.request.theta = theta;    
    ROS_INFO("Set Absolute Pose (x, y, theta) = (%f, %f, %f)", x, y, theta);
    turtlesim::TeleportAbsolute tpa;
    tpa.request.x = x;
    tpa.request.y = y;
    tpa.request.theta = theta;
    ros::service::call<turtlesim::TeleportAbsolute>("/turtle2/teleport_absolute", tpa);
    
}
void poseCallback(const turtlesim::PoseConstPtr& pose)
{
   ROS_INFO("INSIDE poseCallback function"); 	
   setPoseAbs(pose->x,pose->y,pose->theta);
    
}
void spawnPlayerTurtle(std::string name, double x, double y, double theta)
{
    int r,g,b;
    ROS_INFO("Spawn %s", name.c_str());
    turtlesim::Spawn spawn;
    spawn.request.name = name.c_str();
    spawn.request.x = x;
    spawn.request.y = y;
    spawn.request.theta = theta;
    ros::service::call<turtlesim::Spawn>("/spawn", spawn);
    
    turtlesim::SetPen set_pen;
    set_pen.request.width = 25;
    ros::param::get("/turtlesim/background_b", b);
    ros::param::get("/turtlesim/background_g", g);
    ros::param::get("/turtlesim/background_r", r);
    set_pen.request.r = r;
    set_pen.request.g = g;
    set_pen.request.b = b;
    set_pen.request.off = false;
    std::string service_name = "/" + name + "/set_pen";
    ros::service::call(service_name, set_pen);
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "Robot_cleaner");
    ros::NodeHandle nh;

    ROS_INFO("Reset and spawn another turtle");
    std_srvs::Empty empty;
    ros::service::call<std_srvs::Empty>("/reset", empty);
    spawnPlayerTurtle("turtle2", 1.0, 5.0, 0.0);
    ros::Subscriber turtle1_pos_sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 20, poseCallback);
    ros::Rate loop_rate(1);

    while (ros::ok())
    {
    	
        loop_rate.sleep();

        ros::spinOnce();
    }
    
}
