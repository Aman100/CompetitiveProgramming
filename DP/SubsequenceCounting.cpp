#include<bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2, int i, int j,vector<vector<int>> &dp)
{
if(j<0) return 1;
if(i<0) return 0;
if(dp[i][j]!=-1) return dp[i][j];
if(s1[i]==s2[j])
{
int n1=solve(s1,s2,i-1,j-1,dp);
int n2=solve(s1,s2,i-1,j,dp);
return dp[i][j]=(n1+n2)%1000000007;
}
else return dp[i][j]=(solve(s1,s2,i-1,j,dp))%1000000007;
}

int main()
{
string s1="abac";
string s2="cb";
int n1=s1.size();
int n2=s2.size();
vector<vector<int>> dp(n1,vector<int>(n2,-1));
cout<<solve(s1,s2,n1-1,n2-1,dp);
}