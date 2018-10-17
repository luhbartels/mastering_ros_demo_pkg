#include "ros/ros.h"
#include "mastering_ros_demo_pkg/demo_msg.h"
#include <iostream>

void msgs_callback(const mastering_ros_demo_pkg::demo_msg::ConstPtr& msg)
{
	ROS_INFO("Received [%d]", msg->number);
	ROS_INFO_STREAM(msg->greeting);
}

int main (int argc, char **argv)
{
	ros::init(argc, argv, "demo_msg_subscriber");
	ros::NodeHandle node_obj;
	ros::Subscriber msg_subscriber = node_obj.subscribe("/demo_msg_topic", 10, msgs_callback);
	ros::spin();
	return 0;
}