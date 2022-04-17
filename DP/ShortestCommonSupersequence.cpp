#include<bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2, int i, int j,vector<vector<int>> &dp)
{
if(i<0 || j<0) return 0;
if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
if(s1[i]==s2[j]) return dp[i+1][j+1]=1+solve(s1,s2,i-1,j-1,dp);
return dp[i+1][j+1]=max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
}

int main()
{
/*
"bbbaaaba"
"bbababbb"
*/

string s1="bcacaaab";
string s2="bbabaccc";
int s1l=s1.size()-1;
int s2l=s2.size()-1;
vector<vector<int>> dp(s1l+2,vector<int>(s2l+2,-1));
int lcs=solve(s1,s2,s1l,s2l,dp);
int n=s1l+s2l-lcs;
string res;
for(auto rv:dp)
{
for(auto elem:rv) cout<<elem<<'\t';
cout<<endl;
}
int i, j;
for(i=s1.size(),j=s2.size();i>0 && j>0;)
{
cout<<i<<" "<<j<<endl;
if(s1[i-1]==s2[j-1])
{
res+=s1[i-1];
i--;
j--;
}
else if(dp[i][j-1]>dp[i-1][j])
{
res+=s2[j-1];
j--;
}
else
{
res+=s1[i-1];
i--;
}
}
if(i==1) res.insert(res.size()-1,to_string(s1[i-1]));
else if(j==1) res.insert(res.size()-1,to_string(s2[j-1]));
cout<<res<<endl;
cout<<res.size()<<endl;
}
