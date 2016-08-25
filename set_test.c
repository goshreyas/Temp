/*
   4. Write a program to take 2 ararys (A and B) and output (A-B) U (B-A).
   e.g. if A = {1, 3, 5}, B = {2, 3, 4, 5}, then (A-B) U (B-A) = {1, 2, 4}
 */

/*
Logic:
1. Sort array A & B.
2. Remove duplicate number from array A & B.
*/



#include<stdio.h>
#include<stdlib.h>

int set(){
    int i=0, j=0, k=0, C[10];
    int A[] = {1, 3, 6, 7, 8}, B[] = {2, 3, 6, 7}, m=5, n=4;
    while(i<m && j<n) {
        if(A[i] < B[j]){
            C[k++] = A[i];
            i++;            
        } else if(A[i] > B[j]){
            C[k++] = B[j];
            j++;
        }
        else{i++; j++;}
    }

    if(i<m) {
        for (;i<m; i++)
            C[k++] = A[i];
    }
    else if(j<n) {
        for (;j<n; j++)
            C[k++] = B[j];
    }

    for(i=0; i<k; i++){
        printf("%d, ", C[i]);
    }
    printf("\n");
}

void main() {
    set();
}



