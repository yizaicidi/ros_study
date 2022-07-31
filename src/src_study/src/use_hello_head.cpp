#include "ros/ros.h"
#include "src_study/hello.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_head_src");

    hello_ns::MyHello myhello;
    myhello.run();
    return 0;
}
