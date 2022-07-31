#include "ros/ros.h"
#include "plumbing_pubsub/Person.h"

void doPerson(const plumbing_pubsub::Person::ConstPtr &person_p){
    ROS_INFO("订阅人信息：%s,%d,%.2f",person_p->name.c_str(),person_p->age,person_p->height);
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"xuesheng");
    ros::NodeHandle nh;
    ros::Subscriber sub=nh.subscribe("liaotian",100,doPerson);

    ros::spin();

    return 0;
}
