// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double


// void dfs(int curr , vector<vector<int>> adj , stack<int>& st , vector<bool>& visited)
// {
//     visited[curr] = true;

//     for(int i : adj[curr])
//     {
//         if(!visited[i])
//         {
//             dfs(i , adj , st , visited);
//         }
//     }
//     st.push(curr);
// }

// vector<int> topologicalSort(int V , vector<vector<int>> adj)
// {
//     stack<int> st;
//     vector<bool> visited(V,false);
//     vector<int> result;
//     for(int i = 0; i< V ; i++)
//     {
//         if(!visited[i])
//         {
//             dfs(i , adj , st , visited);
//         }
//     }

//     while(!st.empty())
//     {
//         result.push_back(st.top());
//         st.pop();
//     }

//     return result;
// }

// bool isCyclic(int src , vector<bool>& visited , vector<vector<int>> adj , vector<bool>& stk)
// {
//     stk[src] = true;
    
//     if(!visited[src])
//     {
//         visited[src] = true;

//         for(int i : adj[src])
//         {
//             if(!visited[i] and isCyclic( i , visited , adj , stk))
//             {
//                 return true;
//             }
//             if(stk[i])
//             {
//                 return true;
//             }
//         }
//     }
//     stk[src] = false;
//     return false;
// }
// int main()
// {
//     int V = 6;

//     vector<vector<int>> adj(V);

//     adj[5].push_back(2);
//     adj[5].push_back(0);
//     adj[4].push_back(0);
//     adj[4].push_back(1);
//     adj[4].push_back(5);

//     bool cycle = false;
//     vector<bool> stk(V , false);
//     vector<bool> visited(V, false);
//     for(int i = 0 ; i<V; i++)
//     {
//         if(!visited[i] and isCyclic(i , visited , adj , stk))
//         {
//             cycle = true;
//         }
//     }

//     if(cycle)
//     {
//         cout<<"cycle present"<<endl;
//         return 0;
//     }

//     else
//     {
//         cout<<"cycle is not present so topsort possible :\n";
//         vector<int> result = topologicalSort(V , adj);
//         cout<<"topsort Order :\n";
//         for(int i : result)
//         {
//             cout<<i<<" ";
//         }
//         return 0;
//     }
    
// }
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS and Topological Sort
void dfs(int node, vector<bool>& visited, stack<int>& stk, const vector<vector<int>>& adj) {
    visited[node] = true;

    // Traverse all adjacent vertices
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, stk, adj);
        }
    }

    // Push the current node to the stack after visiting all its neighbors
    stk.push(node);
}

// Function to perform Topological Sort on the given graph
vector<int> topologicalSort(int V, const vector<vector<int>>& adj) {
    stack<int> stk;
    vector<bool> visited(V, false);

    // Perform DFS from each unvisited node
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, stk, adj);
        }
    }

    // Retrieve the Topological Order from the stack
    vector<int> topoOrder;
    while (!stk.empty()) {
        topoOrder.push_back(stk.top());
        stk.pop();
    }

    return topoOrder;
}

int main() {
    int V = 6;  // Number of vertices
    vector<vector<int>> adj(V);

    // Add edges to the graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // Perform Topological Sort
    vector<int> result = topologicalSort(V, adj);

    // Print the Topological Order
    cout << "Topological Sort: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
