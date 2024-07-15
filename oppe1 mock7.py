'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
sum1,sum2=0,0
seq=input().split(',')
#print(seq)
for i in range(len(seq)//2):
    sum1+=int(seq[i])
for j in range((len(seq)//2),len(seq)):
    sum2+=int(seq[j])
if(sum1==sum2):
    print('balanced')
else:
    if(sum1>sum2):
        print('left heavy')
    elif(sum2>sum1):
        print('right heavy')
