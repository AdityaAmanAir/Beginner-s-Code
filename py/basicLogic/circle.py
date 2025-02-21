class Circle:
    def __init__(self,r):
        self.radius=r

    def area(self):
        self.area= 3.1415926*(self.radius**2)
        print(self.area)

    def perimeter(self):
        self.perimeter1=2*3.1415926*self.radius
        return self.perimeter1

c1=Circle(7)
c1.area()
print(c1.perimeter())