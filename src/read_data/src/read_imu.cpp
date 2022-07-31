#include "ros/ros.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"
#include "sensor_msgs/Imu.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/point_cloud2_iterator.h"
#include "pcl_ros/point_cloud.h"

void imu_dataCallback(const sensor_msgs::Imu::ConstPtr pose1)
{

    ROS_INFO("\n"
             "订阅的位姿信息：------------------\n"
             "header:seq=%d,frame_id=%s \n"
             "orientation:x=%.2f,y=%.2f,z=%.2f,w=%.2f \n"
             "angular_velocity:x=%.2f,y=%.2f,z=%.2f\n"
             "linear_acceleration:x=%.2f,y=%.2f,z=%.2f\n",
             pose1->header.seq,
             pose1->header.frame_id.c_str(),
             pose1->orientation.x,
             pose1->orientation.y,
             pose1->orientation.z,
             pose1->orientation.w,
             pose1->angular_velocity.x,
             pose1->angular_velocity.y,
             pose1->angular_velocity.z,
             pose1->linear_acceleration.x,
             pose1->linear_acceleration.y,
             pose1->linear_acceleration.z);
}

void odom_dataCallback(const nav_msgs::Odometry::ConstPtr pose)
{
    ROS_INFO("\n"
             "订阅的位置信息：------------------"
             "header:seq=%d,frame_id=%s,child_frame_id=%s"
             "position:x=%.2f,y=%.2f,z=%.2f"
             "orientation:x=%.2f,y=%.2f,z=%.2f,w=%.2f"
             "linear:x=%.2f,y=%.2f,z=%.2f"
             "angular:x=%.2f,y=%.2f,z=%.2f",
             pose->header.seq,
             pose->header.frame_id.c_str(),
             pose->child_frame_id.c_str(),
             pose->pose.pose.position.x,
             pose->pose.pose.position.y,
             pose->pose.pose.position.z,
             pose->pose.pose.orientation.x,
             pose->pose.pose.orientation.y,
             pose->pose.pose.orientation.z,
             pose->pose.pose.orientation.w,
             pose->twist.twist.linear.x,
             pose->twist.twist.linear.y,
             pose->twist.twist.linear.z,
             pose->twist.twist.angular.x,
             pose->twist.twist.angular.y,
             pose->twist.twist.angular.z);
}

void PointClound_dataCallback(const sensor_msgs::PointCloud2::ConstPtr &msg)
{
    ROS_INFO( " %s",msg->header.frame_id.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "read_imu");
    ros::NodeHandle nh;
    // ros::Subscriber sub1 = nh.subscribe<sensor_msgs::Imu>("/imu/data", 1000, imu_dataCallback);
    // ros::Subscriber sub2 = nh.subscribe<nav_msgs::Odometry>("/navsat/odom", 1000, odom_dataCallback);
    ros::Subscriber sub3 = nh.subscribe<sensor_msgs::PointCloud2>("velodyne_points_0", 1000, PointClound_dataCallback);

    ros::spin();
    return 0;
}
