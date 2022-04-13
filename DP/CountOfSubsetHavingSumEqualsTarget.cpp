#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &v, int sum, int target, int index, vector<vector<int>> &dp)
{
	if(sum==target && index==v.size()) return 1;
	if(sum>target && index==v.size() || index==v.size()) return 0;
	if(dp[index][sum]!=-1) return dp[index][sum];
	int take=solve(v,sum+v[index],target,index+1,dp);
	int notTake=solve(v,sum,target,index+1,dp);
	return dp[index][sum]=take + notTake;
}

int main()
{
    // Write your code here.
int tar=1;
vector<int> num={1,2,0};
int netSum=0;
for(int i=0;i<num.size();i++) netSum+=num[i];
vector<vector<int>> dp(num.size(), vector<int>(netSum+1,-1));
cout<<solve(num,0,tar,0,dp)<<endl;
}
