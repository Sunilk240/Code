class Record:
    table = list(None for x in range(10))
    flag = list(0 for x in range(10))
    name = list(None for x in range(10))
r = Record()

def h(x):
    return x % 10

def h2(x):
    return 7 - x % 7

def lp_insert():
    n = input("Enter name: ")
    x = int(input("Enter no: "))
    key = h(x)
    for i in range(10):
        if(r.flag[key]==0):
            r.table[key]=x;
            r.name[key]=n;
            r.flag[key]=1;
            print("done")
            return
        key = (key + 1)%10
    print("Table is Full\n")

def lp_search():
    x = int(input("Enter no: "))
    key = h(x)
    for i in range(10):
        if(r.flag[key]==1 and r.table[key]==x):
            return i+1
        key = (key + 1)%10
    return -1
        


def dh_insert():
    n = input("Enter name: ")
    x = int(input("Enter no: "))
    key1 = h(x)
    key2 = h2(x)
    for i in range(10):
        a = (key1 + key2*i)%10
        if(r.flag[a]==0):
            r.table[a]=x;
            r.name[a]=n;
            r.flag[a]=1;
            return;
    print("Table is Full\n")



def dh_search():
    x = int(input("Enter no: "))
    key1 = h(x)
    key2 = h2(x)
    for i in range(10):
        a = (key1 + key2*i)%10
        if(r.flag[a]==1 and r.table[a]==x):
            return i+1
    return -1


def display():
    for i in range(10):
        if(r.flag[i]==1):
            print(f"{i}  {r.name[i]}  {r.table[i]}")
        else:
            print(f"{i}    - - - - - - -  ")


#main menu
while True:
    print("\n----- MENU  -----\n")
    print("1.Linerar Probing\n2.Double hashing\n3.Exit\n")
    ch = int(input("enter choice"))
    if ch ==1:
        ch2 =0
        while(ch2!=4):
            print("\n---- Linear Probing ----\n")
            print("1.Insert\n2.Search\n3.Display\n4.MAin Menu\n")
            ch2 = int(input("Enter choice: "))
            if ch2 == 1:
                lp_insert()
            elif ch2 == 2:
                x = lp_search()
                if(x==-1):
                    print("Not found\n")
                else:
                    print("No. of comparisons are: ",x)
            elif ch2 == 3:
                display()
            elif ch2 == 4:
                break;         
    elif ch ==2:
        ch2=0
        while(ch2!=4):
            print("\n---- Double hashing ----\n")
            print("1.Insert\n2.Search\n3.Display\n4.MAin Menu\n")
            ch2 = int(input("Enter choice: "))
            if ch2 == 1:
                dh_insert()
            elif ch2==2:
                x = dh_search()
                if(x==-1):
                    print("Not found\n")
                else:
                    print("No. of comparisons are: ",x)
            elif ch2 == 3:
                display()
            elif ch2 == 4:
                break;  
    else:
        print("  Thnakyou  ")
        break;
