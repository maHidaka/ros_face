#!/usr/bin/env python
# -*- coding: utf-8 -*- 

import rospy
import time
from std_msgs.msg import String
from sensor_msgs.msg import Joy
from ros_face_msgs.msg import FaceCmd

class JoyFace:
    def __init__(self):
        self.cmd = FaceCmd()
        self.joy_sub = rospy.Subscriber("/joy", Joy, self.joy_callback)
        self.face_pub = rospy.Publisher("/face_cmd", FaceCmd, queue_size=1)

    def joy_callback(self, msg):
        if msg.buttons[4] == 1:
            self.blink("left")
        else:
            self.cmd.ch1.state = False
            self.cmd.ch2.state = False
        
        if msg.buttons[5] == 1:
            self.blink("right")
        else:
            self.cmd.ch6.state = False
            self.cmd.ch7.state = False

        if msg.buttons[0] == 1:
            self.cmd.ch4.state = True
        else:
            self.cmd.ch4.state = False

        if msg.buttons[1] == 1:
            self.cmd.ch9.state = True
        else:
            self.cmd.ch9.state = False

        if msg.axes[0] > 0.5:
            self.cmd.ch5.state = True
        elif msg.axes[1] < 0.5:
            self.cmd.ch5.state = False
        
        if msg.axes[0] < -0.5:
            self.cmd.ch10.state = True
        elif msg.axes[1] < 0.5:
            self.cmd.ch10.state = False

        if msg.axes[1] > 0.5:
            self.cmd.ch5.state = True
            self.cmd.ch10.state = True


        if msg.axes[3] > 0.5:
            self.cmd.ch3.state = True
        elif msg.axes[4] < 0.5:
            self.cmd.ch3.state = False
        
        if msg.axes[3] < -0.5:
            self.cmd.ch8.state = True
        elif msg.axes[4] < 0.5:
            self.cmd.ch8.state = False

        if msg.axes[4] > 0.5:
            self.cmd.ch3.state = True
            self.cmd.ch8.state = True
        
        print("soiya")
        self.publish_cmd(self.cmd)


    def publish_cmd(self, cmd):
        self.face_pub.publish(cmd)

    def blink(self, side):
        if side == "left":
            self.cmd.ch1.state = True
            self.cmd.ch2.state = True
        
        if side == "right":
            self.cmd.ch6.state = True
            self.cmd.ch7.state = True


if __name__ == "__main__":
    rospy.init_node("joy_face")
    time.sleep(2.0)
    joy_face = JoyFace()

    while not rospy.is_shutdown():
        rospy.sleep(0.01)