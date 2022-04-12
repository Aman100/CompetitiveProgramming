#include<bits/stdc++.h>
using namespace std;

int solve(int row, int c, int prevIndex, vector<vector<int>> &v,vector<vector<int>> &dp)
{
if(row==v.size()) return 0;
int maxVal=INT_MIN;
if(dp[row][prevIndex+1]!=-1) return dp[row][prevIndex+1];
for(int col=c;col<3;col++)
{
if(prevIndex==col) continue;
maxVal=max(v[row][col]+solve(row+1,0,col,v,dp),maxVal);
}
return dp[row][prevIndex+1]=maxVal;
}

int main()
{
int prevIndex=0;
vector<vector<int>> v={
{94, 85, 49},
{14, 63, 1},
{35, 6, 80},
{2, 65, 11},
{94, 92, 47},
{99, 97, 51}
};
vector<vector<int>> dp(6,vector<int>(4,-1));
cout<<solve(0,0,-1,v,dp)<<endl;
}