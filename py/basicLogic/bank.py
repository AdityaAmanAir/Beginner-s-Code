class Account:
    def __init__(self, a,b):
        self.balance=int(a)
        self.account=int(b)

    def debit(self,a):
        self.debits=int(a)
        self.balance = self.balance -self.debits
        print(self.debits, "was debited")

    def credit(self,a): 
        self.credits=int(a)
        self.balance = self.balance+self.credits
        print(self.credits, "was credited")


acc1=Account(10000, 10001)   
print(acc1.balance)     
print(acc1.account)
acc1.debit(1000)
acc1.credit(500)
acc1.debit(1000)
acc1.credit(500)
acc1.balance
