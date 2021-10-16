#ifndef _ROS_geographic_msgs_GeographicMapChanges_h
#define _ROS_geographic_msgs_GeographicMapChanges_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geographic_msgs/GeographicMap.h"
#include "uuid_msgs/UniqueID.h"

namespace geographic_msgs
{

  class GeographicMapChanges : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geographic_msgs::GeographicMap _diffs_type;
      _diffs_type diffs;
      uint32_t deletes_length;
      typedef uuid_msgs::UniqueID _deletes_type;
      _deletes_type st_deletes;
      _deletes_type * deletes;

    GeographicMapChanges():
      header(),
      diffs(),
      deletes_length(0), deletes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->diffs.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->deletes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->deletes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->deletes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->deletes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deletes_length);
      for( uint32_t i = 0; i < deletes_length; i++){
      offset += this->deletes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->diffs.deserialize(inbuffer + offset);
      uint32_t deletes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      deletes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      deletes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      deletes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->deletes_length);
      if(deletes_lengthT > deletes_length)
        this->deletes = (uuid_msgs::UniqueID*)realloc(this->deletes, deletes_lengthT * sizeof(uuid_msgs::UniqueID));
      deletes_length = deletes_lengthT;
      for( uint32_t i = 0; i < deletes_length; i++){
      offset += this->st_deletes.deserialize(inbuffer + offset);
        memcpy( &(this->deletes[i]), &(this->st_deletes), sizeof(uuid_msgs::UniqueID));
      }
     return offset;
    }

    const char * getType(){ return "geographic_msgs/GeographicMapChanges"; };
    const char * getMD5(){ return "4fd027f54298203ec12aa1c4b20e6cb8"; };

  };

}
#endif
