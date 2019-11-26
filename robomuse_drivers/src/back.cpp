#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int8.h"


int main(int argc, char **argv)
{

  ros::init(argc, argv, "back");

  ros::NodeHandle n;

  // Advertize the publisher on the topic you like
  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/robomuse/cmd_vel", 1000);
  ros::Publisher pub2 = n.advertise<std_msgs::Int8>("startencryption", 1000);
  

  while (ros::ok())
  {

    geometry_msgs::Twist myTwistMsg;
    myTwistMsg.linear.x = -0.1;
    myTwistMsg.linear.y = 0;
    myTwistMsg.linear.z = 0;

    myTwistMsg.angular.x = 0;
    myTwistMsg.angular.y = 0;
    myTwistMsg.angular.z = 0;

    ros::Time beginTime = ros::Time::now();


    ros::Duration delay1(5.3);
    beginTime = ros::Time::now();

    while(ros::Time::now() - beginTime <= delay1 )
    {
        pub.publish(myTwistMsg);
        ros::Duration(0.1).sleep();
    }

  std_msgs::Int8 msg;
  msg.data = 1;
  pub2.publish(msg);
  return 0;
  }
}
