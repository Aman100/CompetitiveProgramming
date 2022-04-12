#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int netSum, int sum, int index,vector<vector<int>> &dp)
{
if(index==v.size())
{
int s1=netSum-sum;
int s2=sum;
if(s1==s2) return 1;
return 0;
}
if(dp[index][sum]!=-1) return dp[index][sum];
int take=solve(v,netSum, sum+v[index],index+1,dp);
int notTake=solve(v,netSum, sum,index+1,dp);
return dp[index][sum]=take | notTake;
}

int main()
{
int netSum=0;
vector<int> v={5, 6, 5, 11, 6};
for(int i=0;i<v.size();i++) netSum+=v[i];
vector<vector<int>> dp(n,vector<int>(netSum,-1));
if(netSum%2!=0) cout<<0<<endl;
else cout<<solve(v,netSum,0,0)<<endl;
}