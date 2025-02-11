//
// Created by baiye on 25-1-27.
//

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
//定义无穷大
static const int MAX=1000;
//Dijkstra类，用于存储Dijkstra算法
class Dijkstra {
private:
  int num_cities;
  std::unordered_map<int, std::vector<std::pair<int,int>>> graph;
public:
  //构造函数
  Dijkstra(int num_cities):num_cities(num_cities){}
  //存储不同城市序号与城市之间的距离
  void add_edge(int src, int dest, int length);
  //计算最短路径，返回一个数组，存储路径上的城市序号
  std::vector<int> get_shortest_path(int src, int dest);
};



#endif //DIJKSTRA_H
