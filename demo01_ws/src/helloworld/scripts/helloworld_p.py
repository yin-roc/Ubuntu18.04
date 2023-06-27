#!/usr/bin/env python
# -*- coding: utf-8 -*-
##指定解释器

#1、导包
import rospy

#2、编写主入口
if __name__ == "__main__":

	#3、初始化ros节点
	rospy.init_node("hello_p")
	
	#4、输出日志
	rospy.loginfo("hello world! by python")

 
