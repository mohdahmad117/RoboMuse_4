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
  goal.target_pose.pose.position.x = 5.4851;
  goal.target_pose.pose.position.y = 0.2725;
  goal.target_pose.pose.orientation.z = -0.0133;
  goal.target_pose.pose.orientation.w = 0.9999;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 10.9064;
  goal.target_pose.pose.position.y = 0.9279;
  goal.target_pose.pose.orientation.z = -0.0031;
  goal.target_pose.pose.orientation.w = 0.999;
  ac.sendGoal(goal);
  ac.waitForResult(); 
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 12.6588;
  goal.target_pose.pose.position.y = -1.5926;
  goal.target_pose.pose.orientation.z = -0.2158;
  goal.target_pose.pose.orientation.w = 0.976;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 15.9936;
  goal.target_pose.pose.position.y = -2.7324;
  goal.target_pose.pose.orientation.z = -0.6565;
  goal.target_pose.pose.orientation.w = 0.754;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  return 0;
}
