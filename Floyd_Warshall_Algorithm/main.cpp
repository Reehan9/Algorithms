#include <stdio.h>
#define I 9999999
int min(int a , int b) {
    return (a>b)?b:a;
}
void printMat(int n , int grph[n][n]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%d " , grph[i][j]);
        }
        printf("\n");
    }
}

void warshall(int n , int grph[n][n]){
    for(int k = 0 ; k < n ; k ++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                    grph[i][j] = min(grph[i][j] , grph[i][k]+grph[k][j]);
            }
        }
    }
}

int main() {
    int n = 0 ;
    printf("\n Enter the size of the matrix: ");
    scanf("%d" , &n);
    int A[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d" , &A[i][j]);
        }
    }
    printf("\n");
    printf("The matrix before transitive closure is \n: ");
    printMat(n,A);
    printf("\n");
    warshall(n,A);
    printf("The shortest pairs in the matrix is :\n ");
    printMat(n,A);
    printf("\n");
    return 0;
}
