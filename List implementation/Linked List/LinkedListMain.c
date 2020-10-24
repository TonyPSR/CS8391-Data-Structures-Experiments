#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.c"

int main(){
    List L = NULL;
    Position P;
    char ch;
    int n,x,y,z;

    while(1){
        printf("\n\n1.Create\n2.Insert\n3.Delete\n4.MakeEmpty\n5.Find\n6.IsEmpty\n7.Display\n8.Delete List\n9.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &n);

        switch(n){
            case 1:
                if(L==NULL){
                    L = CreateList();
                    printf("\nList is created");
                }else{
                    printf("\nList is already created");
                }
                break;
            case 2:
                if(L==NULL){
                    printf("\nList is not created");
                }else{
                    printf("\nEnter the value:");
                    scanf("%d", &x);

                    if(L->Next == NULL){
                        Insert(x,L);
                    }else{
                        printf("Enter the posistion:");
                        scanf("%d", &y);
                        P = Find(y,L);
                        if(P!= NULL){
                            Insert(x,P);
                        }else{
                            printf("\nELement not in the list");
                        }
                    }
                }
                break;
            case 3:
                if(L==NULL){
                    printf("\nList is not created");
                }else if(L->Next == NULL){
                    printf("\nList is Empty");
                }else{
                    printf("\nEnter the value to delete:");
                    scanf("%d", &y);
                    Delete(y,L);
                }
                break;
            case 4:
                if(L==NULL){
                    L = CreateList();
                    printf("\nList is not created");
                }else{
                    if(L->Next == NULL){
                        printf("\nLIst is empty");
                    }else{
                        MakeEmpty(L);
                        printf("\n\nNow list is empty");
                    }
                }
                break;
            case 5:
                if(L==NULL){
                    printf("\nList is not created");
                }else{
                    if(L->Next == NULL){
                        printf("\nList is empty");
                    }else{
                        printf("\nEneter the value to find:");
                        scanf("%d", &z);
                        P= Find(z,L);
                        if(P==NULL){
                            printf("\nElement is not found in the list");
                        }else{
                            printf("\nElement is present in the list");
                        }
                    }
                }
                break;
            case 6:
                if(L==NULL){
                    printf("\nList is not created");
                }else if(isEmpty(L)){
                    printf("\nList is empty");
                }else{
                    printf("\nList contains some elements");
                }
                break;
            case 7:
                if(L==NULL){
                    printf("\nList is not created");
                }else{
                    Display(L);
                }
                break;
            case 8:
                if(L==NULL){
                    printf("\nList is not created");
                }else{
                    L = DeleteList(L);
                    printf("\n\nList is deleted");
                }
                break;
            case 9:
                exit(0);
            default:
                printf("\n\n\t\t...Wrong Entry...");
        }
    }
    return 0;
}
