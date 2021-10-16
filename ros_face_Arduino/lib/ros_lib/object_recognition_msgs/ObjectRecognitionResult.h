#ifndef _ROS_object_recognition_msgs_ObjectRecognitionResult_h
#define _ROS_object_recognition_msgs_ObjectRecognitionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "object_recognition_msgs/RecognizedObjectArray.h"

namespace object_recognition_msgs
{

  class ObjectRecognitionResult : public ros::Msg
  {
    public:
      typedef object_recognition_msgs::RecognizedObjectArray _recognized_objects_type;
      _recognized_objects_type recognized_objects;

    ObjectRecognitionResult():
      recognized_objects()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->recognized_objects.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->recognized_objects.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/ObjectRecognitionResult"; };
    const char * getMD5(){ return "868e41288f9f8636e2b6c51f1af6aa9c"; };

  };

}
#endif
