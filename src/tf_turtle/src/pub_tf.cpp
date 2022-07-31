#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"

std::string turtle_name;

void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    static tf2_ros::TransformBroadcaster pub_tf;
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = turtle_name;
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;

    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta);
    ts.transform.rotation.w = qtn.getW();
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();

    pub_tf.sendTransform(ts);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "pub_tf");
    if (argc != 2)
    {
        ROS_ERROR("请传入正确的参数");
    }
    else
    {
        turtle_name = argv[1];
        ROS_INFO("乌龟 %s 坐标发送启动", turtle_name.c_str());
    }
    ros::NodeHandle nh;
    //创建订阅对象获取小乌龟的位姿信息，然后通过回调函数处理订阅到的消息
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>(turtle_name + "/pose", 1000, doPose);
    ros::spin();
    return 0;
}
