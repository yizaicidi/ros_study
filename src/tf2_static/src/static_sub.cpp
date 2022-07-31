#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // ros初始化节点
    ros::init(argc, argv, "static_sub");
    ros::NodeHandle nh;
    //创建tf订阅节点
    //---   创建一个buffer缓存
    tf2_ros::Buffer buffer;
    //---   创建一个监听对象（监听对象可以将订阅的数据存入buffer）
    tf2_ros::TransformListener listener(buffer);

    ros::Rate r(1);
    while (ros::ok())
    {
        //生成一个坐标点（该坐标点是相对于子坐标系
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id = "laser";
        point_laser.header.stamp = ros::Time::now();
        point_laser.point.x = 1;
        point_laser.point.y = 2;
        point_laser.point.z = 7.3;

        //转换坐标点（相对于夫级坐标系
        //------使用 try 语句或休眠，否则可能由于缓存接收延迟而导致坐标转换失败--------------
        try
        {
            //核心代码 ----将point_laser坐标点转换成相对于base_link坐标系的point_base坐标点
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_laser, "base_link");
            ROS_INFO("转换后的数据：(%.2f,%.2f,%.2f),参考的坐标系是：%s",
                     point_base.point.x,
                     point_base.point.y,
                     point_base.point.z,
                     point_base.header.frame_id.c_str());
        }
        catch (const std::exception &e)
        {
            ROS_ERROR("程序错误");
        }

        r.sleep();
        ros::spinOnce();
    }

    return 0;
}
