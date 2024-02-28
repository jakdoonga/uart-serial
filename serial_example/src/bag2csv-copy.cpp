#include <ros/ros.h>
#include <iostream>
#include <string>
#include <typeinfo>

int main (int argc, char** argv)
{
    ros::init(argc, argv, "bag2csv_copy");
    ros::NodeHandle nh;

//     char case_name[] = "load";
//     char case_name[] = "spr";
//     char case_name[] = "spr-load";

    char up[100]; 
    char down[100]; 

    for(int k = 1; k < 3; k++){
        // 25 50 100 150 200
        for(int i=0; i<5; ++i){
                if(i != 0){
                        sprintf(up,"rostopic echo -b up-%d-%d.bag /actual > up-%d-%d.csv", 
                                50*i, k, 50*i, k);
                        sprintf(down,"rostopic echo -b down-%d-%d.bag /actual > down-%d-%d.csv", 
                                50*i, k, 50*i, k);

                        // // case
                        // sprintf(up,"rostopic echo -b up-%d-%d-%s.bag /actual > up-%d-%d-%s.csv", 
                        //         50*i, k, case_name, 50*i, k, case_name);
                        // sprintf(down,"rostopic echo -b down-%d-%d-%s.bag /actual > down-%d-%d-%s.csv", 
                        //         50*i, k, case_name, 50*i, k, case_name);
                        
                        std::system(up);
                        std::cout<<"up done "<<50*i <<k<<std::endl;
                        std::system(down);
                        std::cout<<"down done "<<50*i <<k<<std::endl;
                }
                else{
                        sprintf(up,"rostopic echo -b up-%d-%d.bag /actual > up-%d-%d.csv", 
                                25, k, 25, k);
                        sprintf(down,"rostopic echo -b down-%d-%d.bag /actual > down-%d-%d.csv", 
                                25, k, 25, k);

                        // // case
                        // sprintf(up,"rostopic echo -b up-%d-%d-%s.bag /actual > up-%d-%d-%s.csv", 
                        //         25, k, case_name, 25, k, case_name);
                        // sprintf(down,"rostopic echo -b down-%d-%d-%s.bag /actual > down-%d-%d-%s.csv", 
                        //         25, k, case_name, 25, k, case_name);

                        std::system(up);
                        std::cout<<"up done "<<25 <<k<<std::endl;
                        std::system(down);
                        std::cout<<"down done "<<25 <<k<<std::endl;
                }
                std::cout<<std::endl;
        }
    }
    
    return 0;
}
