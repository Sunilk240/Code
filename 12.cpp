#include<iostream>
using namespace std;
#include<fstream>
#include <cstring>
#define MAX 20

class Database{
    public:
    class Employee{
        public:
        int id;
        char name[MAX];
        int salary;
        Employee(){
            id = -1;
        }
    };
    class Index{
        public:
        int id;
        int position;
    };

Employee e;
Index i;

void add(){
    
    int pos;
    ofstream I;


    I.open("Index.dat", ios::in | ios::binary);
    I.seekp(0,ios::end);
    pos = I.tellp()/sizeof(i);
    I.close();

    cout<<"Enter Name: ";
    cin>>e.name;
    cout<<"Enter id: ";
    cin>>e.id;
    cout<<"Enter salary: ";
    cin>>e.salary;
    ofstream E;
    E.open("Employee.dat", ios::app | ios::binary);
    E.write((char*)&e,sizeof(e));
    E.close();
    

    i.id = e.id;
    i.position = pos;
    I.open("Index.dat", ios::app | ios::binary);
    I.write((char*)&i,sizeof(i));
    I.close();

    cout<<"Data added sucessfully";
}

void Delete(){
    int pos,x;
    fstream E;
    fstream I;
    E.open("Employee.dat", ios::in | ios::out);
    I.open("Index.dat", ios::in | ios::out);

    pos =-1;

    cout<<"Enter Index: ";
    cin>>x;

    while(I.read((char*)&i,sizeof(i))){
        if(i.id == x){
            pos = i.position;
        }
    }

    if(pos == -1){
        cout<<"record not found";
        return;
    }
    else{
        E.seekg(pos*sizeof(e),ios::beg);
        strcpy(e.name,"");
        e.salary = -1;
        e.id = -1;
        E.write((char*)&e,sizeof(e));



    }
    E.close();
    I.close();
}

void Search(){
    int pos,x;
    ifstream E;
    ifstream I;
    E.open("Employee.dat", ios::in|ios::binary);
    I.open("Index.dat", ios::in | ios::binary);

    pos =-1;

    cout<<"Enter Index: ";
    cin>>x;

    while(I.read((char*)&i,sizeof(i))){
        if(i.id == x){
            pos = i.position;
        }
    }

    if(pos == -1){
        cout<<"record not found";
        return;
    }
    else{
        E.seekg(pos*sizeof(e),ios::beg);
        E.read((char*)&e,sizeof(e));
        cout<<"\nName: "<<e.name;
        cout<<"\nID No: "<<e.id;
        cout<<"\nsalary: "<<e.salary;
        cout<<endl;
    }
    E.close();
    I.close();
}

void update(){
    int pos,x;
    char namee[MAX];
    int salaryy;
    fstream E;
    fstream I;
    E.open("Employee.dat", ios::in | ios::out);
    I.open("Index.dat", ios::in | ios::out);

    pos =-1;

    cout<<"Enter Index: ";
    cin>>x;
    
    while(I.read((char*)&i,sizeof(i))){
        if(i.id == x){
            pos = i.position;
        }
    }

    if(pos == -1){
        cout<<"record not found";
        return;
    }
    else{
        E.seekg(pos*sizeof(e));

        cout<<"Enter Name: ";
        cin>>namee;
        cout<<"Enter salary: ";
        cin>>salaryy;

        strcpy(e.name,namee);
        e.salary = salaryy;

        E.write((char*)&e,sizeof(e));

    }
    E.close();
    I.close();
}

void Display(){
    int flag = 0,pos=0;
    ifstream E;
    ifstream I;

    E.open("Employee.dat", ios::in);
    I.open("Index.dat", ios::in );
    // I.seekg(0,ios::beg);
    // E.seekg(0,ios::beg);
    while(I.read((char*)&i,sizeof(i)))
    {   
        
        pos = i.position;
        E.seekg(pos*sizeof(e),ios::beg);
        E.read((char*)&e,sizeof(e));
        if(e.id != -1)
        {
        cout<<"\nName: "<<e.name;
        cout<<"\nID No: "<<e.id;
        cout<<"\nsalary: "<<e.salary;
        cout<<endl;
        }
    }
    E.close();
    I.close();
}

};

int main(){
    Database dt;
    int ch;
    do{
    cout<<"\n---- ---- MENU ---- -----\n";
    cout<<"1.Add\n2.Delete\n3.Search\n4.Update\n5.Display\n6.Exit\n";
    cout<<"---- ---- ---- ---- -----\n";
    cout<<"Enter choice: ";
    cin>>ch;
    switch(ch){
        case 1: {
        
        dt.add();
       
        break;
        }
        case 2: dt.Delete();break;
        case 3: dt.Search();break;
        case 4: dt.update();break;
        case 5: dt.Display();break;
        case 6:cout<<"\nThank you\n";break;
    }
    }while(ch!=6);
}