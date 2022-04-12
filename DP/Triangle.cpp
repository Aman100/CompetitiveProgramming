#include<bits/stdc++.h>
using namespace std;

int solve(int r, int c, vector<vector<int>> &triangle)
{
if(r==triangle.size()) return 0;
return min(triangle[r][c]+solve(r+1,c,triangle),triangle[r][c]+solve(r+1,c+1,triangle));
}

int main()
{
vector<vector<int>> triangle=
{
{1},
{2,3},
{3,6,7},
{8,9,6,10}
};

cout<<solve(0,0,triangle);
}