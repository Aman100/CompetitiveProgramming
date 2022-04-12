#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& w, vector<int> &v, int index, int target, vector<vector<int>> &dp)
{
if(target<0) return -2147483648;
if(target==0 || index==-1) return 0;
if(dp[index][target]!=-1) return dp[index][target];
return dp[index][target]=max(v[index]+solve(w,v,index-1,target-w[index],dp),solve(w,v,index-1,target,dp));
}

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
int n;
cin>>n;
vector<int> w(n);
vector<int> v(n);
for(int j=0;j<n;j++) cin>>w[j];
for(int j=0;j<n;j++) cin>>v[j];
int target;
cin>>target;
vector<vector<int>> dp(v.size(),vector<int>(target+1,-1));
cout<<solve(w,v,v.size()-1,target,dp)<<endl;
}
}