//
// Created by baiye on 25-1-26.
//

#ifndef TRANSPORTATION_HUB_NODE_H
#define TRANSPORTATION_HUB_NODE_H

#include <rclcpp/rclcpp.hpp>
#include <vector>
#include "judger_interfaces/srv/my_service.hpp"
#include "transportation_hub/msg/overall_info.hpp"
#include "transportation_hub/msg/my_answer.hpp"
#include "dijkstra.h"
using  Server = judger_interfaces::srv::MyService;
using Question = transportation_hub::msg::OverallInfo;
using Answer = transportation_hub::msg::MyAnswer;

class transportation_client : public rclcpp::Node{
private:
    rclcpp::Client<Server>::SharedPtr client_;
    rclcpp::Subscription<Question>::SharedPtr question_sub_;
    Answer answer_;
    //回调函数
    void question_callback(const Question::SharedPtr msg);
public:
  //构造函数
    transportation_client();
};



#endif //TRANSPORTATION_HUB_NODE_H
