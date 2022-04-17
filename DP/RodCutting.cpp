#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &price,vector<int>& weight, int index, int target,vector<vector<int>> &dp)
{
	if(target==0) return 0;
	if(target<0) return -2147483648;
	if(index==-1) return 0;
	if(dp[index][target]!=-1) return dp[index][target];
	int take=price[index]+solve(price,weight,index,target-weight[index],dp);
	int notTake=solve(price,weight,index-1,target,dp);
	return dp[index][target]=max(take,notTake);
}

int main()
{
	int n=5;
	vector<int> price={42, 68, 35, 1, 70};
	vector<int> weight(n);
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	for(int i=0;i<n;i++) weight[i]=i+1;
	cout<<solve(price,weight,n-1,n,dp)<<endl;
}