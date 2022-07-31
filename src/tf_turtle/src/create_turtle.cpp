#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "create_turtle");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    ros::service::waitForService("/spawn");

    turtlesim::Spawn spawn;
    spawn.request.x = 1;
    spawn.request.y = 1;
    spawn.request.theta = 1;
    spawn.request.name = "create_turtle";

    bool flag = client.call(spawn);
    if (flag)
    {
        ROS_INFO("新乌龟生成，名字%s，", spawn.response.name.c_str());
    }
    else
    {
        ROS_ERROR("乌龟生成失败");
    }

    ros::spin();

    return 0;
}
