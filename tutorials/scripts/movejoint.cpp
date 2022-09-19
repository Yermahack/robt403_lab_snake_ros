#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <math.h>
#include <iostream>
using namespace std;

std_msgs::Float64 current_state;
std_msgs::Float64 new_state, volt_now, task_num, joint_num;

void callback(const std_msgs::Float64::ConstPtr& msg){
 ROS_INFO("I heard: [%f]", msg->data);
 new_state.data = msg->data;
}

int main(int argc, char **argv){

ros::init(argc,argv,"rotate");

ros::NodeHandle n;

ros::Subscriber sub = n.subscribe("/new_pos", 100, callback);
ros::Publisher pub_start = n.advertise<std_msgs::Float64>("/motortom2m/command", 100);
ros::Publisher pub_end = n.advertise<std_msgs::Float64>("/end/command", 100);
ros::Publisher pub_j6 = n.advertise<std_msgs::Float64>("/joint6/command", 100);
ros::Publisher pub_j4 = n.advertise<std_msgs::Float64>("/joint4/command", 100);
ros::Publisher pub_j2 = n.advertise<std_msgs::Float64>("/joint2/command", 100);
ros::Rate loop_rate(10);

ros::Time startTime = ros::Time::now();

current_state.data = -2;
volt_now.data = -1.1;
task_num.data = 3;

joint_num.data = 1;

while(ros::ok()){
        //std_msgs::Float64 msg_to_send;


        if ( task_num.data == 1.0 && (new_state.data > current_state.data)){
                pub_start.publish(new_state);
                current_state.data = new_state.data;
        }

        if ( task_num.data == 2.0){
            if(volt_now.data == -1.1){
                new_state.data = 0.5;
                pub_start.publish(new_state);
                sleep(2);
                volt_now.data = 0.5;
                ROS_INFO("it is moving to 0.5");
            }else{
                new_state.data = -1.1;
                pub_start.publish(new_state);
                sleep(2);
                volt_now.data = -1.1;
                ROS_INFO("it is moving to -1.1");
            }
         }

        if ( task_num.data == 3.0){
            if(joint_num.data = 0){
//                std::cout <<" | seconds"<<std::endl;
                double secs =ros::Time::now().toSec();

                new_state.data = 0.5 * sin(2 * 3.14 * 0.5 * secs ) - 1;
                std::cout <<new_state.data<<std::endl;
                pub_start.publish(new_state);
            }
            if(joint_num.data = 1){
//                std::cout <<" | seconds"<<std::endl;
                double secs = ros::Time::now().toSec();

                new_state.data = 0.5 * sin(2 * 3.14 * 0.5 * secs);
                std::cout <<new_state.data<<std::endl;
                pub_end.publish(new_state);
            }


        }

//        double secs =ros::Time::now().toSec();

//        new_state.data = 0.5 * sin(2 * 3.14 * 0.5 * secs ) - 1;
//        std::cout <<new_state.data<<std::endl;
//        pub_start.publish(new_state);

//        new_state.data = - 1.5 * sin(2 * 3.14 * 0.5 * secs);
//        std::cout <<new_state.data<<std::endl;
//        pub_end.publish(new_state);

//        new_state.data =  0.5 * sin(2 * 3.14 * 0.5 * secs);
//        std::cout <<new_state.data<<std::endl;
//        pub_j6.publish(new_state);

//        new_state.data = - 1.5 * sin(2 * 3.14 * 0.5 * secs);
//        std::cout <<new_state.data<<std::endl;
//        pub_j4.publish(new_state);

//        new_state.data = 1.2 * sin(2 * 3.14 * 0.25 * secs)-1;
//        std::cout <<new_state.data<<std::endl;
//        pub_j2.publish(new_state);


        ros::spinOnce();

        loop_rate.sleep();

        }
}
