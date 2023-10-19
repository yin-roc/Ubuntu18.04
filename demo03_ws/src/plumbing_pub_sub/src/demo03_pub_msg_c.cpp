#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

/*
    1、包含头文件
    2、初始化ros节点
    3、创建节点句柄
    4、创建发布者对象
    5、编写发布逻辑并发布消息
*/


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2、初始化ros节点
    ros::init(argc, argv, "talker_person");
    // 3、创建节点句柄
    ros::NodeHandle nh;
    // 4、创建发布者对象
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("chatter_person",10);
    // 5、编写发布逻辑并发布消息
    //5-1、创建被发布的数据
    plumbing_pub_sub::Person p;
    p.name = "sunwukong";
    p.age = 2000;
    p.height = 1.45;

    //5-2、设置发布频率
    ros::Rate rate(1);


    //5-3、循环发布数据
    //核心：发布数据
    while (ros::ok())
    {
        pub.publish(p);
        ROS_INFO("发布的消息：%s,%d,%.2f",p.name.c_str(), p.age, p.height);
        p.age += 1;

        //休眠
        rate.sleep();

        ros::spinOnce();
    }
    
    

    return 0;
}
