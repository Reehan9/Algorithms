#include <stdio.h>
#define I 999999

int max(int a , int b ){ return (a>b)?  a : b ;}
void print_result(int n , int graph[][4]){
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j <n ; j++){
           printf("%d " , graph[i][j]);
        }   
    printf("\n");
    }
}
void floyd_war(int n , int graph[][4]){
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; k < n ; k++)
                graph[i][j] = max(graph[i][j] , graph[i][k] + graph[k][j]);
                print_result(n,graph);
}
int main() {
    int graph[][4] { {2,1,I,4},
                     {1,0,9,I},
                     {2,4,1,2},
                     {I,I,I,800}
    };
    floyd_war(4 , graph);
}