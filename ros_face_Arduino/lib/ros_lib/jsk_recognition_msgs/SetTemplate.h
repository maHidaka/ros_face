#ifndef _ROS_SERVICE_SetTemplate_h
#define _ROS_SERVICE_SetTemplate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "geometry_msgs/Pose.h"

namespace jsk_recognition_msgs
{

static const char SETTEMPLATE[] = "jsk_recognition_msgs/SetTemplate";

  class SetTemplateRequest : public ros::Msg
  {
    public:
      typedef const char* _type_type;
      _type_type type;
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      typedef float _dimx_type;
      _dimx_type dimx;
      typedef float _dimy_type;
      _dimy_type dimy;
      typedef geometry_msgs::Pose _relativepose_type;
      _relativepose_type relativepose;
      typedef const char* _savefilename_type;
      _savefilename_type savefilename;

    SetTemplateRequest():
      type(""),
      image(),
      dimx(0),
      dimy(0),
      relativepose(),
      savefilename("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      offset += this->image.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_dimx;
      u_dimx.real = this->dimx;
      *(outbuffer + offset + 0) = (u_dimx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dimx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dimx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dimx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dimx);
      union {
        float real;
        uint32_t base;
      } u_dimy;
      u_dimy.real = this->dimy;
      *(outbuffer + offset + 0) = (u_dimy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dimy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dimy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dimy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dimy);
      offset += this->relativepose.serialize(outbuffer + offset);
      uint32_t length_savefilename = strlen(this->savefilename);
      varToArr(outbuffer + offset, length_savefilename);
      offset += 4;
      memcpy(outbuffer + offset, this->savefilename, length_savefilename);
      offset += length_savefilename;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      offset += this->image.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_dimx;
      u_dimx.base = 0;
      u_dimx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dimx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dimx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dimx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dimx = u_dimx.real;
      offset += sizeof(this->dimx);
      union {
        float real;
        uint32_t base;
      } u_dimy;
      u_dimy.base = 0;
      u_dimy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dimy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dimy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dimy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dimy = u_dimy.real;
      offset += sizeof(this->dimy);
      offset += this->relativepose.deserialize(inbuffer + offset);
      uint32_t length_savefilename;
      arrToVar(length_savefilename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_savefilename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_savefilename-1]=0;
      this->savefilename = (char *)(inbuffer + offset-1);
      offset += length_savefilename;
     return offset;
    }

    const char * getType(){ return SETTEMPLATE; };
    const char * getMD5(){ return "116fa80f27cbdfcd76d0b57a30ef79ec"; };

  };

  class SetTemplateResponse : public ros::Msg
  {
    public:

    SetTemplateResponse()
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

    const char * getType(){ return SETTEMPLATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetTemplate {
    public:
    typedef SetTemplateRequest Request;
    typedef SetTemplateResponse Response;
  };

}
#endif
