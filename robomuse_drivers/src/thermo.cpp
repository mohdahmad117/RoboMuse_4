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
  goal.target_pose.pose.position.x = -1.2013;
  goal.target_pose.pose.position.y = 2.7745;
  goal.target_pose.pose.orientation.z =0.83;
  goal.target_pose.pose.orientation.w = 0.54;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -0.925;
  goal.target_pose.pose.position.y = 4.664;
  goal.target_pose.pose.orientation.z = 0.656;
  goal.target_pose.pose.orientation.w = 0.75;
  ac.sendGoal(goal);
  ac.waitForResult(); 
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 1.025;
  goal.target_pose.pose.position.y = 5.05;
  goal.target_pose.pose.orientation.z =0.0205;
  goal.target_pose.pose.orientation.w = 0.99;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 1.49;
  goal.target_pose.pose.position.y = 3.86;
  goal.target_pose.pose.orientation.z =-0.56;
  goal.target_pose.pose.orientation.w = 0.82;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -0.2524;
  goal.target_pose.pose.position.y = 2.27;
  goal.target_pose.pose.orientation.z =-0.933;
  goal.target_pose.pose.orientation.w = 0.35;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = -0.8;
  goal.target_pose.pose.position.y = 0;
  goal.target_pose.pose.orientation.z =0;
  goal.target_pose.pose.orientation.w = 1;
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  return 0;
}
