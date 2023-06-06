#include<iostream>
using namespace std;
#define MAX 10

class stack{
    public:
    int data[MAX];
    int top;
    stack(){
        top = -1;
    }
    bool empty(){return top==-1;}
    void push(int x){data[++top]=x;}
    int pop(){return data[top--];}
};

int main(){
    int n,x;
    int edge[MAX][MAX];
    int visited[MAX];

    cout<<"Enter number of noders: ";
    cin>>n;

    cout<<"Enter 1 if edge is present else 0:\n ";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"EDGE["<<i<<"]["<<j<<"] ";
            cin>>edge[i][j];
            edge[j][i] = edge[i][j];
        }
    }

    cout<<"Adjacency Matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<edge[i][j];
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    cout<<"\nEnter starting vertex for DFS traversal: ";
    cin>>x;
    stack s;
    s.push(x);
    while(!s.empty()){
        x=s.pop();
        if(visited[x]==0){
            visited[x]=1;
            cout<<" "<<x;
            for(int i =0;i<n;i++){
                if(edge[x][i]!=0 && visited[i]==0){
                    s.push(i);
                }
            }
        }
    }



}