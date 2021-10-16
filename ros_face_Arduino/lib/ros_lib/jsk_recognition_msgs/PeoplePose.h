#ifndef _ROS_jsk_recognition_msgs_PeoplePose_h
#define _ROS_jsk_recognition_msgs_PeoplePose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace jsk_recognition_msgs
{

  class PeoplePose : public ros::Msg
  {
    public:
      uint32_t limb_names_length;
      typedef char* _limb_names_type;
      _limb_names_type st_limb_names;
      _limb_names_type * limb_names;
      uint32_t poses_length;
      typedef geometry_msgs::Pose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;
      uint32_t scores_length;
      typedef float _scores_type;
      _scores_type st_scores;
      _scores_type * scores;

    PeoplePose():
      limb_names_length(0), limb_names(NULL),
      poses_length(0), poses(NULL),
      scores_length(0), scores(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->limb_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->limb_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->limb_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->limb_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->limb_names_length);
      for( uint32_t i = 0; i < limb_names_length; i++){
      uint32_t length_limb_namesi = strlen(this->limb_names[i]);
      varToArr(outbuffer + offset, length_limb_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->limb_names[i], length_limb_namesi);
      offset += length_limb_namesi;
      }
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->scores_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scores_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scores_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scores_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scores_length);
      for( uint32_t i = 0; i < scores_length; i++){
      union {
        float real;
        uint32_t base;
      } u_scoresi;
      u_scoresi.real = this->scores[i];
      *(outbuffer + offset + 0) = (u_scoresi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scoresi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scoresi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scoresi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scores[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t limb_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      limb_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      limb_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      limb_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->limb_names_length);
      if(limb_names_lengthT > limb_names_length)
        this->limb_names = (char**)realloc(this->limb_names, limb_names_lengthT * sizeof(char*));
      limb_names_length = limb_names_lengthT;
      for( uint32_t i = 0; i < limb_names_length; i++){
      uint32_t length_st_limb_names;
      arrToVar(length_st_limb_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_limb_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_limb_names-1]=0;
      this->st_limb_names = (char *)(inbuffer + offset-1);
      offset += length_st_limb_names;
        memcpy( &(this->limb_names[i]), &(this->st_limb_names), sizeof(char*));
      }
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (geometry_msgs::Pose*)realloc(this->poses, poses_lengthT * sizeof(geometry_msgs::Pose));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geometry_msgs::Pose));
      }
      uint32_t scores_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      scores_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      scores_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      scores_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->scores_length);
      if(scores_lengthT > scores_length)
        this->scores = (float*)realloc(this->scores, scores_lengthT * sizeof(float));
      scores_length = scores_lengthT;
      for( uint32_t i = 0; i < scores_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_scores;
      u_st_scores.base = 0;
      u_st_scores.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_scores.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_scores.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_scores.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_scores = u_st_scores.real;
      offset += sizeof(this->st_scores);
        memcpy( &(this->scores[i]), &(this->st_scores), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/PeoplePose"; };
    const char * getMD5(){ return "24f6e59dae1b7cbd9d480f0008a5a515"; };

  };

}
#endif
