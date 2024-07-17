'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def is_prime(n):
    #def is_prime(n):
    # Check if the number is less than
    # or equal to 1, return False if it is
    if n <= 1:
        return False
    # Loop through all numbers from 2 to
    # the square root of n (rounded down to the nearest integer)
    for i in range(2, int(n**0.5)+1):
        # If n is divisible by any of these numbers, return False
        if n % i == 0:
            return False
    # If n is not divisible by any of these numbers, return True
    return True
    
    
def primes_galore(L):
    result=[];count=0
    for i in range(len(L)):
        if(is_prime(i)):
            result.append(L[i])
    for num in result:
        if(is_prime(num)):
            count+=1
    return(count)        
            
        
        

#print(is_prime(1))
print(primes_galore([1, 3, 11, 18, 17, 5, 6, 8, 10]))          