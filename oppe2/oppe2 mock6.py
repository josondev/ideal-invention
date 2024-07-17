'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
l1=[chr(i) for i in range(97,110)];l2=[chr(i) for i in range(110,123)[::-1]]

word=input()
final=''
dict1={};dict2={}

for i in range(len(l1)):
    dict1[l1[i]]=l2[i]
    dict2[l2[i]]=l1[i]

for i in range(len(word)):
    
    if(word[i] in dict1):
        final+=dict1[word[i]]
    
    elif(word[i] in dict2):
        final+=dict2[word[i]]

print(final)        
        
