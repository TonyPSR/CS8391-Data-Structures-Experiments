#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *Next;
};

typedef struct Node *ptrToNode;
typedef ptrToNode List;
typedef ptrToNode Position;

int isEmpty(List L){
    return L->Next == NULL;
}

List CreateList(){
    List L;
    L = (struct Node*) malloc(sizeof(struct Node));
    if(L==NULL){
        printf("Fatal Error");
    }else{
        L->data = -1;
        L->Next = NULL;
    }
    return L;
}

void Insert(int x, Position P){
    ptrToNode Temp;
    Temp = (struct Node*) malloc(sizeof(struct Node));
    if(Temp == NULL){
        printf("Fatal Error");
    }else{
        Temp -> data = x;
        Temp -> Next = P -> Next;
        P -> Next = Temp;
    }
}

Position findPrevious(int x, List L){
    Position P;
    P = L;
    while(P->Next != NULL && P->Next->data!=x){
        P= P->Next;
    }
    return P;
}

int isLast(Position P){
    return (P->Next == NULL);
}

void Delete(int x, List L){
    Position P, TempCell;
    P = findPrevious(x,L);
    if(!isLast(P)){
        TempCell = P->Next;
        P->Next = TempCell -> Next;
        free(TempCell);
    }
}

void MakeEmpty(List L){
    if(L==NULL){
        printf("List is not created");
    }else{
        while(!isEmpty(L)){
            Delete(L->Next->data, L);
        }
    }
}

Position Find(int x,List L){
    Position Temp;
    Temp = L;
    while(Temp!=NULL){
        if(Temp->data == x){
            return Temp;
        }
        Temp = Temp->Next;
    }
    return Temp;
}

void Display (List L){
    L = L->Next;
    while(L!=NULL){
        printf("\n%d", L->data);
        L= L-> Next;
    }
}

List DeleteList(List L){
    MakeEmpty(L);
    free(L);
    L=NULL;
    return L;
}
