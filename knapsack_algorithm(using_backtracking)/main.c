#include <stdio.h>
#include <stdbool.h>
// twt : total weight

int max(int a , int b ) { return (a>b) ? a:b;}
int knapsack(int value[] , int weight[] , int twt , int siz){
    if(siz==0 || twt==0)
        return 0;
    if(weight[siz-1]<=twt)
        return max(value[siz-1]+knapsack(value , weight , twt-weight[siz-1] ,siz - 1) , knapsack(value , weight , twt ,siz - 1)); 
    else 
        return knapsack(value , weight , twt ,siz - 1);
}
int main() {
    int value[] = {60,100,120};
    int weight[] = {10,20,30};
    int twt = 50;
    int siz = sizeof(value)/sizeof(value[0]);
    printf("The optimal solution is %d " , knapsack(value , weight , twt ,siz));
    return 0;
}
