#include<bits/stdc++.h>
using namespace std;
//0 1 2 3 4
//1 1 1 2 2

void combinationSum2(int index, vector<int> &v, vector<int> &result, int targetSum, int sum)
{
if(targetSum==sum)
{
for(auto element:result) cout<<element<<" ";
cout<<endl;
return;
}
for(int i=index;i<v.size();i++)
{
if(i>index && v[i]==v[i-1]) continue;
if((targetSum+v[i])>sum) return;
result.push_back(v[i]);
combinationSum2(i+1,v,result,targetSum+v[i],sum);
result.pop_back();
}
}

int main()
{
vector<int> v={10,1,2,7,6,1,5}, res;
sort(v.begin(),v.end());
int targetSum=0, sum=8;
combinationSum2(0,v,res,targetSum,sum);
}