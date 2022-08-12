#include <stdio.h>
#define I 99999

int main() {
    int row_no = 0 , col_no = 0 , no_of_edges = 0 , V , source , sum = 0;
    printf("\nEnter the number of edges: ");
    scanf("%d" , &V);
    int selected[V] , G[V][V]; 
    for(int i = 0 ; i < V ; i++)
        selected[i] = 0;
    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            scanf("%d" , &G[i][j]);
        }
    }
    printf("Enter the source node\n");
    scanf("%d" , &source);
    selected[source] = 1;
    printf("Source--->Destination\n");
    while(no_of_edges<V-1){
        int min = I;
        for(int i = 0 ; i < V ; i++){
            if(selected[i]){
                for(int j = 0 ; j < V ; j++){
                    if(!selected[j] && min>G[i][j]){
                        min = G[i][j];
                        row_no = i;
                        col_no = j;
                    }
                }
            }
        }
        printf("%d---->%d\n" , row_no , col_no);
        sum += G[row_no][col_no];
        selected[col_no] = 1;
        no_of_edges++;
    }
    printf("Total cost : %d " , sum);
    return 0;
}
