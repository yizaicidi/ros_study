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
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "control_turtle");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/create_turtle/cmd_vel", 1000);

    ros::Rate r(10);
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
            geometry_msgs::TransformStamped tfs = buffer.lookupTransform("create_turtle", "turtle1", ros::Time(0));
            ROS_INFO("son1相对于son2的信息:父级:%s,子级,%s,偏移量:%.2f,%.2f,%.2f",
                     tfs.header.frame_id.c_str(),
                     tfs.child_frame_id.c_str(),
                     tfs.transform.translation.x,
                     tfs.transform.translation.y,
                     tfs.transform.translation.z);
            geometry_msgs::Twist twist;
            twist.linear.x = 0.5 * sqrt(pow(tfs.transform.translation.x, 2) + pow(tfs.transform.translation.y, 2));
            twist.angular.z=4*atan2(tfs.transform.translation.y,tfs.transform.translation.x);
            pub.publish(twist);
        }
        catch (const std::exception &e)
        {
            ROS_ERROR("程序错误:%s", e.what());
        }
        r.sleep();
        ros::spinOnce();
    }

    return 0;
}
