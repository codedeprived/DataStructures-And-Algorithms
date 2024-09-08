class Solution {
public:
/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.*/



    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0 ; i< n ; i++)
        {
            for(int j = 0 ; j< m ;j++)
            {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O')
                {
                    dfs(visited , board , i , j);
                }
            }
        }

        for(int i =0 ; i< n ; i++)
        {
            for(int j = 0 ; j< m ; j++)
            {
                if( visited[i][j] == true)
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }

    }


   void  dfs(vector<vector<bool>>& visited , vector<vector<char>>& board , int row , int col)
    {
        int n = board.size();
        int m = board[0].size();
        stack<pair<int,int>> st;
        st.push({row , col});
        visited[row][col]= true;
        vector<pair<int,int>> directions{{0,1} , {1,0} , {0 , -1 } , {-1,0}};

        while(!st.empty())
        {
            int r = st.top().first;
            int c = st.top().second;
            st.pop();

            for(auto i : directions)
            {
                int rr = r + i.first;
                int cc = c + i.second;

                if(rr >= 0 && rr < n && cc >= 0 && cc < m && !visited[rr][cc] && board[rr][cc] == 'O')
                {
                    visited[rr][cc] = true;
                    st.push({rr,cc});
                }
            }
        }
    }
};