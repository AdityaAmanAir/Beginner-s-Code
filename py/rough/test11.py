class Person:
    name="NaN"
    age=18
    
    def __init__(self,name,dead):
        self.name=name
        self.death=-dead

    def changesNotInObjectButInClass(self):
        Person.name="Anonomus"  #it is an alies of each other

    def changesNotInObjectButInClass2(self):
        self.__class__.age=19   #it is an alies of each other

    @property
    def whenDead(self):
        return self.death*2+20

p1=Person("Aman",2)
print(p1.name)     
print(Person.name)  

p1.changesNotInObjectButInClass()
print(Person.name) 

p2=Person("Aditya",3)
print(p2.name)     
print(Person.name)

print(p2.age)
print(Person.age)

p2.changesNotInObjectButInClass2()

print(Person.age)

print(p2.death)
p2.death=10
print(p2.death)
print(p2.whenDead)
print(p2.death)