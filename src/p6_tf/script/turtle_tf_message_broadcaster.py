import rospy

import turtlesim.msg
import geometry_msgs.msg
import turtlesim.srv
from geometry_msgs.msg import PointStamped, Point
from std_msgs.msg import Header


class PointPublisher:
    def handle_turtle_pose(self, msg, turtlename):
        self.pub.publish(PointStamped(Header(0, rospy.rostime.get_rostime(), "/world"), Point(msg.x, msg.y, 0)))

    def __init__(self):
        self.turtlename = "turtle3"  # rospy.get_param('~turtle')
        self.sub = rospy.Subscriber('/%s/pose' % self.turtlename,
                                    turtlesim.msg.Pose,
                                    self.handle_turtle_pose,
                                    self.turtlename)
        self.pub = rospy.Publisher('turtle_point_stamped', PointStamped, queue_size=1)

if __name__ == '__main__':
    rospy.init_node('tf_turtle_stamped_msg_publisher')
    rospy.wait_for_service('spawn')
    spawner = rospy.ServiceProxy('spawn', turtlesim.srv.Spawn)
    spawner(4, 2, 0, 'turtle3')

    pp = PointPublisher()

    pub = rospy.Publisher("turtle3/cmd_vel", geometry_msgs.msg.Twist, queue_size=1)
    while not rospy.is_shutdown():
        msg = geometry_msgs.msg.Twist()
        msg.linear.x = 1
        msg.angular.z = 1
        pub.publish(msg)
        rospy.sleep(rospy.Duration(0.1))
