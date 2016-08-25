/*
   Find a number in minimum steps
http://www.geeksforgeeks.org/find-a-number-in-minimum-steps/
 */
#include <stdio.h>
#include <stdlib.h>

int found = 0;
int find_steps(int s, int d, int depth) {
    if(/*found ||*/ d<depth) return 0;
    else if(s == d) {
        //printf("%d ", s);
        //found = 1;
        return 1;
    } else {
        int left = find_steps(s-depth, d, depth+1);
        int right = find_steps(s+depth, d, depth+1);
#if 0
        if(left) {
            printf("%d ", s);
            return left+1;
        } else if(right) {
            printf("%d ", s);
            return right+1;
        } else return 0;
#endif
        return (left>right? right : left) + 1;
    }

}

void main() {
    int steps = 0, N;
    do {
    printf("Enter Number:");
    scanf("%d",&N);
    steps = find_steps(0, N, 1);
    printf("\nSteps require: %d\n", steps);
    } while(N);
}



