#include<bits/stdc++.h>
using namespace std;

int solve(int r, int c, vector<vector<int>> &v, vector<vector<int>> &dp)
{
if(r==v.size()-1 && c==v[0].size()-1) return v[r][c];
if(r>=v.size() || c>=v[0].size()) return 2147483647;
if(dp[r][c]!=-1) return dp[r][c];
return dp[r][c]=min((long long int)v[r][c]+(long long int)solve(r,c+1,v,dp), (long long int)v[r][c]+(long long int)solve(r+1,c,v,dp));
}


int main()
{
vector<vector<int>> v={
{1,2,3},
{4,5,4},
{7,5,9}
};
vector<vector<int>> dp(3,vector<int>(3,-1));
cout<<solve(0,0,v,dp);
}