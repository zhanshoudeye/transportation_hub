//
// Created by baiye on 25-1-27.
//

#include "../include/transportation_hub/dijkstra.h"
//存储不同城市序号与城市之间的距离
void Dijkstra::add_edge(int src, int dest, int length){
    graph[src].push_back(std::make_pair(dest, length));
    graph[dest].push_back(std::make_pair(src, length));
}
//计算最短路径，返回一个数组，存储路径上的城市序号
std::vector<int> Dijkstra::get_shortest_path(int src, int dest){
    std::vector<int> distances(num_cities,MAX);
    std::vector<int> previous(num_cities,-1);
    //优先队列，以数组的形式存储两城市的距离和编号
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;

    distances[src] = 0;
    pq.push(std::make_pair(src,0));
    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();

        if(curr==dest)break;
        for(auto& neighbour : graph[curr]){
            int next = neighbour.first;
            int weight = neighbour.second;
            if(distances[next] > distances[curr] + weight){
                distances[next] = distances[curr] + weight;
                previous[next] = curr;
            }
        }
    }
    std::vector<int> path;
    if(distances[dest] != MAX){
        for(int at = dest;at!=-1; at=previous[at]){
            path.push_back(at);
        }
        std::reverse(path.begin(),path.end());
    }
    return path;
}