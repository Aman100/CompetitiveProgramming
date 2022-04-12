#include<bits/stdc++.h>
using namespace std;

void empty(vector<vector<int>> &);

int solve(int r, int c, vector<vector<int>> &grid, int num)
{
if(c<0 || c>=grid[0].size() || r>=grid.size())
{
if(r<grid.size()) return -2147483648;
else return 0;
}
return max(max((long long int)grid[r][c]+(long long int)solve(r+1,c-1,grid,grid[r][c]),(long long int)grid[r][c]+(long long int)solve(r+1,c,grid,grid[r][c])), (long long int)grid[r][c]+(long long int)solve(r+1,c+1,grid,grid[r][c]));
}

int main()
{
/*
-9999 -9888 -9777 -9666 -9555
1      10    2 	   4 	 5
-9999 -9888 -9777 -9666 -9555
-99   -98   -97   -96   -95
*/
vector<vector<int>> grid={
{-1,-2,-3},
{ 5,  6, 7},
{-4,-5,-6}
/*
{-9999, -9888, -9777, -9666, -9555},
{1, 10, 2, 4, 5},
{-9999, -9888, -9777, -9666, -9555},
{0, 0, 0, 0, 0},
{-99, -98, -97, -96, -95}
*/
/*
{10, 10, 2, -13, 20, 4},
{1, -9, -81, 30, 2, 5},
{0, 10, 4, -79, 2, -10},
{1, -5, 2, 20, -11, 4}
*/
/*
{1,2,3},
{9,8,7},
{4,5,6}
*/
//-18,-16,-15,-17
};
vector<vector<int>> dp(5,vector<int>(5,-1));
cout<<solve(0,0,grid,grid[0][0])<<endl;
cout<<solve(0,1,grid,grid[0][1])<<endl;
cout<<solve(0,2,grid,grid[0][2])<<endl;

int maxElement=-2147483648;
for(int i=0;i<grid[0].size();i++)
{
maxElement=max(maxElement,solve(0,i,grid,grid[0][i]));
}
cout<<"RES: "<<maxElement<<endl;
}

void empty(vector<vector<int>> &dp)
{
for(int j=0;j<5;j++)
{
for(int k=0;k<5;k++) dp[j][k]=-1;
}
}