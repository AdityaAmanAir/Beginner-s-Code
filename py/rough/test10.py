class car:
    def __init__(self):
        print("Constructer --")

    name ="XYZ"

    def colour(self,c, s,cot):    
        self.colour=c
        self.shade=s
        self.coating=cot

    @staticmethod
    def welcome():
        print("hello From Staticmethod Car", car.name)

    # def welcome(self):
    #     print("hello From Car", self.name)    
    # not allowed two same name !!!

    def bye(self):
        print("bye From Car", self.name)    

    def dimention(self, h,l,b)  :
        self.breath=b
        self.length=l
        self.height=h

rr=car()
bmw=car()
bmw.name="bmw"
bmw.welcome() #output : XYZ
bmw.bye()
rr.bye()
