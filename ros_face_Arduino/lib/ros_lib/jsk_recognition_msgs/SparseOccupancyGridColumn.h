#ifndef _ROS_jsk_recognition_msgs_SparseOccupancyGridColumn_h
#define _ROS_jsk_recognition_msgs_SparseOccupancyGridColumn_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/SparseOccupancyGridCell.h"

namespace jsk_recognition_msgs
{

  class SparseOccupancyGridColumn : public ros::Msg
  {
    public:
      typedef int32_t _column_index_type;
      _column_index_type column_index;
      uint32_t cells_length;
      typedef jsk_recognition_msgs::SparseOccupancyGridCell _cells_type;
      _cells_type st_cells;
      _cells_type * cells;

    SparseOccupancyGridColumn():
      column_index(0),
      cells_length(0), cells(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_column_index;
      u_column_index.real = this->column_index;
      *(outbuffer + offset + 0) = (u_column_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_column_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_column_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_column_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->column_index);
      *(outbuffer + offset + 0) = (this->cells_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cells_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cells_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cells_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cells_length);
      for( uint32_t i = 0; i < cells_length; i++){
      offset += this->cells[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_column_index;
      u_column_index.base = 0;
      u_column_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_column_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_column_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_column_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->column_index = u_column_index.real;
      offset += sizeof(this->column_index);
      uint32_t cells_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cells_length);
      if(cells_lengthT > cells_length)
        this->cells = (jsk_recognition_msgs::SparseOccupancyGridCell*)realloc(this->cells, cells_lengthT * sizeof(jsk_recognition_msgs::SparseOccupancyGridCell));
      cells_length = cells_lengthT;
      for( uint32_t i = 0; i < cells_length; i++){
      offset += this->st_cells.deserialize(inbuffer + offset);
        memcpy( &(this->cells[i]), &(this->st_cells), sizeof(jsk_recognition_msgs::SparseOccupancyGridCell));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SparseOccupancyGridColumn"; };
    const char * getMD5(){ return "55074b193e722d5ead092ffe27f06522"; };

  };

}
#endif
