#include<bits/stdc++.h>
using namespace std;

long solve(int *v, int index, int sum, int target, int size, vector<vector<long>> &dp)
{
if(sum==target) return 1;
if(sum>target || index==size) return 0;
if(dp[index][sum]!=-1) return dp[index][sum];
long v1=solve(v,index,sum+v[index],target,size,dp);
long v2=solve(v,index+1,sum,target,size,dp);
return dp[index][sum]=v1+v2;
}

int main()
{
int arr[]={5,3,2};
int *denominations=arr;
int d=1;
vector<vector<long>> dp(3,vector<long>(d,-1));
cout<<solve(denominations,0,0,d,3,dp);
}