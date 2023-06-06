def elemets(X):
    itr = iter(X)
    for i in X:
        print(next(iter(X)))

def add(X,x):
    if x not in X:
        X.append(x)

def Delete(X,x):
    if x in X:
        X.remove(x);
    
def contain(X,x):
    return x in X
    
def size(X):
    return len(X)
    
def iterator(X):
    return next(iter(X))
    
def union(X,Y):
    union_Set = X
    for i in Y:
        if i not in X:
            union_Set.append(i)
    return union_Set

def intersection(X,Y):
    inter_set = []
    for i in X:
        if i in Y:
            inter_set.append(i)
    return inter_set
                
def difference(X,Y):
    diff_set = []
    for i in X:
        if i not in  Y:
            diff_set.append(i)
    return diff_set
    
def subset(X,Y):
    for i in X:
        if i not in Y:
            return False
    return True

#main menu
A = []
B = []
while True:
    print('''
    1.Add element 
    2.remove element
    3.contains
    4.length
    5.iterator
    6.intersection
    7.union
    8.difference
    9.subset
    ''')
    ch = int(input("Enter choice: "))
    if ch == 1:
        n = int(input("Enter no. of elements(SET A): "))
        for i in range(n):
            x = int(input(f"Enter element {i+1}"))
            add(A,x)
        n = int(input("Enter no. of elements(SET B): "))
        for i in range(n):
            x = int(input(f"Enter element {i+1}"))
            add(B,x)
        print("\nElemets in the set A are: ")
        elemets(A)
        print("\nElemets in the set B are: ")
        elemets(B)
    elif ch ==2:
        n = int(input("Enter 1 for Set A else any other no. : "))
        if(n==1):
            x = int(input("Enter element to delete: "))
            Delete(A,x)
        else:
            x = int(input("Enter element to delete: "))
            Delete(B,x)
    elif ch ==3:
        pass
    elif ch ==4:
        print("Size of Set A: ",size(A))
        print("Size of Set B: ",size(B))
    elif ch ==5:
        print("iterator set A",iterator(A))
        print("iterator set B",iterator(B))
    elif ch==6:
        print(intersection(A,B))
    elif ch ==7:
        print(union(A,B))
    elif ch ==8:
        print("difference(A-B): ",difference(B,A))
        print("difference(B-A): ",difference(A,B))
    elif ch==9:
        print("subset: ",subset(A,B))
    else:
        break
