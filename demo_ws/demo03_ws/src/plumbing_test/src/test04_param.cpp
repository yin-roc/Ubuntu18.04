#include "ros/ros.h"

/*
    需求：修改参数服务器中 turtlesim 背景色相关的参数

    1、初始化ros节点；
    2、不一定需要创建节点句柄(和后续API有关)；
    3、修改参数。

*/

int main(int argc, char *argv[])
{
    // 1、初始化ros节点；
    ros::init(argc, argv, "change_bgColor");
    // 2、不一定需要创建节点句柄(和后续API有关)；
    
    //方法2：借用节点句柄进行操作(操作方法1)
    // ros::NodeHandle nh("/turtlesim"); // 与之前创建节点句柄不一样，创建了一个命名空间，命名为/turtlesim
    // // 取自 /turtlesim/background_r 的前半段

    // nh.setParam("background_r", 255);
    // nh.setParam("background_g", 255);
    // nh.setParam("background_b", 255);

    //方法3：借用节点句柄进行操作(操作方法2)
    ros::NodeHandle nh; 
    nh.setParam("/turtlesim/background_r", 0);
    nh.setParam("/turtlesim/background_g", 50);
    nh.setParam("/turtlesim/background_b", 100);

    // 3、修改参数。

    // // 方法1：不借用节点句柄 如果调用 ros::param，不需要创建节点句柄
    // ros::param::set("/turtlesim/background_r", 0);
    // ros::param::set("/turtlesim/background_g", 0);
    // ros::param::set("/turtlesim/background_b", 0);

    
    return 0;
}
