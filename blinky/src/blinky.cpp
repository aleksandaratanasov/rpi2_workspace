#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <wiringPi.h>

void setLED(const std_msgs::Bool::ConstPtr& msg)
{
  ROS_INFO_STREAM("Turning LED " << (msg->data ? "on" : "off"));

  if(msg->data) digitalWrite(19, HIGH);
  else digitalWrite(19, LOW);
}

int main(int argc, char **argv)
{
  ROS_INFO("Run 'gpio export 19 out' before starting this node!");
  ros::init(argc, argv, "blinky");
  ros::NodeHandle n;

  // The gpio 19 is configured outside using the 'gpio export 19 out' command
  wiringPiSetupSys(); // When exporting pins this setup is used

  ros::Subscriber sub = n.subscribe("led", 10, setLED);

  ros::spin();

  return 0;
}
