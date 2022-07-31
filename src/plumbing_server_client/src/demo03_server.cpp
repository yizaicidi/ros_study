#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

bool doReq(plumbing_server_client::AddInts::Request &req, plumbing_server_client::AddInts::Response &resp)
{

    int num1 = req.num1;
    int num2 = req.num2;

    ROS_INFO("服务器接到的请求数据为：num1=%d,num2=%d", num1, num2);

    if (num1 < 0 || num2 < 0)
    {
        ROS_ERROR("提交的数据异常，不能为负数");
        return false;
    }

    resp.sum = num1 + num2;
    ROS_INFO("求和结果：sum=%d",resp.sum);
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "AddInts_Server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("AddInts", doReq);
    ROS_INFO("服务已启动。。。");
    ros::spin();

    return 0;
}
