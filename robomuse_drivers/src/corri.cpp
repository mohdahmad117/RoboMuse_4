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
  goal.target_pose.pose.position.x = -0.4607;
  goal.target_pose.pose.position.y = -5.544;
  goal.target_pose.pose.orientation.z = -0.7154;
  goal.target_pose.pose.orientation.w = 0.6986;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -0.9918;
  goal.target_pose.pose.position.y = -11.8850;
  goal.target_pose.pose.orientation.z = -0.7208;
  goal.target_pose.pose.orientation.w = 0.6930;
  ac.sendGoal(goal);
  ac.waitForResult(); 
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -1.5736;
  goal.target_pose.pose.position.y = -17.7197;
  goal.target_pose.pose.orientation.z = -0.29811;
  goal.target_pose.pose.orientation.w = 0.9543;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -3.8047;
  goal.target_pose.pose.position.y = -21.5279;
  goal.target_pose.pose.orientation.z = -0.9912;
  goal.target_pose.pose.orientation.w = 0.1317;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  return 0;
}
