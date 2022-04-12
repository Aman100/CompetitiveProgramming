#include<bits/stdc++.h>
using namespace std;

int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
if(row==grid.size()-1 && col==grid[0].size()-1) return 1;
if(row>=grid.size() || col>=grid[0].size() || grid[row][col]==-1) return 0;
if(dp[row][col]!=-1) return dp[row][col];
return dp[row][col]=(solve(row, col+1,grid,dp) + solve(row+1,col,grid,dp))%1000000007;
}

int main()
{
vector<vector<int>> grid={
{0, -1},
{-1, 0}
};
vector<vector<int>> dp(2,vector<int>(2,-1));
cout<<solve(0,0,grid,dp);
}