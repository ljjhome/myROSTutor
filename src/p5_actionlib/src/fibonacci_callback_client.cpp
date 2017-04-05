#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <p5_actionlib/fibonacciAction.h>

using namespace p5_actionlib;

typedef actionlib::SimpleActionClient<fibonacciAction> Client;

// Called once when the goal completes
void doneCb(const actionlib::SimpleClientGoalState& state,
		const fibonacciResultConstPtr& result)
{
	ROS_INFO("Finished in state [%s]", state.toString().c_str());
	ROS_INFO("Answer: %i", result->sequence.back());
	ros::shutdown();
}

// Called once when the goal becomes active
void activeCb()
{
	ROS_INFO("Goal just went active");
}

// Called every time feedback is received for teh goal
void feedbackCb(const fibonacciFeedbackConstPtr& feedback){
	ROS_INFO("Got Feedback of length %lu", feedback->sequence.size());
}

int main(int argc, char** argv){
	ros::init(argc,argv,"test_fibonacci_callback");
	
	// Create the action cilent
	Client ac("fibonacci", true);
	
	ROS_INFO("Waiting for action server to start.");
	ac.waitForServer();
	
	ROS_INFO("Action server started, sending goal.");

	//send goal
	fibonacciGoal goal;
	goal.order = 20;
	ac.sendGoal(goal, &doneCb, &activeCb,&feedbackCb);
	ros::spin();
	return 0;
}
