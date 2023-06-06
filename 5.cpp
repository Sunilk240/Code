#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100
class node{
    public:
    char w[MAX],m[MAX];
    node *left, *right;
    node(){
        left = NULL;
        right = NULL;
    }
};


    void displayA(node *root){
        if(root==NULL) return;
        displayA(root->left);
        cout<<" "<<root->w;
        cout<<" "<<root->m;
        displayA(root->right);
    }

    void displayD(node *root){
        if(root==NULL) return;
        displayD(root->right);
        cout<<" "<<root->w;
        cout<<" "<<root->m;
        displayD(root->left);
    }

    node* insert(node *root,char w[],char m[]){
        node *p =new node;
        p->left=NULL;
        p->right = NULL;
        strcpy(p->w,w);
        strcpy(p->m,m);
        if(root==NULL){
            root = p;
        }
        else{
            if(strcmp(w,root->w)<0){
                root->left = insert(root->left,w,m);
            }
            else if(strcmp(w,root->w)>0){
                root->right = insert(root->right,w,m);
            }
            else{
                cout<<"word already exisit:::\n";
            }
        }
        return root;
    }

    node* update(node* root,char w[],char m[]){
        if(root==NULL) return NULL;
        if(strcmp(w,root->w)==0){
            strcpy(root->w,w);
            strcpy(root->m,m);
            return root;
        }
        else if(strcmp(w,root->w)<0){
            root->left = update(root->left,w,m);
        }
        else if(strcmp(w,root->w)>0){
            root->right = update(root->right,w,m);
        }
        return root;
    }

    node* Delete(node *root,char w[]){
        if(root == NULL)
            return NULL;
        if(strcmp(w,root->w)<0){
            root->left = Delete(root->left,w);
            return root;
        }
        if(strcmp(w,root->w)>0){
            root->right = Delete(root->right,w);
            return root;
        }
        if(root->left==NULL && root->right==NULL){
            node *temp = root;
            delete temp;
            return NULL;
        }
        if(root->left==NULL){
            node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        if(root->right==NULL){
            node *temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        node *temp = root->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        strcpy(root->w,temp->w);
        root->right=Delete(root->right,w);     
        return root;
    }

    void search(node* root,char w[]){
        if(root==NULL){
            cout<<"Tree is empty\n";
            return ;
        }
        int cmp = 0;
        while(root!=NULL){
            cmp++;
            if(strcmp(w,root->w)==0){
                cout<<"comparison: "<<cmp<<endl;
                return;
            } 
            if(strcmp(w,root->w)<0)
                root = root->left;
            if(strcmp(w,root->w)>0)
                root = root->right;   
        }
        cout<<"Not found\n";
    }

int main(){
    node *root;
    root = NULL;
    char w[MAX];
    char m[MAX];
    int ch;

    do{
    cout<<"\n----- ---- ---- ----\n";
    cout<<"1.Insert\n2.Update\n3.Delete\n4.Search\n5.display ascending\n6.display descending\n7.Exit\n";
    cout<<"----- ---- ---- ----\n";
    cout<<"Enter you choice:";
    
    cin>>ch;
    switch(ch){
        case 1:
            cout<<"Enter word:";
            cin>>w;
            cout<<"Enter meaning:";
            cin.ignore();
            cin.getline(m,MAX);
            root = insert(root,w,m);

            break;
        case 2:
            cout<<"Enter word:";
            cin>>w;
            cout<<"Enter meaning:";
            cin.ignore();
            cin.getline(m,MAX);
            root = update(root,w,m);
            break;
        case 3:
            cout<<"Enter word:";
            cin>>w;
            root = Delete(root,w);
            break;
        case 4:
            cout<<"Enter word:";
            cin>>w;
            search(root,w);
            break;
        case 5:
            displayA(root);
            break;
        case 6:
            displayD(root);
            break;
        case 7:exit(0);
        default:cout<<"Enter a vaild choice\n";
    }
    }while(ch!=7);
}