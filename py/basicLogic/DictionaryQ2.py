# 2. A company wants to keep track of its employees' departments using a dictionary. 
# The keys in the dictionary represent employee IDs, and the values represent the department names. 
# Write a Python program to:
# 1. Add a new employee to the dictionary.
# 2. Remove an employee from the dictionary.
# 3.  Find the department of a given employee ID.
# 4. List all employees in a specific department.

company_Data={"0001":"H.R.","0002":"H.R.","0003":"developer","0004":"jr. Developer","0005":"Sr. Developer","0006":"Jr. Manager","0007":"BackEnd Engineer"}

company_Data.update("0008":"PR")

print(company_Data)