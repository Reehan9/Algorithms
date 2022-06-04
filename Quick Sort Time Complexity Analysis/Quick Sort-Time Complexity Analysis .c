#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
          }
 int partition(int A[] , int low , int high){
     int pivot = A[low];
     int i = low , j = high;
 do {
   do{i++;} while(A[i]<=pivot);
   do{j--;} while(A[j]>pivot);
   if(i<j){
   swap(&A[i] , &A[j]);
 }
    }while(i<j);
    swap(&A[low],&A[j]);
    return j;
    }
 
 void QuickSort(int A[] , int low , int high){
    int j;
    if(low<high){
    j = partition(A , low , high);
    QuickSort(A , low , j);
    QuickSort(A , j+1 , high);
      }
 }
  void printArray(int A[] , int n){
   for(int i = 0 ; i < n ; i++)
   printf("%d " , A[i]);
   printf("\n");
 }
 int main(){
    printf("Enter the size of the array\n");
    int n;
    scanf("%d" , &n);
    int A[n];
    printf("Enter the elements\n");
    for(int i = 0 ; i < n ; i++)
    A[i] = rand()/n;
    clock_t start , end;
    start = clock();
    QuickSort(A,0,n);
    end = clock();
    printf("\n");
   //printArray(A , n);
    double ans = (double)(end-start)/CLOCKS_PER_SEC;
   printf("Time taken is %lf" , ans);
   return 0;
 }