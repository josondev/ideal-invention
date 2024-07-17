'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def crowded_group(scores_dataset, subject, mark_limit):
    
    # Filter students who have marks for the specified subject
    subject_students = [student for student in scores_dataset if subject in student]

    # Extract marks for the specified subject
    marks = [student[subject] for student in subject_students]

    # Sort the marks in ascending order
    marks.sort()

    # Initialize variables to track the maximum group size and current group size
    max_group_size = 0
    current_group_size = 0

    # Iterate through the marks to find the largest possible group
    for i in range(len(marks)):
        current_group_size = 1  # Initialize group size for current student
        for j in range(i + 1, len(marks)):
            if marks[j] - marks[i] <= mark_limit:
                current_group_size += 1
            else:
                break  # Marks difference exceeds mark_limit, stop checking further
        max_group_size = max(max_group_size, current_group_size)

    return max_group_size
 
    
'''print(crowded_group([{'SeqNo': 1, 'Name': 'Devika', 'Gender': 'F', 'City': 'Bengaluru', 
 'Mathematics': 85, 'Physics': 100, 'Chemistry': 79, 'Biology': 75, 
 'Computer Science': 88, 'History': 60, 'Civics': 88, 'Philosophy': 95},{'SeqNo': 2, 'Name': 'D', 'Gender': 'F', 'City': 'Bengaluru', 
 'Mathematics': 85, 'Physics': 10, 'Chemistry': 79, 'Biology': 75, 
 'Computer Science': 88, 'History': 60, 'Civics': 88, 'Philosophy': 95},{'SeqNo': 3, 'Name': 'E', 'Gender': 'F', 'City': 'Bengaluru', 
 'Mathematics': 85, 'Physics': 9, 'Chemistry': 79, 'Biology': 75, 
 'Computer Science': 88, 'History': 60, 'Civics': 88, 'Philosophy': 95},{'SeqNo': 4, 'Name': 'De', 'Gender': 'F', 'City': 'Bengaluru', 
 'Mathematics': 85, 'Physics': 8, 'Chemistry': 79, 'Biology': 75, 
 'Computer Science': 88, 'History': 60, 'Civics': 88, 'Philosophy': 95},{'SeqNo': 5, 'Name': 'ka', 'Gender': 'F', 'City': 'Bengaluru', 
 'Mathematics': 85, 'Physics': 7, 'Chemistry': 79, 'Biology': 75, 
 'Computer Science': 88, 'History': 60, 'Civics': 88, 'Philosophy': 95},{'SeqNo': 6, 'Name': 'a', 'Gender': 'F', 'City': 'Bengaluru', 
 'Mathematics': 85, 'Physics': 6, 'Chemistry': 79, 'Biology': 75, 
 'Computer Science': 88, 'History': 60, 'Civics': 88, 'Philosophy': 95},{'SeqNo': 7, 'Name': 'b', 'Gender': 'F', 'City': 'Bengaluru', 
 'Mathematics': 85, 'Physics': 5, 'Chemistry': 79, 'Biology': 75, 
 'Computer Science': 88, 'History': 60, 'Civics': 88, 'Philosophy': 95},{'SeqNo': 8, 'Name': 'c', 'Gender': 'F', 'City': 'Bengaluru', 
 'Mathematics': 85, 'Physics': 4, 'Chemistry': 79, 'Biology': 75, 
 'Computer Science': 88, 'History': 60, 'Civics': 88, 'Philosophy': 95},{'SeqNo': 9, 'Name': 'd', 'Gender': 'F', 'City': 'Bengaluru', 
 'Mathematics': 85, 'Physics': 100, 'Chemistry': 79, 'Biology': 75, 
 'Computer Science': 88, 'History': 60, 'Civics': 88, 'Philosophy': 95}],'Physics',10))'''    
