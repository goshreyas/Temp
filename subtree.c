#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct N {
    int info;
    struct N *left;
    struct N *right;
}Node;

Node *T1 = NULL, *T2 = NULL;

Node* newnode(int data)
{
    Node* N = (Node*) malloc(sizeof(Node));
    N->info = data;
    N->left = NULL;
    N->right = NULL;

    return(N);
}


int buildTree() {
    //Node *T1; *T2;

    T1 = newnode(1);
    T1->left = newnode(2);
    T1->right = newnode(3);
    T1->left->left = newnode(4);
    T1->left->right = newnode(5);
    T1->right->left  = newnode(6);
    T1->right->right = newnode(7);


    T2 = newnode(1);
    T2->left = newnode(2);
    T2->left->left = newnode(4);
    //T2->right = newnode(7);

}


void print_tree(Node *r, int l)
{
    int i;

    if(!r) return;

    print_tree(r->right, l+1);
    for(i=0; i<l; ++i) printf("   ");
    printf("%d\n", r->info);
    print_tree(r->left, l+1);
}

int check(Node *R1, Node *R2) {
    if(R2 == NULL) return TRUE;
    if(R1 == NULL && R2 != NULL) return FALSE;

    return (R1->info == R2->info) && check(R1->left, R2->left) && check(R1->right, R2->right);

}


int is_subtree(Node *R1, Node *R2) {
    if(R2 == NULL) return TRUE;
    if(R1 == NULL && R2 != NULL) return FALSE;

    return check(R1, R2) || is_subtree(R1->left, R2) || is_subtree(R1->right, R2);

}


int main(){
    int flag = 0;
    buildTree();
    print_tree(T1, 1);
    print_tree(T2, 1);

    flag = is_subtree(NULL, T2);
    printf("\nSubtree: %d\n", flag);
}







