#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>

std_msgs::Float64 g_force;
std_msgs::Float64 pos_now;
void joint_state_callback(const sensor_msgs::JointState& msg){
	//ROS_INFO("the position of joint1 is %f ", msg.position[0]);
	pos_now.data = msg.position[0];
}

int main(int argc, char** argv){
	ros::init(argc,argv,"rrbot_controller");

	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("/mobileRobot/joint_states",1,joint_state_callback);

	ros::Publisher pub1 = nh.advertise<std_msgs::Float64>("/mobileRobot/left_b_effort_controller/command",1);
    ros::Publisher pub2 = nh.advertise<std_msgs::Float64>("/mobileRobot/left_m_effort_controller/command",1);

	ros::Publisher pub3 = nh.advertise<std_msgs::Float64>("/mobileRobot/left_f_effort_controller/command",1);
	ros::Publisher pub4 = nh.advertise<std_msgs::Float64>("/mobileRobot/right_b_effort_controller/command",1);
	ros::Publisher pub5 = nh.advertise<std_msgs::Float64>("/mobileRobot/right_m_effort_controller/command",1);
	ros::Publisher pub6 = nh.advertise<std_msgs::Float64>("/mobileRobot/right_f_effort_controller/command",1);
	ros::Rate loop_rate(10);
	std_msgs::Float64 target_pos;
	target_pos.data=-1.0;
	double kp = 5;
	while(ros::ok()){
		pub1.publish(target_pos);
                pub2.publish(target_pos);
                pub3.publish(target_pos);
                pub4.publish(target_pos);
                pub5.publish(target_pos);
                pub6.publish(target_pos);
		ros::spinOnce();
		loop_rate.sleep();
	}
			
	return 0;
}

