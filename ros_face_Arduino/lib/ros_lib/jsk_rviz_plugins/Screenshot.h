#ifndef _ROS_SERVICE_Screenshot_h
#define _ROS_SERVICE_Screenshot_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_rviz_plugins
{

static const char SCREENSHOT[] = "jsk_rviz_plugins/Screenshot";

  class ScreenshotRequest : public ros::Msg
  {
    public:
      typedef const char* _file_name_type;
      _file_name_type file_name;

    ScreenshotRequest():
      file_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_file_name = strlen(this->file_name);
      varToArr(outbuffer + offset, length_file_name);
      offset += 4;
      memcpy(outbuffer + offset, this->file_name, length_file_name);
      offset += length_file_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_file_name;
      arrToVar(length_file_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_name-1]=0;
      this->file_name = (char *)(inbuffer + offset-1);
      offset += length_file_name;
     return offset;
    }

    const char * getType(){ return SCREENSHOT; };
    const char * getMD5(){ return "2415261c9605b9f38867ffbbe495fc04"; };

  };

  class ScreenshotResponse : public ros::Msg
  {
    public:

    ScreenshotResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SCREENSHOT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Screenshot {
    public:
    typedef ScreenshotRequest Request;
    typedef ScreenshotResponse Response;
  };

}
#endif
