#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;


node *create(struct node *p){
    int x;
    printf("Enter the data (-1 for no data):");
    scanf("%d", &x);

    if(x==-1){
        return NULL;
    }
    p = (node*)malloc(sizeof(node));
    p->data = x;
    printf("Enter the left child of %d:\n", x);
    p->left = create(p->left);
    printf("Enter the right child of %d:\n", x);
    p->right = create(p->right);

    return p;
}

void preOrder(node *t){
    if(t!=NULL){
        printf("\n%d", t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}
void postOrder(node *t){
    if(t!=NULL){
        postOrder(t->left);
        postOrder(t->right);
        printf("\n%d", t->data);
    }
}

void inOrder(node *t){
    if(t!=NULL){
        inOrder(t->left);
        printf("\n%d", t->data);
        inOrder(t->right);
    }
}

int main(){
    node *root;
    root = create(root);
    printf("\nThe preorder traversal of tree is:\n");
    preOrder(root);
    printf("\nThe postOrder traversal of tree is:\n");
    postOrder(root);
    printf("\nThe inOrder traversal of tree is:\n");
    inOrder(root);
    return 0;
}
