#include<iostream>
using namespace std;
#define MAX 10

class Queue{
    public:
    int data[MAX];
    int front;
    int rear;
    stack(){
        front = -1;
        rear = -1;
    }
    bool empty(){
        return front==-1 || front>rear;
    }

    void insert(int x){
        if (front ==-1)
            front++;
        data[++rear]=x;
    }

    int Delete(){
        return data[front--];
    }
};

class node{
    public:
    int vertex;
    node* next;
};

int n, e;
int visited[MAX];
node* G[MAX];

void insert(int vi,int vj){
    node *p,*q;
    p =new node;
    p->vertex=vj;
    p->next=NULL;
    if(G[vi]==NULL)
        G[vi]=p;
    else{
        for(q=G[vi];q->next!=NULL;q=q->next);
        q->next=p;
    }
}

void BFS(int x){
    node *p;
    int w;
    Queue q;
    //q.insert(x);
    cout<<x;
    visited[x]=1;
    cout<<"\nG["<<x<<"] ----> ";
    while(!q.empty()){
        x = q.Delete();
        for(p=G[x];p!=NULL;p=p->next){
            w=p->vertex;
            if(visited[w]==0){
                q.insert(w);
                visited[w]=1;
                cout<<" "<<w;
            }
        }
    }

}
int main(){
    int vi,vj;
    cout<<"Enter no. of nodes: ";
    cin>>n;

    cout<<"Enter no. of edges: ";
    cin>>e;

    for(int i=0;i<n;i++){
        G[i]=NULL;
        visited[i];
    }

    for(int i = 0;i<e;i++){
        cout<<"enter pair (u,v): ";
        cin>>vi>>vj;
        insert(vi,vj);
        insert(vj,vi);
    }
    cout<<"BFS traversal: \n";
    for(int i=0;i<n;i++)
        BFS(i);
    
}