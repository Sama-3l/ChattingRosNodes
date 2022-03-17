#!/usr/bin/env python3

"""
Source: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29
"""

import rospy
from std_msgs.msg import String

def talker():
    d=0
    pub = rospy.Publisher(input('Enter who to talk to: '), String, queue_size=10)
    rospy.init_node(input('Enter talker name'))

    rate = rospy.Rate(10) # 10hz
    
    while not rospy.is_shutdown():
        hello_str = input('Enter message: ')
        #rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()
        d = d + 1

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass