#include<iostream>
using namespace std;
#define infi 9999
#define MAX 10

int main(){
    int n;
    int distance[MAX][MAX];
    cout<<"Enter no. of offices: ";
    cin>>n;
    cout<<"\nInput MAtrix: \n";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"Enter distavce between office ["<<i<<"]["<<j<<"] ";
            cin>>distance[i][j];
            distance[j][i]= distance[i][j];
        }
    }
    cout<<"display: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<distance[i][j];
        }
        cout<<endl;
    }

    int selected[MAX];
    int ne=0;
    int cost=0;
    int min,x,y;

    for(int i=0;i<n;i++){
        selected[i]=0;
    }

    selected[0]=1;
    while(ne<n-1){
        min = infi;
        for(int i=0;i<n;i++){
            if(selected[i]==1){
                for(int j=0;j<n;j++){
                    if(selected[j]==0){
                        if(min>distance[i][j]){
                            min = distance[i][j];
                            x =i;
                            y= j;
                        }
                    }
                }
            }
        }
        selected[y]=1;
        cout<<"\nDistance between office ["<<x<<"]["<<y<<"]   ---> "<<distance[x][y];
        cost+=distance[x][y];
        ne++;
    }
    cout<<"\nMinimum cost: "<<cost;
    return 0;
}