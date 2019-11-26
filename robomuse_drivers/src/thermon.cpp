#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Twist.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


void my_handler (int s)
{
 //system("gnome-terminal");
 system("cd ~/ && ./dock.sh");
 while(1);
 exit(1);
}

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
   ros::NodeHandle n;
  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/robomuse/cmd_vel", 1000);
  geometry_msgs::Twist myTwistMsg;
  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  struct sigaction sigIntHandler;

  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;

  sigaction(SIGINT, &sigIntHandler, NULL);


  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  move_base_msgs::MoveBaseGoal goal;
  geometry_msgs::Point initpose;
  
  //int x1 = initpose.x;
  //while(x1 == initpose.x);

  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = -0.06181;
  goal.target_pose.pose.position.y = -3.0868;
  goal.target_pose.pose.orientation.z =-0.715;
  goal.target_pose.pose.orientation.w = 0.699;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -4.158;
  goal.target_pose.pose.position.y = -3.2909;
  goal.target_pose.pose.orientation.z = -0.999;
  goal.target_pose.pose.orientation.w = 0.0019;
  ac.sendGoal(goal);
  ac.waitForResult(); 
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -7.7648;
  goal.target_pose.pose.position.y = -3.683;
  goal.target_pose.pose.orientation.z = -0.998;
  goal.target_pose.pose.orientation.w = 0.3589;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -7.805;
  goal.target_pose.pose.position.y = -0.5;
  goal.target_pose.pose.orientation.z = -0.715;
  goal.target_pose.pose.orientation.w = -0.699;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -7.544;
  goal.target_pose.pose.position.y = 1.668;
  goal.target_pose.pose.orientation.z = -0.755;
  goal.target_pose.pose.orientation.w = -0.7088;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -8.65;
  goal.target_pose.pose.position.y = 6.0088;
  goal.target_pose.pose.orientation.z =-0.2583;
  goal.target_pose.pose.orientation.w = 0.999;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -3.685;
  goal.target_pose.pose.position.y = 6.0088;
  goal.target_pose.pose.orientation.z = 0.0292;
  goal.target_pose.pose.orientation.w = 0.999;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -0.472;
  goal.target_pose.pose.position.y = 6.0088;
  goal.target_pose.pose.orientation.z =-00013;
  goal.target_pose.pose.orientation.w = 0.999;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");

  return 0;
}
