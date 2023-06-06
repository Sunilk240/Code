#include<iostream>
using namespace std;
#define MAX 10
#define Serious 10
#define NonSerious 5
#define General 1

class PQ{
    public:
    int P[MAX];
    int N[MAX];
    int front,rear;
    PQ(){
        front = -1;
        rear = -1;
    }

    bool empty(){
        return front == -1 ;
    }

    bool full(){
        return rear>=MAX-1;
    }

    void enqueue(int value, int priority){
        int i;
        if(full()){
            cout<<"Queue is full\n";
            return;
        }
        if(front==-1){
            front++;
            rear++;
            P[rear]=priority;
            N[rear]=value;
            cout<<"Added.\n";
        }
        else{
            for(i=rear;i>=front;i--){
                if(P[i]<value){
                    P[i+1]=P[i];
                    N[i+1]=N[i];
                }
                else{
                    break;
                }
            }
            P[i+1]=priority;
            N[i+1]=value;
            rear++;
            cout<<"Added\n";
        }
    }

    void dequeue(){
        if(empty()){
            cout<<"Queue is empty\n";
            return;
        }
        int value = front;
        if(front==rear){
            front = -1;
            rear =-1;
        }
        else{
            front++;
        }
        cout<<"Deleted "<<N[value]<<" -- "<<P[value]<<endl;       
    }

    void display(){
    cout<<"Number\tPriority\n";
        for(int i=front;i<=rear;i++){
        cout<<N[i]<<"\t"<<P[i]<<endl;
        }
    }
};

int main(){
    PQ p;
    int ch;
    do{
    cout<<"\n---- ---- MENU ---- ----\n";
    cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ";
    cin>>ch;
    switch(ch){
        case 1:
            int ch2,x;
            cout<<"Enter value: ";
            cin>>x;
            cout<<"_______ Enter emergency level _______\n";
            cout<<"1. Serious\n2.NonSerious\n3.General\n";
            cin>>ch2;
            switch (ch2)
            {
            case 1:p.enqueue(x,Serious);break;
            case 2:p.enqueue(x,NonSerious);break;
            case 3:p.enqueue(x,General);break;
            }
        break;
        case 2:p.dequeue();break;
        case 3:p.display();break;
        case 4:cout<<"Than you\n";break;
    }


    }while(ch!=4);
}