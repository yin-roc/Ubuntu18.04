#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"
/*
    需求：发布两个坐标系的相对关系

    流程：
        1、包含头文件
        2、设置编码、节点初始化、NodeHandle
        3、创建发布对象；
        4、组织被发布的消息；
        5、发布数据；
        6、spin();
*/

int main(int argc, char *argv[])
{
    // 2、设置编码、节点初始化、NodeHandle
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "static_pub");
    ros::NodeHandle nh;
    // 3、创建发布对象；
    tf2_ros::StaticTransformBroadcaster pub;

    ros::Rate rate(1);

    while (ros::ok())
    {
        // 4、组织被发布的消息；
        geometry_msgs::TransformStamped tfs;
        tfs.header.stamp = ros::Time::now();
        tfs.header.frame_id = "base_link"; // 相对坐标系关系中被参考的那一个
        tfs.child_frame_id = "laser";
        tfs.transform.translation.x = 0.2;
        tfs.transform.translation.y = 0.0;
        tfs.transform.translation.z = 0.5;

        // 需要根据欧拉角转换
        tf2::Quaternion qtn;    // 创建 四元数 对象
        // 向该对象设置欧拉角，这个对象可以将欧拉角转换成四元数
        qtn.setRPY(0, 0, 0); // 欧拉角的单位是弧度

        tfs.transform.rotation.x = qtn.getX();
        tfs.transform.rotation.y = qtn.getY();
        tfs.transform.rotation.z = qtn.getZ();
        tfs.transform.rotation.w = qtn.getW();
        
        // 5、发布数据；
        pub.sendTransform(tfs);
        // 6、spin();
        ros::spinOnce();   
        rate.sleep();
    }
    
    return 0;
}