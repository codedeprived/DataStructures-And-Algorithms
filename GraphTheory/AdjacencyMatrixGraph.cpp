#include<vector>
#include<iostream>
using namespace std;
// Graph Class 
class Graph {

    public:
    // 2-D matrix to hold graph 
    int n ;
    vector<vector<int>> graph;
    //constructor to initialize graph nodes
    Graph(int n)
    {
        this->n = n;
        this->graph = vector<vector<int>> (n , vector<int>(n,0));
    }

    void add_edge(int i , int j )
    {
        // assign edge from u to u;
        //unweighted , undirected 
        graph[i][j] = 1;
        //
        //assign edge from v to u;
        graph[j][i] = 1;

        return;
    }

    void printGraph()
    {   
        cout<<"[";
        for(int i = 0;  i< n ; i++)
        {
            for(int j = 0 ; j< n ; j++)
            {
                cout<<graph[i][j]<<",";
            }
            if(i != n-1)
            {
                cout<<endl;
            }
        }
        cout<<"]";

    }   

};

int main()
{
    Graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(2,3);

    g.printGraph();

}