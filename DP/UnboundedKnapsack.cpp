#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &profit, vector<int>&weight, int capacity, int index, vector<vector<int>> &dp)
{
if(capacity==0) return 0;
if(capacity<0) return -2147483648;
if(index==-1) return 0;
if(dp[index][capacity]!=-1) return dp[index][capacity];
int take=profit[index]+solve(profit,weight,capacity-weight[index],index,dp);
int notTake=solve(profit,weight,capacity,index-1,dp);
return dp[index][capacity]=max(take,notTake);
}

int main()
{
vector<int> profit={5,11,13};
vector<int> weight={2,4,6};
int n=profit.size();
int capacity=10;
vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
cout<<solve(profit,weight,capacity,n-1,dp);
}