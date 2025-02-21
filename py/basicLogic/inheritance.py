class car:
    def start(self):
         self.start1=True
         print("Started...")
         return 1

    def stop (self):
         self.stopt1=True 


class bmw(car):
     def __init__(self,name):
        self.name=name

car1= bmw("i7")  
car2=bmw("rtx")   

print(car1.name)
print(car1.start())