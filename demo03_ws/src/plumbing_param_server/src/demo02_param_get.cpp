#include "ros/ros.h"

/*
    演示实现参数的查询
    实现：
        ros::NodeHandle------------------------------
            
        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)：获得所有参数的名称
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量


        ros::param-----------------------------------
        

*/


int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL, "");
    //初始化ros节点
    ros::init(argc, argv, "get_param_c");

    //创建节点句柄
    ros::NodeHandle nh;

    // ros::NodeHandle----------------------------------
    //1.param
    double radius = nh.param("raduis", 0.5);//没有查找到raduis，使用默认值0.5
    // 查找 键 为radius的值，如果没有，使用默认值0.5
    ROS_INFO("radius = %.2f", radius);

    // 2.getParam
    double radius2 = 0.0;
    // bool result = nh.getParam("radius", radius2);
    // if(result)
    // {
    //     ROS_INFO("获取的半径是：%.2f", radius2);
    // }
    // else
    // {
    //     ROS_INFO("被查询的结果是不存在的。");
    // }

    //3、getParamCached 与 getParam类似，只是底层性能上有提升，
    // 一般测试下，看不出来
    bool result = nh.getParamCached("radius", radius2);
    if(result)
    {
        ROS_INFO("获取的半径是：%.2f", radius2);
    }
    else
    {
        ROS_INFO("被查询的结果是不存在的。");
    }

    //4、getParamNames：获得所有参数的名称
    std::vector<std::string> names;//保存参数名称
    nh.getParamNames(names);
    for(auto && name : names)
    {
        ROS_INFO("遍历的元素：%s", name.c_str());
    }

    // 5、hasParam //运行不起来？？？应该是有输出1，无输出0  //test01_ws可以运行
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radiusxxxx");
    ROS_INFO("radius 存在吗? %d", flag1);
    ROS_INFO("radiusxxxx 存在吗？ %d", flag2);

    //6.searchParam
    std::string key;
    nh.searchParam("radius", key);
    ROS_INFO("搜索结果:%s", key.c_str());

    // ros::param-----------------------------------
    double radius_param = ros::param::param("radius", 100.5);
    ROS_INFO("radius_param = %.2f", 0.25);

    std::vector<std::string> names_param;
    ros::param::getParamNames(names_param);
    for(auto && name : names_param)
    {
        ROS_INFO("键：%s", name.c_str());
    }
    return 0;

}
