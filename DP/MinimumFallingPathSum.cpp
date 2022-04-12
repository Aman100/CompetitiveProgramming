#include<bits/stdc++.h>
using namespace std;

int solve(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
if(c<0 || c>=grid[0].size() || r>=grid.size())
{
if(r<grid.size()) return 2147483647;
else return 0;
}
if(dp[r][c]!=-1) return dp[r][c];
return dp[r][c]=min(min((long long int)grid[r][c]+(long long int)solve(r+1,c-1,grid,dp),(long long int)grid[r][c]+(long long int)solve(r+1,c,grid,dp)), (long long int)grid[r][c]+(long long int)solve(r+1,c+1,grid,dp));
}

int main()
{
vector<vector<int>> vec={
{-1,-2,-3},
{4, 5, 6},
{-7, -8, -9}
};
vector<vector<int>> dp(vec.size(), vector<int>(vec[0].size(),-1));
	int minElement=2147483647;
	for(int i=0;i<vec[0].size();i++)
	{
		minElement=min(minElement,solve(0,i,vec,dp));
		
	}
	return minElement;
}