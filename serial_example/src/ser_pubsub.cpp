#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <std_msgs/UInt32.h>
// #include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Int16MultiArray.h>
#include <iostream>
#include <string>

std::string temp_str;
int16_t temp_int;
std::vector<float> lift_ang(3);
std::vector<short int> sea_enc(3);
// float ang;

void msgCallback(const std_msgs::String::ConstPtr& msg){
  std::cout<<std::endl;
  int offset = 0;

  temp_str.clear();
  temp_str = msg->data;

  // temp_int = std::stoi(temp_str.substr(offset,4));
  // lift_ang[0] = 34.5380 - ((float)temp_int - 1407)*360.0/4096.0;
  // ROS_INFO_STREAM("tca1 enc node5 " << temp_int);
  // offset += 4;

  // temp_int = std::stoi(temp_str.substr(offset,4));
  // lift_ang[1] = 33.7726 - ((float)temp_int - 1949)*360.0/4096.0;
  // ROS_INFO_STREAM("tca1 enc node6 " << temp_int);
  // offset += 4;

  // temp_int = std::stoi(temp_str.substr(offset,4));
  // lift_ang[2] = 40.7557 - ((float)temp_int - 2854)*360.0/4096.0;
  // ROS_INFO_STREAM("tca1 enc node7 " << temp_int);
  // offset += 4;

  temp_int = std::stoi(temp_str.substr(offset,4));
  sea_enc[0] = temp_int;
  ROS_INFO_STREAM("sea enc node5 " << temp_int);
  offset += 4;

  temp_int = std::stoi(temp_str.substr(offset,4));
  sea_enc[1] = temp_int;
  ROS_INFO_STREAM("sea enc node6 " << temp_int);
  offset += 4;
  
  temp_int = std::stoi(temp_str.substr(offset,4));
  sea_enc[2] = temp_int;
  ROS_INFO_STREAM("sea enc node7 " << temp_int);

  std::cout<<std::endl;

  // ang = 0.0;
}

int main (int argc, char** argv)
{
  ros::init(argc, argv, "ser_pubsub");
  ros::NodeHandle nh;

  ros::Subscriber ser_sub= nh.subscribe("read", 100, msgCallback);
  // ros::Publisher ser_pub = nh.advertise<std_msgs::Float32>("lift_ang", 100);
  ros::Publisher ser_pub = nh.advertise<std_msgs::Float32MultiArray>("lift_ang", 100);
  ros::Publisher ser_pub2 = nh.advertise<std_msgs::Int16MultiArray>("sea_enc", 100);

  ros::Rate loop_rate(25);
  while(ros::ok())
  {
    ros::spinOnce();
    // std_msgs::Float32 lift_ang;
    // std_msgs::Float32MultiArray lift_ang_;  
    // lift_ang_.data = lift_ang;
    // ser_pub.publish(lift_ang_);

    std_msgs::Int16MultiArray sea_enc_;  
    sea_enc_.data = sea_enc;
    ser_pub2.publish(sea_enc_);

    loop_rate.sleep();
  }

  return 0;
}
