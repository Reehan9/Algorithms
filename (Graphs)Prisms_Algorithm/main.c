#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Greedy Method Algorithm
#define V 4
#define I INT_MAX

int G[V][V] = {{2,98,4,3}, 
             {4,3,6,4},
             {1,2,I,2},
             {2,3,2,I}};
             
 int main() {
         int no_of_edges = 0;
         int selected[V];
         memset(selected,false,sizeof(selected)); // Intialsing everything to false
         selected[0] = true;
         int row_no;
         int col_no;
         int sum = 0;
         printf("Edge : Weight\n");
         while(no_of_edges<V-1){
          row_no = 0;
          col_no = 0;
         int min = I;
         for(int i = 0 ; i < V ; i++){
         if(selected[i]==true){
         for(int j = 0 ; j < V ; j++){
         if(!selected[j] && G[i][j]){
         if(min>G[i][j]){
         min = G[i][j];
         row_no = i;
         col_no = j;
         }
       }
      }
     }
         }
     printf("%d ---> %d : %d\n" ,row_no , col_no , G[row_no][col_no]);
     sum+=G[row_no][col_no];
     selected[col_no] = true;
     no_of_edges++;
     }
     printf("The required weight is : %d" , sum);
     return 0;
     }