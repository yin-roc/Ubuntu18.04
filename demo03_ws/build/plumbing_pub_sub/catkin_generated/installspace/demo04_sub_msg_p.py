#!/usr/bin/env python2
# -*- coding: utf-8 -*-

import rospy
from plumbing_pub_sub.msg import Person 

"""
    1、导包
    2、初始化ros节点
    3、创建订阅者对象
    4、处理订阅到的消息(回调函数)
    5、spin()函数
"""

def doPerson(p):
    rospy.loginfo("订阅者订阅到的消息：%s, %d, %.2f", p.name, p.age, p.height)
    

if __name__ == "__main__":

    # 2、初始化ros节点
    rospy.init_node("daYe")
    # 3、创建订阅者对象
    sub = rospy.Subscriber("jiaoSheTou", Person, doPerson)
    # 4、处理订阅到的消息(回调函数)
    # 5、spin()函数
    rospy.spin()
    pass