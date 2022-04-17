#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, vector<int> &res, int index)
{
if(index==v.size()) return;
for(int i=index;i<v.size();i++)
{
if(i>index && v[i]==v[i-1]) continue;
res.push_back(v[i]);
for(auto elem:res) cout<<elem;
cout<<endl;
solve(v,res,i+1);
res.pop_back();
}
}

int main()
{
vector<int> v={1,2,2}, res;
sort(v.begin(),v.end());
solve(v,res,0);
}