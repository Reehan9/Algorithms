#include <stdio.h>
#include <stdbool.h>
// Warshall Algorithm to find the transistive closure of a boolean matrix
void print_mat(int n , bool graph[][4]){
   for(int i = 0 ; i < n ; i++){
       for(int j = 0 ; j < n ; j++){
          printf("%d " , graph[i][j]);
       }
           printf("\n");    
}
}
void warshall(int n , bool graph[][4]){
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                if(graph[i][j]== true || (graph[i][k] && graph[k][j]) == true)
                    graph[i][j] = true ;// there exists a direct or an indirect path between the nodes
          print_mat(4 , graph);
}
 int main(void){
     bool grph[][4] = { {1,0,1,0},
                     {0,1,0,1},
                     {1,0,1,0},
                     {0,0,1,1}
                                };
    warshall(4 , grph);
 }
