//
// Created by baiye on 25-1-26.
//

#include "../include/transportation_hub/transportation_hub_node.h"

using  Server = judger_interfaces::srv::MyService;
using Question = transportation_hub::msg::OverallInfo;
using Answer = transportation_hub::msg::MyAnswer;
//
void transportation_client::question_callback(const Question::SharedPtr msg){
    int number_of_cities = msg->number_of_cities;
    int number_of_roads = msg->number_of_roads;
    int src_city = msg->src_city;
    int dest_city = msg->dest_city;
    Dijkstra dijkstra(number_of_cities);
    for(int i = 0; i < number_of_roads; i++){
        dijkstra.add_edge(msg->road_info[i].source, msg->road_info[i].destination);
    }
    std::vector<int> shortest_path=dijkstra.get_shortest_path(src_city, dest_city);
    for(int i = 0; i < shortest_path.size(); i++){
        answer_.my_answer[i] = shortest_path[i];
    }
    send_answer_to_judger(answer_);
}
auto request=std::make_shared<Server::Request>();
this->client_->async_send_request(request,[&](rclcpp::Client<Server>::SharedFuture result_future)->void{
  auto response = result_future.get();
  RCLCPP_INFO(this->get_logger(), "score : %d", response->score);
});
//
transportation_client::transportation_client():Node("transportation_client_node"){
    question_sub_ = this->create_subscription<Question>("question",10,std::bind(&transportation_client::question_callback,this,std::placeholders::_1));
    client_ = this->create_client<Server>("judger_server");
}