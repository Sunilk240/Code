#include<iostream>
using namespace std;
#define MAX 10

int p[MAX];
int q[MAX];
int word[MAX];
int n;

int w[MAX][MAX];
int c[MAX][MAX];
int r[MAX][MAX];

class node{
    public:
    int data;
    node *left, *right;
    node(){
        left = NULL;
        right = NULL;
    }
};

int find(int i, int j){
    int min = 9999;
    int k,l;
    for(int k=i;k<=j;k++){
        if(min>c[i][k-1]+c[k+1][j]){
            min = c[i][k-1] + c[k+1][j];
            l=k;
        }
    }
    return l;
}

node * construct(int i, int j){
    node *root;
    if(i>j){
        return NULL;
    }
    root = new node;
    int x = r[i][j];
    int y = word[x];
    root->data= y;
    root->left=construct(i,r[i][j]-1);
    root->right=construct(r[i][j]+1,j);
    return root;
}

node* optimal(){
    node *root;
    root = NULL;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            w[i][j]=c[i][j]=r[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        w[i][i]=p[i]+q[i]+q[i-1];
        c[i][i]=w[i][i];
        r[i][i]=i;
        cout<<"\n"<<w[i][i]<<" "<<c[i][i]<<" "<<r[i][i];
    }
    cout<<" ---- \n\n";
    
    int j,k;
    for(int step=2;step<=n;step++){
        for(int i=1;i<=n-step+1;i++){
            j=i+step-1;
            w[i][j]=w[i][j-1] + p[j] + q[j];
            k = find(i,j);
            c[i][j] = w[i][j] + c[i][k-1] + c[k+1][j];
            r[i][j] = k;

            cout<<"\n"<<w[i][j]<<" "<<c[i][j]<<" "<<r[i][j];
        }
    }

    
    root = construct(1,n);
    return root;
}


void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    cout<<"Enter no. of identifiers: ";
    cin>>n;
    cout<<"Enter identifiers: ";
    for(int i=1;i<=n;i++)
        cin>>word[i];
    cout<<"Enter probability of succes node: ";
    for(int i=1;i<=n;i++)
        cin>>p[i];
    cout<<"Enter probability of failure node: ";
    for(int i=0;i<=n;i++)
        cin>>q[i];

    node* root;
    root = optimal();
    cout<<"\n Order sequence is: ";
    inorder(root);
}

