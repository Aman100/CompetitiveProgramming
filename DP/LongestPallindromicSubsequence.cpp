#include<bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2, int i, int j,vector<vector<int>> &dp)
{
if(i<0 || j<0) return 0;
if(dp[i][j]!=-1) return dp[i][j];
if(s1[i]==s2[j]) return dp[i][j]=1+solve(s1,s2,i-1,j-1,dp);
return dp[i][j]=max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
}

int main()
{
string s1="bbabcbcab";
string s2=s1;
reverse(s2.begin(),s2.end());
int n=s1.size()-1;
vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
cout<<solve(s1,s2,n,n,dp);
}