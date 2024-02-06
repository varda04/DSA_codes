#linear probing

def insert_lp(n, ht, key):
    loc= key%n
    cnt=0
    while(ht[loc]!= -1 and cnt!=n):
        loc= (loc+1)%n
        cnt=cnt+1
    if cnt==n:
        print("Hash table is currently full!!!")
    else:
        ht[loc]=key
        print("Key successfully inserted.")
    print(ht)
    

def search_lp(n, ht, key):
    loc= key%n
    cnt=0
    while(ht[loc]!= key and cnt!=n):
        loc= (loc+1)%n
        cnt+=1
    if cnt==n:
        print("Key not present in the hash table.")
    else:
        print("Key found.")

def main():
    n=int(input("Enter the size of the hash table: "))
    ht=[]
    for i in range(n):
        ht.append(-1)
    flag=1
    while(flag):
        print("----------------MENU-----------------")
        print("Choose among the following operations to perform on hash table")
        print("1. Insert")
        print("2. Search")
        print("3. Exit")
        c=int(input("Enter your choice: "))
        if c==1:
            key=int(input("Insert number to be entered: "))
            insert_lp(n,ht,key)
        elif c==2:
            key=int(input("Insert number to be searched: "))
            search_lp(n,ht,key)
        elif c==3:
            print("Exiting.")
            flag=0
        else:
            print("Enter valid choice!!!")
main()


#quadratic probing

def insert_lp(n, ht, key):
    loc= key%n
    cnt=0
    step=0
    while(ht[loc]!= -1 and cnt!=n):
        loc= (loc+(step*step))%n
        cnt=cnt+1
        step+=1
    if cnt==n:
        print("Hash table is currently full!!!")
    else:
        ht[loc]=key
        print("Key successfully inserted.")
    print(ht)
    

def search_lp(n, ht, key):
    loc= key%n
    cnt=0
    step=0
    while(ht[loc]!= key and cnt!=n):
        loc= (loc+(step*step))%n
        cnt+=1
        step+=1
    if cnt==n:
        print("Key not present in the hash table.")
    else:
        print("Key found.")

def main():
    n=int(input("Enter the size of the hash table: "))
    ht=[]
    for i in range(n):
        ht.append(-1)
    flag=1
    while(flag):
        print("----------------MENU-----------------")
        print("Choose among the following operations to perform on hash table")
        print("1. Insert")
        print("2. Search")
        print("3. Exit")
        c=int(input("Enter your choice: "))
        if c==1:
            key=int(input("Insert number to be entered: "))
            insert_lp(n,ht,key)
        elif c==2:
            key=int(input("Insert number to be searched: "))
            search_lp(n,ht,key)
        elif c==3:
            print("Exiting.")
            flag=0
        else:
            print("Enter valid choice!!!")
main()



