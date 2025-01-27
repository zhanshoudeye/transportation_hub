//
// Created by baiye on 25-1-27.
//
#include "../include/transportation_hub/transportation_hub_node.h"
int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<transportation_client>());
  rclcpp::shutdown();
}