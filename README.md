# ROBT 403: Laboratory

## Laboratory 3 
### Task 0 - Prerequisites [The 5 DOF planar robot packages were downloaded and compiled.]

The project was implemented on Ubuntu 18.04.6 LTS machine with ROS Melodic. To be able to run the project, the following package must be installed (for ros-melodic):

  - git clone [https://github.com/KNurlanZ/snake-noetic.git](https://github.com/KNurlanZ/snake-noetic.git)

#### The Planar Robot 

![Screenshot from 2022-09-19 17-37-46](https://user-images.githubusercontent.com/38093116/191009069-46c30621-b5c7-406c-ab96-3687db1c58d4.png)

To get started with the Planar Robot: 

### Task 1 - Move a joint of the planar robot
"Create a rosnode that will “listen” for std_msgs/Float64 type data and “publish” this data to the joint of the planar robot. The node should send the command to move if the any new incoming value is higher than the previous one"

### Screenshot Demo: Task 1

![Lab3_Task1](https://user-images.githubusercontent.com/38093116/191019623-1964f711-a30c-46e3-9a59-623d698141a2.png)

### Task 2 - Get the step response
"Get the step response of (you can create a node that will send a square-wave function):

1. the joint at the base of the robot 

2. the joint at the end-effector of the robot"

### Screenshot Demo: Task 2
**Step response plot of the end-effector joint**

Here is the step response for the end joint. As it is visible in the step response plot, the current position is following the goal position with a delay. The reason for that is the goal position changes instantly from 0 to 1 or from 1 to 0 and the velocity of the real robot cannot be infinite. Therefore, we can see the delay in the joint movement. 

![Lab3_Task2_StepResponse_EndJoint](https://user-images.githubusercontent.com/38093116/191019690-93a62df0-6ef9-4f89-9dfa-9886aae017fa.png)

**Step response plot of the start joint**

In comparison, here is the step response for base joint.  As we look at the step response plot of the joint at the robot’s start (base) joint, the error gaps become visibly bigger compared to the end-effector joint. This happens due to the difference in the mass: in the position of the base joint, the mass is heavier, thus the response is slower; while the mass in the end joint is more lightweight and the response is faster. 

![Lab3_Task2_StepResponse_BaseJoint](https://user-images.githubusercontent.com/38093116/191019697-5098343f-fda0-4e75-9db1-c217249b627a.png)



### Task 3 - Get the sine wave response of joints
"Get the sine-wave response of (you can create a node that will send a sine-wave
function):
1. the joint at the base of the robot!

2. the joint at the end-effector of the robot"

**Sine function on end joint response graph**

![Lab3_Task3_SineResponse_EndJoint](https://user-images.githubusercontent.com/38093116/191019723-5ff0b2fe-386e-4862-81f9-b18344b1bb58.png)

**Sine function on start joint response graph**

![Lab3_Task3_SineResponse_StartJoint](https://user-images.githubusercontent.com/38093116/191019731-1d5a340e-ecf4-4176-912b-1479897292d8.png)

Comparing these two graphs, we can see that current position is closer to goal position on end joint due to joint having to move lower weight. However, the difference are not as drastical as in the step response graph

### Lab 3 Video: Tasks 1-3:
  The following two image links direct to the video demo of working snake robot and code explanation for each task.
#### Demo of the robot (click on the image):
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/PnbofYthCl8/0.jpg)](https://www.youtube.com/watch?v=PnbofYthCl8)

#### Explanation of the code (click on the image):
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/PwkaDWMSovA/0.jpg)](https://www.youtube.com/watch?v=PwkaDWMSovA)
