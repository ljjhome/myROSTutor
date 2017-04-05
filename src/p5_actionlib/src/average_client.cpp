#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <p5_actionlib/averageAction.h>
#include <boost/thread.hpp>

void spinThread(){
	ros::spin();
}

int main(int argc, char** argv){
	ros::init(argc,argv,"test_average");
	
	//create the action client
	actionlib::SimpleActionClient<p5_actionlib::averageAction> ac("averagetop");

	boost::thread spin_thread(&spinThread);

	ROS_INFO("Waiting for action server to start.");
	ac.waitForServer();

	ROS_INFO("Action server started, sending goal.");

	//send a goal to the action
	p5_actionlib::averageGoal goal;
	goal.samples = 100;
	ac.sendGoal(goal);

	//wait for the action to return
	bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

	if(finished_before_timeout){
		actionlib::SimpleClientGoalState state = ac.getState();
		ROS_INFO("Action finished: %s", state.toString().c_str());
	}
	else
		ROS_INFO("Action did not finish before the time out.");

	//shutdown the node and join the thread back before exiting
	ros::shutdown();
	spin_thread.join();
	return 0;
}
