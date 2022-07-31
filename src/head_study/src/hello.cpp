#include "ros/ros.h"
#include "head_study/hello.h"

namespace hello_ns{

    void MyHello::run(){
        ROS_INFO("run函数执行------");
    }
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"test_head");
    hello_ns::MyHello helloPub;
    helloPub.run();
    return 0;
}
