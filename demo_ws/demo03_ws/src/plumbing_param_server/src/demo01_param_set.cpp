#include "ros/ros.h"

/*
    需要实现参数的新增与修改
    需求：首先设置机器人的共享参数，类型、半径
         再修改半径（0.2m）
    实现：
        键指函数里面的参数key
        ros::NodeHandle
            setParam("键"，值)
        ros::param
            set("键"，值)
    修改，只需要继续调用 setParam 或 set 函数，保证键是已经存在的，那么值会被覆盖

    void setParam(const std::__cxx11::string &key, const std::map<std::__cxx11::string, bool> &map) const

*/


int main(int argc, char * argv[])
{
    //初始化ros节点
    ros::init(argc, argv, "set_param_c");

    //创建ros节点句柄
    ros::NodeHandle nh;

    //参数增------------------------------------
    //方案1：nh
    nh.setParam("type", "xiaoHuang");
    nh.setParam("radius", 0.15);
    //方案2：ros::param
    ros::param::set("type_param", "xiaoBai");
    ros::param::set("radius_param", 0.15);

    //参数改------------------------------------
    //方案1：nh
    nh.setParam("radius", 0.2); 
    //方案2：ros::param
    ros::param::set("radius_param", 0.25);
    return 0;
}
