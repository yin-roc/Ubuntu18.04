#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h" 

/*
    1、包含头文件
    2、初始化ros节点
    3、创建节点句柄
    4、创建订阅者对象
    5、处理订阅到的数据（回调函数）
    6、调用spin()函数
*/

void doPerson(const plumbing_pub_sub::Person::ConstPtr& p) 
{
    ROS_INFO("订阅人的信息：%s,%d,%.2f", p->name.c_str(), p->age, p->height);
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2、初始化ros节点
    ros::init(argc, argv, "listener_person");
    // 3、创建节点句柄
    ros::NodeHandle nh;
    // 4、创建订阅者对象
    ros::Subscriber sub = nh.subscribe<plumbing_pub_sub::Person>("chatter_person", 10, doPerson);
    // 5、处理订阅到的数据（回调函数）
    // 6、调用spin()函数
    ros::spin();
    return 0;
}
