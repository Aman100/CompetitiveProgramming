#include<bits/stdc++.h>
using namespace std;

void uniqueSubsequence(int index, vector<int> v, vector<int> result, int targetSum, int sum)
{
if(targetSum>sum) return;
if(v.size()==index)
{
if(targetSum==sum)
{
for(auto element:result) cout<<element;
cout<<endl;
}
return;
}
result.push_back(v[index]);
uniqueSubsequence(index,v,result,targetSum+v[index],sum);
result.pop_back();
uniqueSubsequence(index+1,v,result,targetSum,sum);
}

int main()
{
vector<int> res, arr={2,3,6,7};
int targetSum=0, sum=7;
uniqueSubsequence(0, arr, res,targetSum,sum);
}