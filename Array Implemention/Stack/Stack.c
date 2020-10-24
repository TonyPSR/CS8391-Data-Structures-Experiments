#include <stdio.h>
#define SIZE 10


int a[SIZE];
int top = -1;

int pop(){
    if(top <= -1){
        printf("Stack Underflow");
    }else{
        int temp = a[top];
        top--;
        return temp;
    }
    return -1;
}

void push(int x){
    top += 1;
    if(top > SIZE){
        printf("Stack Overflow");
    }else{
        a[top] = x;
    }
}

void printStack(){
    int i;
    if(top != -1){
        for(i=top; i>=0; i--){
            printf("\n%d",a[i]);
        }
    }else{
        printf("Stack is empty");
    }
}
