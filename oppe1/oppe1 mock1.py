'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def prime(n):
    for i in range(2,int(n**0.5)+1):
        if(n%i==0):
            return(False)
    return(True)        
            
def twin_primes(p,q):
    
    if(prime(p)==True and prime(q)==True and abs(p-q)==2):
        return(True)
    return(False)    
#print(twin_primes(int(input()),int(input())))        
    
    