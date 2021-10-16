#ifndef _ROS_ros_face_msgs_FaceCmd_h
#define _ROS_ros_face_msgs_FaceCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros_face_msgs/Ch.h"

namespace ros_face_msgs
{

  class FaceCmd : public ros::Msg
  {
    public:
      typedef ros_face_msgs::Ch _ch1_type;
      _ch1_type ch1;
      typedef ros_face_msgs::Ch _ch2_type;
      _ch2_type ch2;
      typedef ros_face_msgs::Ch _ch3_type;
      _ch3_type ch3;
      typedef ros_face_msgs::Ch _ch4_type;
      _ch4_type ch4;
      typedef ros_face_msgs::Ch _ch5_type;
      _ch5_type ch5;
      typedef ros_face_msgs::Ch _ch6_type;
      _ch6_type ch6;
      typedef ros_face_msgs::Ch _ch7_type;
      _ch7_type ch7;
      typedef ros_face_msgs::Ch _ch8_type;
      _ch8_type ch8;
      typedef ros_face_msgs::Ch _ch9_type;
      _ch9_type ch9;
      typedef ros_face_msgs::Ch _ch10_type;
      _ch10_type ch10;

    FaceCmd():
      ch1(),
      ch2(),
      ch3(),
      ch4(),
      ch5(),
      ch6(),
      ch7(),
      ch8(),
      ch9(),
      ch10()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->ch1.serialize(outbuffer + offset);
      offset += this->ch2.serialize(outbuffer + offset);
      offset += this->ch3.serialize(outbuffer + offset);
      offset += this->ch4.serialize(outbuffer + offset);
      offset += this->ch5.serialize(outbuffer + offset);
      offset += this->ch6.serialize(outbuffer + offset);
      offset += this->ch7.serialize(outbuffer + offset);
      offset += this->ch8.serialize(outbuffer + offset);
      offset += this->ch9.serialize(outbuffer + offset);
      offset += this->ch10.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->ch1.deserialize(inbuffer + offset);
      offset += this->ch2.deserialize(inbuffer + offset);
      offset += this->ch3.deserialize(inbuffer + offset);
      offset += this->ch4.deserialize(inbuffer + offset);
      offset += this->ch5.deserialize(inbuffer + offset);
      offset += this->ch6.deserialize(inbuffer + offset);
      offset += this->ch7.deserialize(inbuffer + offset);
      offset += this->ch8.deserialize(inbuffer + offset);
      offset += this->ch9.deserialize(inbuffer + offset);
      offset += this->ch10.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "ros_face_msgs/FaceCmd"; };
    const char * getMD5(){ return "0065dd40de5423c0414e7739813e1955"; };

  };

}
#endif
