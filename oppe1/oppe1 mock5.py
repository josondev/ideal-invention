'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def diagonal1(board):
    d1=[]
    for i in range(len(board)):
        for j in range(len(board[0])):
            if(i==j):
                d1.extend(board[i][j])
    return(d1)             
 
def diagonal2(board):
    d2=[]
    for j in range(len(board[0])):
        for i in range(len(board[0])-j-1):
            
            d2.extend(board[i][j])
    return(d2) 
    
def columns(board):
    col=[]
    for i in range(len(board[0])):
        pair=[]
        for j in range(len(board)):
            pair.extend(board[j][i])
        col.append(pair)
    return(col)    
       

def matrix(n):
    final=[]
    for i in range(n):
        pair=[]
        rows=input()
        for item in rows:
            pair.extend(item)
        final.append(pair)    
    return(final)
    
def tic_tac_toe(board):
    
    result1 = diagonal1(board)
    result2 = diagonal2(board)
    result3 = columns(board)
        
    for i in range(len(result1)):
        if result1[i] == 'X' or result2[i] == 'X' or result3[i].count('X') == 3:
            return 'X'
        elif result1[i] == 'O' or result2[i] == 'O' or result3[i].count('O') == 3:
            return 'O'
    
    for i in range(len(board)):
        if board[i].count('X') == 3:
            return 'X'
        elif board[i].count('O') == 3:
            return 'O'
                
    return -1

print(tic_tac_toe(matrix(3)))    