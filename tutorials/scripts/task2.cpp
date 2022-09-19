#include "ros/ros.h"
#include "std_msgs/Float64.h"

#include <math.h>

std_msgs::Float64 current_state;
std_msgs::Float64 new_state, volt_now;

int task_num;

void callback(const std_msgs::Float64::ConstPtr& msg){
 ROS_INFO("I heard: [%f]", msg->data);
 new_state.data = msg->data;
}

int main(int argc, char **argv){

ros::init(argc,argv,"rotate");

ros::NodeHandle n;

ros::Subscriber sub = n.subscribe("/new_pos", 100, callback);
ros::Publisher pub_end = n.advertise<std_msgs::Float64>("/end/command", 100);

ros::Rate loop_rate(10);

//ros::Time startTime = ros::Time::now();

current_state.data = -2;
volt_now.data = 0;

while(ros::ok()){
        //std_msgs::Float64 msg_to_send;
        task_num = 2;

        if ( task_num == 1 && (new_state.data > current_state.data)){
                pub.publish(new_state);
                current_state.data = new_state.data;
        }

        if ( task_num == 2){
            if(volt_now.data == 0){
                pub_end.publish(1);
                sleep(5);
                volt_now.data = 1;
                ROS_INFO("it is moving to 1");
            }else{
                pub_end.publish(0);
                sleep(5);
                volt_now.data = 0;
                ROS_INFO("it is moving to 0");
            }


        }



        ros::spinOnce();

        loop_rate.sleep();

        }
}
