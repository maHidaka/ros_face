#include <ros.h>
#include <ros_face_msgs/FaceCmd.h>
#include <ros_face_msgs/Ch.h>


#include <Arduino.h>
#include <Servo.h>


#define pulse_width 2400





#define pin1 2
#define pin2 3
#define pin3 4
#define pin4 5
#define pin5 6
#define pin6 7
#define pin7 8
#define pin8 9
#define pin9 10
#define pin10 11


ros::NodeHandle  nh;

Servo channel_1;
Servo channel_2;
Servo channel_3;
Servo channel_4;
Servo channel_5;
Servo channel_6;
Servo channel_7;
Servo channel_8;
Servo channel_9;
Servo channel_10;


void Cb( const ros_face_msgs::FaceCmd& data){
    if(data.ch1.state){
        channel_1.writeMicroseconds(pulse_width);
    }else{
        channel_1.writeMicroseconds(0);
    }

    if(data.ch2.state){
        channel_2.writeMicroseconds(pulse_width);
    }else{
        channel_2.writeMicroseconds(0);
    }

    if(data.ch3.state){
        channel_3.writeMicroseconds(pulse_width);
    }else{
        channel_3.writeMicroseconds(0);
    }

    if(data.ch4.state){
        channel_4.writeMicroseconds(pulse_width);
    }else{
        channel_4.writeMicroseconds(0);
    }

    if(data.ch5.state){
        channel_5.writeMicroseconds(pulse_width);
    }else{
        channel_5.writeMicroseconds(0);
    }

    if(data.ch6.state){
        channel_6.writeMicroseconds(pulse_width);
    }else{
        channel_6.writeMicroseconds(0);
    }

    if(data.ch7.state){
        channel_7.writeMicroseconds(pulse_width);
    }else{
        channel_7.writeMicroseconds(0);
    }

    if(data.ch8.state){
        channel_8.writeMicroseconds(pulse_width);
    }else{
        channel_8.writeMicroseconds(0);
    }

    if(data.ch9.state){
        channel_9.writeMicroseconds(pulse_width);
    }else{
        channel_9.writeMicroseconds(0);
    }

    if(data.ch10.state){
        channel_10.writeMicroseconds(pulse_width);
    }else{
        channel_10.writeMicroseconds(0);
    }

    delay(20);
}

ros::Subscriber<ros_face_msgs::FaceCmd> sub("face_cmd", Cb);


void setup()
{
    pinMode(13, OUTPUT);
    nh.getHardware()->setBaud(115200);
    nh.initNode();
    nh.subscribe(sub);
    channel_1.attach(pin1,40,2400);
    channel_2.attach(pin2,40,2400);
    channel_3.attach(pin3,40,2400);
    channel_4.attach(pin4,40,2400);
    channel_5.attach(pin5,40,2400);
    channel_6.attach(pin6,40,2400);
    channel_7.attach(pin7,40,2400);
    channel_8.attach(pin8,40,2400);
    channel_9.attach(pin9,40,2400);
    channel_10.attach(pin10,40,2400);
}

void loop()
{
    nh.spinOnce();
    delayMicroseconds(5);
}