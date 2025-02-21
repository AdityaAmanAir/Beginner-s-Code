class Employee:
    def __init__(self,a,b,c):
        self.role=a
        self.department=b
        self.salary=c
    def showDetails(self):
        print(self.role, self.department, self.salary, sep="\n")

class Engineer(Employee):
    def __init__(self,a,b):
        self.name=a
        self.age=b
        super().__init__("Problem Solver","research", 350000)

e1=Employee("Developer", "A.R.",250000)    
e1.showDetails() 
eng1=Engineer("Aditya Aman","18")
eng1.showDetails()


