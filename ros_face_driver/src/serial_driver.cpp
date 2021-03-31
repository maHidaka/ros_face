#include "ros/ros.h"
#include "std_msgs/String.h"

#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int open_serial(const char *device_name)
{
    int fd = open(device_name, O_RDWR | O_NOCTTY | O_NONBLOCK); //デバイス名, 読み書き権限｜制御端末にならない設定｜可能ならば非停止
    fcntl(fd, F_SETFL, 0);                                      //ファイルディスクリプタfdのファイルステータスフラグを0に設定
    //load configuration
    struct termios conf_tio;  //termiosの構造体宣言
    tcgetattr(fd, &conf_tio); //termptrが指すメモリー位置に端末の制御情報を保管
    //set baudrate
    speed_t BAUDRATE = B115200; //ボーレート
    cfsetispeed(&conf_tio, BAUDRATE);
    cfsetospeed(&conf_tio, BAUDRATE);
    //非カノニカルモード
    conf_tio.c_lflag &= ~(ECHO | ICANON); //ICANONはカノニカルモード
    //ポーリングリード
    conf_tio.c_cc[VMIN] = 0;  //最小文字数
    conf_tio.c_cc[VTIME] = 0; //タイムアウト時間
    //store configuration
    tcsetattr(fd, TCSANOW, &conf_tio);
    return fd;
}

int fd;
void serial_callback(const std_msgs::String &serial_msg)
{
    int rec = write(fd, serial_msg.data.c_str(), serial_msg.data.size());
    if (rec >= 0)
        printf("send:%s\n", serial_msg.data.c_str());
    else
    {
        ROS_ERROR_ONCE("Serial Fail: cound not write");
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "s4_comport_serialport");
    ros::NodeHandle n;

    //Publisher
    ros::Publisher serial_pub = n.advertise<std_msgs::String>("Serial_in", 1000);

    //Subscriber
    ros::Subscriber serial_sub = n.subscribe("Serial_out", 10, serial_callback);

    char device_name[] = "/dev/ttyACM0";
    fd = open_serial(device_name);
    if (fd < 0)
    {
        ROS_ERROR("Serial Fail: cound not open %s", device_name);
        printf("Serial Fail\n");
        ros::shutdown();
    }

    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        char buf[256] = {0};
        int recv_data = read(fd, buf, sizeof(buf));
        if (recv_data > 0)
        {
            printf("recv:%03d %s\n", recv_data, buf);
            std_msgs::String serial_msg;
            serial_msg.data = buf;
            serial_pub.publish(serial_msg);
        }
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}