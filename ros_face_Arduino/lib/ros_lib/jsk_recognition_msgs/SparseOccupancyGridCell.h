#ifndef _ROS_jsk_recognition_msgs_SparseOccupancyGridCell_h
#define _ROS_jsk_recognition_msgs_SparseOccupancyGridCell_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

  class SparseOccupancyGridCell : public ros::Msg
  {
    public:
      typedef int32_t _row_index_type;
      _row_index_type row_index;
      typedef float _value_type;
      _value_type value;

    SparseOccupancyGridCell():
      row_index(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_row_index;
      u_row_index.real = this->row_index;
      *(outbuffer + offset + 0) = (u_row_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_row_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_row_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_row_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->row_index);
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_row_index;
      u_row_index.base = 0;
      u_row_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_row_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_row_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_row_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->row_index = u_row_index.real;
      offset += sizeof(this->row_index);
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SparseOccupancyGridCell"; };
    const char * getMD5(){ return "a5179e922852f82ee6322db1f097ab64"; };

  };

}
#endif
