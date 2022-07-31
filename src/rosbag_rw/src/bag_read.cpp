#include "ros/ros.h"
#include "rosbag/bag.h"
#include "rosbag/view.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

int main(int argc, char  *argv[])
{   
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"bag_read");
    ros::NodeHandle nh;

    rosbag::Bag bag;
    bag.open("/home/shzo/autolabor_ros_ws/test3.bag",rosbag::BagMode::Read);
    for (rosbag::MessageInstance const m:rosbag::View(bag))
    {
        std_msgs::String::ConstPtr p=m.instantiate<std_msgs::String>();
        if(p!=nullptr){
            ROS_INFO("读取的数据：%s",p->data.c_str());
        }
    }

    bag.close();
    

        return 0;
}
