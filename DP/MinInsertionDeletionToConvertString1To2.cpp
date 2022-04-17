#include<bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2, int i, int j,vector<vector<int>> &dp)
{
if(i<0 || j<0) return 0;
if(dp[i][j]!=-1) return dp[i][j];
if(s1[i]==s2[j]) return dp[i][j]=1+solve(s1,s2,i-1,j-1,dp);
return dp[i][j]=max(solve(s1,s2,i,j-1,dp),solve(s1,s2,i-1,j,dp));
}

int main()
{
string s1="cde";
string s2="awd";
int s1l=s1.size();
int s2l=s2.size();
vector<vector<int>> dp(s1l,vector<int>(s2l,-1));
int res;
int lcs=solve(s1,s2,s1l-1,s2l-1,dp);
int dORi=abs(s1l-s2l);
if(s1l>s2l) res=dORi+(s1l-dORi-lcs)*2;
else res=dORi+(s1l-lcs)*2;
cout<<res<<endl;
}