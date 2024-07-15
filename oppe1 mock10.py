'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
#print('Hello World')
def get_summary(trans):
    final=[];
    for i in trans:               #to show the store name 
        d={}
        for key in i:
            if(key=='TID'):
               d[key]=i[key]
               d['Cost']=0
            elif(key=='Items'):
                for key1 in i[key]:
                    d['Cost']+=(key1['Price']*key1['Qty'])
        final.append(d)    
    return(final)
 
'''print(get_summary([{
    'TID': 'Gurunath_8528', 
    'Items': [
        		{'Name': 'Notebook', 'Price': 50, 'Qty': 4}, 
        		{'Name': 'Pencil', 'Price': 10, 'Qty': 1}, 
        		{'Name': 'Eraser', 'Price': 15, 'Qty': 1}, 
        		{'Name': 'File', 'Price': 80, 'Qty': 1}
    		]
},{'TID': 'Gurunath_8470', 
    'Items': [
        		{'Name': 'Notebook', 'Price': 50, 'Qty': 1}, 
        		{'Name': 'Pencil', 'Price': 10, 'Qty': 2}, 
        		{'Name': 'Eraser', 'Price': 10, 'Qty': 2}, 
        		{'Name': 'File', 'Price': 10, 'Qty': 1}
    		]}]))'''                
                
            




