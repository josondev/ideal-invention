'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def diagonal1(board):
    return([board[i][j] for i in range(len(board)) for j in range(len(board[0])) if i==j])

def diagonal2(board):
    return([board[i][j] for i in range(len(board[0])) for j in range(len(board[0])) if(j==len(board[0])-i-1)]) 

def columns(board):
    final1=[]
    for i in range(len(board)):
        pair=[]
        for j in range(len(board)):
            pair.append(board[j][i])
        final1.append(pair)
    return(final1) 

count=1    

def check():
    final=[]
    row1,row2,row3=['','',''],['','',''],['','','']
    count=0
    final.append(row1);final.append(row2);final.append(row3);flag,flag1=1,0
    while(flag and not flag1):
        print(final)
        ans=int(input('enter X position:'))
        
        try:
            if(1<=ans<=3):
                final[0][ans-1]='X'
                count+=1
                print(final)
                
        except IndexError:        
            if((final[0][ans-1]=='X' or final[0][ans-1]=='O' )and final[0][ans-1]!=''):
                while(flag):
                    #print(final)
                    ans=int(input('enter the correct position for X:'))
                    if(final[0][ans-1]==''):
                        final[0][ans-1]='X'
                        print(final)
                        break
        result1=diagonal1(final)
        result2=diagonal2(final)
        result3=columns(final)    
        
        if(result1.count('X')==3 or result2.count('X')==3):
            flag=0
            return('X is winner.')
        elif(result1.count('O')==3 or result2.count('O')==3):
            flag=0;flag1=1
            return('O is winner.')
        else:
            result1=diagonal1(final)
            result2=diagonal2(final)
            result3=columns(final)   
            for item in result3:
                if(item.count('X')==3):
                    flag=0
                    flag1=1
                    return('X wins.')
                elif(item.count('O')==3): 
                    flag=0
                    flag1=1
                    return('O wins.')
                    
            for row in final:
                if(row.count('X')==3):
                    flag=0
                    return('X wins')
                elif(row.count('O')==3):
                    flag=0
                    flag1=1
                    return('O wins.') 
            if(result1.count('X')==3 or result2.count('X')==3):
                flag=0
                return('X is winner.')
            elif(result1.count('O')==3 or result2.count('O')==3):
                flag=0
                return('O is winner.')        
            
        
        if(4<=ans<=6):
            try:
                if(final[1][ans-4]!='' and flag):
                        while(flag):
                            #print(final)
                            
                            ans=int(input('enter the correct position for X:'))
                            if(final[1][ans-4]==''):
                                final[1][ans-4]='X'
                                print(final)
                                break
                else:
                    final[1][ans-4]='X'
                    count+=1
                    print(final)
            except:    
                if(final[1][ans-4]!=''):
                        while(flag):
                            
                            #print(final)
                            ans=int(input('enter the correct position for X:'))
                            if(final[1][ans-4]==''):
                                final[1][ans-4]='X'
                                print(final)
                                break
                            
        if(result1.count('X')==3 or result2.count('X')==3):
            flag=0
            flag1=1
            return('X is winner.')
        elif(result1.count('O')==3 or result2.count('O')==3):
            flag=0
            flag1=1
            return('O is winner.')
        else:
            result1=diagonal1(final)
            result2=diagonal2(final)
            result3=columns(final)   
            for item in result3:
                if(item.count('X')==3):
                    flag=0
                    flag1=1
                    return('X wins.')
                elif(item.count('O')==3): 
                    flag=0
                    flag1=1
                    return('O wins.')
                    
            for row in final:
                if(row.count('X')==3):
                    flag=0
                    flag1=1
                    return('X wins')
                elif(row.count('O')==3):
                    flag=0
                    flag1=1
                    return('O wins.') 
            if(result1.count('X')==3 or result2.count('X')==3):
                flag=0
                flag1=1
                return('X is winner.')
            elif(result1.count('O')==3 or result2.count('O')==3):
                flag=0
                flag1=1
                return('O is winner.')       
                            
        if(7<=ans<=9):
            try:
                if(final[2][ans-7]!='' and flag):
                        while(flag):
                            #print(final)
                            ans=int(input('enter the correct position for X:'))
                            if(final[2][ans-7]==''):
                                final[2][ans-7]='X'
                                print(final)
                                break
                else:
                    final[2][ans-7]='X'
                    count+=1
                    print(final)
            except :    
                if(final[2][ans-7]!='' and flag):
                        while(flag):
                            #print(final)
                            ans=int(input('enter the correct position for X:'))
                            if(final[2][ans-7]==''):
                                final[2][ans-7]='X'
                                print(final)
                                break
                            
            result1=diagonal1(final)
            result2=diagonal2(final)
            result3=columns(final)   
            for item in result3:
                if(item.count('X')==3):
                    flag=0
                    flag1=1
                    return('X wins.')
                elif(item.count('O')==3): 
                    flag=0
                    flag1=1
                    return('O wins.')
                    
            for row in final:
                if(row.count('X')==3):
                    flag=0
                    flag1=1
                    return('X wins')
                elif(row.count('O')==3):
                    flag=0
                    flag1=1
                    return('O wins.') 
            if(result1.count('X')==3 or result2.count('X')==3):
                flag=0
                flag1=1
                return('X is winner.')
            elif(result1.count('O')==3 or result2.count('O')==3):
                flag=0
                flag1=1
                return('O is winner.')      
                            
        ans=int(input('enter O position:'))
        try:
            if(1<=ans<=3):
                final[0][ans-1]='O'
                count+=1
                print(final)
                
        except IndexError:        
            if(final[0][ans-1]!=''):
                while(flag):
                    
                    ans=int(input('enter the correct position for O:'))
                    if(final[0][ans-1]==''):
                        final[0][ans-1]='O'
                        print(final)
                        break
        result1=diagonal1(final)
        result2=diagonal2(final)
        result3=columns(final)    
        
        if(result1.count('X')==3 or result2.count('X')==3):
            flag=0
            flag1=1
            return('X is winner.')
        elif(result1.count('O')==3 or result2.count('O')==3):
            flag=0
            flag1=1
            return('O is winner.')
        else:
            result1=diagonal1(final)
            result2=diagonal2(final)
            result3=columns(final)   
            for item in result3:
                if(item.count('X')==3):
                    flag=0
                    flag1=1
                    return('X wins.')
                elif(item.count('O')==3): 
                    flag=0
                    flag1=1
                    return('O wins.')
                    
            for row in final:
                if(row.count('X')==3):
                    flag=0
                    flag1=1
                    return('X wins')
                elif(row.count('O')==3):
                    flag=0
                    flag1=1
                    return('O wins.') 
            if(result1.count('X')==3 or result2.count('X')==3):
                flag=0
                flag1=1
                return('X is winner.')
            elif(result1.count('O')==3 or result2.count('O')==3):
                flag=0
                flag1=1
                return('O is winner.')        
            
        
        if(4<=ans<=6):
            try:
                if(final[1][ans-4]!='' and flag):
                        while(flag):
                            #print(final)
                            
                            ans=int(input('enter the correct position for O:'))
                            if(final[1][ans-4]==''):
                                final[1][ans-4]='O'
                                print(final)
                                break
                else:
                    final[1][ans-4]='O'
                    count+=1
                    print(final)
            except:    
                if(final[1][ans-4]!=''):
                        while(flag):
                            
                            #print(final)
                            ans=int(input('enter the correct position for O:'))
                            if(final[1][ans-4]==''):
                                final[1][ans-4]='O'
                                print(final)
                                break
                            
        if(result1.count('X')==3 or result2.count('X')==3):
            flag=0
            flag1=1
            return('X is winner.')
        elif(result1.count('O')==3 or result2.count('O')==3):
            flag=0
            flag1=1
            return('O is winner.')
        else:
            result1=diagonal1(final)
            result2=diagonal2(final)
            result3=columns(final)   
            for item in result3:
                if(item.count('X')==3):
                    flag=0
                    return('X wins.')
                elif(item.count('O')==3): 
                    flag=1
                    return('O wins.')
                    
            for row in final:
                if(row.count('X')==3):
                    flag=0
                    flag1=1
                    return('X wins')
                elif(row.count('O')==3):
                    flag=0
                    flag1=1
                    return('O wins.') 
            if(result1.count('X')==3 or result2.count('X')==3):
                flag=0
                flag1=1
                return('X is winner.')
            elif(result1.count('O')==3 or result2.count('O')==3):
                flag=0
                flag1=1
                return('O is winner.')       
                            
        if(7<=ans<=9):
            try:
                if(final[2][ans-7]!='' and flag):
                        while(flag):
                            print(final)
                            ans=int(input('enter the correct position for O:'))
                            if(final[2][ans-7]==''):
                                final[2][ans-7]='O'
                                print(final)
                                break
                else:
                    final[2][ans-7]='O'
                    count+=1
                    print(final)
            except :    
                if(final[2][ans-7]!='' and flag):
                        while(flag):
                            #print(final)
                            ans=int(input('enter the correct position for O:'))
                            if(final[2][ans-7]==''):
                                final[2][ans-7]='O'
                                print(final)
                                break
                            
            result1=diagonal1(final)
            result2=diagonal2(final)
            result3=columns(final)   
            for item in result3:
                if(item.count('X')==3):
                    flag=0
                    flag1=1
                    return('X wins.')
                elif(item.count('O')==3): 
                    flag=0
                    flag1=1
                    return('O wins.')
                    
            for row in final:
                if(row.count('X')==3):
                    flag=0
                    flag1=1
                    return('X wins')
                elif(row.count('O')==3):
                    flag=0
                    flag1=1
                    return('O wins.') 
            if(result1.count('X')==3 or result2.count('X')==3):
                flag=0
                flag1=1
                return('X is winner.')
            elif(result1.count('O')==3 or result2.count('O')==3):
                flag=0
                flag1=1
                return('O is winner.')      
                            
    if(count==9):
        return('draw')

        
          
        
print(check())       















