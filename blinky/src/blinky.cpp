#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <wiringPi.h>

void setLED(const std_msgs::Bool::ConstPtr& msg)
{
  ROS_INFO_STREAM("Turning LED on GPIO 17 " << msg->data ? "on" : "off");

  if(msg->data) digitalWrite(17, HIGH);
  else digitalWrite(17, LOW);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "blinky");
  ros::NodeHandle n;
  wiringPiSetupGpio();
  ros::Subscriber sub = n.subscribe("led17", 10, setLED);

  // Configure GPIO17
  pinMode(17, OUTPUT);

  ros::spin();

  return 0;
}
