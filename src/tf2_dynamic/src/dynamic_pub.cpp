#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/TransformStamped.h"
/*
    对于未知话题怎么获取数据流程（以小乌龟位姿为例）

    1。首先获得话题信息,通过此命令可以查看当前ros下一些话题的情况
    rostopic list
    2。然后对我们想要获取话题的数据，首先查看其中有什么消息或者服务
    rostopic info /turtle1/pose
    3。获取到消息类型后，再查看其消息格式
    rosmsg info turtlesim/Pose

    得到以下内容
    float32 x
    float32 y
    float32 theta
    float32 linear_velocity
    float32 angular_velocity

*/

void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("订阅的位姿信息：%.2f,%.2f,%.2f", pose->x, pose->y, pose->theta);
    //处理订阅到的消息
    //使用static让每一次回调函数用的是用一个广播器
    static tf2_ros::TransformBroadcaster pub_tf;
    //组织被发布的数据
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = "turtle1";
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
    ros::init(argc, argv, "dynamic_pub");
    ros::NodeHandle nh;
    //创建订阅对象获取小乌龟的位姿信息，然后通过回调函数处理订阅到的消息
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 1000, doPose);
    ros::spin();
    return 0;
}
