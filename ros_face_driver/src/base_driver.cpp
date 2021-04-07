#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ros_face_msgs/FaceCmd.h"
#include "ros_face_msgs/Ch.h"

class BaseDriver
{
private:
	ros::NodeHandle n;
	ros::Publisher pub;
	ros::Subscriber sub;
	std_msgs::String send_cmd;

public:
	BaseDriver();
	void Publication(std_msgs::String buf);
	void Callback(const ros_face_msgs::FaceCmd recieve_cmd);
};

BaseDriver::BaseDriver()
{
	pub = n.advertise<std_msgs::String>("Serial_out", 100);
	sub = n.subscribe("face_cmd", 100, &BaseDriver::Callback, this);
}

void BaseDriver::Publication(std_msgs::String buf)
{
	send_cmd = buf;
	printf("pub:%s\n", send_cmd.data.c_str());
	pub.publish(send_cmd);
}

void BaseDriver::Callback(const ros_face_msgs::FaceCmd recieve_cmd)
{
	/*
	printf("sub:%s\n", recieve_cmd..c_str());
    BaseDriver::Publication(recieve_cmd);
	*/

    printf("soiya\n");
    printf("%d\n",recieve_cmd.ch1.mode);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "base_driver");

	BaseDriver base_driver;

	ros::Rate loop_rate(100);
	while (ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}
}