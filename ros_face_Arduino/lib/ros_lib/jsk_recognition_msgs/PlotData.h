#ifndef _ROS_jsk_recognition_msgs_PlotData_h
#define _ROS_jsk_recognition_msgs_PlotData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class PlotData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t xs_length;
      typedef float _xs_type;
      _xs_type st_xs;
      _xs_type * xs;
      uint32_t ys_length;
      typedef float _ys_type;
      _ys_type st_ys;
      _ys_type * ys;
      typedef uint32_t _type_type;
      _type_type type;
      typedef const char* _label_type;
      _label_type label;
      typedef bool _fit_line_type;
      _fit_line_type fit_line;
      typedef bool _fit_line_ransac_type;
      _fit_line_ransac_type fit_line_ransac;
      enum { SCATTER = 1 };
      enum { LINE = 2 };

    PlotData():
      header(),
      xs_length(0), xs(NULL),
      ys_length(0), ys(NULL),
      type(0),
      label(""),
      fit_line(0),
      fit_line_ransac(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->xs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->xs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->xs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->xs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xs_length);
      for( uint32_t i = 0; i < xs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_xsi;
      u_xsi.real = this->xs[i];
      *(outbuffer + offset + 0) = (u_xsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xs[i]);
      }
      *(outbuffer + offset + 0) = (this->ys_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ys_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ys_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ys_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ys_length);
      for( uint32_t i = 0; i < ys_length; i++){
      union {
        float real;
        uint32_t base;
      } u_ysi;
      u_ysi.real = this->ys[i];
      *(outbuffer + offset + 0) = (u_ysi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ysi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ysi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ysi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ys[i]);
      }
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_label = strlen(this->label);
      varToArr(outbuffer + offset, length_label);
      offset += 4;
      memcpy(outbuffer + offset, this->label, length_label);
      offset += length_label;
      union {
        bool real;
        uint8_t base;
      } u_fit_line;
      u_fit_line.real = this->fit_line;
      *(outbuffer + offset + 0) = (u_fit_line.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fit_line);
      union {
        bool real;
        uint8_t base;
      } u_fit_line_ransac;
      u_fit_line_ransac.real = this->fit_line_ransac;
      *(outbuffer + offset + 0) = (u_fit_line_ransac.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fit_line_ransac);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t xs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      xs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      xs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      xs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->xs_length);
      if(xs_lengthT > xs_length)
        this->xs = (float*)realloc(this->xs, xs_lengthT * sizeof(float));
      xs_length = xs_lengthT;
      for( uint32_t i = 0; i < xs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_xs;
      u_st_xs.base = 0;
      u_st_xs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_xs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_xs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_xs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_xs = u_st_xs.real;
      offset += sizeof(this->st_xs);
        memcpy( &(this->xs[i]), &(this->st_xs), sizeof(float));
      }
      uint32_t ys_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ys_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ys_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ys_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ys_length);
      if(ys_lengthT > ys_length)
        this->ys = (float*)realloc(this->ys, ys_lengthT * sizeof(float));
      ys_length = ys_lengthT;
      for( uint32_t i = 0; i < ys_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_ys;
      u_st_ys.base = 0;
      u_st_ys.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ys.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ys.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ys.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ys = u_st_ys.real;
      offset += sizeof(this->st_ys);
        memcpy( &(this->ys[i]), &(this->st_ys), sizeof(float));
      }
      this->type =  ((uint32_t) (*(inbuffer + offset)));
      this->type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->type);
      uint32_t length_label;
      arrToVar(length_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_label-1]=0;
      this->label = (char *)(inbuffer + offset-1);
      offset += length_label;
      union {
        bool real;
        uint8_t base;
      } u_fit_line;
      u_fit_line.base = 0;
      u_fit_line.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fit_line = u_fit_line.real;
      offset += sizeof(this->fit_line);
      union {
        bool real;
        uint8_t base;
      } u_fit_line_ransac;
      u_fit_line_ransac.base = 0;
      u_fit_line_ransac.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fit_line_ransac = u_fit_line_ransac.real;
      offset += sizeof(this->fit_line_ransac);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/PlotData"; };
    const char * getMD5(){ return "abc388ba2207b305f8695ad025452af4"; };

  };

}
#endif
