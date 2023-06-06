#include<iostream>
using namespace std;

class node{
    public:
    int count;
    string label;
    node* child[10];
};

class tree{
    public:
    node *root;
    tree(){
        root = NULL;
    }

    void create(){
        root = new node();
        cout<<"\nEnter name of book: ";
        cin>>root->label;
        cout<<"\nEnter no. of chapters: ";
        cin>>root->count;
        
        for(int i=0;i<root->count;i++)
        {
            root->child[i]= new node;
            cout<<"\nEnter chapter "<<i+1<<" ";
            cin>>root->child[i]->label;
            cout<<"\nEnter no. of sections: ";
            cin>>root->child[i]->count;

            for(int j=0;j<root->child[i]->count;j++)
            {
                root->child[i]->child[j]=new node;
                cout<<"\nEnter section "<<j+1<<" ";
                cin>>root->child[i]->child[j]->label;
                cout<<"\nEnter no. of sub-sections: ";
                cin>>root->child[i]->child[j]->count;

                for(int k =0;k<root->child[i]->child[j]->count;k++)
                {
                    root->child[i]->child[j]->child[k]= new node;
                    cout<<"\nEnter Sub-section "<<k+1<<" ";
                    cin>>root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }

    void display(){
        cout<<"\n---- Book Hierarchy ----\n";
        cout<<"\nBook name: "<<root->label<<endl;

        for(int i=0;i<root->count;i++){
            cout<<"\nChapter "<<root->child[i]->label;
            
            for(int j=0;j<root->child[i]->count;j++){
                cout<<"\nSection "<<root->child[i]->child[j]->label;

                for(int k =0;k<root->child[i]->child[j]->count;k++){
                    cout<<"\nSub-section "<<root->child[i]->child[j]->child[k]->label;
                }
            }
            cout<<endl;
        }
    }
};

int main(){
    tree t;
    int ch;
    do{
        cout<<"\n_______ MENU _______\n";
        cout<<"1.create\n2.Display\n3.Exit\nEnter choice: ";
        cin>>ch;
        switch(ch){
            case 1:t.create();break;
            case 2:t.display();break;
            case 3: cout<<"\n  Thank you  \n";break;
        }
    }while (ch!=3);
}