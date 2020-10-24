#include<stdio.h>
#include "queueLinkedList.c"

int main(){
    int choice, num;

    while(1){
        printf("\n\n1.EnQueue\n2.DeQueue\n3.Print Queue\n4.Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the number to Insert:");
                scanf("%d", &num);
                enQueue(num);
                break;
            case 2:
                num = deQueue();
                if(num != -985454)
                    printf("\n%d is removed from the Queue",num);
                else
                    printf("\nQueue is empty");
                break;
            case 3:
                printQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");

        }
    }

    return 0;
}
