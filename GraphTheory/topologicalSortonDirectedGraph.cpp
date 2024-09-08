#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

void dfs(char src, const unordered_map<char, vector<pair<char, int>>>& graph, stack<char>& stk, vector<bool>& visited) {
    visited[src - 'A'] = true;
    stk.push(src);

    auto it = graph.find(src);
    if (it != graph.end()) { // Check if the node exists in the graph
        for (const pair<char, int>& i : it->second) {
            if (!visited[i.first - 'A']) {
                dfs(i.first, graph, stk, visited);
            }
        }
    }
}

vector<char> topologicalSort(unordered_map<char, vector<pair<char, int>>> graph, int V) {
    stack<char> stk;
    vector<bool> visited(V, false);

    // Loop through all possible nodes 'A' to 'A' + V
    for (char i = 'A'; i < 'A' + V; i++) {
        if (!visited[i - 'A'] && graph.find(i) != graph.end()) { // Check if node exists in graph
            dfs(i, graph, stk, visited);
        }
    }

    vector<char> topOrder;
    while (!stk.empty()) {
        topOrder.push_back(stk.top());
        stk.pop();
    }

    return topOrder;
}

int main() {
    unordered_map<char, vector<pair<char, int>>> graph;
    graph['A'].push_back(make_pair('B', 3));
    graph['A'].push_back(make_pair('C', 5));
    graph['B'].push_back(make_pair('D', 2));
    graph['C'].push_back(make_pair('E', 4));
    graph['D'].push_back(make_pair('F', 1));
    graph['E'].push_back(make_pair('G', 2));
    graph['F'].push_back(make_pair('H', 1));
    
    // Adjusted V to be the highest node minus 'A' + 1
    int V = 8; // Nodes from 'A' to 'H'
    vector<char> result = topologicalSort(graph, V);

    cout << "Topological Sort Order: ";
    for (char node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
