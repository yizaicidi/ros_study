#include "ros/ros.h"
#include "plumbing_pubsub/Person.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ROS_INFO("这是消息发布");
    ros::init(argc, argv, "banzhuren");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<plumbing_pubsub::Person>("liaotian", 1000);
    plumbing_pubsub::Person p;
    p.name = "xiabeize";
    p.age = 24;
    p.height = 114514;

    ros::Rate r(1);
    while (ros::ok())
    {
        pub.publish(p);
        p.age += 1;
        ROS_INFO("我叫%s,今年%d岁,高%.2fm", p.name.c_str(), p.age, p.height);
        r.sleep();
        ros::spinOnce();
    }

    return 0;
}
