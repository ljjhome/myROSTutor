#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char** argv){
	ros::init(argc,argv,"basic_shapes");
	ros::NodeHandle n;
	ros::Rate r(1);
	ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker",1);

	//Set our initial shape type to be a cube
	uint32_t shape = visualization_msgs::Marker::CUBE;

	while(ros::ok()){
		visualization_msgs::Marker marker;
		// Set the frame ID and timestamp, see TF tutroial
		marker.header.frame_id = "/my_frame";
		marker.header.stamp = ros::Time::now();
		
		// Set the name space and id for this marker. This serves to create a unique ID
		marker.ns = "basic_shapes";
		marker.id = 0;
	
		//Set the marker type
		marker.type = shape;

		// Set the marker action
		marker.action = visualization_msgs::Marker::ADD;

		// Set the pos of the marker. this is a full 6DOF pose relative to the frame/time specified in the header
		marker.pose.position.x = 0;
		marker.pose.position.y = 0;
		marker.pose.position.z = 0;
		marker.pose.orientation.x = 0.0;
		marker.pose.orientation.y = 0.0;
		marker.pose.orientation.z = 0.0;
		marker.pose.orientation.w = 1.0;
		
		//Set the scale of the marker
		marker.scale.x = 1.0;
		marker.scale.y = 1.0;
		marker.scale.z = 1.0;
	
		//Set the color be sure to set alph to something non-zeros
		marker.color.r = 0.0f;
		marker.color.g = 1.0f;
		marker.color.b = 0.0f;
		marker.color.a = 1.0;

		marker.lifetime = ros::Duration();

		//Publish the marker
		while(marker_pub.getNumSubscribers()<1)
		{
			if(!ros::ok()){
				return 0;
			}
			ROS_WARN_ONCE("Please create a subscriber to the marker");
			sleep(1);
		}
		marker_pub.publish(marker);
		
		// Cycle between different shapes
		switch(shape)
		{
		case visualization_msgs::Marker::CUBE:
			shape = visualization_msgs::Marker::SPHERE;
			break;
		case visualization_msgs::Marker::SPHERE:
			shape = visualization_msgs::Marker::ARROW;
			break;
		case visualization_msgs::Marker::ARROW:
			shape = visualization_msgs::Marker::CYLINDER;
			break;
		case visualization_msgs::Marker::CYLINDER:
			shape = visualization_msgs::Marker::CUBE;
			break;
		}
		r.sleep();
	}
}
