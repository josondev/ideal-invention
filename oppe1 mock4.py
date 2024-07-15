'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
total={}
for i in range(4):
    info=input().split(',')
    total[info[0]]=int(info[1])+int(info[2])+int(info[3])+int(info[4])+int(info[5])
print(total)    