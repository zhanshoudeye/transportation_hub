//
// Created by baiye on 25-1-26.
//

#ifndef TRANSPORTATION_HUB_NODE_H
#define TRANSPORTATION_HUB_NODE_H

#include <vector>
#include <rclcpp/rclcpp.hpp>
#include "dijkstra.h"
#include "judger_interfaces/srv/my_service.hpp"
#include "judger_interfaces/msg/my_answer.hpp"
#include "judger_interfaces/msg/overall_info.hpp"
using Server = judger_interfaces::srv::MyService;
using Question = judger_interfaces::msg::OverallInfo;
using Answer = judger_interfaces::msg::MyAnswer;

class transportation_client : public rclcpp::Node{
private:
    rclcpp::Client<Server>::SharedPtr client_;
    rclcpp::Subscription<Question>::SharedPtr question_sub_;
    Answer answer_;
    //回调函数
    void question_callback(const Question::SharedPtr msg);
    void send_answer(const Answer answer);
public:
  //构造函数
    transportation_client();
};



#endif //TRANSPORTATION_HUB_NODE_H
