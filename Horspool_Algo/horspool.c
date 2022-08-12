#include <string.h>
#include <stdio.h>

int main () {
    int table[126];
    char patt[100] , str[1000];
    printf("Enter the string\n");
    scanf("%s" , str);
    printf("Enter the substring\n");
    scanf("%s" , patt);
    int m = strlen(patt);
    int n = strlen(str);
    for(int i = 0 ; i < 126 ; i++)
        table[i] = m;
    for(int j = 0 ; j < m-1 ; j++)
        table[patt[j]] = m-1-j;
    int i = m-1;
    while(i<=n-1){
        int k = 0;
        while(k<m && patt[m-1-k]==str[i-k])
            k++;
        if(k==m){
            printf("Pattern found at position : %d" ,  i-m+2);
            break;
        }
        else 
            i = table[str[i]]+i;
    }
    return 0;
}
