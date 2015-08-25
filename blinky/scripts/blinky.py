#!/usr/bin/env python
import rospy
from std_msgs.msg import Bool
import RPi.GPIO as GPIO

def callback(ledSwitch):
    rospy.loginfo(rospy.get_caller_id() + " Receiving command to turn LED on GPIO17 %s", "on" if data.data else "off")
    GPIO.output(17, data.data)
    
def main():

    rospy.init_node('blinky_control', anonymous=False)
    rospy.Subscriber('led17', Bool, callback)
    
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)
    GPIO.setup(17, GPIO.OUT)

    rospy.spin()

if __name__ == "__main__":
    main()
