class Employees:
    def calculate_payment(self):
        return -1
    
class developer(Employees):

    def __init__(self,monthly):
        self.monthly=monthly
        # return self.monthly

    def calculate_payment(self):
        self.pay=self.monthly
class manager(Employees):

    def __init__(self,yearly):
        self.yearly=yearly
        # return self.yearly

    def calculate_payment(self):
        self.pay=self.yearly //12

class intern(Employees):

    def __init__(self,hourly,rate):
        self.hourly  =hourly
        # return self.hourly

    def calculate_payment(self):
        self.pay=self.hourly * self.rate   

company1=Employees[
    manager(12000),
    developer(10000),
    intern(48,1000)
]            