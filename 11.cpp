#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Database{
    public:
    class Student{
        public:
        int roll;
        char div;
        char add[100];
        char name[100];
    };

    Student stud;

    void insert(){
        cout<<"\nEnter name: ";
        cin>>stud.name;
        cout<<"\nEnter roll: ";
        cin>>stud.roll;
        cout<<"\nEnter div: ";
        cin>>stud.div;
        cout<<"\nenter address: ";
        cin>>stud.add;

        ofstream f1;
        f1.open("abc.dat", ios::app | ios::binary);
        f1.write((char*)&stud,sizeof(stud));
        f1.close();
    }

    void display(){
        cout<<"Data: ";
        ifstream f;
        f.open("abc.dat",ios::in | ios::binary);
        while(f.read((char*)&stud,sizeof(stud)))
        {
            if (stud.roll != -1)
            {
            cout<<"\n\nNAme: "<<stud.name;
            cout<<"\nRoll: "<<stud.roll;
            cout<<"\ndiv: "<<stud.div;
            cout<<"\nadd: "<<stud.add;
            }
        }
        f.close();
    }

    void search(){
        int rn;
        cout<<"Enter roll no. to search: ";
        cin>>rn;
        ifstream f;
        f.open("abc.dat",ios::in | ios::binary);
        while(f.read((char*)&stud,sizeof(stud))){
            if(stud.roll == rn)
            {
            cout<<"\n\nNAme: "<<stud.name;
            cout<<"\nRoll: "<<stud.roll;
            cout<<"\ndiv: "<<stud.div;
            cout<<"\nadd: "<<stud.add;
            f.close();
            return;
            }
        }
        cout<<"data not found";
        f.close();
    }

    void Delete(){
        int rn;
        bool flag =0;
        cout<<"Enter roll no. to delete: ";
        cin>>rn;
        fstream fout;
        fstream fin;
        fin.open("abc.dat",ios::in | ios::binary);
        fout.open("temp.dat",ios::out | ios::binary);
        while(fin.read((char*)&stud,sizeof(stud))){
            if(stud.roll == rn)
                flag = 1;
            else
                fout.write((char*)&stud,sizeof(stud));           
        }
        
        fout.close();
        fin.close();
        remove("abc.dat");
        rename("temp.dat","abc.dat");
        if(flag)
            cout<<"data deleted\n";
        else
            cout<<"Data Not Found\n";
    }

};

int main(){
    Database d;
    int ch;
    do{
        cout<<"\n---- ---- MENU ---- ----\n";
        cout<<"\n1.insert\n2.delete\n3.update\n4.search\n5.display\nEnter choice: ";
        cin>>ch;
        switch(ch){
            case 1: d.insert(); break;
            case 2: d.Delete(); break;
            case 3: break;
            case 4: d.search(); break;
            case 5: d.display(); break;
            case 6: break;
        }

    }while(ch!=6);
}