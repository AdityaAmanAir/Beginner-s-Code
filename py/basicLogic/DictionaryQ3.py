# Nested Dictionary
# A nested dictionary represents a classroom with student names as keys and their details (like age, grade, and subjects) as another dictionary. 
# Write a program to:
# Add a new student to the dictionary.
# Update the grade of an existing student.
# Display all students and their details.


# Creating a nested Dictionary classroom
classroom = {
    "A": {"age": 14, "grade": "8th", "subjects": ["Math", "Science", "English"]},
    "B": {"age": 15, "grade": "9th", "subjects": ["History", "Math", "Geography"]},
}

# Add a new student to the dictionary
new_student_name = "C"
if new_student_name not in classroom:
    classroom[new_student_name] = {"age": 14, "grade": "8th", "subjects": ["Math", "English", "Art"]}
    print(f"Student {new_student_name} added.")
else:
    print(f"Student {new_student_name} already exists.")


# Update the grade of an existing student.
existing_student_name = "A"
if existing_student_name in classroom:
    classroom[existing_student_name]["grade"] = "9th"    	
    print(f"Grade of {existing_student_name} updated to 9th.")
else:
 	print(f"Student {existing_student_name} not found.")


#Display all students and their details.
print("\nClassroom Details:")
for student_name, details in classroom.items():
    print(f"Name: {student_name}, Details: {details}")
