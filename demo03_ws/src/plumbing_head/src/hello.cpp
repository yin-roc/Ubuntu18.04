#include "ros/ros.h"  
#include "plumbing_head/hello.h" 
// 头文件：#include "plumbing_head/hello.h"  
// 检测到 #include 错误。请更新 includePath。
// 解决方法：
    // 在c_cpp_properties.json 文件中添加路径
    // "/home/yin/demo_ws/demo03_ws/src/plumbing_head/include/**"
    // 逗号、引号不能少，/** 是需要手动加入的内容
    // 设置完还在报错，则编译一下

namespace hello_ns
{
    void Myhello::run()
    {
        ROS_INFO("run函数执行.....");
    }
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "hello_head");
    
    // 函数调用
    hello_ns::Myhello myhello;
    myhello.run();
    
    return 0;
}
