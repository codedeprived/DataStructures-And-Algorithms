#include<unordered_map>
#include<list>
#include<iostream>
#include<vector>
using namespace std;
# define MAX 4
class Graph{

    public:
    //map to store Node (key) mapped to values(Adjacent Nodes or Connected Nodes)
    unordered_map< char, list<char> > graphLists;
    vector<int> visited;//visited Array to keep track of already visited node
    Graph()
    {
        //constructor to initialize visited vector;
        visited = vector<int>(4,0);
    }
    void add_edge(char v1 , char v2){
        // v1 connencted to v2 
        graphLists[v1].push_back(v2);

        //v2 connectted to v1 (undirected graph)
        graphLists[v2].push_back(v1);

    }
    void printGraph()
    {
        cout<<"Lists Representation of graph :"<<endl;

        for(auto i : graphLists)
        {
            cout<<i.first<<"->";
            for(auto j : i.second)
            {
                cout<<j<<"->";
            }
            cout<<endl;
        }
    }
    void dfs(char start)
    {
        if(visited[start - 'A'])
        {
            return;
        }
        visited[start-'A'] = 1;
        cout<<start<<" ";

        for(auto i : graphLists[start])
        {
            dfs(i);
        }
        return;
    }
    
};

int main()
{
    Graph g;

    g.add_edge('A', 'B');
    g.add_edge('B', 'C');
    g.add_edge('C', 'D');

    //g.printGraph();
    g.dfs('A');
}