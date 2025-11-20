class Persion:
    def __init__(self,name:str,age:int):
        self.name=name
        self.age=age

class car:
    def __init__(self, brand:str,model:str,year:int):
        self.brand=brand
        self.model=model
        self.year=year

    def display_info(self):
        print("brand =", self.brand)
        print("model="+ self.model)
        print("year=", self.year)


p1=Persion("Chicken Brahman", 18)
print(p1.name)
print(p1.age)        

c1=car("yadav","cow",16)
c1.display_info()