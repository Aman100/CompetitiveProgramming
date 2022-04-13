#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int index, int target, vector<vector<int>> &dp)
{
if(target==0) return 0;
if(target<0 || index==-1) return INT_MAX;
if(dp[index][target]!=-1) return dp[index][target];
return dp[index][target]=min((long long int)1+(long long int)solve(v,index,target-v[index],dp),(long long int)solve(v,index-1,target,dp));
}

int main()
{
vector<int> v={17,10,5};
int n=num.size(), x=6;
vector<vector<int>> dp(n,vector<int>(x+1,-1));
int s=solve(num,n-1,x,dp);
return (2147483647==s)?-1:s;
cout<<solve(v,n-1,target);
}