#include <ros/ros.h>
#include <std_msgs/String.h>

void chatterCallback(const std_msgs::String::ConstPtr& msg){
	ROS_INFO_STREAM(msg->data.c_str());
}

using namespace ros;
using namespace std;
int main(int argc, char **argv){

	string listener, l1;
	cout << "Name: ";
	getline(cin, listener);
	l1 = listener;
	listener = listener + "L";
	init(argc, argv, listener);

	NodeHandle n1;
	Subscriber sub = n1.subscribe(l1, 1000, chatterCallback);
	spin();

	return 0;
}