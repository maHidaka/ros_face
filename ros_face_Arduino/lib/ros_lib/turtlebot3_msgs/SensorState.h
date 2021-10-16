#ifndef _ROS_turtlebot3_msgs_SensorState_h
#define _ROS_turtlebot3_msgs_SensorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace turtlebot3_msgs
{

  class SensorState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _bumper_type;
      _bumper_type bumper;
      typedef float _cliff_type;
      _cliff_type cliff;
      typedef float _sonar_type;
      _sonar_type sonar;
      typedef float _illumination_type;
      _illumination_type illumination;
      typedef uint8_t _led_type;
      _led_type led;
      typedef uint8_t _button_type;
      _button_type button;
      typedef bool _torque_type;
      _torque_type torque;
      typedef int32_t _left_encoder_type;
      _left_encoder_type left_encoder;
      typedef int32_t _right_encoder_type;
      _right_encoder_type right_encoder;
      typedef float _battery_type;
      _battery_type battery;
      enum { BUMPER_FORWARD =  1 };
      enum { BUMPER_BACKWARD =  2 };
      enum { CLIFF =  1 };
      enum { SONAR =  1 };
      enum { ILLUMINATION =  1 };
      enum { BUTTON0 =  1 };
      enum { BUTTON1 =  2 };
      enum { ERROR_LEFT_MOTOR =  1 };
      enum { ERROR_RIGHT_MOTOR =  2 };
      enum { TORQUE_ON =  1 };
      enum { TORQUE_OFF =  2 };

    SensorState():
      header(),
      bumper(0),
      cliff(0),
      sonar(0),
      illumination(0),
      led(0),
      button(0),
      torque(0),
      left_encoder(0),
      right_encoder(0),
      battery(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->bumper >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bumper);
      union {
        float real;
        uint32_t base;
      } u_cliff;
      u_cliff.real = this->cliff;
      *(outbuffer + offset + 0) = (u_cliff.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cliff.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cliff.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cliff.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cliff);
      union {
        float real;
        uint32_t base;
      } u_sonar;
      u_sonar.real = this->sonar;
      *(outbuffer + offset + 0) = (u_sonar.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sonar.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sonar.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sonar.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sonar);
      union {
        float real;
        uint32_t base;
      } u_illumination;
      u_illumination.real = this->illumination;
      *(outbuffer + offset + 0) = (u_illumination.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_illumination.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_illumination.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_illumination.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->illumination);
      *(outbuffer + offset + 0) = (this->led >> (8 * 0)) & 0xFF;
      offset += sizeof(this->led);
      *(outbuffer + offset + 0) = (this->button >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button);
      union {
        bool real;
        uint8_t base;
      } u_torque;
      u_torque.real = this->torque;
      *(outbuffer + offset + 0) = (u_torque.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->torque);
      union {
        int32_t real;
        uint32_t base;
      } u_left_encoder;
      u_left_encoder.real = this->left_encoder;
      *(outbuffer + offset + 0) = (u_left_encoder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_encoder.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_encoder.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_encoder.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_encoder);
      union {
        int32_t real;
        uint32_t base;
      } u_right_encoder;
      u_right_encoder.real = this->right_encoder;
      *(outbuffer + offset + 0) = (u_right_encoder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_encoder.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_encoder.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_encoder.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_encoder);
      union {
        float real;
        uint32_t base;
      } u_battery;
      u_battery.real = this->battery;
      *(outbuffer + offset + 0) = (u_battery.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->bumper =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->bumper);
      union {
        float real;
        uint32_t base;
      } u_cliff;
      u_cliff.base = 0;
      u_cliff.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cliff.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cliff.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cliff.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cliff = u_cliff.real;
      offset += sizeof(this->cliff);
      union {
        float real;
        uint32_t base;
      } u_sonar;
      u_sonar.base = 0;
      u_sonar.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sonar.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sonar.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sonar.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sonar = u_sonar.real;
      offset += sizeof(this->sonar);
      union {
        float real;
        uint32_t base;
      } u_illumination;
      u_illumination.base = 0;
      u_illumination.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_illumination.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_illumination.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_illumination.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->illumination = u_illumination.real;
      offset += sizeof(this->illumination);
      this->led =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->led);
      this->button =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->button);
      union {
        bool real;
        uint8_t base;
      } u_torque;
      u_torque.base = 0;
      u_torque.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->torque = u_torque.real;
      offset += sizeof(this->torque);
      union {
        int32_t real;
        uint32_t base;
      } u_left_encoder;
      u_left_encoder.base = 0;
      u_left_encoder.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_encoder.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_encoder.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_encoder.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_encoder = u_left_encoder.real;
      offset += sizeof(this->left_encoder);
      union {
        int32_t real;
        uint32_t base;
      } u_right_encoder;
      u_right_encoder.base = 0;
      u_right_encoder.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_encoder.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_encoder.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_encoder.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_encoder = u_right_encoder.real;
      offset += sizeof(this->right_encoder);
      union {
        float real;
        uint32_t base;
      } u_battery;
      u_battery.base = 0;
      u_battery.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery = u_battery.real;
      offset += sizeof(this->battery);
     return offset;
    }

    const char * getType(){ return "turtlebot3_msgs/SensorState"; };
    const char * getMD5(){ return "7250c1dc0b61c4190e78f528f599285f"; };

  };

}
#endif
