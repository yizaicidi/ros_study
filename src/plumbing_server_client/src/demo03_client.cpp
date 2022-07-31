/*
   需求:
        编写两个节点实现服务通信，客户端节点需要提交两个整数到服务器
        服务器需要解析客户端提交的数据，相加后，将结果响应回客户端，
        客户端再解析

    服务器实现:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建 客户端 对象
        5.请求服务，接收响应
*/

//头文件
#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

int main(int argc, char *argv[])
{

    setlocale(LC_ALL, "");

    //调用动态传值
    // 1.格式：rsorun xxxxx xxxx   12  34
    //节点执行时，需要获得命令中的参数，并组织request

    if (argc != 3)
    {
        ROS_ERROR("请提交两个整数");
        return 1;
    }

    //初始化节点
    ros::init(argc, argv, "AddInts_client");
    //创建ros句柄
    ros::NodeHandle nh;
    //创建客户端对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("AddInts");
    //等待服务启动 防止由于客户端先启动抛异常
    // 1.这个函数需要传入参数  参数为等待需要的服务
    ros::service::waitForService("AddInts");
    // 2.这个函数不需要传参
    // client.waitForExistence();
    //组织请求数据，返回bool值，标记是否成功
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    bool flag = client.call(ai);

    if (flag)
    {
        ROS_INFO("请求正常处理，结果为：%d", ai.response.sum);
    }
    else
    {
        ROS_ERROR("处理失败。。。");
    }

    return 0;
}
