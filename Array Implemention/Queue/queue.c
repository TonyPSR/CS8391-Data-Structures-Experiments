#include<stdio.h>
#define SIZE 3

int a[SIZE];
int end = -1;
int start = 0;

void enQueue(int x){
    end++;
    if(end<SIZE){
        a[end] = x;
    }else{
        printf("Queue is full. Insertion not possible");
        end--;
    }
}

int deQueue(){
    int temp = -985454 ;
    if(start > end){
        start--;
    }else{
        temp = a[start];
    }
    start++;
    return temp;
}

void printQueue(){
    int i;
    if(start <= end){
        for(i=start; i<=end; i++){
            printf("\n%d",a[i]);
        }
    }else{
        printf("Queue is empty");
    }

}
