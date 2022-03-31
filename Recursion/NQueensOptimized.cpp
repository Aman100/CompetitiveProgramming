#include<bits/stdc++.h>
using namespace std;

void nqueens(int c, vector<vector<char>> &chessBoard,vector<int> &left, vector<int> &bottomLeft, vector<int> &upperLeft)
{

if(c==chessBoard.size())
{
for(auto rv:chessBoard)
{
for(auto elem:rv) cout<<elem<<" ";
cout<<endl;
}
cout<<endl<<endl;
return;
}

for(int r=0;r<chessBoard.size();r++)
{
if(left[r]==0 && bottomLeft[r+c]==0 && upperLeft[c-r+chessBoard.size()-1]==0)
{
chessBoard[r][c]='Q';
left[r]=bottomLeft[r+c]=upperLeft[c-r+chessBoard.size()-1]=1;
nqueens(c+1,chessBoard,left,bottomLeft,upperLeft);
left[r]=bottomLeft[r+c]=upperLeft[c-r+chessBoard.size()-1]=0;
chessBoard[r][c]='-';
}
}

}

int main()
{
int n=8;
vector<vector<char>> chessBoard(n,vector<char>(n,'-'));
vector<int> left(n,0);
vector<int> bottomLeft(2*n-1,0);
vector<int> upperLeft(2*n-1,0);
nqueens(0,chessBoard,left,bottomLeft, upperLeft);
}