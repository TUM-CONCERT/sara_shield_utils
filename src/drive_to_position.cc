#include <ros/node_handle.h>

#include <array>
#include <string>
#include <vector>

#include <ros/node_handle.h>
#include <ros/time.h>
#include <std_msgs/Float32MultiArray.h>

int main(int argc, char * argv[])
{
    ros::init(argc, argv, "motion_node");

    ros::NodeHandle nh("~");

    ros::Publisher target_joint_pos_publisher = nh.advertise<std_msgs::Float32MultiArray>("/sara_shield/goal_joint_pos", 100);

    ros::Duration delay(0.3);

    delay.sleep();

    //int numExistingSubscribers = target_joint_pos_publisher.getNumSubscribers();

    //while(numExistingSubscribers==0)
    //{
    //    poll_rate.sleep();
    //}

    // Now the publisher is ready

    std::vector<float> joint_position ={ 0.0, 0.46, 0.003, 2.019, 0.0046, -1.46};

    std_msgs::Float32MultiArray goal_joint_position;
    goal_joint_position.data = joint_position;
    target_joint_pos_publisher.publish(goal_joint_position);
}