#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap (int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int n;
    clock_t start , end;
    printf("Enter the number of elements\n");
    scanf("%d" , &n);
    int A[n];
    for(int i = 0  ; i < n ; i++){
        A[i] = rand();
    }
    //Bubble sorting begins
    start = clock();
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n ; j++){
            if(A[j]>A[j+1])
                swap(&A[j] , &A[j+1]);
        }
    }
    //Bubble Sort ends
    end = clock();
    double diff = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time taken is : %lf" , diff);
    return 0;
}