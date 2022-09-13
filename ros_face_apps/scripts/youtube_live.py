#!/usr/bin/env python
# -*- coding: utf-8 -*- 

import rospy
import time
from std_msgs.msg import String
from sensor_msgs.msg import Joy
import time
import requests
import json
from ros_face_msgs.msg import FaceCmd



class JoyFace:
    def __init__(self):
        self.cmd = FaceCmd()
        self.face_pub = rospy.Publisher("/face_cmd", FaceCmd, queue_size=1)
        self.yt_url = ''
        self.YT_API_KEY = ''

    def publish_cmd(self, cmd):
        self.face_pub.publish(cmd)

    def blink(self, side):
        if side == "left":
            self.cmd.ch1.state = True
            self.cmd.ch2.state = True
        if side == "right":
            self.cmd.ch6.state = True
            self.cmd.ch7.state = True
        self.publish_cmd(self.cmd)
        time.sleep(0.6)
        self.cmd.ch1.state = False
        self.cmd.ch2.state = False
        self.cmd.ch6.state = False
        self.cmd.ch7.state = False
        self.publish_cmd(self.cmd)

    def get_chat_id(self):
        video_id = self.yt_url.replace('https://www.youtube.com/watch?v=', '')
        rospy.loginfo("Video ID : %s",video_id)
        url    = 'https://www.googleapis.com/youtube/v3/videos'
        params = {'key': self.YT_API_KEY, 'id': video_id, 'part': 'liveStreamingDetails'}
        data   = requests.get(url, params=params).json()
        liveStreamingDetails = data['items'][0]['liveStreamingDetails']
        if 'activeLiveChatId' in liveStreamingDetails.keys():
            chat_id = liveStreamingDetails['activeLiveChatId']
        else:
            chat_id = None
            rospy.logerr('Could not get chat_id !')

        return chat_id


    def get_chat(self, chat_id, pageToken):
        rospy.loginfo("token: %s",pageToken)
        url    = 'https://www.googleapis.com/youtube/v3/liveChat/messages'
        params = {'key': self.YT_API_KEY, 'liveChatId': chat_id, 'part': 'snippet'}
        if type(pageToken) != None:
            params['pageToken'] = pageToken

        data = requests.get(url, params=params).json()
        for item in data['items']:
            #msg       = item['snippet']['displayMessage']
            #usr       = item['authorDetails']['displayName']
            msg = item['snippet']['textMessageDetails']['messageText']
            rospy.logwarn(msg)
            if str(msg) == 'left':
                rospy.logwarn("LEFT!")
                self.blink("left")
            if str(msg) == 'right':
                rospy.logwarn("RIGHT!")
                self.blink("right")
            #supChat   = item['snippet']['superChatDetails']
            #supStic   = item['snippet']['superStickerDetails']
            #log_text  = '[by {}  https://www.youtube.com/channel/{}]\n  {}'.format(usr, channelId, msg)
        return data['nextPageToken']



if __name__ == "__main__":
    rospy.init_node("joy_face")
    time.sleep(2.0)
    joy_face = JoyFace()
    chat_id = joy_face.get_chat_id()
    nextPageToken = None
    while not rospy.is_shutdown():
        # try:
        #     nextPageToken = joy_face.get_chat(chat_id, nextPageToken, 'log_file.txt')
        #     rospy.loginfo(nextPageToken)
        # except:
        #     rospy.logwarn("failed")
        
        nextPageToken = joy_face.get_chat(chat_id, nextPageToken)
        rospy.sleep(3)





