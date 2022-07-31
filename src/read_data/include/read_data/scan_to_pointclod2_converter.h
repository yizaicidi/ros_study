#ifndef LESSON2_SCAN_TO_POINTCLOUD2_CONVERTER_H
#define LESSON2_SCAN_TO_POINTCLOUD2_CONVERTER_H

// ros
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

// pcl_ros
#include <pcl_ros/point_cloud.h>

// pcl
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

class ScanToPointCloud2Converter
{
    // 使用PCL中点的数据结构 pcl::PointXYZ
    typedef pcl::PointXYZ PointT;
    // 使用PCL中点云的数据结构 pcl::PointCloud<pcl::PointXYZ>
    typedef pcl::PointCloud<PointT> PointCloudT;

private:
    ros::NodeHandle node_handle_;           // ros中的句柄
    ros::NodeHandle private_node_;          // ros中的私有句柄
    ros::Subscriber laser_scan_subscriber_; // 声明一个Subscriber
    ros::Publisher pointcloud2_publisher_;  // 声明一个Publisher
    PointT invalid_point_;                  // 保存无效点的值,为nan
public:
    ScanToPointCloud2Converter();
    ~ScanToPointCloud2Converter();
    void ScanCallback(const sensor_msgs::LaserScan::ConstPtr &scan_msg);
};

#endif // LESSON2_SCAN_TO_POINTCLOUD2_CONVERTER_H
