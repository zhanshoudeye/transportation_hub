//
// Created by baiye on 25-1-26.
//

#include "transportation_hub_node.h"

using Server = judger_interfaces::srv::MyService;
using Question = judger_interfaces::msg::OverallInfo;
using Answer = judger_interfaces::msg::MyAnswer;
transportation_client::transportation_client():Node("transportation_client_node"){
    question_sub_ = this->create_subscription<Question>("question",10,std::bind(&transportation_client::question_callback,this,std::placeholders::_1));
    client_ = this->create_client<Server>("judger_server");
}
void transportation_client::question_callback(const Question::SharedPtr msg){

    Dijkstra dijkstra(msg->number_of_cities);
    for(int i = 0; i < msg->number_of_roads; i++){
        dijkstra.add_edge(msg->infos[i].source, msg->infos[i].destination,msg->infos[i].length);
    }

    answer_.my_answer = dijkstra.get_shortest_path(msg->src_city, msg->des_city);

    send_answer(answer_);
}
void transportation_client::send_answer(Answer answer){
    auto request = std::make_shared<Server::Request>();
    request->answer = answer;

    auto result = client_->async_send_request(request,[&](rclcpp::Client<Server>::SharedFuture result_future)->void{
         auto response = result_future.get();
         RCLCPP_INFO(this->get_logger(), "Score : %d", response->score);
    });


}