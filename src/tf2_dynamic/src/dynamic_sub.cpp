#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "dynamic_sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    ros::Rate r(1);
    while (ros::ok())
    {
        geometry_msgs::PointStamped point_turtle;
        point_turtle.header.frame_id = "turtle1";
        //关于时间戳   为什么不用实时的时间戳？
        point_turtle.header.stamp = ros::Time(0.0);
        point_turtle.point.x = 1;
        point_turtle.point.y = 2;
        point_turtle.point.z = 3;

        try
        {
            geometry_msgs::PointStamped point_world;
            point_world = buffer.transform(point_turtle, "world");
            ROS_INFO("转换后的数据：(%.2f,%.2f,%.2f),参考的坐标系是：%s",
                     point_world.point.x,
                     point_world.point.y,
                     point_world.point.z,
                     point_world.header.frame_id.c_str());
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
