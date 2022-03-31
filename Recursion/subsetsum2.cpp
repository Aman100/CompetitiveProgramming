
#include<bits/stdc++.h>
using namespace std;

void subsetSum2(int index, vector<int> &v, vector<int> &result,vector<vector<int>> &ans)
{
if(index==v.size())
{
ans.push_back();
return;
}
for(int i=index;i<v.size();i++)
{
if(i>index && v[i]==v[i-1]) continue;
result.push_back(v[i]);

subsetSum2(i+1,v,result);
result.pop_back();
}
ans.push_back();
}

int main()
{
vector<int> v={0}, res;
subsetSum2(0,v,res);
}
