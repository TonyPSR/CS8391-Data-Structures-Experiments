#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Node{
    int data;
    struct Node *next;
};


struct Node *start[10];
struct Node *node;
struct Node *p ;
struct Node *prev ;

int a[MAX];

int create(int num){
    return num%MAX;
}


void insert(int num){
    int key = create(num);
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = num;

    if(start[key] == NULL){
        start[key] = node;
        start[key]->next = NULL;
    }else{
        node->next = start[key];
        start[key] = node;
    }
}

void print(){
    int i;
    for(i=0; i<MAX; i++){
        if(start[i]==NULL){
            printf("......");
        }else{
            p = start[i];
            while(p != NULL){
                printf("%d\t", p->data);
                p = p->next;
            }
        }
        printf("\n");
    }
}

void del(int num){
    int key = create(num);
    if(start[key] == NULL){
        printf("No element found");
    }else{
        p = (struct Node*)malloc(sizeof(struct Node));
        prev = (struct Node*)malloc(sizeof(struct Node));
        p=start[key];

        if(p->data == num){
            start[key]=start[key]->next;
        }
        while(p->data != num){
            prev = p;
            p=p->next;
        }
        prev->next = p->next;
        free(p);
    }
}

int main(){
    int ch, num;
    do{
        printf("\n1.Insert\n2.Delete\n3.Print Hash Table");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the number to insert:");
                scanf("%d", &num);
                insert(num);
                break;
            case 2:
                printf("Enter the number to delete:");
                scanf("%d", &num);
                del(num);
                break;
            case 3:
                printf("\n\n");
                print();
                printf("\n\n");
        }
   }while(1);
    return 0;
}

