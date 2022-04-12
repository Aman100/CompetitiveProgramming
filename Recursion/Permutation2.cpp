#include<bits/stdc++.h>
using namespace std;

void permutation2(int index, vector<int> &v)
{
if(index==v.size())
{
for(auto elem:v) cout<<elem<<" ";
cout<<endl;
return;
}
for(int i=index;i<v.size();i++)
{
swap(v[index],v[i]);
permutation2(index+1,v);
swap(v[index],v[i]);
}
}

int main()
{
vector<int> v={1,2,3};
permutation2(0,v);
}