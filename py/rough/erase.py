class A:
    def disp(self):
    #abstract class method
        raise NotImplementedError()
class B(A):
    def disp(self):
        print("The method of class B")
class C(A):
    def disp(self):
        print("The method of class C")
#create object
ob=A() # we cannot create object
ob.disp() #we cannot call the method
ob1=B()
ob1.disp()
ob2=C()
ob2.disp()