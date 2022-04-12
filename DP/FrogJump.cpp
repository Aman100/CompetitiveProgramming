#include<bits/stdc++.h>
using namespace std;

int frogJump(int index, vector<int> height, int dp[])
{
if(index==0) return 0;
if(dp[index]!=-1) return dp[index];
int left=frogJump(index-1,height,dp)+abs(height[index]-height[index-1]);
int right=INT_MAX;
if(index>1) right=frogJump(index-2,height,dp)+abs(height[index]-height[index-2]);
return dp[index]=min(left,right);
}


int main()
{
vector<int> height={7, 4, 4, 2, 6, 6, 3, 4 };
int n=8;
int dp[n+1];
for(int i=0;i<n+1;i++) dp[i]=-1;
cout<<frogJump(n-1,height,dp)<<endl;
}