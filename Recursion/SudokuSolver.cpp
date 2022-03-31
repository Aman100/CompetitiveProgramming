#include<bits/stdc++.h>
using namespace std;

bool isValidPosition(int row, int col, char n,vector<vector<char>> &sudoku)
{
for(int i=0;i<9;i++)
{
if(sudoku[row][i]==n) return false;
if(sudoku[i][col]==n) return false;
if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==n) return false;
}
return true;
}

bool sudokuSolver(vector<vector<char>> &sudoku, int r, int c)
{
for(int row=0;row<sudoku.size();row++)
{
for(int col=0;col<sudoku.size();col++)
{
if(sudoku[row][col]!='-') continue;
for(char n='1';n<='9';n++)
{
if(isValidPosition(row,col,n,sudoku))
{
sudoku[row][col]=n;
if(sudokuSolver(sudoku,r+1,0)==true) return true;
sudoku[row][col]='-';
}
}
return false;
}
}
return true;
}

int main()
{
int n=9;
vector<vector<char>> sudoku=
{
{'5','3','-','-','7','-','-','-','-'},
{'6','-','-','1','9','5','-','-','-'},
{'-','9','8','-','-','-','-','6','-'},
{'8','-','-','-','6','-','-','-','3'},
{'4','-','-','8','-','3','-','-','1'},
{'7','-','-','-','2','-','-','-','6'},
{'-','6','-','-','-','-','2','8','-'},
{'-','-','-','4','1','9','-','-','5'},
{'-','-','-','-','8','-','-','7','9'}
};
sudokuSolver(sudoku,0,0);
for(auto rv:sudoku)
{
for(auto elem:rv) cout<<elem<<" ";
cout<<endl;
}
}

