#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int index, int sum, int target, int netSum, vector<vector<int>> &dp)
{
if(index==v.size())
{
int s2=sum;
int s1=netSum-sum;
if(target>0) 
{
if(s1>=s2 && s1-s2==target) return 1;
}
else
{
s1=sum-netSum;
if(s1<=s2 && s1+s2==target) return 1;
}
return 0;
}
if(dp[index][sum]!=-1) return dp[index][sum];
int take=solve(v,index+1,sum+v[index],target,netSum,dp);
int notTake=solve(v,index+1,sum,target,netSum,dp);
return dp[index][sum]=take+notTake;
}

int main()
{
vector<int> v={1,1,1};
int target=-1, netSum=0;
for(int i=0;i<v.size();i++) netSum+=v[i];
vector<vector<int>> dp(v.size(),vector<int>(netSum,-1));
cout<<solve(arr,0,0,target,netSum,dp)<<endl;
}