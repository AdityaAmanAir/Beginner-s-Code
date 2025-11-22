class Employe:
    empCount=0

    def __init__(self,name,salary):
        self.name=name 
        self.salary=salary
        Employe.empCount+=1

    def disp(self)->list:
        print("name :", self.name)
        print("Salary :", self.salary)
        return (self.name, self.salary )
    
    def __del__(self):
        print("Saale gareeb!")
    
unemployed=Employe("Bihari", 1000)    
unemployed.disp()

unemployed=Employe("Brhaman", "free_money")    
unemployed.disp()

unemployed=Employe("yadav", "milk")    
unemployed.disp()
