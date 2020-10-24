#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int data;
    struct Stack *next;
};

struct Stack *top = NULL;
struct Stack *temp;


int pop(){
    int tempData;
    if(top == NULL){
        printf("\nThe stack is empty");
        return 0;
    }else{
        temp = top;
        tempData = temp->data;
        top = top->next;
        free(temp);
    }
    return tempData;
}

void push(int elem){
    temp = (struct Stack*)malloc(sizeof(struct Stack));
    temp->data = elem;
    temp->next = top;
    top = temp;
}

void printStack(){
    if(top==NULL){
        printf("\nThe stack is empty");
    }else{
        printf("\nThe elements in the stack are: ");
        for(temp = top; temp->next!=NULL;temp=temp->next){
            printf("%d->", temp->data);
        }
        printf("%d",temp->data);
    }


}


