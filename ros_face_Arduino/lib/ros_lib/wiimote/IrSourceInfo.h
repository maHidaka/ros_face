#ifndef _ROS_wiimote_IrSourceInfo_h
#define _ROS_wiimote_IrSourceInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wiimote
{

  class IrSourceInfo : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef int64_t _ir_size_type;
      _ir_size_type ir_size;

    IrSourceInfo():
      x(0),
      y(0),
      ir_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      union {
        int64_t real;
        uint64_t base;
      } u_ir_size;
      u_ir_size.real = this->ir_size;
      *(outbuffer + offset + 0) = (u_ir_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ir_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ir_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ir_size.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ir_size.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ir_size.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ir_size.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ir_size.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ir_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      union {
        int64_t real;
        uint64_t base;
      } u_ir_size;
      u_ir_size.base = 0;
      u_ir_size.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ir_size.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ir_size.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ir_size.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ir_size.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ir_size.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ir_size.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ir_size.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ir_size = u_ir_size.real;
      offset += sizeof(this->ir_size);
     return offset;
    }

    const char * getType(){ return "wiimote/IrSourceInfo"; };
    const char * getMD5(){ return "95274ca88b9f008b99984b9a61d2772e"; };

  };

}
#endif
