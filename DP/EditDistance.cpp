#include<bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2, int i, int j,vector<vector<int>> &dp)
{
if(i<0) return j+1;
if(j<0) return i+1;
if(dp[i][j]!=-1) return dp[i][j];
if(s1[i]==s2[j]) return solve(s1,s2,i-1,j-1,dp);
int del=1+solve(s1,s2,i-1,j,dp);
int replace=1+solve(s1,s2,i-1,j-1,dp);
int insert=1+solve(s1,s2,i,j-1,dp);
return dp[i][j]=min(min(del,replace),insert);
}

int main()
{
/*
acdefgd 4
aawdfg

wncpoddas 10
wqegesggfff

whgtdwhgtdg Actual->9 - Calculated->6
aswcfg
*/
string s1="whgtdwhgtdg";
string s2="aswcfg";
vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
int l1=s1.size();
int l2=s2.size();
cout<<solve(s1,s2,l1-1,l2-1,dp)<<endl;
}