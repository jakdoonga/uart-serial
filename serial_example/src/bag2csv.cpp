#include <ros/ros.h>
#include <iostream>
#include <string>
#include <typeinfo>

int main (int argc, char** argv)
{
    ros::init(argc, argv, "bag2csv");
    ros::NodeHandle nh;

    int cnt;
    int link_num = 3;

    // char case_name[] = "new"
    char case_name[] = "load";
    // char case_name[] = "spr"
    // char case_name[] = "spr-load"

    /* if just link, comment above case_name and use below

    // 5 10 15 20
    sprintf(up,"rostopic echo -b %d-up-%d-%d.bag /actual > %d-up-%d-%d.csv", 
            link_num, 5*i, cnt, link_num, 5*i, cnt);
    sprintf(down,"rostopic echo -b %d-down-%d-%d.bag /actual > %d-down-%d-%d.csv", 
            link_num, 5*i, cnt, link_num, 5*i, cnt);

    // 30 40 ~ 200
    sprintf(up,"rostopic echo -b %d-up-%d-%d.bag /actual > %d-up-%d-%d.csv",
            link_num, 30+10*i, cnt, link_num, 30+10*i, cnt);
    sprintf(down,"rostopic echo -b %d-down-%d-%d.bag /actual > %d-down-%d-%d.csv", 
            link_num, 30+10*i, cnt, link_num, 30+10*i, cnt);

    */


    char up[100]; 
    char down[100]; 

    std::cout<<"first"<<std::endl;
    cnt = 1;
    // 5 10 15 20
    for(int i=1; i<5; ++i){
        sprintf(up,"rostopic echo -b %d-up-%d-%d-%s.bag /actual > %d-up-%d-%d-%s.csv", 
                link_num, 5*i, cnt, case_name, link_num, 5*i, cnt, case_name);
        sprintf(down,"rostopic echo -b %d-down-%d-%d-%s.bag /actual > %d-down-%d-%d-%s.csv", 
                link_num, 5*i, cnt, case_name, link_num, 5*i, cnt, case_name);

        std::system(up);
        std::cout<<"up done "<<5*i<<std::endl;
        std::system(down);
        std::cout<<"down done "<<5*i<<std::endl;
    }

    // 30 40 ~ 200
    for(int i=0; i<18; ++i){
        sprintf(up,"rostopic echo -b %d-up-%d-%d-%s.bag /actual > %d-up-%d-%d-%s.csv",
                link_num, 30+10*i, cnt, case_name, link_num, 30+10*i, cnt, case_name);
        sprintf(down,"rostopic echo -b %d-down-%d-%d-%s.bag /actual > %d-down-%d-%d-%s.csv", 
                link_num, 30+10*i, cnt, case_name, link_num, 30+10*i, cnt, case_name);

        std::system(up);
        std::cout<<"up done "<<30+10*i<<std::endl;
        std::system(down);
        std::cout<<"down done "<<30+10*i<<std::endl;
    }

    std::cout<<"second"<<std::endl;
    cnt = 2;
    // 5 10 15 20
    for(int i=1; i<5; ++i){
        sprintf(up,"rostopic echo -b %d-up-%d-%d-%s.bag /actual > %d-up-%d-%d-%s.csv", 
                link_num, 5*i, cnt, case_name, link_num, 5*i, cnt, case_name);
        sprintf(down,"rostopic echo -b %d-down-%d-%d-%s.bag /actual > %d-down-%d-%d-%s.csv", 
                link_num, 5*i, cnt, case_name, link_num, 5*i, cnt, case_name);

        std::system(up);
        std::cout<<"up done "<<5*i<<std::endl;
        std::system(down);
        std::cout<<"down done "<<5*i<<std::endl;
    }

    // 30 40 ~ 200
    for(int i=0; i<18; ++i){
        sprintf(up,"rostopic echo -b %d-up-%d-%d-%s.bag /actual > %d-up-%d-%d-%s.csv",
                link_num, 30+10*i, cnt, case_name, link_num, 30+10*i, cnt, case_name);
        sprintf(down,"rostopic echo -b %d-down-%d-%d-%s.bag /actual > %d-down-%d-%d-%s.csv", 
                link_num, 30+10*i, cnt, case_name, link_num, 30+10*i, cnt, case_name);

        std::system(up);
        std::cout<<"up done "<<30+10*i<<std::endl;
        std::system(down);
        std::cout<<"down done "<<30+10*i<<std::endl;
    }
    return 0;
}
