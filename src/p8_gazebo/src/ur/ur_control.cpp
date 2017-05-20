#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>
int main(int argc, char** argv){
    ros::init(argc, argv, "control_ur");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<trajectory_msgs::JointTrajectory>("/arm_controller/command",1);
    ros::Rate loop_rate(10);
    trajectory_msgs::JointTrajectory traj;
    trajectory_msgs::JointTrajectoryPoint trajpoint;
    traj.joint_names.push_back("shoulder_pan_joint");
    traj.joint_names.push_back("shoulder_lift_joint");
    traj.joint_names.push_back("elbow_joint");
    traj.joint_names.push_back("wrist_1_joint");
    traj.joint_names.push_back("wrist_2_joint");
    traj.joint_names.push_back("wrist_3_joint");

    trajpoint.positions.push_back(1);
    
    trajpoint.positions.push_back(1);
    trajpoint.positions.push_back(1);
    trajpoint.positions.push_back(1);
    trajpoint.positions.push_back(1);
    trajpoint.positions.push_back(1);

    ros::Duration duration(5.0);
    trajpoint.time_from_start = duration; 
    traj.points.push_back(trajpoint);
    while(ros::ok()){
        pub.publish(traj);
        loop_rate.sleep();
    }
    return 0;
}


