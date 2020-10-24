#include <stdio.h>

int q[20], top = -1, front = -1,  rear = -1, a[20][20], vis[20], stack[20];

int deleteNode();
void add(int item);
void bfs(int s, int n);
void dfs(int s, int n);
void push(int item);
int pop();

int main(){
   char c, dummy;
   int n,i,s,ch,j;
   printf("\nEnter the number of nodes in graph:");
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
            vis[i] = 0;
        }
        printf("\n\nMenu");
        printf("\n1.BFS(Breadth First Search\n2.DFS(Depth First Search");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        printf("\nEnter the source vertex");
        scanf("%d", &s);
        switch(ch){
            case 1:
                bfs(s,n);break;
            case 2:
                dfs(s,n);break;
        }
        printf("\n\nWould you like to continue?\n(yes(y) or no(n)");
        scanf("%c", &c);
   }while(c=='y'||c=='Y');
   return 0;
}

void bfs(int source, int n){
    int p,i;
    add(source);
    vis[source] = 1;
    p=deleteNode();
    if(p!=0)
        printf("%d",p);
    for(i=1;i<=n;i++){
        if((a[p][i]!=0) && (vis[i] == 0)){
            add(i);
            vis[i] = 1;
        }
        p=deleteNode();
        if(p!=0)
            printf("%d",p);
    }

    for(i=1;i<=n;i++){
        if(vis[i]==0)
            bfs(i,n);
    }
}

void add(int item){
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

int deleteNode(){
    int k;
    if((front>rear) || (front== -1)){
        return 0;
    }else{
        k=q[front++];
    }
    return k;
}

void dfs(int source, int n){
    int i,k;
    push(source);
    vis[source] = 1;
    k=pop();
    if(k!=0){
        printf("%d",k);
    }
    for(i=1;i<=n;i++){
        if((a[k][i]!=0) && (vis[i]==0)){
            push(i);
            vis[i] = 1;
        }
        k=pop();
        if(k!=0)
            printf("%d",k);
    }
    for(i=1;i<=n;i++){
        if(vis[i] == 0){
            dfs(i,n);
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
