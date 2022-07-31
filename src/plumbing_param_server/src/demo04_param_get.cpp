#include "ros/ros.h"

/*
    需要实现参数的新增和修改
    需求：设置机器人的共享参数，类型、半径
        再修改半径

    实现：
        ros::NodeHandle----------------------------------------------
            param(键,默认值)
                存在，返回对应结果，否则返回默认值

            getParam(键,存储结果的变量)
                存在,返回 true,且将值赋值给参数2
                若果键不存在，那么返回值为 false，且不为参数2赋值

            getParamCached键,存储结果的变量)--提高变量获取效率
                存在,返回 true,且将值赋值给参数2
                若果键不存在，那么返回值为 false，且不为参数2赋值

            getParamNames(std::vector<std::string>)
                获取所有的键,并存储在参数 vector 中

            hasParam(键)
                是否包含某个键，存在返回 true，否则返回 false

            searchParam(参数1，参数2)
                搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
        ros::param-----------------------------------------------------
            get()
 */

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "get_param");
    ros::NodeHandle nh;

    // ros::NodeHandle----------------------------------------------
    // 1.param(键,默认值)
    double radius = nh.param("radius", 0.5); // 0.5为默认值，获取不到时设置为0.5
    ROS_INFO("radius=%.2f", radius);
    // 2.getParam
    double radius2 = 0.0;
    bool result = nh.getParam("radiusasfasf", radius2);
    if (result)
    {
        ROS_INFO("获取参数成功:%.2f", radius2);
    }
    else
    {
        ROS_ERROR("获取参数失败");
    }
    // 3.getParamCached和getParam类似  但是一般测试情况下看不出来
    double radius3 = 0.0;
    bool result2 = nh.getParamCached("radius", radius3);
    if (result2)
    {
        ROS_INFO("获取参数成功:%.2f", radius3);
    }
    else
    {
        ROS_ERROR("获取参数失败");
    }
    // 4.getParamNames
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("遍历的元素%s", name.c_str());
    }
    // 5.hasParam
    bool result3 = nh.hasParam("radius");
    bool result4 = nh.hasParam("raskodashfi");
    ROS_INFO("radius存在吗%d", result3);
    ROS_INFO("raskodashfi存在吗%d", result4);
    // 6.searchParam
    std::string key;
    nh.searchParam("radius", key);
    ROS_INFO("搜索结果：%s", key.c_str());

    // ros::param-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
    // set()
    ros::param::param("radius",100.5);
    return 0;
}
