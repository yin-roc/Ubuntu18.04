#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

/*
    客户端：提交两个整数，并处理响应的数据
        1、包含头文件
        2、初始化ros节点
        3、创建节点句柄
        4、创建客户端对象
        5、提交请求并处理响应

    实现参数的动态提交：（2）
        1、格式：rosrun xxxx xxxx 12 34
        2、节点在执行时，需要获取命令中的参数，并组织进 request

    问题：(3)
        如果先启动客户端，那么会请求异常
    需求：(3)
        如果先启动客户端，不要直接抛出异常，而是挂起，等服务器启动后，再正常请求
    解决：(3)
        在ros中内置了相关函数，这些函数可以让客户端启动后挂起，等待服务器启动
        1.client.waitForExistence();
        2.ros::service::waitForService("服务话题");

*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    //优化实现，获取命令中的参数（2）
    if(argc != 3)//（2）
    //3个参数：第一个参数是文件的路径，第二个参数是12，第三个参数是34（2）
    {
        ROS_INFO("提交的参数个数不对！");
        return 1;
    }

    // 2、初始化ros节点
    ros::init(argc, argv, "daBao");
    // 3、创建节点句柄
    ros::NodeHandle nh;
    // 4、创建客户端对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    // 5、提交请求并处理响应
    plumbing_server_client::AddInts ai;
    //5-1.组织请求
    ai.request.num1 = atoi(argv[1]);//（2）此处被修改
    //argv[1]还是字符串类型，因为char * argv[],因此需要将他转换成整数类型
    //因此，使用atoi，用来将字符串转化为整数

    ai.request.num2 = atoi(argv[2]);//（2）此处被修改

    //5-2.处理响应
    
    //调用判断服务器状态的函数（3）
    //函数1（3）
    // client.waitForExistence() //（3）;
    ros::service::waitForService("addInts");//(3)

    bool flag = client.call(ai);
    if(flag)
    {
        ROS_INFO("响应成功！");
        //获取结果
        ROS_INFO("响应结果 = %d", ai.response.sum);
    }
    else
    {
        ROS_INFO("处理失败.....");
    }

    return 0;
}
