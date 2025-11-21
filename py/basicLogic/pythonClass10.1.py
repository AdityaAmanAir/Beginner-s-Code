class Employee:
    def __init__ (self,salary,id):
        
        self.id=id
        self.salary=salary
        
    def set_new_salary(self,n)   :
        self.salary=n 

    def set_new_id(self,n)   :
        self.id=n     

    def showDetails(self)    :
        print("NAME :", self.name)
        print("AGE :", self.age)
        print("SALARY :", self.salary)
        print("ID :", self.id)    

class Engineer (Employee):

    def __init__(self, name,age):
        self.name=name
        self.age=age
    def set_new_name(self,n)   :
        self.name=n

    def set_new_age(self,n)   :
        self.age=n

e1=Engineer("Aman",18)
e1.set_new_name("Aditya Aman")    
e1.set_new_age(19)    
e1.set_new_id(1111)
e1.set_new_salary(2000)

e1.showDetails()

        