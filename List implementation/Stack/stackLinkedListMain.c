#include <stdio.h>
#include "stackLinkedList.c"

int main(){
    int choice, num;

    while(1){
        printf("\n\n1.Push\n2.Pop\n3.Print\n4.Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the number to push:");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                num = pop();
                if(num!= -1)
                    printf("\nPoped %d from the stack",num);
                break;
            case 3:
                printStack();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");

        }
    }

    return 0;
}
