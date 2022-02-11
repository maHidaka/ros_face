#include <ros.h>
#include <ros_face_msgs/FaceCmd.h>
#include <ros_face_msgs/Ch.h>


#include <Arduino.h>
#include <Servo.h>



#define topic_period 0.5f
#define main_period 0.025f
#define enable_time 2
ros::NodeHandle  nh;



void Cb( const ros_face_msgs::FaceCmd& data){
    digitalWrite(13,true);
    servo.write();
    digitalWrite(13,false);
}

ros::Subscriber<ros_face_msgs::FaceCmd> sub("face_cmd", Cb);


void setup()
{
    pinMode(13, OUTPUT);
    servo.attach(2,10,100);
    nh.getHardware()->setBaud(115200);
    nh.initNode();
    nh.subscribe(sub);
}

void loop()
{
    nh.spinOnce();
    delay(1);
}