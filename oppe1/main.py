'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
seq=input();boxes={};coins,f,s,t,fo,fi,k=[],[],[],[],[],[],[];maxi,x=0,0

for i in range(1,6):
    boxes[i]=0

for j in range(len(seq)):
    if(j==0):
        for i in range(j,len(seq),5):
            f.append(int(seq[i]))
        coins.append(f)    
    elif(j==1):
        for i in range(j,len(seq),5):
            s.append(int(seq[i]))
        coins.append(s)    
    elif(j==2):
        for i in range(j,len(seq),5):
            t.append(int(seq[i]))
        coins.append(t)    
    elif(j==3):
        for i in range(j,len(seq),5):
            fo.append(int(seq[i]))
        coins.append(fo)    
    elif(j==4):
        for i in range(j,len(seq),5):
            fi.append(int(seq[i]))
        coins.append(fi) 
        
for i in range(1,6):
    boxes[i]=sum(coins[i-1])
   
for key in boxes:
    k.append((key,boxes[key]))
    
for i in range(len(k)):
    if(maxi<k[i][1]):
        maxi=k[i][1]
        x=k[i][0]

print(x)        
