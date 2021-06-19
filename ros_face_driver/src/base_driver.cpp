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
	std_msgs::String setdata;
	std_msgs::String format(ros_face_msgs::FaceCmd pre);

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

//受け取ったface_cmdデータをSerial_outの形式に変換する
std_msgs::String BaseDriver::format(ros_face_msgs::FaceCmd predata)
{
	setdata = std_msgs::String(predata.ch1);
	return setdata;
}

//トピックSerial_outをパブリッシュする処理
void BaseDriver::Publication(std_msgs::String buf)
{
	send_cmd = buf;
	printf("pub:%s\n", send_cmd.data.c_str());
	pub.publish(send_cmd);
}

//face_cmdトピックが更新されたら呼ばれるコールバック関数
void BaseDriver::Callback(const ros_face_msgs::FaceCmd recieve_cmd)
{
	//printf("soiya\n");
	//printf("%d\n", recieve_cmd.ch1.mode);
	std_msgs::String tmp;
	tmp = BaseDriver::format(recieve_cmd);
	BaseDriver::Publication(tmp);
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