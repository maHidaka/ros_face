#ifndef _ROS_jsk_recognition_msgs_SparseOccupancyGridArray_h
#define _ROS_jsk_recognition_msgs_SparseOccupancyGridArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/SparseOccupancyGrid.h"

namespace jsk_recognition_msgs
{

  class SparseOccupancyGridArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t grids_length;
      typedef jsk_recognition_msgs::SparseOccupancyGrid _grids_type;
      _grids_type st_grids;
      _grids_type * grids;

    SparseOccupancyGridArray():
      header(),
      grids_length(0), grids(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->grids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->grids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->grids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->grids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grids_length);
      for( uint32_t i = 0; i < grids_length; i++){
      offset += this->grids[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t grids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      grids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      grids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      grids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->grids_length);
      if(grids_lengthT > grids_length)
        this->grids = (jsk_recognition_msgs::SparseOccupancyGrid*)realloc(this->grids, grids_lengthT * sizeof(jsk_recognition_msgs::SparseOccupancyGrid));
      grids_length = grids_lengthT;
      for( uint32_t i = 0; i < grids_length; i++){
      offset += this->st_grids.deserialize(inbuffer + offset);
        memcpy( &(this->grids[i]), &(this->st_grids), sizeof(jsk_recognition_msgs::SparseOccupancyGrid));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SparseOccupancyGridArray"; };
    const char * getMD5(){ return "fa9a1f59b783128c759e159dd0c46731"; };

  };

}
#endif
