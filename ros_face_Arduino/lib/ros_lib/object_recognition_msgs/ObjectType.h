#ifndef _ROS_object_recognition_msgs_ObjectType_h
#define _ROS_object_recognition_msgs_ObjectType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace object_recognition_msgs
{

  class ObjectType : public ros::Msg
  {
    public:
      typedef const char* _key_type;
      _key_type key;
      typedef const char* _db_type;
      _db_type db;

    ObjectType():
      key(""),
      db("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_key = strlen(this->key);
      varToArr(outbuffer + offset, length_key);
      offset += 4;
      memcpy(outbuffer + offset, this->key, length_key);
      offset += length_key;
      uint32_t length_db = strlen(this->db);
      varToArr(outbuffer + offset, length_db);
      offset += 4;
      memcpy(outbuffer + offset, this->db, length_db);
      offset += length_db;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_key;
      arrToVar(length_key, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_key; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_key-1]=0;
      this->key = (char *)(inbuffer + offset-1);
      offset += length_key;
      uint32_t length_db;
      arrToVar(length_db, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_db; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_db-1]=0;
      this->db = (char *)(inbuffer + offset-1);
      offset += length_db;
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/ObjectType"; };
    const char * getMD5(){ return "ac757ec5be1998b0167e7efcda79e3cf"; };

  };

}
#endif
