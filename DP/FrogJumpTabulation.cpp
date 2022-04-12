#include<bits/stdc++.h>
using namespace std;

int main()
{
		 // 0  1  2  3
vector<int> height={7, 4, 4, 2, 6, 6, 3, 4 };
int n=8, l, r;
int dp[n];
dp[0]=0;
for(int i=1;i<=n;i++)
{
l=dp[i-1]+abs(height[i]-height[i-1]);
if(i>1) r=dp[i-2]+abs(height[i]-height[i-2]);
dp[i]=min(l,r);
}
cout<<dp[n-1]<<endl;
}