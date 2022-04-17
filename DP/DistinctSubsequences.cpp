#include<bits/stdc++.h>
using namespace std;

int solve(string &s, int index)
{
if(index==s.size()) return 1;
int take=solve(s,index+1);
int notTake=solve(s,index+1);
return take+notTake;
}

int main()
{
string s="1234";
cout<<solve(s,0)<<endl;
}