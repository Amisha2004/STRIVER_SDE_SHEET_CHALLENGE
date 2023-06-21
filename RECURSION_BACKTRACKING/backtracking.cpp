#include <bits/stdc++.h> 
using namespace std;
/*******************************N QUEENS PROBLEM**********************************************/
// BACKTRACKING 
// TC: O(N! * N)
// SC: O(N^2)
bool isSafe(int row,int col, vector<vector<int>>&queens,int n){
     for(int j=0;j<n;j++){
         if(queens[row][j]==1){
             return false;
         }
     }
     for(int i=0;i<n;i++){
         if(queens[i][col]==1){
             return false;
         }
     }
     for(int i=row,j=col;i>=0&&j>=0;i--,j--){
         if(queens[i][j]==1){
             return false;
         }
     }
     for(int i=row,j=col;i<n&&j>=0;i++,j--){
         if(queens[i][j]==1){
             return false;
         }
     }
    return true;
}
void possiblequeens(int col,vector<vector<int>>&queens, vector<vector<int>>&ans,int n){
    if(col==n){
        vector<int> temp;
        for(int i=0;i<n;i++){
          for (int j = 0; j < n; j++) {
            temp.push_back(queens[i][j]);
          }
        }  
        ans.push_back(temp);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, queens, n)) {
          queens[row][col] = 1;
          possiblequeens(col + 1, queens, ans, n);
          queens[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>>ans;
    vector<vector<int>>queens(n,vector<int>(n,0));
    possiblequeens(0,queens,ans,n);
    return ans;
}
/*****************************SUDUKO SOLVER***********************************************/
bool  isPossible(int row,int col, int ch,int board[9][9] ){
          for(int i=0;i<9;i++){
              if(board[i][col]==ch){
                  return false;
              }
          }
          for(int i=0;i<9;i++){
              if(board[row][i]==ch){
                  return false;
              }
          }
          for(int i=0;i<9;i++){
             if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
                  return false;
          }
          return true;
    }
bool sudukohelper(int board[9][9]){
   for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]==0){
                    for(int ch= 1;ch<=9;ch++){
                        if(isPossible(i,j,ch,board)){
                            board[i][j]=ch;
                            if(sudukohelper(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]=0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
}
bool isItSudoku(int board[9][9]) {
    return sudukohelper(board);
}
/**********************************M COLOURING PROBLEM*************************************************/
bool isSafe(int node, int color[], vector<vector<int>> &mat, int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && mat[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}
bool solve(int node, int color[], int m, int N,vector<vector<int>> &mat) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, mat, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, mat)) return true;
      color[node] = 0;
    }

  }
  return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
     int N= mat.size();
      int color[N] = { 0};
  if (solve(0, color, m, N, mat)) return "YES";
  return "NO";
}
/***********************************RAT IN A MAZE************************************************/
#include <bits/stdc++.h> 
void findPathHelper(int i,int j,vector<vector<int> > &maze,vector<vector<int>>&ans,int n){
    if (i == n - 1 && j == n - 1) {
       vector<int>temp;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(maze[i][j]==2) temp.push_back(1);
          else temp.push_back(0);
        }
      }
      ans.push_back(temp);
      return;
    }
     if (i + 1 < n && maze[i + 1][j] == 1) {
      maze[i+1][j]=2;
      findPathHelper(i + 1, j, maze, ans ,n);
      maze[i+1][j]=1;
    }
    if (i - 1 >= 0 && maze[i - 1][j] == 1) {
     maze[i-1][j]=2;
      findPathHelper(i - 1, j, maze, ans,n);
      maze[i-1][j]=1;
    }
    if (j + 1 < n &&  maze[i][j+1] == 1) {
     maze[i][j+1]=2;
      findPathHelper(i, j+1, maze, ans ,n);
      maze[i][j+1]=1;
    }

    if (j - 1 >= 0 &&  maze[i][j-1] == 1) {
      maze[i][j-1]=2;
      findPathHelper(i , j-1, maze, ans ,n);
      maze[i][j-1]=1;
    }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  if(n==1 && maze[0][0]==1) return {{1}};
    vector<vector<int>>ans;
    maze[0][0]=2;
    // if(maze[0][0]==1){
      findPathHelper(0,0,maze,ans,n);
    // }
    return ans;
}
/***************************************************************************/