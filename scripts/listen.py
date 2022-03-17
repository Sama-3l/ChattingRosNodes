#!/usr/bin/env python3
#rospy.get_caller_id()
"""
Source: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29
"""

import rospy
from std_msgs.msg import String


def callback(data):
    rospy.loginfo("Message Recieved: %s", data.data)
    
def listener():
    rospy.init_node(input('Enter listener name'))

    rospy.Subscriber(input('Enter your name: '), String, callback)
    rospy.spin()

listener()