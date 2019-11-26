#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <stdio.h>
#include <iostream>
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
using namespace std;
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

   int i;
   cout << "Where to go: ";
   cin >> i;
   if(i==1)
   {
     cout << "You chose point 1 ";
     goal.target_pose.pose.position.x = -1.0;
     goal.target_pose.pose.position.y = 0.0;
     goal.target_pose.pose.position.z = 0.0;
     goal.target_pose.pose.orientation.w = 1.0;
     ROS_INFO("Sending goal");
     ac.sendGoal(goal);
     ac.waitForResult();
     if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("reached");
     else
     ROS_INFO("not reached");
   }
   else if(i==2)
   {
     cout << "You chose point 2 ";
     goal.target_pose.header.frame_id = "map";
     goal.target_pose.header.stamp = ros::Time::now();
     goal.target_pose.pose.position.x = -1.0;
     goal.target_pose.pose.position.y = -1.0;
     goal.target_pose.pose.position.z = 0.0;
     goal.target_pose.pose.orientation.w = 1.0;
     ROS_INFO("Sending goal");
     ac.sendGoal(goal);
     ac.waitForResult();
     if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("reached");
     else
      ROS_INFO("not reached");
    }
    else if(i==3)
    {
     cout << "You chose point 3 ";
     goal.target_pose.header.frame_id = "map";
     goal.target_pose.header.stamp = ros::Time::now();
     goal.target_pose.pose.position.x = 0.0;
     goal.target_pose.pose.position.y = -1.0;
     goal.target_pose.pose.position.z = 0.0;
     goal.target_pose.pose.orientation.w = 1.0;
     ROS_INFO("Sending goal");
     ac.sendGoal(goal);
     ac.waitForResult();
     if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("reached");
     else
     ROS_INFO("not reached");
    }
    else
    {
     goal.target_pose.header.frame_id = "map";
     goal.target_pose.header.stamp = ros::Time::now();
     goal.target_pose.pose.position.x = 0.0;
     goal.target_pose.pose.position.y = 0.0;
     goal.target_pose.pose.position.z = 0.0;
     goal.target_pose.pose.orientation.w = 1.0;
     ROS_INFO("Sending goal");
     ac.sendGoal(goal);
     ac.waitForResult();
     if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("reached");
     else
       ROS_INFO("not reached");
   }
   return 0;
  }
