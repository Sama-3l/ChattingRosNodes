#include <ros/ros.h>
#include <std_msgs/String.h>

#include <sstream>

using namespace std;
using namespace ros;
int main(int argc, char **argv){

	cout << "Enter Name: ";
	string name;
	getline(cin, name);
	name = name + "T";
	
	init(argc, argv, name);

	NodeHandle n1;
	Publisher chatter_pub;

	string talker;
	cout << "Talking to: ";
	getline(cin, talker);
	chatter_pub = n1.advertise<std_msgs::String>(talker, 10);

	Rate loop_rate(1);

	int count = 0;
	while (ok()){
		
		std_msgs::String msg;

		stringstream ss;
		string message;
		
		cout << "Enter Message: ";
		getline(cin, message);
		ss << message;
		msg.data = ss.str();

		//ROS_INFO("%s", msg.data.c_str());

		chatter_pub.publish(msg);

		spinOnce();

		loop_rate.sleep();
		++count;
	}


	return 0;
}