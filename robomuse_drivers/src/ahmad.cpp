#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);
  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  move_base_msgs::MoveBaseGoal goal;
  //we'll send a goal to the robot to move 1 meter forward
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = 0.0;
  goal.target_pose.pose.position.y = 2.0;
  goal.target_pose.pose.orientation.z =0.0;
  goal.target_pose.pose.orientation.w = 0.0;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 2.343;
  goal.target_pose.pose.position.y = -1.519;
  goal.target_pose.pose.orientation.z =-0.0275;
  goal.target_pose.pose.orientation.w = 0.9996;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 4.232;
  goal.target_pose.pose.position.y = -1.601;
  goal.target_pose.pose.orientation.z =.0031;
  goal.target_pose.pose.orientation.w = 0.999;
  ac.sendGoal(goal);
  ac.waitForResult(); 
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 6.1365;
  goal.target_pose.pose.position.y = -1.4126;
  goal.target_pose.pose.orientation.z =0.00412;
  goal.target_pose.pose.orientation.w = 0.999;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 6.7416;
  goal.target_pose.pose.position.y = 0.5926;
  goal.target_pose.pose.orientation.z =0.10000;
  goal.target_pose.pose.orientation.w = 0.633;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 4.232;
  goal.target_pose.pose.position.y = -1.601;
  goal.target_pose.pose.orientation.z =.0031;
  goal.target_pose.pose.orientation.w = 0.999;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 2.343;
  goal.target_pose.pose.position.y = -1.519;
  goal.target_pose.pose.orientation.z =-0.0275;
  goal.target_pose.pose.orientation.w = 0.9996;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 0;
  goal.target_pose.pose.position.y = 0;
  goal.target_pose.pose.orientation.z = 0;
  goal.target_pose.pose.orientation.w = 1;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  return 0;
}
