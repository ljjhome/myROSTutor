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

	ros::Subscriber sub = nh.subscribe("rrbot/joint_states",1,joint_state_callback);

	ros::Publisher pub = nh.advertise<std_msgs::Float64>("rrbot/joint1_position_controller/command",1);

	ros::Rate loop_rate(10);
	std_msgs::Float64 target_pos;
	target_pos.data=1.5;
	double kp = 5;
	while(ros::ok()){
		//g_force.data = kp*(target_pos.data-pos_now.data);
		pub.publish(target_pos);
		ros::spinOnce();
		loop_rate.sleep();
	}
			
	return 0;
}

