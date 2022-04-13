#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &v, int sum, int target, int index, vector<vector<int>> &dp)
{
cout<<index<<" "<<sum<<endl;
if(sum==target) return 1;
if(sum>target || index>=v.size()) return 0;
if(dp[index][sum]!=-1) return dp[index][sum];
int take=solve(v,sum+v[index],target,index+1,dp);
if(take==1) return dp[index][sum]=1;
int notTake=solve(v,sum,target,index+1,dp);
if(notTake==1) return dp[index][sum]=1;
return dp[index][sum]=0;
}

int main()
{
vector<int> v={1,2,3};
int target=1;
int n=v.size();
vector<vector<int>> dp(n,vector<int>(target,-1));
cout<<solve(v,0,target,0,dp)<<endl;
}