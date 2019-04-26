#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>
using namespace std;

#define RATE_HZ 2

void responde(const std_msgs::String &mensaje)
{
  cout << mensaje.data << endl;
}

string msg = "";

int main(int argc, char **argv)
{
  ros::init(argc,argv,"controla_led_node");
  
  ros::NodeHandle nh;
  
  std_msgs::String s;
  ros::Publisher pub = nh.advertise<std_msgs::String>("/led",1);

  ros::Subscriber sub = nh.subscribe("/respuesta",1000,&responde);
  
  ros::Rate rate(RATE_HZ);
  
  while(ros::ok()) 
  {
    cout << "Prender led?" << endl;
    cin >> msg;
    s.data = msg;
    pub.publish(s);
    ros::spinOnce();
    rate.sleep();
  }
}
