
#include<bits/stdc++.h>
using namespace std;
//0 1 2 3
//5 3 3 5
int solve(int index,vector<int> &v, int n, vector<int> &dp)
{
if(index>=n) return 0;
if(dp[index]!=-1) return dp[index];
int n1=v[index]+solve(index+2,v,n,dp);
int n2=solve(index+1,v,n,dp);
return dp[index]=max(n1,n2);
}

int main()
{
int n=3;
vector<int> dp(n,-1);
vector<int> v={1,2,3};
int n1=solve(0,v,n-1,dp);
for(int i=0;i<n;i++) dp[i]=-1;
int n2=solve(1,v,n,dp);
cout<<max(n1,n2)<<endl;
}