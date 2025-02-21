class Order:
    def __init__(self,a,b):
        self.item=a
        self.price=b

    def __gt__(self,a):
        if(self.price>a.price):
            print("True")
        else:
            print("False")    
        
ord1=Order("Chips",10)
ord2=Order("Coffee",40)
ord1>ord2