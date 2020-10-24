#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int a[SIZE];
int cur_pos=0;

void printList(){
    int i;
    if(cur_pos==0){
        printf("List is empty.");
    }else{
        for(i=0; i<cur_pos; i++){
            printf("Element at position - %d is %d\n",i,a[i]);
        }
    }
}

void append(int elem){
    if(cur_pos<=SIZE){
        a[cur_pos] = elem;
        cur_pos++;
    }else{
        printf("List is full");
    }
}
void insert(int elem, int pos){
    int i;
    if((cur_pos-1)==SIZE){
        printf("List is full.");
    }else{
        for(i=cur_pos; i>pos; i--){
            a[i] = a[i-1];
        }
        a[pos] = elem;
        cur_pos++;
    }
}

int find(int elem){
    int i=0;
    for(i=0; i<cur_pos; i++){
        if(a[i] == elem){
            return i;
        }
    }
    return 27121977;
}

void del(int elem){
    int j, temp;
    temp = find(elem);
    if(temp == 27121977){
        printf("%d is not found in list", elem);
    }else{
        for(j=temp; j<(cur_pos-1); j++){
            a[j] = a[j+1];
        }
        cur_pos--;
    }
}

void makeEmpty(){
    int i;
    for(i=0; i<cur_pos; i++){
        a[i] = 0;
    }
    cur_pos = 0;
}

