#include <ros.h>
#include <ros_face_msgs/FaceCmd.h>
#include <ros_face_msgs/Ch.h>



#define topic_period 0.5f
#define main_period 0.025f
#define enable_time 2
ros::NodeHandle  nh;


void disable(){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
}

void Cb( const ros_face_msgs::FaceCmd& data){
    digitalWrite(13,true);

    for (float i = 0; i <= topic_period; i=i+main_period){
        disable();
        if(data.ch1.time >= i)digitalWrite(2, data.ch1.state);
        if(data.ch2.time >= i)digitalWrite(3, data.ch2.state);
        if(data.ch3.time >= i)digitalWrite(4, data.ch3.state);
        if(data.ch4.time >= i)digitalWrite(5, data.ch4.state);
        if(data.ch5.time >= i)digitalWrite(6, data.ch5.state);
        if(data.ch6.time >= i)digitalWrite(7, data.ch6.state);
        if(data.ch7.time >= i)digitalWrite(8, data.ch7.state);
        if(data.ch8.time >= i)digitalWrite(9, data.ch8.state);
        if(data.ch9.time >= i)digitalWrite(10, data.ch9.state);
        if(data.ch10.time >= i)digitalWrite(11, data.ch10.state);

        delay(enable_time);
        disable();
        int buy_time = main_period - enable_time;
        delay(buy_time);
    }
    digitalWrite(13,false);
    disable();
}

ros::Subscriber<ros_face_msgs::FaceCmd> sub("face_cmd", Cb);


void setup()
{
    pinMode(13, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    nh.getHardware()->setBaud(115200);
    nh.initNode();
    nh.subscribe(sub);
}

void loop()
{
    nh.spinOnce();
    delay(50);
}