#ifndef _ROS_moveit_msgs_ContactInformation_h
#define _ROS_moveit_msgs_ContactInformation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace moveit_msgs
{

  class ContactInformation : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef geometry_msgs::Vector3 _normal_type;
      _normal_type normal;
      typedef float _depth_type;
      _depth_type depth;
      typedef const char* _contact_body_1_type;
      _contact_body_1_type contact_body_1;
      typedef uint32_t _body_type_1_type;
      _body_type_1_type body_type_1;
      typedef const char* _contact_body_2_type;
      _contact_body_2_type contact_body_2;
      typedef uint32_t _body_type_2_type;
      _body_type_2_type body_type_2;
      enum { ROBOT_LINK = 0 };
      enum { WORLD_OBJECT = 1 };
      enum { ROBOT_ATTACHED = 2 };

    ContactInformation():
      header(),
      position(),
      normal(),
      depth(0),
      contact_body_1(""),
      body_type_1(0),
      contact_body_2(""),
      body_type_2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->normal.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->depth);
      uint32_t length_contact_body_1 = strlen(this->contact_body_1);
      varToArr(outbuffer + offset, length_contact_body_1);
      offset += 4;
      memcpy(outbuffer + offset, this->contact_body_1, length_contact_body_1);
      offset += length_contact_body_1;
      *(outbuffer + offset + 0) = (this->body_type_1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->body_type_1 >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->body_type_1 >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->body_type_1 >> (8 * 3)) & 0xFF;
      offset += sizeof(this->body_type_1);
      uint32_t length_contact_body_2 = strlen(this->contact_body_2);
      varToArr(outbuffer + offset, length_contact_body_2);
      offset += 4;
      memcpy(outbuffer + offset, this->contact_body_2, length_contact_body_2);
      offset += length_contact_body_2;
      *(outbuffer + offset + 0) = (this->body_type_2 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->body_type_2 >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->body_type_2 >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->body_type_2 >> (8 * 3)) & 0xFF;
      offset += sizeof(this->body_type_2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->normal.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->depth));
      uint32_t length_contact_body_1;
      arrToVar(length_contact_body_1, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_contact_body_1; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_contact_body_1-1]=0;
      this->contact_body_1 = (char *)(inbuffer + offset-1);
      offset += length_contact_body_1;
      this->body_type_1 =  ((uint32_t) (*(inbuffer + offset)));
      this->body_type_1 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->body_type_1 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->body_type_1 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->body_type_1);
      uint32_t length_contact_body_2;
      arrToVar(length_contact_body_2, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_contact_body_2; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_contact_body_2-1]=0;
      this->contact_body_2 = (char *)(inbuffer + offset-1);
      offset += length_contact_body_2;
      this->body_type_2 =  ((uint32_t) (*(inbuffer + offset)));
      this->body_type_2 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->body_type_2 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->body_type_2 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->body_type_2);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/ContactInformation"; };
    const char * getMD5(){ return "116228ca08b0c286ec5ca32a50fdc17b"; };

  };

}
#endif
