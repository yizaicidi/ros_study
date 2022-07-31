/*

需求:
    现有坐标系统，父级坐标系统 world,下有两子级系统 son1，son2，
    son1 相对于 world，以及 son2 相对于 world 的关系是已知的，
    求 son1 与 son2中的坐标关系，又已知在 son1中一点的坐标，要求求出该点在 son2 中的坐标
实现流程:
    1.包含头文件
    2.初始化 ros 节点
    3.创建 ros 句柄
    4.创建 TF 订阅对象
    5.解析订阅信息中获取 son1 坐标系原点在 son2 中的坐标
      解析 son1 中的点相对于 son2 的坐标
    6.spin

*/
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/TransformStamped.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "sub_frames");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    // son1中的点
    geometry_msgs::PointStamped psAtson1;
    psAtson1.header.frame_id = "son1";
    psAtson1.header.stamp = ros::Time::now();
    psAtson1.point.x = 1;
    psAtson1.point.y = 1;
    psAtson1.point.z = 1;

    while (ros::ok())
    {
        try
        {
            //计算son1与son2的相对关系
            /*
                A相对于B的坐标关系

                参数1：目标坐标系，即要转到的坐标系B
                参数2：当前的坐标系  A
                参数3：ros::Time(0)取间隔最短的两个坐标关系帧计算相对关系
                返回值:g
            */
            geometry_msgs::TransformStamped Son1ToSon2 = buffer.lookupTransform("son2", "son1", ros::Time(0));
            ROS_INFO("son1相对于son2的信息:父级:%s,子级,%s,偏移量:%.2f,%.2f,%.2f",
                     Son1ToSon2.header.frame_id.c_str(),
                     Son1ToSon2.child_frame_id.c_str(),
                     Son1ToSon2.transform.translation.x,
                     Son1ToSon2.transform.translation.y,
                     Son1ToSon2.transform.translation.z);

            //坐标点解析
            geometry_msgs::PointStamped psAtson2;
            psAtson2 = buffer.transform(psAtson1, "son2");
            ROS_INFO("坐标点在坐标系%s的数据为:(%.2f,%.2f,%.2f)",
                     psAtson2.header.frame_id.c_str(),
                     psAtson2.point.x,
                     psAtson2.point.y,
                     psAtson2.point.z);
        }
        catch (const std::exception &e)
        {
            ROS_ERROR("程序错误:%s",e.what());
        }
    }

    return 0;
}
