#ifndef _ROS_jsk_recognition_msgs_PlotDataArray_h
#define _ROS_jsk_recognition_msgs_PlotDataArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/PlotData.h"

namespace jsk_recognition_msgs
{

  class PlotDataArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t data_length;
      typedef jsk_recognition_msgs::PlotData _data_type;
      _data_type st_data;
      _data_type * data;
      typedef bool _no_legend_type;
      _no_legend_type no_legend;
      typedef float _legend_font_size_type;
      _legend_font_size_type legend_font_size;
      typedef float _max_x_type;
      _max_x_type max_x;
      typedef float _min_x_type;
      _min_x_type min_x;
      typedef float _min_y_type;
      _min_y_type min_y;
      typedef float _max_y_type;
      _max_y_type max_y;

    PlotDataArray():
      header(),
      data_length(0), data(NULL),
      no_legend(0),
      legend_font_size(0),
      max_x(0),
      min_x(0),
      min_y(0),
      max_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_no_legend;
      u_no_legend.real = this->no_legend;
      *(outbuffer + offset + 0) = (u_no_legend.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->no_legend);
      union {
        float real;
        uint32_t base;
      } u_legend_font_size;
      u_legend_font_size.real = this->legend_font_size;
      *(outbuffer + offset + 0) = (u_legend_font_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_legend_font_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_legend_font_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_legend_font_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->legend_font_size);
      union {
        float real;
        uint32_t base;
      } u_max_x;
      u_max_x.real = this->max_x;
      *(outbuffer + offset + 0) = (u_max_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_x);
      union {
        float real;
        uint32_t base;
      } u_min_x;
      u_min_x.real = this->min_x;
      *(outbuffer + offset + 0) = (u_min_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_x);
      union {
        float real;
        uint32_t base;
      } u_min_y;
      u_min_y.real = this->min_y;
      *(outbuffer + offset + 0) = (u_min_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_y);
      union {
        float real;
        uint32_t base;
      } u_max_y;
      u_max_y.real = this->max_y;
      *(outbuffer + offset + 0) = (u_max_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (jsk_recognition_msgs::PlotData*)realloc(this->data, data_lengthT * sizeof(jsk_recognition_msgs::PlotData));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(jsk_recognition_msgs::PlotData));
      }
      union {
        bool real;
        uint8_t base;
      } u_no_legend;
      u_no_legend.base = 0;
      u_no_legend.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->no_legend = u_no_legend.real;
      offset += sizeof(this->no_legend);
      union {
        float real;
        uint32_t base;
      } u_legend_font_size;
      u_legend_font_size.base = 0;
      u_legend_font_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_legend_font_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_legend_font_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_legend_font_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->legend_font_size = u_legend_font_size.real;
      offset += sizeof(this->legend_font_size);
      union {
        float real;
        uint32_t base;
      } u_max_x;
      u_max_x.base = 0;
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_x = u_max_x.real;
      offset += sizeof(this->max_x);
      union {
        float real;
        uint32_t base;
      } u_min_x;
      u_min_x.base = 0;
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_x = u_min_x.real;
      offset += sizeof(this->min_x);
      union {
        float real;
        uint32_t base;
      } u_min_y;
      u_min_y.base = 0;
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_y = u_min_y.real;
      offset += sizeof(this->min_y);
      union {
        float real;
        uint32_t base;
      } u_max_y;
      u_max_y.base = 0;
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_y = u_max_y.real;
      offset += sizeof(this->max_y);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/PlotDataArray"; };
    const char * getMD5(){ return "e83e9378b374b8436f955a6cd212770a"; };

  };

}
#endif
