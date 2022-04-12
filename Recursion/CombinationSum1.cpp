class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> result;
        vector<vector<int>> ans;
        int targetSum=0;
        uniqueSubsequence(0,candidates,result, ans, targetSum,target);
        return ans;
    }

void uniqueSubsequence(int index, vector<int> v, vector<int> &result, vector<vector<int>> &ans, int targetSum, int sum)
{
if(targetSum>sum) return;
if(v.size()==index)
{
if(targetSum==sum) ans.push_back(result);
return;
}
result.push_back(v[index]);
uniqueSubsequence(index,v,result,ans,targetSum+v[index],sum);
result.pop_back();
uniqueSubsequence(index+1,v,result,ans,targetSum,sum);
}
    
};