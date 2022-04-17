#include<bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2, int i, int j,vector<vector<int>> &dp)
{
if(i<0 || j<0) return 0;
if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
if(s1[i]==s2[j]) return dp[i+1][j+1]=1+solve(s1,s2,i-1,j-1,dp);
return dp[i+1][j+1]=max(solve(s1,s2,i,j-1,dp),solve(s1,s2,i-1,j,dp));
}

int main()
{
string s1="abcjklp";
string s2="acjkp";
int n1=s1.size()-1;
int n2=s2.size()-1;
stack<char> lcs;
vector<vector<int>> dp(n1+2,vector<int>(n2+2,-1));
cout<<solve(s1,s2,n1,n2,dp)<<endl;
string res="";
for(int i=s1.size(),j=s2.size();i>0 || j>0;)
{
if(s1[i-1]==s2[j-1])
{
res+=s1[i-1];
i--;
j--;
}
else if(dp[i][j-1]>dp[i-1][j]) j--;
else i--;
}
reverse(res.begin(),res.end());
cout<<res<<endl;
}