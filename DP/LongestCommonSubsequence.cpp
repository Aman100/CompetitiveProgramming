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
string s1="dingdingdingding";
string s2="ing";
int n1=s1.size()-1;
int n2=s2.size()-1;
vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
cout<<solve(s1,s2,n1,n2,dp)<<endl;
}