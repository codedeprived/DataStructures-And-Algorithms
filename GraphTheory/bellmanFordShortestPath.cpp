#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void addEdge(vector<vector<pair<int,int>>>& graph , int src , int dest , int cost)
{
    graph[src].push_back({dest,cost});
    return;
}

vector<int> bellmonFord(vector<vector<pair<int,int>>>& graph , int V , int start)
{
    vector<int> dist(V,INT_MAX);

    dist[start] = 0;


    for(int i = 0;  i< V-1; i++)
    {
        for(int j = 0;  j<V ; j++)
        {
           for(auto k : graph[j])
           {
                if(dist[j] + k.second < dist[k.first])
                {
                    dist[k.first] = dist[j] + k.second;
                }
           }
        }
    }
    for(int i = 0;  i< V-1; i++)
    {
        for(int j = 0;  j<V; j++)
        {
           for(auto k : graph[j])
           {
                if(dist[j] + k.second < dist[k.second])
                {
                    dist[k.first] = INT_MIN;
                }
           }
        }
    }
    return dist;

}
int main()
{   int V = 9 ;
    vector<vector<pair<int,int>>> graph(V);

    vector<int> src = { 0 ,1 , 2 ,4 , 3 , 1 , 1 , 5 , 6 ,5 };
    vector<int> dest = {1 , 2 , 4 , 3 , 2 , 5 , 6 , 6 ,7 ,7};
    vector<int> cost = { 1 , 1 , 1 , -3 , 1 , 4 , 4 , 5, 4, 3};

     
    for(int i = 0 ; i< src.size() ; i++)
    {
        addEdge(graph , src[i] , dest[i] , cost[i]);
    }
    vector<int> distance = bellmonFord(graph , V , 0);
    int j = 0;
    cout<<"source "<< " destination "<< " distance " << endl;
    for(int i : distance)
    {
        cout << src[j]<< " to "<< dest[j] << " :  ";j++;
        if(i == INT_MIN)
        {
            cout<<"unreachable"<<endl;
            continue;
        }
        cout<<i<<endl;
        

    }
}
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double

// void addEdge(vector<vector<pair<int, int>>> &graph, int src, int dest, int cost) {
//     graph[src].push_back({dest, cost});
// }

// vector<int> bellmonFord(vector<vector<pair<int, int>>> &graph, int V, int start) {
//     vector<int> dist(V, INT_MAX);
//     dist[start] = 0;

//     // Relaxation step
//     for (int i = 0; i < V - 1; i++) {
//         for (int j = 0; j < V; j++) {  // Fix: use V instead of graph.size()
//             for (auto k : graph[j]) {
//                 if (dist[j] != INT_MAX && dist[j] + k.second < dist[k.first]) {
//                     dist[k.first] = dist[j] + k.second;
//                 }
//             }
//         }
//     }

//     // Check for negative weight cycles
//     for (int j = 0; j < V; j++) {
//         for (auto k : graph[j]) {
//             if (dist[j] != INT_MAX && dist[j] + k.second < dist[k.first]) {
//                 dist[k.first] = INT_MIN; // Mark nodes part of a negative cycle
//             }
//         }
//     }
//     return dist;
// }

// int main() {
//     int V = 9;
//     vector<vector<pair<int, int>>> graph(V);  // Fix: Initialize graph with V vertices

//     vector<int> src = {0, 1, 2, 4, 3, 1, 1, 5, 6, 5};
//     vector<int> dest = {1, 2, 4, 3, 2, 5, 6, 6, 7, 7};
//     vector<int> cost = {1, 1, 1, -3, 1, 4, 4, 5, 4, 3};

//     for (int i = 0; i < src.size(); i++) {
//         addEdge(graph, src[i], dest[i], cost[i]);
//     }

//     vector<int> distance = bellmonFord(graph, V, 0);

//     for (int i : distance) {
//         if (i == INT_MAX) {
//             cout << "Unreachable" << endl;
//         } else if (i == INT_MIN) {
//             cout << "Negative Cycle" << endl;
//         } else {
//             cout << i << endl;
//         }
//     }

//     return 0;
// }
