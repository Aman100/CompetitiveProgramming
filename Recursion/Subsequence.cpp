#include<bits/stdc++.h>
using namespace std;

void subsequences(int index, vector<int> v, vector<int> res)
{
if(index==v.size())
{
for(auto elem:res) cout<<elem<<" ";
cout<<endl;
return;
}
res.push_back(v[index]);
subsequences(index+1,v,res);
res.pop_back();
subsequences(index+1,v,res);
}

int main()
{
vector<int> v={1,2,3,4}, res;
subsequences(0,v,res);
}