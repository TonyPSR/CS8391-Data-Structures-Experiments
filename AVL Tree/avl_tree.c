#include<stdio.h>
#include<stdlib.h>

int q[20], i,j, front=-1, rear = -1, a[20][20], visited[20], top=-1, stack[20];
int p;

int dequeue(){
    int k;
    if((front>rear) || (front== -1)){
        return 0;
    }else{
        k=q[front++];
    }
    return k;
}

void enqueue(int item){
    if(rear == 19){
        printf("\n\nQueue is full: Error, no space");
    }else{
        if(rear == -1){
            q[++rear] = item;
            front++;
        }else{
            q[++rear] = item;
        }
    }
}

void bfs(int s, int n){

    enqueue(s);
    visited[s] = 1;
    p = dequeue();
    if(p!=0){
        printf("%d ",p);
    }
    for(i=1; i<=n; i++){
        if(a[p][i]!=0 && visited[i]==0){
            enqueue(i);
            visited[i] = 1;
        }
        p=dequeue();
        if(p!=0){
            printf("%d",p);
        }
    }

    for(i=1; i<=n; i++){
        if(visited[i] == 0){
            bfs(i,n);
        }
    }
}

void push(int item){
    if(top==19){
        printf("\n\nStack Overflow");
    }else{
        stack[++top] = item;
    }
}

int pop(){
    int k;
    if(top == -1){
        return 0;
    }else{
        k=stack[top--];
        return k;
    }
}

void dfs(int s, int n){
    int i,k;
    push(s);
    visited[s] = 1;
    k=pop();
    if(k!=0){
        printf("%d",k);
    }
    while(k!=0){
        for(i=1;i<=n;i++){
            if((a[k][i]!=0) && (visited[i]==0)){
                push(i);
                visited[i] = 1;
            }
            k=pop();
            if(k!=0)
                printf("%d",k);
        }
        for(i=1;i<=n;i++){
            if(visited[i] == 0){
                dfs(i,n);
            }
        }
    }
}



int main(){
   int n,i,s,ch,j;
   printf("\nEnter the number of nodes in graph:\n");
   scanf("%d", &n);

   for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("\nEnter if %d has a node with %d",i,j);
            scanf("%d", &a[i][j]);
        }
   }
   printf("\n\nThe Adjacency Matrix\n");
   for(i=1;i<=n;i++){
        for(j=1; j<=n;j++){
            printf("%d", a[i][j]);
        }
        printf("\n");
   }

   do{
        for(i=1;i<=n;i++){
            visited[i] = 0;
        }
        printf("\n\nMenu");
        printf("\n1.BFS(Breadth First Search\n2.DFS(Depth First Search\n3.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        printf("\nEnter the source vertex");
        scanf("%d", &s);
        switch(ch){
            case 1:
                bfs(s,n);break;
            case 2:
                dfs(s,n);break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!!!");
        }
   }while(1);

   return 0;
}

