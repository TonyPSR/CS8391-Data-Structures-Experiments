#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int coeff;
    int pow;
    struct node *next;
};


struct node *poly1=NULL;
struct node *poly2=NULL;
struct node *polySum=NULL;


void createPoly(struct node *node)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->next = NULL;
    printf("\nENTER '-1' TO EXIT\n");
    while(1){
        printf("\nEnter coefficient:");
        scanf("%d",&temp->coeff);
        if(temp->coeff == -1){
            break;
        }
        printf("Enter power:");
        scanf("%d",&temp->pow);
        node->next = temp;
    }
}

void printPoly(struct node *node)
{
    while(node->next!=NULL)
    {
        printf("%d x^ %d",node->coeff,node->pow);
        node=node->next;
        if(node->next!=NULL)
            printf(" + ");
    }
}

void polyAddition(struct node *poly1,struct node *poly2,struct node *polySum)
{
    while(poly1->next &&  poly2->next)
        {
        if(poly1->pow>poly2->pow)
        {
            polySum->pow=poly1->pow;
            polySum->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow)
        {
            polySum->pow=poly2->pow;
            polySum->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        else
        {
            polySum->pow=poly1->pow;
            polySum->coeff=poly1->coeff+poly2->coeff;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        polySum->next=(struct node *)malloc(sizeof(struct node));
        polySum=polySum->next;
        polySum->next=NULL;
        }
        while(poly1->next || poly2->next)
        {
            if(poly1->next)
            {
                polySum->pow=poly1->pow;
                polySum->coeff=poly1->coeff;
                poly1=poly1->next;
            }
            if(poly2->next)
            {
                polySum->pow=poly2->pow;
                polySum->coeff=poly2->coeff;
                poly2=poly2->next;
            }
            polySum->next=(struct node *)malloc(sizeof(struct node));
            polySum=polySum->next;
            polySum->next=NULL;
    }
}
int main()
{
    poly1=(struct node *)malloc(sizeof(struct node));
    poly2=(struct node *)malloc(sizeof(struct node));
    polySum=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter Polynomial A:");
    createPoly(poly1);
    printf("\nEnter Polynomial B:");
    createPoly(poly2);
    printf("\nPolynomial A: ");
    printPoly(poly1);
    printf("\nPolynomial B: ");
    printPoly(poly2);
    polyAddition(poly1,poly2,polySum);
    printf("\n\nSummation of Polynomial A and B:\n");
    printPoly(polySum);
    return 0;
}
