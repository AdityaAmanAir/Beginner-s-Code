class Rectangler:
    def __init__(self, l,w):
        self.length=l
        self.width=w

    def area(self)    :
        print("Area = ", self.length * self.width)


    def pare(self)    :
        print("Area = ", 2*(self.length + self.width))    

bigRecBalls=Rectangler(10,5)        
bigRecBalls.area()
bigRecBalls.pare()