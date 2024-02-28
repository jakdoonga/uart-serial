#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <std_msgs/UInt32.h>
#include <iostream>
#include <string>
#include <vector>

serial::Serial ser;

void write_callback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO_STREAM("Writing to serial port" << msg->data);
    ser.write(msg->data);
}

int main (int argc, char** argv){
    ros::init(argc, argv, "serial_example_node");
    ros::NodeHandle nh;

    ros::Subscriber write_sub = nh.subscribe("write", 10, write_callback);
    ros::Publisher read_pub = nh.advertise<std_msgs::String>("read", 1);

    try
    {
        ser.setPort("/dev/ttyACM0");
        ser.setBaudrate(115200);
        serial::Timeout to = serial::Timeout::simpleTimeout(60);
        ser.setTimeout(to);
        ser.open();
    }
    catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port ");
        return -1;
    }

    if(ser.isOpen()){
        ROS_INFO_STREAM("Serial Port initialized");
    }else{
        return -1;
    }

    ros::Rate loop_rate(25);
    while(ros::ok()){
        ros::spinOnce();
        if(ser.available()){
            std_msgs::String result;
            std::string buf;

            buf = ser.readline((size_t)100, (std::string)"\r\n");
            result.data = buf;
            read_pub.publish(result);

            ser.flush();

            ROS_INFO_STREAM(result.data);    
        }
        loop_rate.sleep();
    }
    ser.close();
}

