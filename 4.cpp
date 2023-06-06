#include<iostream>
using namespace std;
#define MAX 10

class node{
    public:
    char data;
    node* left, *right;
    node(){
        left = NULL;
        right = NULL;
    }
};

class stack{
    public:
    node* arr[MAX];
    int top;
    stack(){
        top = -1;
    }
    bool empty(){return top == -1;}
    bool full(){return top>=MAX-1;}
    void push(node* x){arr[++top]=x;}
    node* pop(){return arr[top--];}
    node* Top(){return arr[top];}
};

int priority(char ch){
    switch(ch){
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':return 3;
    }
}

//expression tree from inorder
node* exptree(char exp[]){
    stack operand_stk,operator_stk;
    node* p;
    int i=0;
    while (exp[i]!='\0'){
        p=new node();                                ////////////////////////////////////////////////
        p->data= exp[i];
        p->left = NULL;
        if(isalpha(exp[i])){
            operand_stk.push(p);
            }
        else{
            if(operator_stk.empty()){
                operator_stk.push(p);
            }
            else{
                if(priority(exp[i])>priority(operator_stk.Top()->data)){
                    operator_stk.push(p);
                }
                else{
                    while(!operator_stk.empty() && priority(exp[i])<=priority(operator_stk.Top()->data)){
                        node *q=new node;          ////////////////////////////////////////////////
                        q=operator_stk.pop();
                        q->right=operand_stk.pop();
                        q->left=operand_stk.pop();
                        operand_stk.push(q);
                    }
                    operator_stk.push(p);       //////////////
                }
                
            }
        }
        i++;
    }
    
    while(!operator_stk.empty() ){
        node *q=new node;          ////////////////////////////////////////////////
        q=operator_stk.pop();
        q->right=operand_stk.pop();
        q->left=operand_stk.pop();
        operand_stk.push(q);
    }
    
    return operand_stk.pop();
}

// void postorder(node* root){
//     if(root!=NULL){
//     postorder(root->left);
//     postorder(root->right);
//     cout<<root->data<<" ";
//     }
// }

void postorder(node* root){
    if (root==NULL){
        cout<<"Empty";
        return;
    }
    
    stack s1,s2;
    s1.push(root);
    node* p;
    while(!s1.empty()){
        root = s1.pop();
        s2.push(root);
        if(root->left!=NULL)
            s1.push(root->left);
        if(root->right!=NULL)
            s1.push(root->right);

    }
    while(!s2.empty()){
        cout<<s2.pop()->data;
    }
}

void Delete(node* root){
    if(root==NULL)
    return;
    Delete(root->left);
    Delete(root->right);
    delete root;
    cout<<"Deleted ";
}

int main(){
    node *root;
    root = NULL;
    char exp[20];
    int ch;
    do{
        cout<<"\n---- ---- MENU ---- ----\n";
        cout<<"1.create\n2.display\n3.Delete\n4.Exit\nEnter choice: ";
        cin>>ch;
        switch(ch){
            case 1: 
                cout<<"Enter infix expression: ";
                cin>>exp;
                root = exptree(exp);
                
            break;
            case 2: postorder(root);
             break;
            case 3: Delete(root);
            break;
            case 4: cout<<"Thankyou\n";break;
        }
    }while(ch!=3);
}