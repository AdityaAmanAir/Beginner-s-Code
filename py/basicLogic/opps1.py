class Student:
    def __init__(self, name, mark1,mark2, mark3):
        self.name=name
        self.mark1=mark1
        self.mark2=mark2
        self.mark3=mark3

    def get(self):
        sum = (self.mark1+self.mark2+self.mark3)
        print(sum/3)

   #def __init__(self):
   #    pass    

#s1=Student
s1 = Student("Aditya",3,4,5)
s1.get()

s1.name="Aman"
s1.get()