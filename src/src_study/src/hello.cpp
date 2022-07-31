#include "ros/ros.h"
#include "src_study/hello.h"

namespace hello_ns{
    void MyHello::run()
    {
        ROS_INFO("hello 这是源文件");
    }
}