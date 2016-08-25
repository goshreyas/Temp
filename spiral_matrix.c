/*Print Matrix in Spiral*/


#include<stdio.h>
#include<stdlib.h>


int print_spiral(/*int M[][], int m, int n*/){

//    int M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//    int m = 2, n = 2;

    int M[3][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    int m = 2, n = 4;

    int a=0, b=m; //<Row>
    int c=0, d=n; //<Col>
    int i,j;
    for(i=0;i<=m;i++,printf("\n"))
        for(j=0;j<=n;j++,printf(", "))
            printf("%d",M[i][j]);
    printf("\n");
    while(a<b && c<d) {
        for(i=c; i<d; i++) printf("%d, ", M[a][i]);
        for(i=a; i<b; i++) printf("%d, ", M[i][d]);
        for(i=d; i>c; i--) printf("%d, ", M[b][i]); 
        for(i=b; i>a; i--) printf("%d, ", M[i][c]);
        a++;b--;
        c++;d--;
    }
    if(a==b){
        for(i=c; i<=d; i++)
            printf("%d, ", M[a][i]);    
    }else if(c==d){
        for(i=a; i<=b; i++)
            printf("%d, ", M[i][c]);
    }

    printf("\n");
}

void main() {
    print_spiral();
}


