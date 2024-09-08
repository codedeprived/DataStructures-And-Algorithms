#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void dfs(char src , const unordered_map<char, vector<pair<char,int>>>& graph , stack<char>& stk , vector<bool>& visited )
{
    visited[src-'A'] = true;

    auto it = graph.find(src);
    if (it != graph.end()) { // Check if the node exists in the graph
        for (const pair<char, int>& i : it->second) {
            if (!visited[i.first - 'A']) {
                dfs(i.first, graph, stk, visited);
            }
        }
    }
    stk.push(src);
}
vector<char> topologicalSort(unordered_map<char,vector<pair<char,int>>> graph , int V)
{
    stack<char> stk;
    vector<bool> visited(V, false);

    for (char i = 'A'; i < 'A' + V; i++) {
        if (!visited[i - 'A'] && graph.find(i) != graph.end()) { // Check if node exists in graph
            dfs(i, graph, stk, visited);
        }
    }

    vector<char> topOrder;
    while(!stk.empty())
    {
        topOrder.push_back(stk.top());
        stk.pop();
    }

    return topOrder;

}
vector<int> findShortestPath(unordered_map<char, vector<pair<char, int>>> graph, int V, char start) {
    vector<char> topOrder = topologicalSort(graph, V);

    // Initialize distances to all nodes as infinite except the start node
    vector<int> dist(V, INT_MAX);
    dist[start - 'A'] = 0; // Distance to the start node is 0

    // Traverse nodes in topological order
    for (char u : topOrder) {
        // If the current node has been reached (i.e., its distance is not infinity)
        if (dist[u - 'A'] != INT_MAX) {
            // Check all neighbors of the current node
            for (const auto& neighbor : graph[u]) {
                char v = neighbor.first;
                int weight = neighbor.second;

                // Relax the edge if a shorter path is found
                if (dist[u - 'A'] + weight < dist[v - 'A']) {
                    dist[v - 'A'] = dist[u - 'A'] + weight;
                }
            }
        }
    }

    return dist;
}
int main()
{
    // this is my graph representation , holds int -> Vertex , and vector<edge> (holds all neigbours of my vertex ) like edge.dest = neibour
    //edge.weigth = cost from going  from Vertex Vi to all its neibours ;
    // my DAG ( weighted)
     unordered_map<char, vector<pair<char,int>>> graph;

    int V = 8;
    char start = 'A';

    graph['A'].push_back({'B',3});
    graph['A'].push_back({'C',6});
    graph['B'].push_back({'C',4});
    graph['B'].push_back({'D',4});
    graph['B'].push_back({'E',9});
    graph['C'].push_back({'D',8});
    graph['C'].push_back({'G',11});
    graph['D'].push_back({'E',-4});
    graph['D'].push_back({'F',5});
    graph['D'].push_back({'G',2});
    graph['E'].push_back({'H',9});
    graph['F'].push_back({'H',1});
    graph['G'].push_back({'H',2});

    graph['H'];
    vector<int> shortestPath = findShortestPath(graph , V , start);
    
    cout<<"shortest distance from A to E is : "<<shortestPath['E' - 'A'];




}