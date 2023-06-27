#! /usr/bin/env python
# -*- coding: utf-8 -*-

#导包
import rospy

#入口
if __name__ == '__main__':

    #初始化ROS节点
    rospy.init_node("hello_p")
    
    #输出日志
    rospy.loginfo("hello vscode! 这是python!")