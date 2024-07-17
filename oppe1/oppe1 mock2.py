'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def long_tail(L):
    count=0
    for num in L:
        char=list(str(num))
        for i in range(len(char)):
            if(char[i]=='.'):
                if(len(char[:i+1])<len(char[i:])):
                    count+=1
    return(count)                
#print(long_tail([1.1, 2.0, 10.1, 38.001, 56.123, 100.00001]))    