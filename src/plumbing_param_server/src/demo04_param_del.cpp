#include "ros/ros.h"

/*
    参数服务器操作之删除_C++实现:

    ros::NodeHandle
        deleteParam("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false

    ros::param
        del("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false

*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "param_del");
    ros::NodeHandle nh;
    //删除
    // ros::NodeHandle
    // deleteParam("键")
    bool flag1 = nh.deleteParam("radius");
    if (flag1)
    {
        ROS_INFO("删除成功");
    }
    else
    {
        ROS_ERROR("删除失败");
    }
    // ros::param
    // del("键")
    bool flag2 = ros::param::del("radius_param");
    if (flag2)
    {
        ROS_INFO("删除成功");
    }
    else
    {
        ROS_ERROR("删除失败");
    }

    return 0;
}
