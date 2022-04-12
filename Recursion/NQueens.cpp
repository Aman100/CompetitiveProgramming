#include<bits/stdc++.h>
using namespace std;

bool isValidPlace(int row, int col,vector<vector<char>> &chessBoard)
{

int size=chessBoard.size();
int brow=row;
int bcol=col;

//upper left diagonal
while(row>=0 && col>=0)
{
if(chessBoard[row][col]=='Q') return false;
row--;
col--;
}

row=brow;
col=bcol;

//left
while(col>=0)
{
if(chessBoard[row][col]=='Q') return false;
col--;
}

//bottom left diagonal
row=brow;
col=bcol;
while(row<size && col>=0)
{
if(chessBoard[row][col]=='Q') return false;
row++;
col--;
}

return true;
}

void nqueens(int col, vector<vector<char>> &chessBoard)
{
if(col==chessBoard.size())
{
for(auto rv:chessBoard)
{
for(auto elem:rv) cout<<elem<<" ";
cout<<endl;
}
cout<<endl<<endl;
}

for(int row=0;row<chessBoard.size();row++)
{
if(isValidPlace(row,col,chessBoard))
{
chessBoard[row][col]='Q';
nqueens(col+1,chessBoard);
chessBoard[row][col]='-';
}
}
}

int main()
{
int n=8, columns=0;
vector<vector<char>> chessBoard(n,vector<char>(n,'-'));
cout<<chessBoard.size()<<endl;
nqueens(columns,chessBoard);

}