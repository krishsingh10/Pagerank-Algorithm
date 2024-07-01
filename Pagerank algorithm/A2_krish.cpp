#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void build_graph(unordered_map<int,vector<int>> &graph_map, vector<vector<int>> &links_vec) {
    for(int i=0; i<links_vec.size(); i++){
        if(graph_map.find(links_vec[i][1]) == graph_map.end()){
            vector<int> temp;
            graph_map[links_vec[i][1]] = temp;
        }
        graph_map[links_vec[i][0]].push_back(links_vec[i][1]);
    }
}

void init_pagerank(unordered_map<int,double> &pagerank, unordered_map<int,vector<int>> &graph_map) {
    for(auto node: graph_map){
        pagerank[node.first] = 0;
    }
    pagerank.begin()->second = 1;
}

void calculate_pagerank(unordered_map<int,double> &pagerank, unordered_map<int,vector<int>> &graph_map, 
vector<vector<int>> &links_vec, double damping_factor, int max_iterations, int total_nodes) {
    while(max_iterations--){
        unordered_map<int,double> temp_pagerank;
        for(auto node: graph_map){
            temp_pagerank[node.first] = 0;
        }
        for(int i=0;i<links_vec.size();i++){
            temp_pagerank[links_vec[i][1]] += (1/(double)graph_map[links_vec[i][0]].size())*pagerank[links_vec[i][0]];
        }
        double temp = 0;
        for(auto node: graph_map){
            if(node.second.size()==0){
                temp += (1/(double)total_nodes)*(pagerank[node.first]);
            }
        }
        for(auto node:graph_map){
            temp_pagerank[node.first] += temp;
        }
        for(auto node:graph_map){
            pagerank[node.first] = (damping_factor*temp_pagerank[node.first]);
            pagerank[node.first] += (1-damping_factor)*(1/(double)total_nodes);
        }
    }
}

void print_results(vector<bool> &visited_nodes, unordered_map<int,double> &pagerank) {
    double pagerank_sum = 0;
    for(int i = 0; i<visited_nodes.size(); i++) {
        if(visited_nodes[i]){
            cout << i << " = " << pagerank[i] << "\n";
            pagerank_sum += pagerank[i];
        }
    }
    cout << "s= " << pagerank_sum << "\n";
}

int main() {
    vector<vector<int>> links;
    vector<bool> visited_nodes(1000001,false);
    int from_node, to_node;
    while(cin >> from_node) {
        cin >> to_node;
        links.push_back({from_node, to_node});
        visited_nodes[from_node] = true;
        visited_nodes[to_node] = true;
    }
    
    double damping_factor = 0.85;
    int max_iterations = 103;

    unordered_map<int,vector<int>> graph_map;
    build_graph(graph_map, links);

    int total_nodes = graph_map.size();
    unordered_map<int,double> pagerank;
    init_pagerank(pagerank, graph_map);

    calculate_pagerank(pagerank, graph_map, links, damping_factor, max_iterations, total_nodes);

    print_results(visited_nodes, pagerank);

    return 0;
}