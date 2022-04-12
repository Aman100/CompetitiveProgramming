#include<bits/stdc++.h>
using namespace std;

int solve(int row, int col, vector<vector<int>> &grid)
{
if(row==grid.size()-1 && col==grid[0].size()-1) return 1;
if(row>=grid.size() || col>=grid[0].size()) return 0;
return solve(row, col+1,grid) + solve(row+1,col,grid);
}

int main()
{
vector<vector<int>> grid={
{1,1,1},
{1,1,1},
{1,1,1}
};
cout<<solve(0,0,grid);
}