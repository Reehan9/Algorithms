#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printA(int n , int heap[n]){
    for(int i = 0 ; i < n ; i++){
      printf("%d " , heap[i]);  
    }
    printf("\n");
}

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify (int n , int heap[n] , int i){
    int largest = i;
    int left = 2*i+1;
    int right  = 2*i+2;
    if(left<n && heap[left]>heap[largest]) largest = left;
    if(right<n && heap[right]>heap[largest]) largest = right;
    if(largest!=i){
        swap(&heap[i] , &heap[largest]);
        heapify(n , heap ,largest);
    }
}
void heapsort(int n , int heap[n]){
    for(int i = n/2-1 ; i>=0 ; i--){
        heapify(n , heap , i);
    }
    for(int i = n ; i >=0 ; i--){
        swap(&heap[0] , &heap[i]);
        heapify(i , heap , 0);
    }
}



int main(){
    int n;
    printf("Enter the number of elements\n");
    scanf("%d" , &n);
    int heap[n];
    clock_t start , end;
    for(int i = 0 ; i < n ; i++)
        heap[i] = rand()/127;
    //printf("Before Sorting\n");
    //printA(n , heap);
    //printf("\n");
    start = clock();
    heapsort(n , heap);
    end  = clock();
    //printf("After Sorting\n");
    //printA(n , heap);
    //printf("\n");
    double timer = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time taken :  %lf " , timer);
    return 0;    
}
