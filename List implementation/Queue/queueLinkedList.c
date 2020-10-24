#include <stdio.h>


struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
struct node *temp;
struct node *ptr;


int isEmpty()
{
     if ((front == NULL) && (rear == NULL))
        return 1;
     else
        return 0;
}

void enQueue(int value)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->next = NULL;
        rear->data = value;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->next = temp;
        temp->data = value;
        temp->next = NULL;

        rear = temp;
    }
}


int deQueue()
{
    int num = -985454;

    ptr = front;

    if (!isEmpty())
    {
      if (ptr->next != NULL)
        {
            ptr = ptr->next;
            num = front->data;
            free(front);
            front = ptr;
        }
        else
        {
            num = front->data;
            free(front);
            front = NULL;
            rear = NULL;
        }
    }
    return num;
}

void printQueue()
{
    ptr = front;

    if (isEmpty())
    {
        printf("Queue is empty");
        return;
    }
    while (ptr != rear)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
    if (ptr == rear)
        printf("\n%d", ptr->data);
}

