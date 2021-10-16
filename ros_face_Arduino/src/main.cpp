#include <ros.h>
#include <ros_face_msgs/FaceCmd.h>
#include <ros_face_msgs/Ch.h>

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
    digitalWrite(13, LOW);
}

void Cb( const ros_face_msgs::FaceCmd& data){
    disable();
    digitalWrite(13,true);
    digitalWrite(2, data.ch2.state);
    digitalWrite(3, data.ch3.state);
    digitalWrite(4, data.ch4.state);
    digitalWrite(5, data.ch5.state);
    digitalWrite(6, data.ch6.state);
    digitalWrite(7, data.ch7.state);
    digitalWrite(8, data.ch8.state);
    digitalWrite(9, data.ch9.state);
    digitalWrite(10, data.ch10.state);
    digitalWrite(11, data.ch11.state);
    digitalWrite(12, data.ch12.state);


    delay(2);
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
    nh.initNode();
    nh.subscribe(sub);
}

void loop()
{
    nh.spinOnce();
    delay(500);
}