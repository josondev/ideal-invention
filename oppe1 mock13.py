'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def exactly_two(players):
    l=[];final=[]
    for name in players:
        count=0
        for sport in players[name]:
            if(players[name][sport]==True):
                count+=1
        l.append([name,count])        
    #return(l)
    for i in range(len(l)):
        if(l[i][1]==2):
            final.append(l[i][0])
    return(set(final))
    
'''print(exactly_two({
    'Karthik': {
        'Tennis': True,
        'Badminton': True,
        'Cricket': False
           },
    'Rahul': {
        'Tennis': False,
        'Badminton': False,
        'Cricket': True
    },
    'shyam': {
        'Tennis': True,
        'Badminton': True,
        'Cricket': False
           }
}))'''    
    
