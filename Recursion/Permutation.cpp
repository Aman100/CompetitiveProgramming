#include<bits/stdc++.h>
using namespace std;

void permutation(int index, vector<int> v, vector<int> result,map<int,int> m)
{
if(result.size()==v.size())
{
for(auto elem:result) cout<<elem<<" ";
cout<<endl;
return;
}
for(int i=index;i<v.size();i++)
{
if(!m[i])
{
result.push_back(v[i]);
m[i]=1;
permutation(0,v,result,m);
result.pop_back();
m[i]=0;
}
}
}

int main()
{
vector<int> v={1,2,3,4}, res;
map<int,int> m;
permutation(0,v,res,m);
}