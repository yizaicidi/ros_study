#include "ros/ros.h"

/*
    需要实现参数的新增和修改
    需求：设置机器人的共享参数，类型、半径
        再修改半径

    实现：
        ros::NodeHandle
            setParam()
        ros::param
            set()
 */

int main(int argc, char *argv[])
{
    //初始化ROS节点
    ros::init(argc, argv, "set_param");
    //创建ROS节点句柄
    ros::NodeHandle nh;
    //参数增
    //方案一：nh
    nh.setParam("type", "xiaohuangche");
    nh.setParam("radius", 0.15);
    //方案2：ros::param
    ros::param::set("type_param", "xiaobaiche");
    ros::param::set("radius_param", 0.15);

    //参数改
    //方案1：nh
    nh.setParam("radius", 0.2);
    //方案2：ros::param
    ros::param::set("radius_param", 0.25);

    return 0;
}
