#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char **argv) {

	ros::init(argc, argv, "minimal_publisher1");
	ros::NodeHandle n;
	ros::Publisher my_publisher_object = n.advertise<std_msgs::Float64>("topic1", 1);

	std_msgs::Float64 input_float; 

	ros::Rate naptime(1.0);

	input_float.data = 0.0;

	while (ros::ok()) 
    	{
        // this loop has no sleep timer, and thus it will consume excessive CPU time
        // expect one core to be 100% dedicated (wastefully) to this small task
        input_float.data = input_float.data + 0.001; //increment by 0.001 each iteration
        my_publisher_object.publish(input_float); // publish the value--of type Float64-- 
        //to the topic "topic1"
	//the next line will cause the loop to sleep for the balance of the desired period 
        // to achieve the specified loop frequency 
	naptime.sleep(); 
    	}
}
