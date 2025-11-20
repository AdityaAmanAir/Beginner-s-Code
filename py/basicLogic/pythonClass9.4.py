class Account:
    def __init__(self,b,a):
        self.__balance=b
        self.__account=a

    def __credit(self,amount:int):
        self.__account+=amount

    def __debit(self,amount:int):
        self.__account-=amount    

    def add(self, amount):
        self.__credit(amount)

    def sub(self, amount):
        self.__debit(amount)    

    def balance(self)    :
        self.__init__()
        print("The amount in your Account is :", self.__balance)

b1=Account(10000,1234)        
b1.balance()
b1.add(2000)
b1.sub(500)
b1.balance