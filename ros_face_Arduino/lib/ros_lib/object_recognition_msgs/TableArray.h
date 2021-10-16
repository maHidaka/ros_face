#ifndef _ROS_object_recognition_msgs_TableArray_h
#define _ROS_object_recognition_msgs_TableArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "object_recognition_msgs/Table.h"

namespace object_recognition_msgs
{

  class TableArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t tables_length;
      typedef object_recognition_msgs::Table _tables_type;
      _tables_type st_tables;
      _tables_type * tables;

    TableArray():
      header(),
      tables_length(0), tables(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->tables_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tables_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tables_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tables_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tables_length);
      for( uint32_t i = 0; i < tables_length; i++){
      offset += this->tables[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t tables_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tables_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tables_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tables_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tables_length);
      if(tables_lengthT > tables_length)
        this->tables = (object_recognition_msgs::Table*)realloc(this->tables, tables_lengthT * sizeof(object_recognition_msgs::Table));
      tables_length = tables_lengthT;
      for( uint32_t i = 0; i < tables_length; i++){
      offset += this->st_tables.deserialize(inbuffer + offset);
        memcpy( &(this->tables[i]), &(this->st_tables), sizeof(object_recognition_msgs::Table));
      }
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/TableArray"; };
    const char * getMD5(){ return "d1c853e5acd0ed273eb6682dc01ab428"; };

  };

}
#endif
