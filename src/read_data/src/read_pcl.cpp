#include <ros/ros.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>

void callback(const sensor_msgs::PointCloud2 &msg)
{
    pcl::PointCloud<pcl::PointXYZ> cloud;
    pcl::fromROSMsg(msg, cloud);
    pcl::io::savePCDFileASCII("/home/shzo/autolabor_ros_ws/src/read_data/data/test.pcd", cloud);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "pcl_write");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/velodyne_points_0", 1, callback);

    ros::spin();
    return 0;
}
