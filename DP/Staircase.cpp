#include<bits/stdc++.h>
using namespace std;

int countWays(int n, int dp[])
{
if(n<0) return 0;
if(n==0) return 1;
if(n==1) return 1;
if(dp[n]!=0) return dp[n];
dp[n]=countWays(n-2,dp)+countWays(n-1,dp);
return dp[n];
}

int main()
{
int n;
cin>>n;
int dp[n+1]={0};
cout<<countWays(n,dp);
}