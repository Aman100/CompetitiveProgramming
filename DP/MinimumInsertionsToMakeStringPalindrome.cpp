#include<bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2, int i, int j,vector<vector<int>> &dp)
{
if(i<0 || j<0) return 0;
if(s1[i]==s2[j]) return dp[i][j]=1+solve(s1,s2,i-1,j-1,dp);
if(dp[i][j]!=-1) return dp[i][j];
return dp[i][j]=max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
}

int main()
{
string s1="abcaa";
string s2=s1;
int n=s1.size()-1;
reverse(s2.begin(),s2.end());
vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
int lcs=solve(s1,s2,n,n,dp);
cout<<n+1-lcs<<endl;
}