#include "ros/ros.h"
#include "std_msgs/String.h"

class BaseDriver{
	private:
		ros::NodeHandle n;
		ros::Publisher pub;
		ros::Subscriber sub;
		std_msgs::String send_cmd;
	public:
		BaseDriver();
		void Publication(std_msgs::String buf);
		void Callback(const std_msgs::String &cmd);
};

BaseDriver::BaseDriver()
{
	pub = n.advertise<std_msgs::String>("Serial_out", 10);
	sub = n.subscribe("face_cmd", 10, &BaseDriver::Callback, this);
}


void BaseDriver::Publication(std_msgs::String buf)
{
	send_cmd.data = buf.data;
    printf("pub:%s\n", send_cmd.data.c_str());
	pub.publish(send_cmd);
}


void BaseDriver::Callback(const std_msgs::String &cmd)
{
	printf("sub:%s\n", cmd.data.c_str());
    BaseDriver::Publication(cmd);
}


int main(int argc, char**argv)
{
	ros::init(argc, argv, "base_driver");
	
	BaseDriver base_driver;

	ros::Rate loop_rate(100);
	while(ros::ok()){
		
        ros::spinOnce();
		loop_rate.sleep();
	}
}