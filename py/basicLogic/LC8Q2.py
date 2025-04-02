students_enrolled_in_python={"Alice","Bob","Charlie",'David',"Eva",}
students_enrolled_in_java={"Charlie",
"David",
"Fiona",
"George",
"Henry",
}

#Identify students who are enrolled in both Python and Java courses.
print(students_enrolled_in_python.intersection(students_enrolled_in_java))

#Find students who are enrolled in either Python or Java but not both.
print(students_enrolled_in_java.symmetric_difference(students_enrolled_in_python))

#Determine the total number of unique students across both courses.
set1=students_enrolled_in_python.difference(students_enrolled_in_java)
set2=students_enrolled_in_java.difference(students_enrolled_in_python)
print(len(set1)+len(set2)+len(students_enrolled_in_python.intersection(students_enrolled_in_java)))