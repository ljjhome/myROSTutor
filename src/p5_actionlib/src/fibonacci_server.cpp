#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <p5_actionlib/fibonacciAction.h>

class fibAction
{
protected:
	ros::NodeHandle nh_;
	//NodeHandle must be created before this line
	actionlib::SimpleActionServer<p5_actionlib::fibonacciAction> as_;
	std::string action_name_;
	//create message that are used to publish feedback/resualt
	p5_actionlib::fibonacciFeedback feedback_;
	p5_actionlib::fibonacciResult result_;

public:
	fibAction(std::string name):
		as_(nh_, name, boost::bind(&fibAction::executeCB, this, _1), false),
		action_name_(name)
	{
		as_.start();
	}

	~fibAction(void){}

	void executeCB(const p5_actionlib::fibonacciGoalConstPtr &goal)
	{
		// helper variables
		ros::Rate r(1);
		bool success = true;

		//push_back the seeds for teh fibonacci sequence
		feedback_.sequence.clear();
		feedback_.sequence.push_back(0);
		feedback_.sequence.push_back(1);
	
		// pubulish info to the console for the user
		ROS_INFO("%s: Executing, creating fibonacci sequence of order %i with seeds %i, %i",
			action_name_.c_str(), goal->order,feedback_.sequence[0], feedback_.sequence[1]);

		// start executing the action
		for(int i = 1; i<=goal->order;i++)
		{
			//check that preempt has not been requested by the client
			if(as_.isPreemptRequested()||!ros::ok()){
				ROS_INFO("%s: Preempted", action_name_.c_str());
				//set action state to preempted
				as_.setPreempted();
				success = false;
				break;
			}
			feedback_.sequence.push_back(feedback_.sequence[i] + feedback_.sequence[i-1]);

			//publish the feedback
			as_.publishFeedback(feedback_);

			//this sleep is not necessary, the sequence is computed at 1hz for demostration purpose
			r.sleep();
		}
		
		if(success){
			result_.sequence = feedback_.sequence;
			ROS_INFO("%s: Succeeded", action_name_.c_str());
			//set the action state to succeeded
			as_.setSucceeded(result_);
		}
	}
};

int main(int argc, char** argv){
	ros::init(argc,argv,"fibonacci");
	fibAction fibonacci("fibonacci");
	ros::spin();
	return 0;
}
