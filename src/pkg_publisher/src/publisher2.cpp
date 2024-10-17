#include "ros/ros.h"
#include <sensor_msgs/msg/JointState.h>
#include "publisher/quintic.hpp"
#include "std_msgs/Float64MultiArray"



class MyNode
{
    public: 
      std_msgs::Float64MultiArray q0,qf; 
      ros::NodeHandle n;
      ros::Publisher command_pub;
      std::vector<std::string> joint_names_ = {"panda_joint1",
                                                "panda_joint2",
                                                "panda_joint3",
                                                "panda_joint4",
                                                "panda_joint5",
                                                "panda_joint6",
                                                "panda_joint7"};
     MyNode()
     {
            command_pub = n.advertise<sensor_msgs::msg::JointState>("command", 1000);
            q0.data.resize(joint_names_.size());
            qf.data.resize(joint_names_.size());



            // Attendi il singolo messaggio e salvalo nella variabile globale
            auto msg=ros::topic::waitForMessage<sensor_msgs::msg::JointState>("joint_states",ros::Duration(1.0));
            for (size_t i = 0; i < msg->name.size(); ++i) 
            {
                ROS_INFO("Nome: %s, Posizione: %f", msg->name[i].c_str(), msg->position[i]);
            }

            q0=msg->position;
            qf.data=q0.data;
            qf.data[5]+=M_PI/4;             //configurazione da raggiungere

            using namespace std::chrono_literals;
            ros::Time t0=ros::Time::now();
            rclcpp::Duration t(0, 0); 
            ros::Rate loop_rate(5); //5 Hz
            double traj_duration=8.0;
        
            t=ros::Time::now()-t0;

            //riempio il goal
            std_msgs::Float64MultiArray goal;
            goal.data.resize(joint_names_.size());
            goal.data =qf.data;
            goal.layout.dim.resize(1);
            goal.layout.dim[0].label="lunghezza";
            goal.layout.dim[0].size=1;
            //goal.layout.dim[0].stride= ?????
            //goal.layout.data_offset=???;
            command_pub.publish(goal);
            loop_rate.sleep();
     }
}

int main (int argc, char **argv)
{
  ros::init(argc, argv, "prova");
  MyNode my_node;
  ros::spin();
  return 0;
}