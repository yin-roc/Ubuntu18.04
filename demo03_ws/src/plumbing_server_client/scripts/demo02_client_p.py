#! /usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from plumbing_server_client.srv import *
import sys
"""
    客户端：组织并提交请求，处理服务端响应
        1、导包
        2、初始化ros节点
        3、创建客户端数据
        4、组织请求数据,并发送请求
        5、处理响应。      

    优化实现：
        可以在执行节点时，动态传入参数

    问题:（3）
        客户端先于服务端启动，会抛出异常
    需要：
        客户端先于服务端启动，不要抛出异常，而是挂起，等待服务启动后，再发送请求
    实现：
        ROS内置了相关函数，这些函数可以判断服务器的状态，如果服务没有启动，那么让客户端挂起

        方案1：
            client.wait_for_service() 

        方案2：
            rospy.wait_for_service("话题名称")
        注意两者区别
"""

if __name__ == "__main__":

    # 判断参数长度(2)
    if len(sys.argv) != 3:
        rospy.logerr("传入的参数个数不对。")
        sys.exit(1)

    # 2、初始化ros节点
    rospy.init_node("erHei")
    # 3、创建客户端数据
    client = rospy.ServiceProxy("addInts",AddInts)
    rospy.loginfo("客户端对象实现")
    # (name: Any, service_class: Any, persistent: bool = False, headers: Any | None = None) -> None

    # 4、组织请求数据,并发送请求
    
    # 解析传入的参数(2)
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])

    # 等待服务器启动(3)
    # client.wait_for_service() #方法1
    rospy.wait_for_service("addInts")   #方法2
 
    response = client.call(num1, num2)
    # 5、处理响应。
    rospy.loginfo("相应的数据：%d", response.sum) 
    pass