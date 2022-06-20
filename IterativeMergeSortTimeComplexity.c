#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merging( int A[] , int l , int mid , int h ){
    int B[h+1];
    int i = l , j = mid+1 , k = l;
    while(i<=mid && j<=h){
        if(A[i]<A[j])
            B[k++] = A[i++];
            else 
                B[k++] = A[j++];
    }
    for(; j <= h ; j++)
        B[k++] = A[j];
    for(; i <=mid ; i++)
        B[k++] = A[i];
    for(int o = l ; o <=h ; o++)
        A[o] = B[o];
}
   void mergeS(int A[] , int n){
       int p, l , i , h , mid;
       for(p = 2 ; p<=n ; p = p*2){
           for( i = 0 ; i + p - 1 < n ; i = i+p){
               l = i ;
               h = i+p-1;
               mid = (l+h)/2;
               merging(A,l,mid,h);
           }
           if(n-i>p/2){
               l = i ;
               h = i+p-1;
               mid = (l+h)/2;
               merging(A,l,mid,n-1);
           }
       }
       if(p/2<n) { 
       merging(A,0,p/2-1,n-1); 
                    } 
   } 
     int main() {
         int n ;
         printf("\nEnter the number of elements\n");
         scanf("%d" , &n);
         int A[n];
         for(int i = 0  ; i < n ; i++)
         A[i] = rand();
         clock_t start , end;
         start = clock();
         mergeS(A,n);
         end = clock();
         double t = (double)(end-start)/CLOCKS_PER_SEC;
         printf("Total time taken : %lf" ,t);
     }