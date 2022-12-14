//#include <moveit/move_group_interface/move_group.h>
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_visual_tools/moveit_visual_tools.h>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle node_handle;
  // ros::Publisher chatter_pub = node_handle.advertise<std_msgs::Float64MultiArray>("end_pub",1000);
  ros::Publisher end_x = node_handle.advertise<std_msgs::Float64>("end_pub_x",1000);
  ros::Publisher end_y = node_handle.advertise<std_msgs::Float64>("end_pub_y",1000);

  ros::AsyncSpinner spinner(0);
  spinner.start(); // For moveit implementation we need AsyncSpinner, we cant use ros::spinOnce()
  static const std::string PLANNING_GROUP = "arm"; 
  /* Now we specify with what group we want work, here group1 is the name of my group controller*/
  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP); // loading move_group

  const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP); //For joint control
  geometry_msgs::PoseStamped current_pose;
  geometry_msgs::PoseStamped target_pose; // Pose in ROS is implemented using geometry_msgs::PoseStamped, google what is the type of this msg
  ros::Rate loop_rate(100); 

  while (ros::ok()){

    std_msgs::Float64 x_msg, y_msg;
    // x_y_msg.data.resize(2);
    
    current_pose = move_group.getCurrentPose();
    x_msg.data = current_pose.pose.position.x;
    y_msg.data = current_pose.pose.position.y;
    // x_y_msg.data[0] = current_pose.pose.position.x;
    // x_y_msg.data[1] = current_pose.pose.position.y;
    
    end_x.publish(x_msg);
    end_y.publish(y_msg);
    // ROS_INFO("%f; %f", x_y_msg.data[0], x_y_msg.data[1]);
    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("Done");
  ros::shutdown();
  return 0;
}
