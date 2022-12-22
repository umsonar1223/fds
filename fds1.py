groupA=[]
groupB=[]
groupC=[]

n1=int(input("Enter the student count who play Cricket : "))
print("Enter %i student name : "%n1)
groupA=list(map(str,input().split(" ")))

n2=int(input("Enter the student count who play Badminton : "))
print("Enter %i student name : "%n2)
groupB=list(map(str,input().split(" ")))

n3=int(input("Enter the student count who play Football : "))
print("Enter %i student name : "%n3)
groupC=list(map(str,input().split(" ")))

print(" Group A = ",groupA)
print(" Group B = ",groupB)
print(" Group C = ",groupC)

def first(groupA,groupB):
    newlist=[]
    lena=len(groupA)
    lenb=len(groupB)
    
    for i in range(lena):
        for j in range(lenb):
            if(groupA[i]==groupB[j]):
                newlist.append(groupA[i])
                break
    print(" 1) List of students who play cricket and Badminton : ")
    print(newlist)


def second(groupA,groupB):
    
    newlist=[]
    lena=len(groupA)
    lenb=len(groupB)
    
    for i in range(lena):
        for j in range(lenb):
            if(groupA[i]==groupB[j]):
                flag=1
                break
            
        if(flag==0):
            newlist.append(groupA[i])
        flag=0
                
    for i in range(lenb):
        for j in range(lena):
            if(groupB[i]==groupA[j]):
                flag=1
                break
            
        if(flag==0):
            newlist.append(groupB[i])
        flag=0
    print("2) List of students who play either cricket or Badminton but not both : ")
    print(newlist)

def third(groupA,groupB,groupC):
    
    newlist=[]
    lena=len(groupA)
    lenb=len(groupB)
    lenc=len(groupC)
    flag=0
    for i in range(lenc):
        for j in range(lena):
            if(groupC[i]==groupA[j]):
                flag=1
                break
        for var in range(lenb):
            if(groupC[i]==groupB[var]):
                flag=1
                break
        if(flag==0):
            newlist.append(groupC[i])
        flag=0
        
    print("3) Number of students who play neither cricket nor Badminton  : ")
    print(newlist)
            
def fourth(groupA,groupB,groupC):
    list1=[]
    newlist = []
    lena = len(groupA)
    lenb = len(groupB)
    lenc = len(groupC)
    flag=0
    for i in range(lena):
        for j in range(lenc):
            if(groupA[i]==groupC[j]):
                list1.append(groupA[i])
                break
            
    newl=len(list1)
    for i in range(newl):
        for j in range(lenb):
            if(list1[i]==groupB[j]):   
                flag=1
                break
        if(flag==0):
            newlist.append(list1[i])
        flag=0
        
    print("4) Number of students who play cricket and football but not badminton ")
    print(newlist)
       
first(groupA,groupB)
second(groupA,groupB)
third(groupA,groupB,groupC)
fourth(groupA,groupB,groupC)
