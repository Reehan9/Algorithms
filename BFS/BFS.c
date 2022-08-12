#include <stdio.h>
void BFS(int v , int n, int A[n][n] , int visited[n]){
    int f = 0 , r = -1;
    int q[n];
    q[++r] = v;
    while(f<=r){
        int u = q[f++];
        for(int i = 0 ; i < n ; i++){
            if(visited[i]==0 && A[u][i]==1){
                visited[i]  = 1;
                q[++r] = i;
            }
        }
      printf("%d , " , u);    
    }
}

int main() {
    int n , source;
    printf("Enter the number of nodes\n");
    scanf("%d" , &n);
    int A[n][n] , visited[n];
    printf("Enter the boolean matrix\n");
    for(int i = 0 ; i < n ; visited[i++] = 0){
        for(int j = 0 ; j < n ; j++){
            scanf("%d" , &A[i][j]);
        }
    }
   printf("Enter the source node:  ");
   scanf("%d" , &source);
   visited[source] = 1;
   printf("The number of nodes that are reachable from %d  :   " , source);
   BFS(source , n , A, visited);   
}
