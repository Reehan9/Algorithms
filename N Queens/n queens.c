#include <stdio.h>
#include <stdbool.h>
void printA(int n , int board[n][n]){
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            printf("%d " , board[i][j]);
         }
        printf("\n");
    }
}

bool isSafe(int n , int board[n][n] , int row , int col){
    for(int i = 0 ; i < col ; i++)
        if(board[row][i])
            return false;
    for(int i = row , j = col ; i>=0 && j >=0 ; i-- , j--)
          if(board[i][j])
              return false;
    for(int i = row , j = col ; i<n && j>=0 ; i++ , j--)
        if(board[i][j])
        return false;
    return true;
}

bool solve(int n , int board[n][n] , int col){
    if(col>=n)
        return true;
    for(int i = 0 ; i < n ; i++ ){
        if(isSafe(n , board , i , col)){
            board[i][col] = 1;
        if(solve(n , board , col+1))
            return true;
        board[i][col] = 0;
        }
    }
    return false;
}

bool Callfun(){
    int n ; 
    printf("Enter the number of vertices:   ");
    scanf("%d" , &n);
    int board[n][n];
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < n ; j++)
          board[i][j] = 0;
    if(solve(n , board , 0)==false){
        printf("Solution does not exsist\n");
        return false;
    }
    else {
        printf("\n");
        printA(n , board);
    }
 return true;
}
int main() {
    Callfun();
    return 0;
}

