class Employee:
    def __init__(self,name,salary):
        self.name=name
        self.salary=int(salary)
        # self.bonus=0

    def __bonusCalc__(self)    :
        self.bonus=0.1*(self.salary)
        return(self.bonus)

    def bonus(self)    :
        self.__bonusCalc__()
        print("The  Salary is :", self.bonus)
        return self.bonus



e1=Employee("Gareeb", 1000)        
e1.bonus()
e1.__bonusCalc__() # this cannot be accesed from here

