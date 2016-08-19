#include <stdio.h>
#include <stdlib.h>

void multiply(int A[], int k) {

    int i, ov = 0, t;

    for(i = 1; i<=A[0]; i++) {

        t = A[i] * k + ov;
        A[i] = t%10;
        ov = t/10;

    }

    while(ov) {
        A[i++] = ov % 10;
        ov = ov / 10;
    }
    A[0] = i-1;

}

char *get_fact(int n) {

    int A[100000], t, r=n, i=1, f=n, k;
    char *fact = NULL;

    A[0] = 0;
    i = 1;
    while(r) {
        A[i++] = r%10;
        r = r/10;
    }

    A[0]=i-1;

    f = n-1;
    while(f) {

        multiply(A, f);
        f--;
    }

    if(A[0]>0) {
        fact = (char *)malloc(sizeof(char)*A[0]+1);
        for(k=0, i=A[0]; i>=1; i--) {
            fact[k++] = '0' + A[i];
        }
        fact[k]='\0'; 
    }


    return fact;

}


void main(){
    int n;
    printf("\nEnter num:");
    scanf("%d", &n);

    char *fa = NULL;

    while(n) {
        fa = get_fact(n);
        if(fa) printf("\nFactorial(%d): %s", n, fa);
        free(fa);

        printf("\nEnter num:");
        scanf("%d", &n);
    }
}





