#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


void addEdge(vector<vector<pair<int,int>>>& graph , int src , int dest , int weight)
{
    graph[src].push_back({dest,weight});
    return;
}

pair<vector<int>,vector<int>> dijkastra(vector<vector<pair<int,int>>>& graph , int src , int V)
{
    vector<bool> visited(V,false);
    vector<int> dist(V ,INT_MAX);
    vector<int> prev(V,-1);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});  // Push the source vertex with distance 0

    while (!pq.empty()) {
        int index = pq.top().second; // Get the vertex with the smallest distance
        int minValue = pq.top().first;
        pq.pop();

        // If the vertex has been visited, skip it
        if (visited[index]) continue;

        // Mark the vertex as visited
        visited[index] = true;

        // Explore the neighbors of the current vertex
        for (auto edge : graph[index]) {
            int neighbor = edge.first;  // Adjacent vertex
            int weight = edge.second;   // Edge weight

            // If the neighbor hasn't been visited and the new distance is shorter
            if (!visited[neighbor] && dist[index] + weight < dist[neighbor]) {
                prev[neighbor] = index;
                // Update the distance to this neighbor
                dist[neighbor] = dist[index] + weight;
                // Push the updated distance and vertex to the priority queue
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return {dist,prev};
}
int main()
{
  int V = 5;
  vector<vector<pair<int,int>>> graph(5);

    addEdge(graph , 0, 1, 4);
    addEdge(graph , 0, 2, 1);
    addEdge(graph , 2, 1, 2);
    addEdge(graph , 1, 3, 1);
    addEdge(graph , 2, 3, 5);
    addEdge(graph , 3, 4, 3);
    int src = 0;
    pair<vector<int>,vector<int>> distAndPrev = dijkastra(graph , src , V);
    vector<int> minDistanceFromSrcToAllOtherNodes = distAndPrev.first;
    vector<int> prev = distAndPrev.second;


    int j = 0;
    for(auto i : minDistanceFromSrcToAllOtherNodes)
    {
        cout<<"shortest distance from "<<src <<" -> "<< j++ << " : "<< i<<" "<<endl;

    }

    //debug check
    // cout<<endl;

    // for(auto i : prev)
    // {
    //     cout<<i<<" ";
    // }
    //holds path from src to dest
    // here src = 0 , dest = 4;
    vector<int> Path;
    int dest = 4;
    
    if(minDistanceFromSrcToAllOtherNodes[dest] == INT_MAX)
    {
        cout<<"Destination Unreachable: Error 502!"<<endl;
    }
    else{
        //Path reconstruction
        for(int i = dest ; i!=-1 ; i = prev[i] )
        {
            Path.push_back(i);
        }
        reverse(Path.begin() , Path.end());

        for(auto i : Path)
        {
            cout<<i<<" -> ";
        }
    }
    
  return 0;
}