#include "test.c"

int main(){
    int i,n,p;

    while(1){
            printf("\n1.Append\n2.Insertion\n3.Search\n4.Deletion\n5.Make Empty\n6.PrintList\n7.Exit\n");
            printf("\nEnter your choice:");
            scanf("%d", &n);

            switch(n){
                case 1:
                    printf("Enter the element:");
                    scanf("%d", &i);
                    append(i);
                    break;
                case 2:
                    printf("\nEnter the element:");
                    scanf("%d", &i);
                    printf("\nEnter the position:");
                    scanf("%d", &p);
                    insert(i,p);
                    break;
                case 3:
                    printf("Enter the element:");
                    scanf("%d", &i);
                    p=find(i);
                    if(p==27121977){
                        printf("\nThe given element is not found in the list");
                    }else{
                        printf("\n%d is found at position - %d", i,p);
                    }
                    break;
                case 4:
                    printf("\nEnter the element:");
                    scanf("%d", &i);
                    del(i);
                    break;
                case 5:
                    makeEmpty();
                    break;
                case 6:
                    printList();
                    break;
                case 7:
                    exit(0);
                default:
                    printf("Invalid Choice!!!");
            }
    }
    return 0;
}
