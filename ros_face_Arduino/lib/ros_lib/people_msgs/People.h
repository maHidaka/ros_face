#ifndef _ROS_people_msgs_People_h
#define _ROS_people_msgs_People_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "people_msgs/Person.h"

namespace people_msgs
{

  class People : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t people_length;
      typedef people_msgs::Person _people_type;
      _people_type st_people;
      _people_type * people;

    People():
      header(),
      people_length(0), people(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->people_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->people_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->people_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->people_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->people_length);
      for( uint32_t i = 0; i < people_length; i++){
      offset += this->people[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t people_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      people_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      people_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      people_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->people_length);
      if(people_lengthT > people_length)
        this->people = (people_msgs::Person*)realloc(this->people, people_lengthT * sizeof(people_msgs::Person));
      people_length = people_lengthT;
      for( uint32_t i = 0; i < people_length; i++){
      offset += this->st_people.deserialize(inbuffer + offset);
        memcpy( &(this->people[i]), &(this->st_people), sizeof(people_msgs::Person));
      }
     return offset;
    }

    const char * getType(){ return "people_msgs/People"; };
    const char * getMD5(){ return "18722f4b8db20cc2369740732357847b"; };

  };

}
#endif
