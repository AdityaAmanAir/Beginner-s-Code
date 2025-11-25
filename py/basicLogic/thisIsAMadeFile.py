def hello():
    print("Hello From Def 1")

def hello2():
    print("Hello From Def 2")    

print("Hello Global 1") 
print(__name__)      # Function name: "my_func"
print(__doc__)       # Function docstring

if __name__=="__main__":
    print("Hello from main")
    hello2()

print("Hello Global 2")    