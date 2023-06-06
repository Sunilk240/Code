#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100
class node{
    public:
    char w[MAX],m[MAX];
    node *left, *right;
    int ht, bf;
    node(){
        left = NULL;
        right = NULL;
    }
};


int height(node* root){
    int lh,rh;
    if(root->left==NULL)
        lh=0;
    else
        lh=1+root->left->ht;
    if(root->right==NULL)
        rh=0;
    else
        rh=1+root->right->ht;
    if(lh>rh)
        return lh;
    return rh;   
}

int BF(node* root){
    int lh,rh;
    if(root->left==NULL)
        lh=0;
    else
        lh=1+root->left->ht;
    if(root->right==NULL)
        rh=0;
    else
        rh=1+root->right->ht;
    return lh-rh;  
}

node* rotate_left(node* root){
    node * p;
    p = new node;
    p = root->right;
    root->right = p->left;
    p->left = root;
    p->bf=BF(p);
    p->ht=height(p);
    return p;
}


node* rotate_right(node* root){
    node * p;
    p = new node;
    p = root->left;
    root->left = p->right;
    p->right = root;
    p->bf=BF(p);
    p->ht=height(p);
    return p;
}


node* LL(node* root){
    root = rotate_right(root);
    return root;
}

node* RR(node* root){
    root = rotate_left(root);
    return root;
}

node* LR(node* root){
    root->left = rotate_left(root->left);
    root = rotate_right(root);
    return root;
}

node* RL(node* root){
    root->right = rotate_right(root->right);
    root = rotate_left(root);
    return root;
}

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
                if(BF(root)==2){
                    if(strcmp(w,root->left->w)<0)
                        root = LL(root);
                    else        
                        root = LR(root);
                }
            }
            else if(strcmp(w,root->w)>0){
                root->right = insert(root->right,w,m);
                if(BF(root)==-2){
                    if(strcmp(w,root->right->w)>0)
                        root = RR(root);
                    else        
                        root = RL(root);
                }
            }
            else{
                cout<<"word already exisit:::\n";
            }
        }
        root->ht = height(root);
        root->bf = BF(root);
        return root;
    }

    node* update(node* root,char w[],char m[]){
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
        else if(strcmp(w,root->w)<0){
            root->left = Delete(root->left,w);
            if(BF(root)==-2){
                if(BF(root->right)>=0)
                    root = RL(root);
                else
                    root = RR(root);
            }   
        }
        else if(strcmp(w,root->w)>0){
            root->right = Delete(root->right,w);
            if(BF(root)==2){
                if(BF(root->left)>=0)
                    root = LL(root);
                else
                    root = LR(root);
            }
        }
        else{
        if(root->right!=NULL){
            node *temp = root->right;
            while(temp->left!=NULL){
            temp=temp->left;
            }
            strcpy(root->w,temp->w);
            root->right=Delete(root->right,temp->w);
        }
        else{
            return(root->left);
        }
        }
        root->ht = height(root);
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