'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def std_dev(X):
    import math
    mean=sum(X)/len(X)
    sum1=0
    for num in X:
        sum1+=(num-mean)**2
    #s=math.sqrt((sum1)/(len(X)-1))   
    return(math.sqrt((sum1)/(len(X)-1)))
    
X = [float(x) for x in input().split(',')]
sigma = std_dev(X)
print(f'{sigma:.2f}')

