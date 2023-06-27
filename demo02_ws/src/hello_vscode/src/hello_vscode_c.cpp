#include "ros/ros.h"


int main(int argc, char* argv[]) 
{
    //
    ros::init(argc, argv, "hello_ros");
    
    setlocale(LC_ALL, ""); //
    // setlocale(LC_CTYPE, "zh_CN.utf8");
    ROS_INFO("hello, 哈哈");

    return 0;
}