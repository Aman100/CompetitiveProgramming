//Foundation Of Backtracking, Recursion, DP

#include<bits/stdc++.h>
using namespace std;

void generateSubsequences1(int index, vector<int> &nums, vector<int> &result)
{
if(index==nums.size()) return;
for(int i=index;i<nums.size();i++)
{
result.push_back(nums[i]);
generateSubsequences1(i+1,nums,result);
for(auto elem:result) cout<<elem<<" ";
cout<<endl;
result.pop_back();
}
}

void generateSubsequences2(int index, vector<int> &nums, vector<int> &result)
{
if(index==nums.size()) return;
for(int i=index;i<nums.size();i++)
{
result.push_back(nums[i]);
generateSubsequences2(i+1,nums,result);
for(auto elem:result) cout<<elem<<" ";
cout<<endl;
result.pop_back();
}
}

int main()
{
vector<int> nums={1,2,3}, result;
generateSubsequences1(0,nums,result);
cout<<"----------------------"<<endl;
generateSubsequences2(0,nums,result);
}
