/** @brief ROS初始化函数。
 *
 * 该函数可以解析并使用节点启动时传入的参数(通过参数设置节点名称、命名空间...)
 *
 * 该函数有多个重载版本，如果使用NodeHandle建议调用该版本。
 *
 * \param argc 参数个数
 * \param argv 参数列表
 * \param name 节点名称，需要保证其唯一性，不允许包含命名空间
 * \param options 节点启动选项，被封装进了ros::init_options
 *
 */

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, ""); //解决中文乱码

    /**
     * @brief 2.初始化 ROS 节点:命名(唯一)
     *
     * 作用：ROS初始化函数
     *
     * 参数：
     * 1. argv  -----封装实参个数（n+1）
     * 2. argv  -----封装参数的数组
     * 3. name  -----为节点命名（唯一性）
     * 4.options-----节点启动选项
     * 返回值:void
     * 使用：
     * 1.argc与argv的使用
     *  如果按照ROS中的特定格式传入实参，那么ROS可以加以使用，比如设置全局变量，给节点命名
     * 2.options的使用
     *  需要多次启动同一节点且都保持运行
     *  解决：ros::init_options::AnonymousName
     */
    ros::init(argc, argv, "erGuozi",ros::init_options::AnonymousName);
    // 3.实例化 ROS 句柄
    ros::NodeHandle nh;
    /**
     * @brief // 4.实例化 发布者 对象
     *
     * 作用：创建发布者对象
     *
     * 模板：被发布的消息类型
     *
     * 参数：
     * 1.话题名称 
     * 2.队列长度 
     * 3.latch（可选）如果为 true,该话题发布的最后一条消息将被保存，
     * 并且后期当有订阅者连接时会将该消息发送给订阅者
     * 使用：
     * latch 设置为true的作用？
     * 以静态地图发布为例，虽然可以使用固定频率发布出去，但是效率太低了，所以可以将地图发布对象的latch设置为true
     * 并且发布方只发送一次数据，每当订阅者连接时，将地图数据发送给订阅者（只发送一次），提高发送效率
     * 
     */
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang", 10,true);
    // 5.组织被发布的数据，并编写逻辑发布数据
    //要求以10hz的频率发布数据，并且在文本后面添加编号
    //先创建被发布的消息
    std_msgs::String msg;
    //发布频率
    ros::Rate rate(1);
    //设置编号
    int count = 0;
    //编写循环，循环中发布数据
    ros::Duration(3).sleep();
    while (ros::ok())
    {
        if(count>=50){
            ros::shutdown();
        }
        count++;
        // msg.data = "hello";
        //数据拼接
        std::stringstream ss;
        ss << "hello-->" << count;
        msg.data = ss.str();
        if(count<=10){
            pub.publish(msg);
            //添加日志
            ROS_INFO("发布的数据是:%s", ss.str().c_str());
        }

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}