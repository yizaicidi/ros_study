//发布方实现

// 1.包含头文件
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, ""); //解决中文乱码
	// 2.初始化 ROS 节点:命名(唯一)
	ros::init(argc, argv, "erGuozi");
	// 3.实例化 ROS 句柄
	ros::NodeHandle nh;
	// 4.实例化 发布者 对象
	ros::Publisher pub = nh.advertise<std_msgs::String>("fang", 10);
	// 5.组织被发布的数据，并编写逻辑发布数据
	//要求以10hz的频率发布数据，并且在文本后面添加编号
	//先创建被发布的消息
	std_msgs::String msg;
	//发布频率
	ros::Rate rate(0.5);
	//设置编号
	int count = 0;
	//编写循环，循环中发布数据
	ros::Duration(3).sleep();
	while (ros::ok())
	{
		count++;
		// msg.data = "hello";
		//数据拼接
		std::stringstream ss;
		ss << "hello-->" << count;
		msg.data = ss.str();
		pub.publish(msg);
		//添加日志
		ROS_INFO("发布的数据是:%s", ss.str().c_str());
		rate.sleep();
		ros::spinOnce();
	}

	return 0;
}
