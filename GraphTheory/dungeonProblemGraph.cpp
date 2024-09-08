#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int findPathLength(vector<vector<char>> level)
{
    int n = level.size();
    int m = level[0].size();

    int sr , sc ;
    int er , ec ;
    for(int i = 0; i< n ; i++)
    {
        for(int j = 0 ; j< m ; j++)
        {
            if(level[i][j] == 'S')
            {
                sr = i ; sc = j;
            }
            if( level[i][j] == 'E')
            {
                er = i ; ec = j;
            }
        }
    }
    vector<vector<bool>> visited(n , vector<bool>(m,false));
    queue<int> qr;
    queue<int> qc;

    qr.push(sr); qc.push(sc);
    visited[sr][sc] = true;

    int pathLength = 0;
    int nodes_left_in_layer = 1;
    int nodes_in_next_layer = 0;
    bool exitFound = false;

    while(!qr.empty())
    {
        int r = qr.front(); qr.pop();
        int c = qc.front(); qc.pop();
        if(er == r && ec == c)
        {
            exitFound = true;
            break;
        }
        vector<pair<int,int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};

        for(auto i : directions)
        {
            int rr = r + i.first;
            int cc = c + i.second;

            if(rr >= 0 && rr < n && cc >= 0 && cc < m && !visited[rr][cc] && level[rr][cc] != '#')
            {
                visited[rr][cc]  = true;
                qr.push(rr);
                qc.push(cc);
                nodes_in_next_layer++;
            }
        }
        nodes_left_in_layer--;
        if(nodes_left_in_layer == 0)
        {
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            pathLength++;
        }   
    }
    if(exitFound)
    {
        return pathLength;
    }
    return -1;
}

int main()
{
  vector<vector<char>> level = {{'S', '.', '.' ,'#','.','.','.'}
                                ,{'.', '#', '.' ,'.','.','#','.'}
                                ,{'.', '#', '.' ,'.','.','.','.'}
                                ,{'.', '.', '#' ,'#','.','.','#'}
                                ,{'#', '#', '#' ,'.','.','#','E'}};
    int ans = findPathLength(level);
    cout<<"path Length "<<ans<<endl;

}