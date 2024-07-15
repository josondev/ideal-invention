'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
n=input()
final='';count=0
for char in n:
    if(char=='l'):
        final+='1'
        count+=1
    elif(char=='o'):
        final+='0'
        count+=1
    else:
        final+=char
if(count>0):
    print(count,'mistakes')
    print(final)
else:
    print('No mistakes')