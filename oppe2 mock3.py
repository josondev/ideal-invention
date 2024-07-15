'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def survival(T):
    # Check if there exists a point on the metal plate where the temperature is less than or equal to the threshold T
    for x in range(6):
        for y in range(6):                              #for loop sodhapal
            temperature = 30 + x**2 + y**2 - 3*x - 4*y
            if temperature <= T:
                return True
    return False
    
    
        

print(survival(30))        
