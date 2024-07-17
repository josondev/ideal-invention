'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def identity(n):
    final=[]
    for i in range(n):
        pair=[]
        for j in range(n):
            if(i==j):
                pair.append(1)
            else:
                pair.append(0)
        final.append(pair)
    return(final) 
    
def diagonal(m):
    diag=[]
    for i in range(len(m)):
        for j in range(len(m[0])):
            if(i==j):
               diag.append(m[i][j])
    return(diag)        
    
def elem(m):
    rest=[]
    for i in range(len(m)):
        for j in range(len(m[0])):
            if(i!=j):
               rest.append(m[i][j])
    return(rest) 

def matrix_type(m):
    diag=[]
    result=identity(len(m))
    if(m==result):
        return('identity')
    else:
        
        result1=diagonal(m)
        result2=elem(m)
        if(all(num==0 for num in result2)):
            if(all(num==result1[0] for num in result1)):
                return('scalar')
            else:
                return('diagonal')
        else:
            return('non-diagonal')
            
            
#print(matrix_type([[2, 0, 0], [0, 2, 0], [0, 0, 2]]))  
                    
        
#print(matrix_type([[1,0,0],[0,1,0],[0,0,1]]))        
    
    
    





