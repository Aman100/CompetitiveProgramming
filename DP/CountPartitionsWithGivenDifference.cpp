#include<bits/stdc++.h>
using namespace std;
//(1+2)-3=
//s1-s2=d;
/*
s1+s2=s
s-s2=s1
*/

int solve(vector<int> &v, int sum, int index, int d, int netSum,vector<vector<int>> &dp)
{
if(index==v.size())
{
int s1=sum;
int s2=netSum-sum;
if(s1>=s2 && s1-s2==d) return 1;
return 0;
}
if(dp[index][sum]!=-1)
{
cout<<"CULPRIT: "<<index<<" "<<sum<<endl;
return dp[index][sum];
}
int take=solve(v,sum+v[index],index+1,d,netSum,dp);
int notTake=solve(v,sum,index+1,d,netSum,dp);
cout<<index<<" "<<sum<<" "<<take<<" "<<notTake<<endl;
return dp[index][sum]=(take+notTake)%1000000007;
}

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
int n, d;
cin>>n>>d;
vector<int> v(n);
for(int j=0;j<n;j++) cin>>v[j];
int netSum=0;
for(int i=0;i<v.size();i++) netSum+=v[i];
vector<vector<int>> dp(n,vector<int>(netSum+1,-1));
cout<<solve(v,0,0,d,netSum,dp)<<endl;
for(auto rv:dp)
{
for(auto elem:rv) cout<<elem<<'\t'<<" ";
cout<<endl;
}
}
}