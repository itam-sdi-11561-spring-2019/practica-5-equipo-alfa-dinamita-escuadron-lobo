#include <ros.h>
#include <std_msgs/String.h>
using namespace std;

ros::NodeHandle  nh;

int led = 11;

char msg[6] = "";

void prendeLED(std_msgs::String &mensaje)
{
  digitalWrite(11,HIGH);
  delay(3000);
  digitalWrite(11,LOW);
  msg[6] = "Listo";
}

ros::Subscriber<std_msgs::String> sub("led",prendeLED);

std_msgs::String s;
ros::Publisher pub("respuesta",&s);

void setup()
{
  pinMode(led,OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(pub);
}

void loop() 
{
  s.data = msg;
  pub.publish(&s);
  nh.spinOnce();
}
