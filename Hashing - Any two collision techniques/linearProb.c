#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int key,i;
int a[MAX];

int create(int num){
    return num%MAX;
}
void init(){
    for(i=0; i<MAX; i++){
        a[i] = -1;
    }
}

void insert(int num){
    int f=0;
    key = create(num);
    if(a[key]==-1){
        a[key] = num;
    }else{
        int count = 0;

        //getting no. of occupied location in array
        for(i=0; i<MAX; i++){
            if(a[i]!=-1)
                count += 1;
        }

        if(count==MAX){
            printf("\nHash table full");
        }

        for(i=key+1; i<MAX; i++){
            if(a[i] == -1){
                a[i] = num;
                f=1;
                break;
            }
        }
        if(f==0){
            for(i=0; i<key; i++){
                if(a[i] == -1){
                    a[i] = num;
                    break;
                }
            }
        }

    }
}

void print(){
    for(i=0;i<MAX;i++){
        if(a[i] == -1){
            printf("\n....");
        }else
            printf("\n%d", a[i]);
    }
}

int main(){
    init();
    int ch, num;
    do{
        printf("\n1.Insert\n2.Print Hash Table\n3.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the number to insert:");
                scanf("%d", &num);
                insert(num);
                break;
            case 2:
                printf("\n\n");
                print();
                printf("\n\n");
                break;
            case 3:
                exit(0);break;
            default:
                printf("\nInvalid choice!!");
        }
   }while(1);
    return 0;
}
