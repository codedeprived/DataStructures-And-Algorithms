#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

#define MAX 11 // Increased MAX to accommodate the highest node number

class Graph {
public:
    vector<int> adj[MAX]; // Adjacency list for storing edges
    bool visited[MAX] = {false}; // Initialize visited array with false

    // Function to add an edge from node u to node v
    void add_edge(int u, int v) {
        adj[u].push_back(v); // Add v to u's adjacency list
        adj[v].push_back(u);
        return;
    }

    // iterative DFS function starting from node a
    void dfs(int start) {
    stack<int> s;                 // Stack to manage the nodes to visit
    s.push(start);                // Start from the given node
    //fill(visited, visited + MAX, false); // Initialize all nodes as not visited
    
    while (!s.empty()) {
        int current = s.top();    // Get the current node from the top of the stack
        s.pop();                  // Remove the current node from the stack
        
        if (!visited[current]) {  // If the current node has not been visited
            visited[current] = true;  // Mark it as visited
            cout << current << " ";   // Print the current node
            
            // Add all unvisited adjacent nodes to the stack
            for (auto i = adj[current].rbegin(); i != adj[current].rend(); ++i) {
                if (!visited[*i]) {
                    s.push(*i);
                }
            }
        }
    }
}

void bfs(int v)
{
    fill (visited , visited+MAX , false);
    queue<int> q;

    q.push(v);
    visited[v] = true;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";

        for(int i : adj[curr])
        {
            if(!visited[i])
            {
                visited[i]  = true;
                q.push(i);
            }
        }
    }
}
int findComponents() {
    int components = 0; // Yeh count karega kitne connected components hain
    fill(visited, visited + MAX, false); // Sab nodes ko initially unvisited mark karo
    
    for (int i = 1; i < MAX; i++) { // Saare nodes par iterate karo
        if (!visited[i] && !adj[i].empty()) { // Agar node visit nahi hua aur uska adjacency list khali nahi hai
            dfs(i); // Yeh dfs call karega us node se start karke
            components++; // Ek component mil gaya, toh count increment karo
        }
    }
    return components; // Total connected components return karo
}

};

int main() {
    Graph g; // Create a graph object
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,4);
    g.add_edge(2,5);
    g.add_edge(3,6);
    g.add_edge(3,7);
    //cout<<g.findComponents();
    //cout<<endl;
    g.bfs(1); // Start DFS from node 1
    return 0;
}
